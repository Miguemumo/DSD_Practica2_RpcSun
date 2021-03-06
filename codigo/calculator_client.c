/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculator.h"


void
calculadora_1(char *host, double *numeros, char *operacion, int util_numeros)
{
	CLIENT *clnt;
	double  *result_1;
	int suma_1_arg1;
	int suma_1_arg2;
	double  *result_2;
	int resta_1_arg1;
	int resta_1_arg2;
	double  *result_3;
	int multiplicacion_1_arg1;
	int multiplicacion_1_arg2;
	double  *result_4;
	int division_1_arg1;
	int division_1_arg2;


	double *result;
	double operando1, operando2;

	char operator[1];

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, CALCULADORAVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	operando1 = numeros[0];
	printf("%lf", operando1);
	for (int ii=1; ii < util_numeros; ii++){
		operando2 = numeros[ii];
		operator[0] = operacion[ii-1];
		
		if (!strcmp(operator,"+")){
			result = suma_1(operando1,operando2,clnt);
			operando1 = *result;
		}
		if (!strcmp(operator,"-")){
			result = resta_1(operando1,operando2,clnt);
			operando1 = *result;
		}
		if (!strcmp(operator,"x")){
			result = multiplicacion_1(operando1,operando2,clnt);
			operando1 = *result;
		}
		if (!strcmp(operator,"/")){
			result = division_1(operando1,operando2,clnt);
			operando1 = *result;
		}
		if (!strcmp(operator,"^")){
			result = potencia_1(operando1,operando2,clnt);
			operando1 = *result;
		}
		printf(" %c %lf ",*operator, operando2);
	}

	if (result == (double *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	printf("= %lf\n",operando1);


#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	char operation[255];
	double numeros[255];
	//double integer1 = 0, integer2 = 0;

	if (argc < 5 || argc%2 == 0) {
		printf ("usage: %s server_host integer (operation integer)...\n", argv[0]);
		exit (1);
	}

	int utils=0;
	for (int ii=3; ii < argc; ii += 2){
		operation[utils] = *(argv[ii]);
		utils++;
	}
	utils = 0;
	for (int ii=2; ii < argc; ii += 2){
		numeros[utils] = atoi(argv[ii]);
		utils++;
	}

	host = argv[1];

	calculadora_1 (host, numeros, operation, utils);
	exit (0);
}

