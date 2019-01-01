/*
 * example01.c
 *
 * Created on: 01 stycznia, 2019
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed
 *    Address: POLAND, masovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
 *
 */

#include <carramba-libs.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <malloc.h>


int main(int argc, char **argv)
{
	char *input;
	int rest = 0;
	int k = 0;
	const char *about = info(0);
	printf("%s", about);
	input = (char*)malloc(64*sizeof(char));
	input = readline("Wprowadź swój numer (PESEL|NIP|REGON|IBAN): ");
	int len = strlen(input);
	if (len == 0 )
	{
		printf("Błąd wprowadzania...\nKończę działanie!\n");
		free(input);
		exit(EXIT_FAILURE);
		
	}	
	rest = test(input);
	if (rest == RETURN_CODE_VALID && len == 11)
		printf("Numer: %s to prawidłowy numer PESEL\n", input);
	else if ( rest == RETURN_CODE_VALID && len == 10 )
		printf("Numer: %s to prawidłowy numer NIP!\n", input);
	else if (rest == RETURN_CODE_VALID && (len == 7 || len == 9 || len == 14))
		printf("Numer: %s to prawidłowy numer REGON\n", input);
	else if ( rest == RETURN_CODE_VALID && len > 14 )
		printf("Prawidłowy numer IBAN!\n");
	else
		printf("Wprowadziłeś nieprawidłowy numer!\nKończę działanie!\n");
	if (input)
		free(input);		
	exit(EXIT_SUCCESS);
}		
