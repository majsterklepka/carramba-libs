/*
 * carramba-libs.h
 *
 *  Created on: 24 Dec 2018
 *      Author: Paweł Sobótka <48721262935pl@gmail.com>
 *     License: GNU GPLv3 or later
 *   Copyright: ©2017-2019 Paweł Sobótka all rights reserved
 *
 */

#ifndef CARRAMBA_LIBS_H_
#define CARRAMBA_LIBS_H_

#define INFO_FORMAT_PLAINTEXT	0
#define INFO_FORMAT_MARKDOWN	10
#define INFO_FORMAT_KRAMDOWN	20

#define RETURN_CODE_VALID 	0
#define	RETURN_CODE_INVALID	-1


int iban_validation_test(const char *iban);

int regon_validation_test(const char *regon);

int pesel_validation_test(const char *pesel);

int nip_validation_test(const char *nip);

const char *version();

const char *info(int format);

int test(const char *number); 

#endif /* CARRAMBA_LIBS_H_ */
