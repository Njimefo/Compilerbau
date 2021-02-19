/*
 * tablebuild.c -- symbol table creation
 */



#include "tablebuild.h"

#include <types/types.h>
#include <absyn/absyn.h>
#include <table/table.h>
#include <stdio.h>
#include <util/errors.h>
#include <string.h>
#include <stdlib.h>


#define BOOL_BYTE_SIZE   4    /* size of a bool in bytes */
#define INT_BYTE_SIZE    4    /* size of an int in bytes */


void buildType(GlobalDeclaration *declaration, SymbolTable *symbolTable, TypeExpression *expression);

void buildProcedureParams(GlobalDeclaration *declaration, SymbolTable *symbolTable, SymbolTable *localTable,
                          ParameterList *parameterList);

void buildProcedureVariable(GlobalDeclaration *declaration, SymbolTable *symbolTable, SymbolTable *localTable,
                            VariableDeclarationList *variableDecList);

SymbolTable *buildSymbolTable(Program *program, bool showSymbolTables) {
    intType = newPrimitiveType("int", INT_BYTE_SIZE);
    boolType = newPrimitiveType("boolean", BOOL_BYTE_SIZE);

    SymbolTable *table = initializeGlobalTable();


    if (program == NULL) {
        error("Program is NULL!");
    }
    Program *newProgram;
    newProgram = program;
    SymbolTable *tableTable = newTable(NULL);
    while (!newProgram->isEmpty) {
        GlobalDeclaration *globalDeclaration = newProgram->head;
        buildGlobalDecl(globalDeclaration, table, showSymbolTables, tableTable);
        //enter(table, entry);
        newProgram = newProgram->tail;
    }
    if (enter(table, newProcEntry(newIdentifier("main"), emptyParamTypes(), newTable(NULL))) != NULL) {
        mainIsMissing();
    }
    Entry *entry = lookup(table, newIdentifier("main"));
    if (entry->kind != ENTRY_KIND_PROC) {
        mainIsNotAProcedure();
    }
    if (!entry->u.procEntry.paramTypes->isEmpty) {
        mainMustNotHaveParameters();
    }
    if (showSymbolTables)
        showTable(table);
    return table;
}

Entry *
buildGlobalDecl(GlobalDeclaration *declaration, SymbolTable *table, bool showSymbolTables, SymbolTable *tableTable) {
    SymbolTable *localTable = newTable(table);
    ParamTypes *paramTypes = NULL;
    Entry *entry = NULL;
    switch (declaration->kind) {

        case DECLARATION_TYPEDECLARATION:
            buildType(declaration, table, declaration->u.typeDeclaration.typeExpression);
            entry = newTypeEntry(declaration->name, declaration->u.typeDeclaration.typeExpression->dataType);
           ;
            if  (enter(table, entry) == NULL)
                redeclarationAsType(declaration->line, declaration->name);
            break;
        case DECLARATION_PROCEDUREDECLARATION:
            buildProcedureParams(declaration, table, localTable, declaration->u.procedureDeclaration.parameters);
            buildProcedureVariable(declaration, table, localTable, declaration->u.procedureDeclaration.variables);
            paramTypes = buildParamTypes(declaration, table, declaration->u.procedureDeclaration.parameters);
            entry = newProcEntry(declaration->name, paramTypes, localTable);
            if (enter(table, entry) == NULL)
                redeclarationAsProcedure(declaration->line, declaration->name);
            // also hier mach ich das mit dem list
            if (showSymbolTables)
                showTable(localTable);
            break;
    }
}

int getSize(ParameterList *parameterList) {
    ParameterList *tmp = parameterList;
    int i = 0;
    while (!tmp->isEmpty) {
        tmp = tmp->tail;
        i++;
    }
    return i;
}


