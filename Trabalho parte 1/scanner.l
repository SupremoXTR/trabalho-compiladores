%{
#include "tokens.h"
#include "hash.h"
int running=1;
int lineNumber=1;
%}

%x COMMENT


%%

char			{return KW_CHAR;}
int			{return KW_INT;}
float			{return KW_FLOAT;}
data			{return KW_DATA;}

if			{return KW_IF;}
else			{return KW_ELSE;}
until			{return KW_UNTIL;}
comefrom		{return KW_COMEFROM;}
read			{return KW_READ;}
print			{return KW_PRINT;}
return			{return KW_RETURN;}


[a-zA-Z][a-zA-Z 0-9]+[a-zA-Z0-9]	{if(yytext[-1]!='"' && (int)yytext[-1]!=39){hashInsert(yytext,TK_IDENTIFIER);return TK_IDENTIFIER;}}
[a-zA-Z][a-zA-Z0-9]			{if(yytext[-1]!='"' && (int)yytext[-1]!=39){hashInsert(yytext,TK_IDENTIFIER);return TK_IDENTIFIER;}}
[a-zA-Z]				{if(yytext[-1]!='"' && (int)yytext[-1]!=39){hashInsert(yytext,TK_IDENTIFIER);return TK_IDENTIFIER;}}

"<="			{return OPERATOR_LE;}
">="			{return OPERATOR_GE;}
"=="			{return OPERATOR_EQ;}
"!="			{return OPERATOR_DIF;}
".."			{return OPERATOR_RANGE;}

[0-9]+			{hashInsert(yytext,LIT_INTEGER);return LIT_INTEGER;}


[-+*/|=(){}<>;,:&~]	{return (int)yytext[0];}
"["			{return (int)yytext[0];}
"]"			{return (int)yytext[0];}

[ \t]
"\n"			{++lineNumber;}

"##".*
"#/"			{BEGIN(COMMENT);}
.			{return TOKEN_ERROR;}

<COMMENT>"/#"		{BEGIN(INITIAL);}
<COMMENT>"\n"		{++lineNumber;}
<COMMENT>.	


%%

#include "hash.c"
#include "main.c"

int getLineNumber(void)
{
	return lineNumber;
}

int isRunning(void)
{
	return running;
}


int yywrap()
{
 running = 0;
 return 1;
}



