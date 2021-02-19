%{

/*
 * parser.y -- SPL parser specification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/errors.h>
#include <table/identifier.h>
#include <types/types.h>
#include <absyn/absyn.h>
#include <phases/_01_scanner/scanner.h>
#include <phases/_02_03_parser/parser.h>

int yylex();
void yyerror(Program**, char *);
extern int yylineno;
%}

%expect 0 //TODO Change?
%parse-param {Program** program}

%union {
  NoVal noVal;
  IntVal intVal;
  StringVal stringVal;

  Expression *expression;
  Variable *variable;
  Statement *statement;
  TypeExpression *typeExpression;
  GlobalDeclaration *globalDeclaration;
  VariableDeclaration *variableDeclaration;
  ParameterDeclaration *parameterDeclaration;

  StatementList *statementList;
  ExpressionList *expressionList;
  VariableDeclarationList *variableList;
  ParameterList *parameterList;
  GlobalDeclarationList *globalDeclarationList;

  //Program * program;
}


%token	<noVal>		ARRAY ELSE IF OF PROC
%token	<noVal>		REF TYPE VAR WHILE
%token	<noVal>		LPAREN RPAREN LBRACK
%token	<noVal>		RBRACK LCURL RCURL
%token	<noVal>		EQ NE LT LE GT GE
%token	<noVal>		ASGN COLON COMMA SEMIC
%token	<noVal>		PLUS MINUS STAR SLASH
%token	<stringVal>	IDENT
%token	<intVal>	INTLIT


%type <variable> Variable
%type <expression> ArithExpression ArithTherm ArithFactor LogicalExpression
%type <parameterDeclaration> ProcDefParam ProcDefParamContent
%type <parameterList> ProcDefParamList SubProcDefParamList
%type <statementList> StatementList
%type <statement> Statement IfElseStatement IfElseBalanced IfElseUnBalanced  WhileStatement BlockStatement EmptyStatement AssignStatement PocCallStatement
%type <expressionList> PocCallParamList
%type <globalDeclaration> TypeDef Declaration
%type <typeExpression> ArrayDef VariableDeclContent
%type <globalDeclarationList> DeclarationList
%type <variableDeclaration> VariableDecl
%type <variableList> VariableDeclList
%type <globalDeclaration> ProcDef
//%type <program> program
%start			program


%%
program		       :  DeclarationList { *program = ($1); };

DeclarationList    : Declaration DeclarationList {$$ = newGlobalDeclarationList($1, $2);}
                   | /* Nichts */ {$$ = emptyGlobalDeclarationList();};

Declaration        : TypeDef { $$ = $1; }
                   | ProcDef { $$ = $1; }

TypeDef            : TYPE IDENT EQ IDENT SEMIC { $$ = newTypeDeclaration($1.line, newIdentifier($2.val), newNamedTypeExpression($1.line, newIdentifier($4.val)));}
                   | TYPE IDENT EQ ArrayDef SEMIC {$$ = newTypeDeclaration($1.line, newIdentifier($2.val), $4);};

ArrayDef           : ARRAY LBRACK INTLIT RBRACK OF IDENT { $$ = newArrayTypeExpression($1.line, newNamedTypeExpression($1.line,newIdentifier($6.val)), $3.val); }
				   | ARRAY LBRACK INTLIT RBRACK OF ArrayDef { $$ = newArrayTypeExpression($1.line, $6 ,$3.val);};


ProcDef            : PROC IDENT LPAREN ProcDefParamList RPAREN LCURL RCURL {$$ = newProcedureDeclaration($1.line, newIdentifier($2.val), $4, emptyVariableList(), emptyStatementList());}
                   | PROC IDENT LPAREN ProcDefParamList RPAREN LCURL VariableDeclList  RCURL {
                            $$ = newProcedureDeclaration($1.line, newIdentifier($2.val), $4, $7, emptyStatementList());}
                   | PROC IDENT LPAREN ProcDefParamList RPAREN LCURL VariableDeclList StatementList RCURL {

                            $$ = newProcedureDeclaration($1.line, newIdentifier($2.val), $4, $7, $8);
                            }
                   | PROC IDENT LPAREN ProcDefParamList RPAREN LCURL StatementList RCURL { $$ = newProcedureDeclaration($1.line, newIdentifier($2.val), $4, emptyVariableList(), $7);};


ProcDefParamList   :  /* Kein Prozedurparameter */ { $$ = emptyParameterList(); }
                      | ProcDefParam  SubProcDefParamList { $$ = newParameterList($1, $2); };


SubProcDefParamList: /* Kein Parameter*/ { $$ = emptyParameterList(); }
                     | COMMA ProcDefParam SubProcDefParamList { $$ = newParameterList($2, $3);};

ProcDefParam       : ProcDefParamContent /*zb: a : int*/ { $$ = $1;}
                   | REF ProcDefParamContent /* zb: ref a : int */{
                        $2->isReference = true;
                        $$ = $2;
                   };

/*
ProcDefParamContent : IDENT COLON IDENT  {
                           Identifier * identifier = newIdentifier($1.val);
                           TypeExpression * expression = newNamedTypeExpression($1.line, newIdentifier($3.val));

                           $$ = newParameterDeclaration($1.line,identifier, expression, false );
                      };*/
ProcDefParamContent : IDENT COLON VariableDeclContent {$$ = newParameterDeclaration($1.line, newIdentifier($1.val), $3, false); };


VariableDeclList   : VariableDecl { $$ = newVariableList($1, emptyVariableList());}
                   | VariableDecl VariableDeclList { $$ = newVariableList($1, $2);};

VariableDecl       : VAR IDENT COLON VariableDeclContent SEMIC { $$ = newVariableDeclaration($1.line, newIdentifier($2.val)
, $4);};
VariableDeclContent : IDENT { $$ = newNamedTypeExpression($1.line, newIdentifier($1.val));}
                    | ArrayDef { $$ = $1; };

StatementList      : Statement { $$ = newStatementList($1, emptyStatementList());}
                   | Statement StatementList{
                        $$ = newStatementList($1, $2);
                   };

Statement          : IfElseStatement { $$ = $1;}
                   | WhileStatement { $$ = $1;};


IfElseStatement    : IfElseBalanced { $$ = $1;}
                   | IfElseUnBalanced { $$ = $1;};

IfElseBalanced     : EmptyStatement { $$ = $1;}
                   | AssignStatement { $$ = $1;}
                   | PocCallStatement { $$ = $1;}
                   | BlockStatement { $$ = $1;}
                   | IF LPAREN LogicalExpression RPAREN IfElseBalanced ELSE IfElseBalanced { $$ = newIfStatement($1.line, $3, $5, $7);};

// changes newEmptyStatement($1.line)
IfElseUnBalanced   : IF LPAREN LogicalExpression RPAREN Statement { $$ = newIfStatement($1.line, $3, $5, newEmptyStatement($1.line));}
                   | IF LPAREN LogicalExpression RPAREN IfElseBalanced ELSE IfElseUnBalanced { $$ = newIfStatement($1.line, $3, $5, $7);};

BlockStatement      : LCURL  RCURL { $$ = newCompoundStatement($1.line, emptyStatementList());}
                    | LCURL StatementList RCURL { $$ = newCompoundStatement($1.line, $2);};


EmptyStatement     : SEMIC {$$ = newEmptyStatement($1.line); };
AssignStatement    : Variable ASGN LogicalExpression SEMIC { $$ = newAssignStatement($1->line, $1, $3);};

WhileStatement     : WHILE LPAREN LogicalExpression RPAREN Statement { $$ = newWhileStatement($1.line, $3, $5);};


PocCallStatement   : IDENT LPAREN RPAREN SEMIC { $$ = newCallStatement($1.line, newIdentifier($1.val) , emptyExpressionList());}  //println();
                   | IDENT LPAREN PocCallParamList RPAREN SEMIC { $$ = newCallStatement($1.line, newIdentifier($1.val) , $3);};  //println(3)


PocCallParamList   : ArithExpression { $$ = newExpressionList($1, emptyExpressionList());}
                   | ArithExpression COMMA PocCallParamList { $$ = newExpressionList($1, $3);};

LogicalExpression  : ArithExpression EQ ArithExpression{
                        $$ = newBinaryExpression($2.line, ABSYN_OP_EQU , $1 , $3);
                        }
                   | ArithExpression NE ArithExpression{
                         $$ = newBinaryExpression($2.line, ABSYN_OP_NEQ , $1 , $3);
                   }
                   | ArithExpression LT ArithExpression{
                        $$ = newBinaryExpression($2.line, ABSYN_OP_LST , $1 , $3);
                   }
                   | ArithExpression LE ArithExpression{
                         $$ = newBinaryExpression($2.line, ABSYN_OP_LSE , $1 , $3);
                   }
                   | ArithExpression GT ArithExpression{
                          $$ = newBinaryExpression($2.line, ABSYN_OP_GRT , $1 , $3);
                   }
                   | ArithExpression GE ArithExpression{
                          $$ = newBinaryExpression($2.line, ABSYN_OP_GRE , $1 , $3);
                   }
                   | ArithExpression { $$ = $1;}



ArithExpression    : ArithExpression PLUS ArithTherm {
                        $$ = newBinaryExpression($2.line, ABSYN_OP_ADD , $1 , $3);
                    }
                   | ArithExpression MINUS ArithTherm {
                        $$ = newBinaryExpression($2.line, ABSYN_OP_SUB , $1 , $3);
                   }
                   | ArithTherm;
ArithTherm         : ArithTherm STAR ArithFactor{
                        $$ = newBinaryExpression($2.line, ABSYN_OP_MUL , $1 , $3);
                    }
                   | ArithTherm SLASH ArithFactor {
                        $$ = newBinaryExpression($2.line, ABSYN_OP_DIV , $1 , $3);
                   }
                   | ArithFactor {
                        $$ = $1;
                   };
ArithFactor        : MINUS ArithFactor{
                        $$ = newBinaryExpression($1.line, ABSYN_OP_SUB , newIntLiteral ($1.line, 0) , $2);
                    }
                   | INTLIT {
                        $$ = newIntLiteral ($1.line, $1.val);
                   }
                   | Variable {
                        $$ = newVariableExpression($1->line, $1);
                   }
                   | LPAREN ArithExpression RPAREN {
                        $$ = $2;
                   }

Variable           : IDENT {
                        $$ = newNamedVariable($1.line, newIdentifier($1.val) );

                         }
                   | Variable LBRACK ArithExpression RBRACK
                           {
                                 $$ = newArrayAccess($2.line, $1, $3);
                           };


%%

void yyerror(Program** program, char *msg) {
    // The first parameter is needed because of '%parse-param {Program** program}'.
    // However, it is unused and gcc emits a warning for it. The following line "uses" the parameter,
    // but does nothing. It is used to silence the warning.
    (void)program;
    syntaxError(yylval.noVal.line, msg);
}