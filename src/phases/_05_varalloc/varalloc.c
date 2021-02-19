/*
 * varalloc.c -- variable allocation
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <absyn/absyn.h>
#include <table/table.h>
#include "types/types.h"
#include "varalloc.h"




/**
 * Formats the variables of a procedure to a human readable format and prints it
 * @param procDec       The procedure Declaration
 * @param globalTable   The global symbol table
 */
static void showProcedureVarAlloc(GlobalDeclaration *procDec, SymbolTable *globalTable) {
    SymbolTable *localTable;
    Entry *procEntry, *localEntry;
    ParamTypes *paramTypes;
    ParameterList *parameterList;
    VariableDeclarationList *variableList;
    int argNum;

    procEntry = lookup(globalTable, procDec->name);
    localTable = procEntry->u.procEntry.localTable;
    printf("\nVariable allocation for procedure '%s'\n", procDec->name->string);

    argNum = 1;
    paramTypes = procEntry->u.procEntry.paramTypes;
    while (!paramTypes->isEmpty) {
        printf("arg %d: sp + %d\n", argNum, paramTypes->offset);

        paramTypes = paramTypes->next;
        argNum++;
    }
    printf("size of argument area = %d\n", procEntry->u.procEntry.argumentArea);


    parameterList = procDec->u.procedureDeclaration.parameters;
    while (!parameterList->isEmpty) {
        printf("param '%s': fp + %d\n",
               parameterList->head->name->string,
               lookup(localTable, parameterList->head->name)->u.varEntry.offset);

        parameterList = parameterList->tail;
    }

    variableList = procDec->u.procedureDeclaration.variables;
    while (!variableList->isEmpty) {
        localEntry = lookup(localTable, variableList->head->name);
        if (localEntry->kind == ENTRY_KIND_VAR) {
            printf("var '%s': fp - %d\n",
                   variableList->head->name->string,
                   -localEntry->u.varEntry.offset);
        }

        variableList = variableList->tail;
    }

    printf("size of localvar area = %d\n", procEntry->u.procEntry.localvarArea);
    printf("size of outgoing area = %d\n", procEntry->u.procEntry.outgoingArea);
}

/**
  * Formats the variable allocation to a human readable format and prints it
  *
  * @param program      The abstract syntax tree of the program
  * @param globalTable  The symbol table containing all symbols of the spl program
  */
static void showVarAllocation(Program *program, SymbolTable *globalTable) {
    GlobalDeclarationList *declarationList;

    declarationList = program;
    while (!declarationList->isEmpty) {
        if (declarationList->head->kind == DECLARATION_PROCEDUREDECLARATION) {
            showProcedureVarAlloc(declarationList->head, globalTable);
        }

        declarationList = declarationList->tail;
    }
}

void allocVars(Program *program, SymbolTable *globalTable, bool showVarAlloc) {
    //TODO (assignment 5): Allocate stack slots for all parameters and local variables
    Entry *entry = NULL;
    Program *_program = (Program *) malloc(sizeof(Program));

    /****** offsets and areasizes *****/
    *_program = *program; //shallow copy of the program
    GlobalDeclaration *globalDeclaration = NULL;
    while (!_program->isEmpty) {
        globalDeclaration = _program->head;
        switch (globalDeclaration->kind) {
            case DECLARATION_PROCEDUREDECLARATION:
                entry = lookup(globalTable, globalDeclaration->name);
                allocProcEntry(globalDeclaration, entry);
                break;
            default:
                break;

        }
        _program = _program->tail;
    }

    /****** outgoing arguments *****/
    //_program = NULL;
    _program = (Program *) malloc(sizeof(Program));
    *_program = *program; //deep copy of the program
    while (!_program->isEmpty) {
        globalDeclaration = _program->head;
        switch (globalDeclaration->kind) {
            case DECLARATION_PROCEDUREDECLARATION:
                entry = lookup(globalTable, globalDeclaration->name);
                int maxOutArgSize = -1;
                allocOutArgsProcEntry(globalTable, globalDeclaration->u.procedureDeclaration.body, &maxOutArgSize);
                entry->u.procEntry.outgoingArea = maxOutArgSize;
                break;
            default:
                break;

        }
        _program = _program->tail;
    }
    if (showVarAlloc) showVarAllocation(program, globalTable);
}

