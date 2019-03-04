/*
 * regon.c
 *
 * Created on: 28 grudnia, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed, individual creator
 *    Address: POLAND, masovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
 *
 *
 * This file is part of Carramba Libs.
 *
 *   Carramba Libs is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Carramba Libs is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Carramba Libs.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _GNU_SOURCE

#include <carramba-libs.h>

int regon_validation_test(const char *regon)
{
	int waga14[] = {2,4,8,5,0,9,7,3,6,1,2,4,8};

	int waga9[] = {8,9,2,3,4,5,6,7};

	int waga7[] = {2,3,4,5,6,7};

	int len = 0;

	int sum[14];

	char input[15];

	int wynik = 0;

	int rest = 0;

//----------------------------------------------------------
	
	len = strlen(regon);

//----------------------------------------------------------

	for (int i = 0; i < len; i++)
	{
		if (!isdigit(regon[i]))
			return RETURN_CODE_INVALID;
	}

//----------------------------------------------------------

	if ( len != 7 || len != 9 || len != 14)
		return RETURN_CODE_INVALID;

//----------------------------------------------------------

	for ( int i = 0; i < 14; i++)
		sum[i] = 0;

	for ( int i = 0; i < 15; i++)
		input[i] = '\0';

//----------------------------------------------------------
	
	strcpy(input,regon);
	if(errno){
		libcarramba_errstr = "strcpy(input, regon)";
		perror(libcarramba_errstr);
		exit(EXIT_FAILURE);
	}

//----------------------------------------------------------

	len = strlen(input);

//----------------------------------------------------------

	for (int i = 0; i < (len - 1); i++)
	{
		if ( len == 9 )		
			sum[i] = ((int)input[i] - 48) * waga9[i];
		else if ( len == 14 )
			sum[i] = ((int)input[i] - 48) * waga14[i];
		else if ( len == 7)
			sum[i] = ((int)input[i] - 48) * waga7[i];
		wynik += sum[i];			 
	}

//----------------------------------------------------------

	rest = wynik % 11;

//----------------------------------------------------------

	if ( len == 9 )
	{
		if ( rest == ((int)input[8] - 48) || rest == 10 )
			return RETURN_CODE_VALID;
	} else if ( len == 14 ){
		if ( rest == ((int)input[13] - 48) || rest == 10 )
			return RETURN_CODE_VALID;
	} else {
		if ( rest == ((int)input[6] - 48) || rest == 10 )
			return RETURN_CODE_VALID;
	}

//----------------------------------------------------------

	return RETURN_CODE_INVALID;	
}

