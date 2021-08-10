int isRunning(void);
int getLineNumber(void);


int main(int argc, char **argv)
{
int tok;
if(argc<2)
 {
 	fprintf(stderr,"Call ./a.out file_name\n");
 	exit(1);
 }
 if ((yyin = fopen(argv[1],"r"))==0)
 {
 	printf("Cannot open file %s \n",argv[1]);
 	exit(1);
 }

hashInit();

while(isRunning())
 {
 tok = yylex();
 if(!isRunning())break;
 switch(tok)
  {
  case KW_CHAR: 	printf("Encontrei KW_CHAR na linha %d\n",getLineNumber());break;
  case KW_INT: 	printf("Encontrei KW_INT na linha %d\n",getLineNumber());break;
  case KW_FLOAT: 	printf("Encontrei KW_FLOAT na linha %d\n",getLineNumber());break;
  case KW_DATA: 	printf("Encontrei KW_DATA na linha %d\n",getLineNumber());break;
  
  case KW_IF: 		printf("Encontrei KW_IF na linha %d\n",getLineNumber());break;
  case KW_ELSE: 	printf("Encontrei KW_ELSE na linha %d\n",getLineNumber());break;
  case KW_UNTIL: 	printf("Encontrei KW_UNTIL na linha %d\n",getLineNumber());break;
  case KW_COMEFROM: 	printf("Encontrei KW_COMEFROM na linha %d\n",getLineNumber());break;
  case KW_READ: 	printf("Encontrei KW_READ na linha %d\n",getLineNumber());break;
  case KW_PRINT: 	printf("Encontrei KW_PRINT na linha %d\n",getLineNumber());break;
  case KW_RETURN: 	printf("Encontrei KW_RETURN na linha %d\n",getLineNumber());break;
  
  case OPERATOR_LE: 	printf("Encontrei OPERATOR_LE na linha %d\n",getLineNumber());break;
  case OPERATOR_GE: 	printf("Encontrei OPERATOR_GE na linha %d\n",getLineNumber());break;
  case OPERATOR_EQ: 	printf("Encontrei OPERATOR_EQ na linha %d\n",getLineNumber());break;
  case OPERATOR_DIF: 	printf("Encontrei OPERATOR_DIF na linha %d\n",getLineNumber());break;
  case OPERATOR_RANGE: printf("Encontrei OPERATOR_RANGE na linha %d\n",getLineNumber());break;
  
  case TK_IDENTIFIER: 	printf("Encontrei TK_IDENTIFIER na linha %d\n",getLineNumber());break;
  
  case LIT_INTEGER: 	printf("Encontrei LIT_INTEGER na linha %d\n",getLineNumber());break;
  case LIT_CHAR: 	printf("Encontrei LIT_CHAR na linha %d\n",getLineNumber());break;
  case LIT_STRING: 	printf("Encontrei LIT_STRING na linha %d\n",getLineNumber());break;
  
  case TOKEN_ERROR: 	printf("TOKEN_ERROR at line %d\n",getLineNumber());break;
  
  default: 		printf("Encontrei %c na linha %d\n",tok,getLineNumber());break;
  }
 }
 printf("Main Finalizada. File tem %d linhas\n",lineNumber);
 hashPrint();
 exit(0);
}


