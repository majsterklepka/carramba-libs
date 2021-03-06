/*
 * carramba-libs.h
 *
 * Created on: 24 grudnia, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed, individual creator
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
 */

#ifndef CARRAMBA_LIBS_H_
#define CARRAMBA_LIBS_H_

#define INFO_FORMAT_PLAINTEXT	0
#define INFO_FORMAT_MARKDOWN	10
#define INFO_FORMAT_MARKUP	20

#define RETURN_CODE_VALID 	0
#define	RETURN_CODE_INVALID	1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <error.h>
#include <errno.h>

#ifndef NIP_C_
#define NIP_C_		1
#endif

#ifndef REGON_C_
#define REGON_C_	1
#endif

#ifndef PESEL_C_
#define PESEL_C_	1
#endif

#ifndef IBAN_C_
#define IBAN_C_		1
#endif

char *libcarramba_errstr;

int iban_validation_test(const char *iban);

int regon_validation_test(const char *regon);

int pesel_validation_test(const char *pesel);

int nip_validation_test(const char *nip);

const char *carramba_libs_version();

const char *carramba_libs_info(int format);

int carramba_libs_api_test(const char *number); 

#endif /* CARRAMBA_LIBS_H_ */
