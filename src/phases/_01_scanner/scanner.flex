%{

/*
 * scanner.flex -- SPL scanner specification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <util/errors.h>
#include <util/memory.h>
#include <table/identifier.h>
#include <types/types.h>
#include <absyn/absyn.h>
#include <phases/_01_scanner/scanner.h>
#include <phases/_02_03_parser/parser.h>

static int lineNumber = 1;

%}

 /* Disables the ability to read multiple files (which is not required in SPL). */
%option noyywrap
 /* Sets the caching behavior of the generated scanner. */
%option never-interactive
 /* This header may not always exist on Windows systems. */
%option nounistd
 /* Disables unused functions, so no warnings are displayed during compilation. */
%option nounput
%option noinput

%%

    // TODO (assignment 1): The regular expressions for all tokens need to be defined here.

("//").*    ;
array   {
            yylval.noVal.line =lineNumber;
            return ARRAY;
        }
else    {
            yylval.noVal.line =lineNumber;
            return ELSE;
        }
if      {
            yylval.noVal.line =lineNumber;
            return IF;
        }
of      {
            yylval.noVal.line =lineNumber;
            return OF;
        }
proc    {
            yylval.noVal.line =lineNumber;
            return PROC;
        }
ref     {
            yylval.noVal.line =lineNumber;
            return REF;
        }
type    {
            yylval.noVal.line =lineNumber;
            return TYPE;
        }
var     {
            yylval.noVal.line =lineNumber;
            return VAR;
        }
while   {
            yylval.noVal.line =lineNumber;
            return WHILE;
        }

"("     {
            yylval.noVal.line =lineNumber;
            return LPAREN;
        }

")"     {
            yylval.noVal.line =lineNumber;
            return RPAREN;
        }
"["     {
            yylval.noVal.line =lineNumber;
            return LBRACK;
        }
"]"     {
            yylval.noVal.line =lineNumber;
            return RBRACK;
        }
"{"     {
            yylval.noVal.line =lineNumber;
            return LCURL;
        }
"}"     {
            yylval.noVal.line =lineNumber;
            return RCURL;
        }
"="     {
            yylval.noVal.line =lineNumber;
            return EQ;
        }
"#"     {
            yylval.noVal.line =lineNumber;
            return NE;
        }
"<"     {
            yylval.noVal.line =lineNumber;
            return LT;
        }
"<="    {
            yylval.noVal.line =lineNumber;
            return LE;
        }
">"     {
            yylval.noVal.line =lineNumber;
            return GT;
        }
">="    {
            yylval.noVal.line =lineNumber;
            return GE;
        }
":="    {
            yylval.noVal.line =lineNumber;
            return ASGN;
        }
":"     {
            yylval.noVal.line =lineNumber;
            return COLON;
        }
","     {
            yylval.noVal.line =lineNumber;
            return COMMA;
        }
";"     {
            yylval.noVal.line =lineNumber;
            return SEMIC;
        }
"+"     {
            yylval.noVal.line =lineNumber;
            return PLUS;
        }
"-"     {
            yylval.noVal.line =lineNumber;
            return MINUS;
        }
"*"     {
            yylval.noVal.line =lineNumber;
            return STAR;
        }
"/"     {
            yylval.noVal.line =lineNumber;
            return SLASH;
        }

[a-zA-Z][a-zA-Z0-9_]*  {
                            yylval.stringVal.line = lineNumber;
                            //char * cha = alloca(yylex());
                            //strcpy(cha, yytext);
                            //yylval.stringVal.val = cha;
                            yylval.stringVal.val = allocate(yyleng+1);
                            strcpy(yylval.stringVal.val, yytext);
                            return IDENT;
            }

(0x)[0-9a-fA-F]+    {
                        yylval.intVal.line = lineNumber;
                        yylval.intVal.val = (int)strtol(yytext, NULL, 0);
                        return INTLIT;
                    }
('\\n')     {
                yylval.intVal.line = lineNumber;
                yylval.intVal.val = (int) '\n';
                return INTLIT;
            }
('.')     {
                yylval.intVal.line = lineNumber;
                yylval.intVal.val = (int) yytext[1];
                return INTLIT;
            }


[0-9]*     {
            yylval.intVal.line = lineNumber;
            yylval.intVal.val = atoi(yytext);
            return INTLIT;
                }



(\n)     { ++lineNumber; };

[" \t"]     ;

.|\n		{
              illegalCharacter(lineNumber, yytext[0]);
			}


%%



