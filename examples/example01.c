/*
 * example01.c
 *
 * Created on: 01 stycznia, 2019
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/carramba-libs.git
 *    Company: mgr inż. Paweł Sobótka, self-employed
 *    Address: POLAND, masovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

#include <carramba-libs.h>//plik nagłówkowy biblioteki libcarramba
#include <readline/readline.h>
#include <readline/history.h>
#include <malloc.h>
#include <locale.h>

/*
przykładowa implementacja biblioteki libcarramba i jej dwóch funkcji
carramba_libs_info(int format) oraz carramba_libs_api_test(const char *input)
więcej w pliku README.md w katalogu examples 
repozytorium majsterklepka/carramba-libs na GitHub.com
*/

void show_answer(int rest, const char *input);

int main(int argc, char **argv)
{
	char *input; //
	int rest = 0;//nadawanie wartrości początkowej zmiennym
	int k = 65;  //
//---------------------------------------------------------------
	setlocale(LC_ALL, "pl_PL.UTF-8");//definiowanie języka
//---------------------------------------------------------------
	/* wyświetlanie informacji o bibliotece */	
	const char *about = carramba_libs_info(INFO_FORMAT_PLAINTEXT);
	printf("%s\n", about);
//---------------------------------------------------------------	
	input = (char*)malloc(k*sizeof(char));//alokowanie pamięci dla zmiennej
	input = readline("Wprowadź swój numer (PESEL|NIP|REGON|IBAN)\n(klawisz ENTER kończy wprowadzanie)\n(max. 64 znaków w lini): ");//czytanie ze stdin danych wejściowych
	printf("\n");//drukowanie znaku nowego wiersza
//---------------------------------------------------------------
	int len = strlen(input);//sprawdzanie długości ciągu wejściowego
	if (len == 0 )// test logiczny, jesli PRAWDA to kończy działanie programu
	{
		printf("Błąd wprowadzania...\nKończę działanie!\n");
		if(input)
			free(input);
		exit(EXIT_FAILURE);
		
	}	
//---------------------------------------------------------------
	/*funkcja testowa biblioteki libcarramba
	  sprawdza czy ciąg wejściowy input
	  jest poprawnym numerem NIP, REGON, IBAN bądź REGON
	  wartość zwracana jest równa RETURN_CODE_VALID,
	  zgodnie z definicją w pliku carramba-libs.h,	 
	  jeśli jest to poprawny numer,
	  jeśli nie, to zwracana jest wartość RETURN_CODE_INVALID
	 */	 		
	rest = carramba_libs_api_test(input);	
//---------------------------------------------------------------
	show_answer(rest, input);//funkcja wyświetlająca odpowiedź na problem
//---------------------------------------------------------------	
	//zwalnianie pamięci gdy zajęta	
	if (input)
		free(input);		
//---------------------------------------------------------------
	exit(EXIT_SUCCESS);
}


/*
  funkcja wyświetlając w sposób przyjazny dla operatora
  wartość zwracaną przez funkcję carramba_libs_api_test(const char *input)
  z określeniem jaki to jest numer, gdy wartość zwracana
  jest równa RETURN_CODE_VALID
*/
void show_answer(int rest, const char *input)
{
	int len = strlen(input);

	if (rest == RETURN_CODE_VALID && len == 11)
		printf("Numer: %s to prawidłowy numer PESEL\n", input);
	else if ( rest == RETURN_CODE_VALID && (len == 10 || len == 12))
		printf("Numer: %s to prawidłowy numer NIP!\n", input);
	else if (rest == RETURN_CODE_VALID && (len == 7 || len == 9 || len == 14))
		printf("Numer: %s to prawidłowy numer REGON\n", input);
	else if ( rest == RETURN_CODE_VALID && len > 14 )
		printf("Prawidłowy numer IBAN!\n");
	else
		printf("Wprowadziłeś nieprawidłowy numer!\nKończę działanie!\n");
}		
