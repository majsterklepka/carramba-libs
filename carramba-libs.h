/*
 * carramba-libs.h
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
