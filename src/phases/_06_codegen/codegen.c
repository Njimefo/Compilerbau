/*
 * codegen.c -- ECO32 code generator
 */

#include "codegen.h"
#include <stdlib.h>
#include <stdio.h>
#include <util/errors.h>
#include <absyn/absyn.h>
#include <table/table.h>
#include <types/types.h>
#include "codeprint.h"

#define FIRST_REGISTER 8
#define LAST_REGISTER 23

static const int StackPointerReg = 29;
static const int FramePointerReg = 25;
static const int ReturnAddrReg = 31;
static const int NullReg = 0;
static const int INT_BYTESIZE = 4;
static int RegCounter = 0;
static char *actualLabel = NULL;
static const char *indexError = "_indexError";
static int labelCounter = 0;

/**
 * Emits needed import statements, to allow usage of the predefined functions and sets the correct settings
 * for the assembler.
 * @param out The file pointer where the output has to be emitted to.
 */
void assemblerProlog(FILE *out) {
    emitImport(out, "printi");
    emitImport(out, "printc");
    emitImport(out, "readi");
    emitImport(out, "readc");
    emitImport(out, "exit");
    emitImport(out, "time");
    emitImport(out, "clearAll");
    emitImport(out, "setPixel");
    emitImport(out, "drawLine");
    emitImport(out, "drawCircle");
    emitImport(out, "_indexError");

    emit(out, "");
    emit(out, "\t.code");
    emit(out, "\t.align\t4");
}

void genCode(Program *program, SymbolTable *globalTable, FILE *out) {
    assemblerProlog(out);

    while (!program->isEmpty) {
        switch (program->head->kind) {
            case DECLARATION_PROCEDUREDECLARATION:
                genCode_Proc(program->head, globalTable, out);
                break;
            default:
                break;
        }
        program = program->tail;
    }
}

void genCode_Proc(GlobalDeclaration *globalDeclaration, SymbolTable *globalTable, FILE *out) {


    Entry *procEntry = NULL;
    procEntry = lookup(globalTable, globalDeclaration->name);
    actualLabel = globalDeclaration->name->string;

    emitExport(out, actualLabel);
    emitLabel(out, actualLabel);
    int frameSize = 0;
    if (procEntry->u.procEntry.outgoingArea == -1)
        frameSize += procEntry->u.procEntry.localvarArea + INT_BYTESIZE;
    else
        frameSize += procEntry->u.procEntry.localvarArea + 2 * INT_BYTESIZE +
                     procEntry->u.procEntry.outgoingArea;

    commentRRI(out, "sub", StackPointerReg, StackPointerReg, frameSize, "allocate frame");

    int oldFramePointer = 0;
    if (procEntry->u.procEntry.outgoingArea != -1)
        oldFramePointer += procEntry->u.procEntry.outgoingArea + INT_BYTESIZE;

    commentRRI(out, "stw", FramePointerReg, StackPointerReg, oldFramePointer, "save old frame pointer");
    commentRRI(out, "add", FramePointerReg, StackPointerReg, frameSize, "setup new frame pointer");

    int oldBackAddr = procEntry->u.procEntry.localvarArea + 2 * INT_BYTESIZE;

    if (procEntry->u.procEntry.outgoingArea != -1)
        commentRRI(out, "stw", ReturnAddrReg, FramePointerReg, -oldBackAddr, "save return register");

    while (!globalDeclaration->u.procedureDeclaration.body->isEmpty) {
        genCode_Stm(procEntry, globalDeclaration->u.procedureDeclaration.body->head, globalTable, out);
        globalDeclaration->u.procedureDeclaration.body = globalDeclaration->u.procedureDeclaration.body->tail;
    }

    if (procEntry->u.procEntry.outgoingArea != -1)
        commentRRI(out, "ldw", ReturnAddrReg, FramePointerReg, -oldBackAddr, "restore return register");

    commentRRI(out, "ldw", FramePointerReg, StackPointerReg, oldFramePointer, "restore old frame pointer");
    commentRRI(out, "add", StackPointerReg, StackPointerReg, frameSize, "release frame");
    commentR(out, "jr", ReturnAddrReg, "return");
}

