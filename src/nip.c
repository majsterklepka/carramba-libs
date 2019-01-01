/*
 * nip.c
 *
 * Created on: 25 grudnia, 2018
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


int nip_validation_test(const char *nip)
{

	char input[11];

	int waga[] = {6,5,7,2,3,4,5,6,7};

	int sum[10];

	int wynik = 0;

	int rest = 0;

	int len = 0;

	int count = 0;

//----------------------------------------------------------

	for (int i = 0; i < 10; i++)
		sum[i] = 0;

	for (int i = 0; i < 10; i++)
		input[i] = '\0';

	for (int i = 0; i < 2; i++)
		if (isalpha(nip[i]))
			count++;
//----------------------------------------------------------

	if (count == 2)
		for(int i = 0; i < 10; i++)
			input[i] = *(nip + i + 2);
	else
		for(int i = 0; i < 10; i++)
			input[i] = *(nip + i);
	input[10] = '\0';

//----------------------------------------------------------
	
	len = strlen(nip);		

	if ( len == 12 && count == 2)
	{
		for (int i = 0; i < 9; i++){
			sum[i] = ((int)input[i] - 48) * waga[i];
			wynik += sum[i];
		}
		
		rest = wynik % 11;
		if (rest == ((int)input[9] - 48) || rest == 10 )
			return RETURN_CODE_VALID;
		else
			return RETURN_CODE_INVALID;
	}else if (len == 10 && count == 0){

		for (int i = 0; i < 9; i++){
			sum[i] = ((int)input[i] - 48) * waga[i];
			wynik += sum[i];
		}
		rest = wynik % 11;
//----------------------------------------------------------
		if (rest == ((int)input[9] - 48) || rest == 10 )
			return RETURN_CODE_VALID;
		else
			return RETURN_CODE_INVALID;
	}

//----------------------------------------------------------

	return RETURN_CODE_INVALID;

}