ParamTypes *
buildParamTypes(GlobalDeclaration *globalDeclaration, SymbolTable *globalTable, ParameterList *parameterList) {

    if (parameterList->isEmpty) return emptyParamTypes();
    ParamTypes *paramTypes = NULL;
    ParameterList *parameterList1 = NULL;
    parameterList1 = parameterList;

    int size = getSize(globalDeclaration->u.procedureDeclaration.parameters);
    buildType(globalDeclaration, globalTable,
              parameterList1->head->typeExpression);
    paramTypes = newParamTypes(parameterList1->head->typeExpression->dataType,
                               parameterList1->head->isReference,
                               emptyParamTypes());
    if (parameterList1->head->typeExpression->dataType->kind ==
        TYPE_KIND_ARRAY) {
        if (!parameterList1->head->isReference) {
            mustBeAReferenceParameter(parameterList1->head->line,
                                      parameterList1->head->name);
        }
    }
    ParamTypes *current = paramTypes;
    parameterList1 = parameterList1->tail;
    for (int i = 1; i < size; i++) {
        buildType(globalDeclaration, globalTable,
                  parameterList1->head->typeExpression);


        current->next = newParamTypes(
                parameterList1->head->typeExpression->dataType,
                parameterList1->head->isReference, emptyParamTypes());
        current = current->next;
        parameterList1 = parameterList1->tail;
    }
/*
    while (!globalDeclaration->u.procedureDeclaration.parameters->isEmpty) {
        buildType(globalDeclaration, globalTable,
                  globalDeclaration->u.procedureDeclaration.parameters->head->typeExpression);
        paramTypes = newParamTypes(
                globalDeclaration->u.procedureDeclaration.parameters->head->typeExpression->dataType,
                globalDeclaration->u.procedureDeclaration.parameters->head->isReference,
                paramTypes);
        globalDeclaration->u.procedureDeclaration.parameters = globalDeclaration->u.procedureDeclaration.parameters->tail;
    }
    return paramTypes;
*/
    return paramTypes;
}

void buildProcedureVariable(GlobalDeclaration *declaration, SymbolTable *symbolTable, SymbolTable *localTable,
                            VariableDeclarationList *variableDecList) {
    if (variableDecList->isEmpty) return;
    Entry *entry = NULL;
    TypeExpression *namedType = (TypeExpression *) malloc(sizeof(TypeExpression));
    *namedType = *variableDecList->head->typeExpression;
    //Entry * varEntry = NULL;
    while (namedType->kind != TYPEEXPRESSION_NAMEDTYPEEXPRESSION)
        namedType = namedType->u.arrayTypeExpression.baseType;

    entry = lookup(localTable, namedType->u.namedTypeExpression.name);
    if (entry != NULL && entry->kind != ENTRY_KIND_TYPE)
        notAType(namedType->line, namedType->u.namedTypeExpression.name);


    buildType(declaration, symbolTable, variableDecList->head->typeExpression);
    entry = newVarEntry(variableDecList->head->name, variableDecList->head->typeExpression->dataType, 0);
    if (enter(localTable, entry) == NULL) {
        redeclarationAsVariable(variableDecList->head->line, variableDecList->head->name);
    }
    buildProcedureVariable(declaration, symbolTable, localTable, variableDecList->tail);
}

void buildProcedureParams(GlobalDeclaration *declaration, SymbolTable *symbolTable, SymbolTable *localTable,
                          ParameterList *parameterList) {
    if (parameterList->isEmpty) return;

    Entry *entry = NULL;
    buildType(declaration, symbolTable, parameterList->head->typeExpression);
    entry = newVarEntry(parameterList->head->name, parameterList->head->typeExpression->dataType,
                        parameterList->head->isReference);
    if (enter(localTable, entry) == NULL) {
        redeclarationAsParameter(parameterList->head->line, parameterList->head->name);
    }
    buildProcedureParams(declaration, symbolTable, localTable, parameterList->tail);
}


void buildType(GlobalDeclaration *declaration, SymbolTable *symbolTable, TypeExpression *expression) {
    Entry *entry;
    Entry *procEntry = NULL;
    switch (expression->kind) {
        case TYPEEXPRESSION_NAMEDTYPEEXPRESSION:


            entry = lookup(symbolTable, expression->u.namedTypeExpression.name);
            if (entry == NULL) {
                undefinedType(expression->line, expression->u.namedTypeExpression.name);
            }
            if (entry->kind == ENTRY_KIND_TYPE) {
                expression->dataType = entry->u.typeEntry.type;
            } else {
                notAType(expression->line, expression->u.namedTypeExpression.name);
            }
            break;
        case TYPEEXPRESSION_ARRAYTYPEEXPRESSION:
            buildType(declaration, symbolTable, expression->u.arrayTypeExpression.baseType);
            expression->dataType = newArrayType(expression->u.arrayTypeExpression.arraySize,
                                                expression->u.arrayTypeExpression.baseType->dataType);
            break;
    }
}
