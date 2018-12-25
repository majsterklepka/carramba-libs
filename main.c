/*
 * main.c
 *
 * Created on: 24 grudnia, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed
 *    Address: POLAND, mazovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <carramba-libs.h>
#include "config.h"


const char *version()
{	
	return (const char*)VERSION;
}

const char *info(int format);

int test(const char *number)
{

} 