void genCode_Stm(Entry *procEntry, Statement *stm, SymbolTable *globalTable, FILE *out) {
    Entry *calleeProcEntry = NULL;
    char *label0;
    char *label1;

    ParamTypes *paramTypes = (ParamTypes *) malloc(sizeof(ParamTypes));
    switch (stm->kind) {
        case STATEMENT_ASSIGNSTATEMENT:
            genCode_Variable(procEntry, stm->u.assignStatement.target, globalTable, out);
            genCode_Expression(procEntry, stm->u.assignStatement.value, globalTable, out, 0);

            emitRRI(out, "stw", getActualReg() - 1, getActualReg() - 2, 0);
            RegCounter -= 2;
            break;
        case STATEMENT_CALLSTATEMENT:
            calleeProcEntry = lookup(globalTable, stm->u.callStatement.procedureName);
            int argCounter = 0;
            *paramTypes = *calleeProcEntry->u.procEntry.paramTypes;
            while (!paramTypes->isEmpty) {
                genCode_Expression(procEntry, stm->u.callStatement.argumentList->head, globalTable, out,
                                   paramTypes->isRef);
                RegCounter--;
                commentRRI(out, "stw", getActualReg(), StackPointerReg, paramTypes->offset,
                           "store arg #%d", argCounter);
                paramTypes = paramTypes->next;
                stm->u.callStatement.argumentList = stm->u.callStatement.argumentList->tail;
                argCounter++;

            }
            emitSS(out, "jal", stm->u.callStatement.procedureName->string);

            break;
        case STATEMENT_COMPOUNDSTATEMENT:
            while (!stm->u.compoundStatement.statements->isEmpty) {
                genCode_Stm(procEntry, stm->u.compoundStatement.statements->head, globalTable, out);
                stm->u.compoundStatement.statements = stm->u.compoundStatement.statements->tail;
            }
            break;

        case STATEMENT_IFSTATEMENT:
            label0 = generateNewLabel();
            actualLabel = label0;
            label1 = generateNewLabel();
            genCode_Expression(procEntry, stm->u.ifStatement.condition, globalTable, out, 0);
            genCode_Stm(procEntry, stm->u.ifStatement.thenPart, globalTable, out);

            emitSS(out, "j", label0);
            emitLabel(out, label0);
            genCode_Stm(procEntry, stm->u.ifStatement.elsePart, globalTable, out);
            if (stm->u.ifStatement.elsePart->kind != STATEMENT_EMPTYSTATEMENT)
                emitLabel(out, label1);
            break;
        case STATEMENT_WHILESTATEMENT:
            label0 = generateNewLabel();
            label1 = generateNewLabel();
            emitLabel(out, label0);
            actualLabel = label1;
            genCode_Expression(procEntry, stm->u.whileStatement.condition, globalTable, out, 0);
            genCode_Stm(procEntry, stm->u.whileStatement.body, globalTable, out);
            emitSS(out, "j", label0);
            emitLabel(out, label1);
            break;


        default:
            break;

    }
}

void genCode_Variable(Entry *procEntry, Variable *var, SymbolTable *globalTable, FILE *out) {
    Entry *varEntry = NULL;
    switch (var->kind) {
        case VARIABLE_NAMEDVARIABLE:
            varEntry = lookup(procEntry->u.procEntry.localTable, var->u.namedVariable.name);
            emitRRI(out, "add", getActualReg(), FramePointerReg, varEntry->u.varEntry.offset);
            if (varEntry->u.varEntry.isRef)
                emitRRI(out, "ldw", getActualReg(), getActualReg(), 0);
            RegCounter++;
            break;
        case VARIABLE_ARRAYACCESS:
            genCode_Variable(procEntry, var->u.arrayAccess.array, globalTable, out);
            genCode_Expression(procEntry, var->u.arrayAccess.index, globalTable, out, 0);

            emitRRI(out, "add", getActualReg(), NullReg, var->u.arrayAccess.array->dataType->byteSize / 4);

            RegCounter--;
            emitRRL(out, "bgeu", getActualReg(), getActualReg() + 1, indexError);

            // originl
            //emitRRI(out, "mul", getActualReg(), getActualReg(), var->u.arrayAccess.array.dataType->byteSize);
            emitRRI(out, "mul", getActualReg(), getActualReg(), var->dataType->byteSize);
            emitRRR(out, "add", getActualReg() - 1, getActualReg() - 1, getActualReg());
            break;
    }
}

