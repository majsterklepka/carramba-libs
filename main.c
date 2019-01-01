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

#include <locale.h>
#include <carramba-libs.h>
#include "config.h"

char *build_date = __DATE__;
char *build_time = __TIME__;


const char *version()
{	
	return (const char*)VERSION;
}

const char *info(int format)
{
	char *info1, *info2, *line;
	char *info3, *info4, *url, *license;
	char *output;
	line = ">--------*INFO*--------<";
	url = "https://github.com/majsterklepka/carramba-libs.git";
	license = "General Public License version 3.0 or later (GNU GPLv3 or later)";
	if ( format == INFO_FORMAT_MARKUP )
	{
		asprintf(&info1, "<p><i>%s</i> build at: %s %s by <b>%s</b></p>", PACKAGE_STRING, build_date, build_time, BUILDER);

		asprintf(&info2, "<p>Build machine: %s, %s, %s</p>", BUILD_VENDOR, BUILD_CPU, BUILD_OS);
 
		asprintf(&info3, "<p>GitHub Package Repository URL:\n<br/><a href=\"%s\" title=\"GitHub Repository\">%s</a></p>", url, url);

		asprintf(&info4, "<p>%s</p>", license);

		asprintf(&output, "<p>%s\n<br />%s\n%s\n%s\n%s\n%<br />s\n", line, info1, info2, info4, info3, line);

	}else if ( format == INFO_FORMAT_MARKDOWN )
	{
		asprintf(&info1, "_%s_ build at: %s %s by *%s*", PACKAGE_STRING, build_date, build_time, BUILDER);

		asprintf(&info2, "*Build machine:* %s, %s, %s", BUILD_VENDOR, BUILD_CPU, BUILD_OS);
 
		asprintf(&info3, "_GitHub Package Repository URL:_   [%s](%s \"GitHub Repository\")   ", url, url);

		asprintf(&info4, "_%s_", license);

		asprintf(&output, "%s   \n%s\n%s\n%s\n%s\n%s   \n", line, info1, info2, info4, info3, line);

	}else{
		asprintf(&info1, "%s build at: %s %s by %s", PACKAGE_STRING, build_date, build_time, BUILDER);

		asprintf(&info2, "Build machine: %s, %s, %s", BUILD_VENDOR, BUILD_CPU, BUILD_OS);
 
		asprintf(&info3, "GitHub Package Repository URL:\n%s", url);

		asprintf(&info4, "%s", license);

		asprintf(&output, "%s\n%s\n%s\n%s\n%s\n%s\n", line, info1, info2, info4, info3, line); 
	}
	
	return (const char*)output;
}

int test(const char *number)
{
	int len = strlen(number);
	
	#if NIP_C_
	if ( len == 10 )
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

int main()
{
	const char *about = info(INFO_FORMAT_PLAINTEXT);
	printf("%s", about);
	exit(EXIT_SUCCESS);
}
