/*
 * varalloc.h -- variable allocation
 */


#ifndef _VARALLOC_H_
#define _VARALLOC_H_


#define REF_BYTE_SIZE	4	/* size of an address in bytes */

/**
 * This class is used to calculate the memory needed for variables and stack frames
 * of the currently compiled SPL program.
 *
 * Those values have to be stored in their corresponding fields in the ProcedureEntry, VariableEntry or
 * ParameterTypes structs.
 *
 * @param program The program for which the variables have to be allocated.
 * @param globalTable The symbol table for the current program.
 * @param showVarAlloc A boolean value indicating, whether the progress of the allocation should be displayed to the user.
 */
void allocVars(Program *program, SymbolTable *globalTable, bool showVarAlloc);
void allocProcEntry(GlobalDeclaration *globalDeclaration, Entry* procEntry);
void allocParams(SymbolTable *localTable, int *inArgs, ParameterList *params, ParamTypes* paramTypes);
void allocVars_Proc(SymbolTable *localTable, int * varLengthCounter, VariableDeclarationList* vars );
void allocOutArgsProcEntry(SymbolTable *globalTable, StatementList *procBody, int * currentMaxInArgSize) ;
void allocOutArgsProcEntry_Stm(SymbolTable *globalTable, Statement * statement, int * currentMaxInArgSize) ;
#endif /* _VARALLOC_H_ */