void genCode_Expression(Entry *procEntry, Expression *expression, SymbolTable *globalTable, FILE *out, bool b) {

    switch (expression->kind) {
        case EXPRESSION_VARIABLEEXPRESSION:
            genCode_Variable(procEntry, expression->u.variableExpression.variable, globalTable, out);
            if (!b)
                emitRRI(out, "ldw", getActualReg() - 1, getActualReg() - 1, 0);
            break;
        case EXPRESSION_INTLITERAL:
            emitRRI(out, "add", getActualReg(), NullReg, expression->u.intLiteral.value);
            RegCounter++;
            break;
        case EXPRESSION_BINARYEXPRESSION:
            genCode_Expression(procEntry, expression->u.binaryExpression.leftOperand, globalTable, out, 0);
            genCode_Expression(procEntry, expression->u.binaryExpression.rightOperand, globalTable, out, 0);
            switch (expression->u.binaryExpression.operator) {
                case ABSYN_OP_ADD:
                    emitRRR(out, "add", getActualReg() - 2, getActualReg() - 2, getActualReg() - 1);
                    RegCounter--;
                    break;
                case ABSYN_OP_SUB:
                    emitRRR(out, "sub", getActualReg() - 2, getActualReg() - 2, getActualReg() - 1);
                    RegCounter--;
                    break;
                case ABSYN_OP_DIV :
                    emitRRR(out, "div", getActualReg() - 2, getActualReg() - 2, getActualReg() - 1);
                    RegCounter--;
                    break;
                case ABSYN_OP_MUL:
                    emitRRR(out, "mul", getActualReg() - 2, getActualReg() - 2, getActualReg() - 1);
                    RegCounter--;
                    break;
                case ABSYN_OP_NEQ:
                    emitRRL(out, "beq", getActualReg() - 2, getActualReg() - 1, actualLabel);
                    RegCounter -= 2;
                    break;
                case ABSYN_OP_EQU:
                    emitRRL(out, "bne", getActualReg() - 2, getActualReg() - 1, actualLabel);
                    RegCounter -= 2;
                    break;
                case ABSYN_OP_LST:
                    emitRRL(out, "bge", getActualReg() - 2, getActualReg() - 1, actualLabel);
                    RegCounter -= 2;
                    break;
                case ABSYN_OP_GRT:
                    emitRRL(out, "ble", getActualReg() - 2, getActualReg() - 1, actualLabel);
                    RegCounter -= 2;
                    break;
                case ABSYN_OP_GRE:
                    emitRRL(out, "blt", getActualReg() - 2, getActualReg() - 1, actualLabel);
                    RegCounter -= 2;
                    break;
                case ABSYN_OP_LSE:
                    emitRRL(out, "bgt", getActualReg() - 2, getActualReg() - 1, actualLabel);
                    RegCounter -= 2;
                    break;
            }
            break;

    }
}

int getActualReg() {
    int returnRegister = FIRST_REGISTER + RegCounter;
    printf("%d", returnRegister);
    if (returnRegister < 8 || returnRegister > 24)
        registerOverflow();
    return returnRegister;
}

char *generateNewLabel() {
    int maxchar = 15;
    char *_labelIdentifier = (char *) malloc(maxchar * sizeof(char));
    sprintf(_labelIdentifier, "L%d", labelCounter++);
    return _labelIdentifier;
}
