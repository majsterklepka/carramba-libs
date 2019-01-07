/*
 * pesel.c
 *
 * Created on: 30 grudnia, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed
 *    Address: POLAND, masovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
 *
 *
 * This file is part of Carramba Libs.
 *
 *   Foobar is free software: you can redistribute it and/or modify
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

#include <carramba-libs.h>

int pesel_validation_test(const char *pesel)
{
	char input[12];

	int waga[] ={1,3,7,9,1,3,7,9,1,3};

	int sum[10];

	int wynik = 0;

	int wynik1 = 0;

	int rest = 0;

	int len = 0;

//----------------------------------------------------------

	for (int i = 0; i < 12; i++)
		input[i] ='\0';

	for (int i = 0; i < 10; i++)
		sum[i] = 0;

//----------------------------------------------------------

	len = strlen(pesel);
	
	if ( len != 11 )
		return RETURN_CODE_INVALID;
	for (int i = 0; i < len; i++)
	{
		if(!isdigit(pesel[i]))
			return RETURN_CODE_INVALID;
	}

//----------------------------------------------------------
	
	strcpy(input, pesel);

//----------------------------------------------------------

	for (int i = 0; i < 10; i++)
	{
		sum[i] = ((int)input[i] - 48)*waga[i];
		wynik += sum[i];
	}

//----------------------------------------------------------

	rest = wynik % 10;
	wynik1 = 10 - rest;
	rest = wynik1 % 10;

//----------------------------------------------------------

	if (rest == ((int)input[10] - 48))
		return RETURN_CODE_VALID;

//----------------------------------------------------------

	return RETURN_CODE_INVALID;
}
