/*
 * procedurebodycheck.c -- semantic analysis
 */

#include <string.h>
#include <util/errors.h>
#include <absyn/absyn.h>
#include <types/types.h>
#include "procedurebodycheck.h"
#include <table/table.h>
#include <stdlib.h>

#define INT_BYTE_SIZE    4
#define  BOOL_BYTE_SIZE 4


void check(Program *program, SymbolTable *globalTable) {


    while (!program->isEmpty) {
        if (program->head->kind == DECLARATION_PROCEDUREDECLARATION)
            checkProc(program->head, globalTable);
        program = program->tail;
    }

    Entry *mainEntry = lookup(globalTable, newIdentifier("main"));
    if (mainEntry == NULL)
        mainIsMissing();
    else if (mainEntry->kind != ENTRY_KIND_PROC)
        mainIsNotAProcedure();
    else if (!mainEntry->u.procEntry.paramTypes->isEmpty)
        mainMustNotHaveParameters();

}

void checkProc(GlobalDeclaration *procDecl, SymbolTable *globalTable) {
    Entry *procEntry = lookup(globalTable, procDecl->name);
    checkStmList(procEntry, procDecl->u.procedureDeclaration.body, globalTable);
}

void checkStmList(Entry *procEntry, StatementList *stmList, SymbolTable *globalTable) {
    while (!stmList->isEmpty) {
        checkProcStm(procEntry, stmList->head, globalTable);
        stmList = stmList->tail;
    }
}

void checkProcStm(Entry *procEntry, Statement *stm, SymbolTable *globalTable) {
    Entry *calleeEntry = NULL;
    ParamTypes *calleeParamTypes = NULL;
    ExpressionList *calleeArgsList = NULL;
    switch (stm->kind) {
        case STATEMENT_ASSIGNSTATEMENT:
            checkProcVariable(procEntry, stm->u.assignStatement.target, globalTable);
            checkProcExpression(procEntry, stm->u.assignStatement.value, globalTable);

            if (stm->u.assignStatement.value->dataType != stm->u.assignStatement.target->dataType)
                assignmentHasDifferentTypes(stm->line);

            if (stm->u.assignStatement.value->dataType != intType)
                assignmentRequiresIntegers(stm->line);

            break;

        case STATEMENT_WHILESTATEMENT:
            checkProcExpression(procEntry, stm->u.whileStatement.condition, globalTable);
            checkProcStm(procEntry, stm->u.whileStatement.body, globalTable);
            if (stm->u.whileStatement.condition->dataType != boolType)
                whileConditionMustBeBoolean(stm->line);
            break;
        case STATEMENT_IFSTATEMENT:
            checkProcExpression(procEntry, stm->u.ifStatement.condition, globalTable);
            checkProcStm(procEntry, stm->u.ifStatement.thenPart, globalTable);
            checkProcStm(procEntry, stm->u.ifStatement.elsePart, globalTable);
            if (stm->u.ifStatement.condition->dataType != boolType)
                ifConditionMustBeBoolean(stm->line);
            break;
        case STATEMENT_COMPOUNDSTATEMENT:
            checkStmList(procEntry, stm->u.compoundStatement.statements, globalTable);
            break;
        case STATEMENT_CALLSTATEMENT:
            calleeEntry = lookup(procEntry->u.procEntry.localTable,stm->u.callStatement.procedureName);
            if (calleeEntry != NULL && calleeEntry->kind != ENTRY_KIND_PROC)
                callOfNonProcedure(stm->line, stm->u.callStatement.procedureName);
            calleeEntry = lookup(globalTable, stm->u.callStatement.procedureName);

            if (calleeEntry == NULL)
                undefinedProcedure(stm->line, stm->u.callStatement.procedureName);
/*
            if (calleeEntry->kind != ENTRY_KIND_PROC)
                callOfNonProcedure(stm->line, stm->u.callStatement.procedureName);
*/
            checkExprList(procEntry, stm->u.callStatement.argumentList, globalTable);

            calleeParamTypes = (ParamTypes *) malloc(sizeof(ParamTypes));
            *calleeParamTypes = *calleeEntry->u.procEntry.paramTypes;

            int paramsCount = 0;
            while (!calleeParamTypes->isEmpty) {
                paramsCount++;
                calleeParamTypes = calleeParamTypes->next;
            }

            calleeArgsList = (ExpressionList *) malloc(sizeof(ExpressionList));
            *calleeArgsList = *stm->u.callStatement.argumentList;

            int argsCount = 0;
            while (!calleeArgsList->isEmpty) {
                argsCount++;
                calleeArgsList = calleeArgsList->tail;
            }

            if (paramsCount > argsCount)
                tooFewArguments(stm->line, stm->u.callStatement.procedureName);
            if (paramsCount < argsCount)
                tooManyArguments(stm->line, stm->u.callStatement.procedureName);

            calleeParamTypes = (ParamTypes *) malloc(sizeof(ParamTypes));
            *calleeParamTypes = *calleeEntry->u.procEntry.paramTypes;
            calleeArgsList = (ExpressionList *) malloc(sizeof(ExpressionList));
            *calleeArgsList = *stm->u.callStatement.argumentList;
            argsCount = 0;
            while (!calleeArgsList->isEmpty) {
                argsCount++;
                if (calleeParamTypes->type != calleeArgsList->head->dataType)
                    argumentTypeMismatch(stm->line, stm->u.callStatement.procedureName, argsCount);

                if (calleeParamTypes->isRef && calleeArgsList->head->kind != EXPRESSION_VARIABLEEXPRESSION)
                    argumentMustBeAVariable(stm->line, stm->u.callStatement.procedureName, argsCount);

                if (!calleeParamTypes->isRef && calleeParamTypes->type->kind == TYPE_KIND_ARRAY)
                    mustBeAReferenceParameter(stm->line, stm->u.callStatement.procedureName);

                calleeParamTypes = calleeParamTypes->next;
                calleeArgsList = calleeArgsList->tail;
            }
            break;


        default:
            break;;


    }
}

