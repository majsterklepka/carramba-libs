/*
 * regon.c
 *
 * Created on: 28 grudnia, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed
 *    Address: POLAND, masovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
 *
 */

#define REGON_C_	1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <carramba-libs.h>

int regon_validation_test(const char *regon)
{
	int waga14[] = {2,4,8,5,0,9,7,3,6,1,2,4,8};
	int waga9[] = {8,9,2,3,4,5,6,7};
	int len = 0;
	int sum[14];
	char input[15];
	int wynik = 0;
	int rest = 0;
	
	len = strlen(regon);
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(regon[i]))
			return RETURN_CODE_INVALID;
	}
	for ( int i = 0; i < 14; i++)
		sum[i] = 0;

	for ( int i = 0; i < 15; i++)
		input[i] = '\0';

	if ( len == 7 )
	{
		int i = 0;
		for (i = 0; i < 9; i++)
		{	
			if (i == 0 || i == 1)
				input[i] = '0';
			else{
				input[i] = *(regon + i);
			}
		}
		input[i] = '\0';	
	}else if(len == 9 || len == 14 )
	{
		int i = 0;
		while ( i < len )
		{
			input[i] = *(regon + i);
			i++;
		}
		input[i] = '\0';				
	} 
	len = strlen(input);
	for (int i = 0; i < (len - 1); i++)
	{
		if ( len == 9 )		
			sum[i] = ((int)input[i] - 48) * waga9[i];
		else if ( len == 14 )
			sum[i] = ((int)input[i] - 48) * waga14[i];
		wynik += sum[i];			 
	}
	rest = wynik % 11;
	if (len == 9)
	{
		if ( rest == ((int)input[8] - 48) || rest == 10 )
			return RETURN_CODE_VALID;
	} else if ( len == 14 )
	{
		if ( rest == ((int)input[13] - 48) || rest == 10 )
			return RETURN_CODE_VALID;
	}
	return RETURN_CODE_INVALID;	
}

