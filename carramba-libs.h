/*
 * carramba-libs.h
 *
 *  Created on: 24 gru 2018
 *      Author: Paweł Sobótka <48721262935pl@gmail.com>
 *     License: GNU GPLv3 or later
 *   Copyright: ©2017-2019 Paweł Sobótka all rights reserved
 *
 */

#ifndef CARRAMBA_LIBS_H
#define CARRAMBA_LIBS_H

int iban_validation_test(const char *iban);

int regon_validation_test(const char *regon);

int pesel_validation_test(const char *pesel);

int nip_validation_test(const char *nip);

#endif /* CARRAMBA_LIBS_H */
