/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_HOME_PROMETHEUS_DOCUMENTS_BRIGHT_FOLDER_SEMESTER_4_COMPILERBAU_MYTEST_CC_SRC_PHASES_02_03_PARSER_PARSER_H_INCLUDED
# define YY_YY_HOME_PROMETHEUS_DOCUMENTS_BRIGHT_FOLDER_SEMESTER_4_COMPILERBAU_MYTEST_CC_SRC_PHASES_02_03_PARSER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    ELSE = 259,
    IF = 260,
    OF = 261,
    PROC = 262,
    REF = 263,
    TYPE = 264,
    VAR = 265,
    WHILE = 266,
    LPAREN = 267,
    RPAREN = 268,
    LBRACK = 269,
    RBRACK = 270,
    LCURL = 271,
    RCURL = 272,
    EQ = 273,
    NE = 274,
    LT = 275,
    LE = 276,
    GT = 277,
    GE = 278,
    ASGN = 279,
    COLON = 280,
    COMMA = 281,
    SEMIC = 282,
    PLUS = 283,
    MINUS = 284,
    STAR = 285,
    SLASH = 286,
    IDENT = 287,
    INTLIT = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"

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

#line 113 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (Program** program);

#endif /* !YY_YY_HOME_PROMETHEUS_DOCUMENTS_BRIGHT_FOLDER_SEMESTER_4_COMPILERBAU_MYTEST_CC_SRC_PHASES_02_03_PARSER_PARSER_H_INCLUDED  */
