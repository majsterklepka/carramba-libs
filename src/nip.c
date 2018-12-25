int nip_validation_test(const char *nip)
{

char input[10];

int waga[] = {6,5,7,2,3,4,5,6,7};

int sum[10];

int wynik = 0;

int rest = 0;

int len = 0;

int count = 0;


for (int i = 0; i < 10; i++)
	sum[i] = 0;

for (int i = 0; i < 10; i++)
	input[i] = '\0';

len = strlen(nip);

for (int i = 0; i < 2; i++)
	if (isalpha(nip[i]))
		count++;
if (count == 2)
	for(int i = 0; i < 10; i++)
		input[i] = *(nip + i + 2);
else
	for(int i = 0; i < 10; i++)
		input[i] = *(nip + i);
		

if ( len == 12 && count == 2)
{
	for (int i = 0; i < 9; i++){
		sum[i] = ((int)input[i] - 48) * waga[i];
		wynik += sum[i];
	}
	
	rest = wynik % 11;
	if (rest == ((int)input[9] - 48) || rest == 10 )
		return RETURN_CODE_VALID;
	else
		return RETURN_CODE_INVALID;
}else if (len == 10 && count == 0){

	for (int i = 0; i < 9; i++){
		sum[i] = ((int)input[i] - 48) * waga[i];
		wynik += sum[i];
	}
	
	rest = wynik % 11;
	if (rest == ((int)input[9] - 48) || rest == 10 )
		return RETURN_CODE_VALID;
	else
		return RETURN_CODE_INVALID;


}
	return RETURN_CODE_INVALID;

}