void checkExprList(Entry *procEntry, ExpressionList *expressionList, SymbolTable *globalTable) {
    while (!expressionList->isEmpty) {
        checkProcExpression(procEntry, expressionList->head, globalTable);
        expressionList = expressionList->tail;
    }
}

void checkProcVariable(Entry *procEntry, Variable *var, SymbolTable *globalTable) {
    Entry *varEntry = NULL;
    switch (var->kind) {
        case VARIABLE_NAMEDVARIABLE:
            if(strcmp(var->u.namedVariable.name->string,procEntry->name->string) == 0 )
                notAVariable(var->line, var->u.namedVariable.name);
            varEntry = lookup(procEntry->u.procEntry.localTable, var->u.namedVariable.name);

            if (varEntry == NULL) {
                varEntry = lookup(globalTable, var->u.namedVariable.name);
                if (varEntry != NULL)
                    notAVariable(var->line, var->u.namedVariable.name);
                else
                    undefinedVariable(var->line, var->u.namedVariable.name);
            }
            else if (varEntry->kind != ENTRY_KIND_VAR)
                notAVariable(var->line, var->u.namedVariable.name);

                var->dataType = varEntry->u.varEntry.type;
            break;
        case VARIABLE_ARRAYACCESS:
            checkProcExpression(procEntry, var->u.arrayAccess.index, globalTable);
            checkProcVariable(procEntry, var->u.arrayAccess.array, globalTable);

            if (var->u.arrayAccess.index->dataType != intType)
                indexingWithNonInteger(var->line);
            if (var->u.arrayAccess.array->dataType->kind != TYPE_KIND_ARRAY)
                indexingNonArray(var->line);

            var->dataType = var->u.arrayAccess.array->dataType->u.arrayType.baseType;
            break;

    }
}

void checkProcExpression(Entry *procEntry, Expression *exp, SymbolTable *globalTable) {
    switch (exp->kind) {
        case EXPRESSION_INTLITERAL:
            exp->dataType = intType;
            break;
        case EXPRESSION_VARIABLEEXPRESSION:
            checkProcVariable(procEntry, exp->u.variableExpression.variable, globalTable);
            exp->dataType = exp->u.variableExpression.variable->dataType;
            break;
        case EXPRESSION_BINARYEXPRESSION:
            checkProcExpression(procEntry, exp->u.binaryExpression.leftOperand, globalTable);
            checkProcExpression(procEntry, exp->u.binaryExpression.rightOperand, globalTable);
            if (exp->u.binaryExpression.leftOperand->dataType != exp->u.binaryExpression.rightOperand->dataType)
                operatorDifferentTypes(exp->line);
            if (exp->u.binaryExpression.leftOperand->dataType != intType) {
                switch (exp->u.binaryExpression.operator) {
                    case ABSYN_OP_ADD:
                    case ABSYN_OP_SUB:
                    case ABSYN_OP_MUL:
                    case ABSYN_OP_DIV:
                        arithmeticOperatorNonInteger(exp->line);
                        break;
                    default:
                        comparisonNonInteger(exp->line);
                        break;

                }
            }

            switch (exp->u.binaryExpression.operator) {
                case ABSYN_OP_ADD:
                case ABSYN_OP_SUB:
                case ABSYN_OP_MUL:
                case ABSYN_OP_DIV:
                    exp->dataType = intType;
                    break;
                default:
                    exp->dataType = boolType;
                    break;

            }
            break;
    }
}
