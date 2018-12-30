/*
 * main.c
 *
 * Created on: 24 grudnia, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed
 *    Address: POLAND, masovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
 *
 */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <carramba-libs.h>
#include "config.h"


const char *version()
{	
	return (const char*)VERSION;
}

const char *info(int format)
{
	char *info1, *info2, *line;
	char *info3, *info4, *url, *license;
	char *output;
	line = "<------...------>";
	url = "https://github.com/majsterklepka/carramba-libs.git";
	license = "General Public License version 3.0 or later (GNU GPLv3 or later)";
	asprintf(&info1, "%s build at: %s %s by %s", PACKAGE_STRING, __DATE__, __TIME__, BUILDER);
	asprintf(&info2, "Build machine: %s, %s, %s", BUILD_VENDOR, BUILD_CPU, BUILD_OS); 
	asprintf(&info3, "GitHub Package Repository URL:\n%s", url);
	asprintf(&info4, "%s", license);
	if ( format == INFO_FORMAT_KRAMDOWN )
	{
	}else if ( format == INFO_FORMAT_MARKDOWN )
	{
	}else{
		asprintf(&output, "%s\n%s\n%s\n%s\n%s\n%s\n", line, info1, info2, info4, info3, line); 
	}
	
	return (const char*)output;
}

int test(const char *number)
{

} 
