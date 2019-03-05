/*
 * main.c
 *
 * Created on: 24 grudnia, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        PACKAGE_URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed
 *    Address: POLAND, masovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
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
 *
 */
#define _GNU_SOURCE

#include <locale.h>
#include <carramba-libs.h>
#include "config.h"

char *build_date = __DATE__;
char *build_time = __TIME__;

const char *carramba_libs_version()
{
	return PACKAGE_STRING;
}

const char *carramba_libs_info(int format)
{
	char *info1, *info2, *line;
	char *info3, *info4;
	char *output;
	line = ">--------*INFO*--------<";
	const char *license[] = {"This program is free software: you can redistribute it and/or modify", "it under the terms of the GNU General Public License as published by", "the Free Software Foundation, either version 3 of the License, or", "(at your option) any later version.", "This program is distributed in the hope that it will be useful,", "but WITHOUT ANY WARRANTY; without even the implied warranty of", "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the", "GNU General Public License for more details.", "You should have received a copy of the GNU General Public License", "along with this program.  If not, see <http://www.gnu.org/licenses/>"};
	if ( format == INFO_FORMAT_MARKUP )
	{
		asprintf(&info1, "<p><i>%s</i> build at: %s %s by <b>%s</b></p>", PACKAGE_STRING, build_date, build_time, BUILDER);

		asprintf(&info2, "<p>Build machine: %s</p>", BUILD);
 
		asprintf(&info3, "<p>GitHub Package Repository:\n<br/><a href=\"%s\" title=\"GitHub Repository\">%s</a></p>", PACKAGE_URL, PACKAGE_URL);

		asprintf(&info4, "<p>%s<br/>\n%s<br/>\n%s<br/>\n%s</p>\n<p>%s<br/>\n%s<br/>\n%s<br/>\n%s</p>\n<p>%s<br/>%s</p>", license[0],license[1],license[2], license[3], license[4],license[5],license[6], license[7], license[8],license[9]);

		asprintf(&output, "<p>%s<br />\n%s\n%s\n%s\n%s%<br />\n%s</p>\n", line, info1, info2, info4, info3, line);

	}else if ( format == INFO_FORMAT_MARKDOWN )
	{
		asprintf(&info1, "_%s_ build at: %s %s by *%s*", PACKAGE_STRING, build_date, build_time, BUILDER);

		asprintf(&info2, "*Build machine:* %s", BUILD);
 
		asprintf(&info3, "_GitHub Package Repository:_     [%s](%s \"GitHub Repository\")   ", PACKAGE_URL, PACKAGE_URL);

		asprintf(&info4, "%s  \n%s  \n%s  \n%s\n\n%s  \n%s  \n%s  \n%s\n\n%s  \n%s", license[0],license[1],license[2], license[3], license[4],license[5],license[6], license[7], license[8],license[9]);

		asprintf(&output, "%s   \n%s\n%s\n%s\n%s\n%s   \n", line, info1, info2, info4, info3, line);

	}else{
		asprintf(&info1, "%s build at: %s %s by %s", PACKAGE_STRING, build_date, build_time, BUILDER);

		asprintf(&info2, "Build machine: %s", BUILD);
 
		asprintf(&info3, "GitHub Package Repository:\n%s", PACKAGE_URL);
		
		asprintf(&info4, "%s\n%s\n%s\n%s\n\n%s\n%s\n%s\n%s\n\n%s\n%s", license[0],license[1],license[2], license[3], license[4],license[5],license[6], license[7], license[8],license[9]);
		

		asprintf(&output, "%s\n%s\n%s\n\n%s\n\n%s\n%s\n", line, info1, info2, info4, info3, line); 
	}
	
	return (const char*)output;
}

int carramba_libs_api_test(const char *number)
{
	int len = strlen(number);
	
	#if NIP_C_
	if ( len == 10 || len == 12 )
	{
		return nip_validation_test(number);
	}
	#endif

	#if REGON_C_
	if ( len == 7 || len == 9 || len == 14 )
	{
		return regon_validation_test(number);
	}
	#endif

	#if PESEL_C_
	if ( len == 11 )
	{
		return pesel_validation_test(number);	
	}
	#endif
	
	#if IBAN_C_
	if ( len > 14 )
	{
		return iban_validation_test(number);
	}
	#endif

	return RETURN_CODE_INVALID;
} 