void allocOutArgsProcEntry_Stm(SymbolTable *globalTable, Statement *statement, int *currentMaxInArgSize) {

    Entry *actualCalledProc = NULL;
    if (statement == NULL) return;
    switch (statement->kind) {
        case STATEMENT_CALLSTATEMENT:

            actualCalledProc = lookup(globalTable, statement->u.callStatement.procedureName);
            *currentMaxInArgSize = actualCalledProc->u.procEntry.argumentArea > *currentMaxInArgSize
                                   ? actualCalledProc->u.procEntry.argumentArea : *currentMaxInArgSize;
            break;
        case STATEMENT_IFSTATEMENT:
            allocOutArgsProcEntry_Stm(globalTable, statement->u.ifStatement.thenPart, currentMaxInArgSize);
            allocOutArgsProcEntry_Stm(globalTable, statement->u.ifStatement.elsePart, currentMaxInArgSize);
            break;
        case STATEMENT_WHILESTATEMENT:
            allocOutArgsProcEntry_Stm(globalTable, statement->u.whileStatement.body, currentMaxInArgSize);
            break;
        case STATEMENT_COMPOUNDSTATEMENT:
            allocOutArgsProcEntry(globalTable, statement->u.compoundStatement.statements, currentMaxInArgSize);
            break;
    }
}

void allocOutArgsProcEntry(SymbolTable *globalTable, StatementList *procBody, int *currentMaxInArgSize) {

    Entry *actualCalledProc = NULL;
    while (!procBody->isEmpty) {
        switch (procBody->head->kind) {
            case STATEMENT_CALLSTATEMENT:
                actualCalledProc = lookup(globalTable, procBody->head->u.callStatement.procedureName);
                if(actualCalledProc->u.procEntry.argumentArea > *currentMaxInArgSize)
                    *currentMaxInArgSize = actualCalledProc->u.procEntry.argumentArea;
                break;
            case STATEMENT_IFSTATEMENT:
                allocOutArgsProcEntry_Stm(globalTable, procBody->head->u.ifStatement.thenPart, currentMaxInArgSize);
                allocOutArgsProcEntry_Stm(globalTable, procBody->head->u.ifStatement.elsePart, currentMaxInArgSize);
                break;
            case STATEMENT_WHILESTATEMENT:
                allocOutArgsProcEntry_Stm(globalTable, procBody->head->u.whileStatement.body, currentMaxInArgSize);
                break;
            case STATEMENT_COMPOUNDSTATEMENT:
                allocOutArgsProcEntry(globalTable, procBody->head->u.compoundStatement.statements, currentMaxInArgSize);
                break;

        }
        procBody = procBody->tail;
    }




}

void allocProcEntry(GlobalDeclaration *globalDeclaration, Entry *procEntry) {
    int inArgs = 0;
    SymbolTable *localTable = procEntry->u.procEntry.localTable;

    allocParams(localTable, &inArgs, globalDeclaration->u.procedureDeclaration.parameters,
                procEntry->u.procEntry.paramTypes);
    procEntry->u.procEntry.argumentArea = inArgs;

    int varLengthCounter = 0;
    allocVars_Proc(localTable, &varLengthCounter, globalDeclaration->u.procedureDeclaration.variables);
    procEntry->u.procEntry.localvarArea = varLengthCounter;

}

void allocParams(SymbolTable *localTable, int *inArgs, ParameterList *params, ParamTypes *paramTypes) {
    Entry *paramEntry = NULL;
    *inArgs = 0;
    ParamTypes *actualParamTypes = (ParamTypes *) malloc(sizeof(ParamTypes));

    *actualParamTypes = *paramTypes;

    while (!params->isEmpty) {
        paramEntry = lookup(localTable, params->head->name);
        paramEntry->u.varEntry.offset = actualParamTypes->offset = *inArgs;
        if (!params->head->isReference)
            *inArgs += paramEntry->u.varEntry.type->byteSize;
        else *inArgs += 4; //4 bytes for passing adress

        params = params->tail;
        actualParamTypes = actualParamTypes->next;
    }
}

void allocVars_Proc(SymbolTable *localTable, int *varLengthCounter, VariableDeclarationList *vars) {
    Entry *varEntry = NULL;
    *varLengthCounter = 0;
    while (!vars->isEmpty) {
        varEntry = lookup(localTable, vars->head->name);
        *varLengthCounter += varEntry->u.varEntry.type->byteSize;
        varEntry->u.varEntry.offset = (*varLengthCounter) * -1;
        vars = vars->tail;
    }
}

