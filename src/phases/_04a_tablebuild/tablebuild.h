/*
 * tablebuild.h -- symbol table creation
 */

#ifndef _TABLEBUILD_H
#define _TABLEBUILD_H

#include <table/table.h>
#include "absyn/absyn.h"

/**
 * This function is used to create and populate a table containing entries for every symbol in the currently
 * compiled SPL program.
 * Every declaration of the SPL program needs its corresponding entry in the table.
 *
 * Types calculated in this function can be stored in the type field of Expressions, Variables and TypeExpressions.
 *
 * @param program The program for which the table has to be built.
 * @param showSymbolTables A boolean value indicating, that the table should be displayed to the user.
 */
SymbolTable *buildSymbolTable(Program *program, bool showSymbolTables);

/**
 *
 * @param declaration  program head containing the declarations in the procedure
 * @param table  main table
 * @param showSymbolTables bool to or not to show there is no try
 * @return
 */
Entry *buildGlobalDecl(GlobalDeclaration *declaration, SymbolTable *table, bool showSymbolTables, SymbolTable * tableTable);
ParamTypes * buildParamTypes(GlobalDeclaration *globalDeclaration, SymbolTable *globalTable, ParameterList * parameterList);

#endif //_TABLEBUILD_H