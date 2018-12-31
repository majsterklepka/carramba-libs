# Project carramba-libs
library for validate important number in polish goverment administration: PESEL, NIP REGON, IBAN

While checking the correctness of numbers, there is a simple rule: the whole number consists of numbers, each of these digits is multiplied by the balance and the last one, we add products and calculate the sum mod 10 (11), the final digit in the number is a checksum that must match the calculated .

## PESEL number

The PESEL number consists of 10 digits, the last one(11) is a checksum. I will not describe the components of a PESEL number, all can be found on the Internet. Briefly, validation is done by:

```
1 2 3 4 5 6 7 8 9 10 11
a b c d e f g h i j     -> next digits in the PESEL number
x x x x x x x x x x   y -> the balance of each digit, y -> checksum
```

To calculate the checksum, multiply each digit by balance, add the products to each other and calculate the checksum mod 10

```
checksum = (a*1 + b*3 + c*7 + d*9 + e*1 + f*3 + g*7 + h*9 + i*1 + j*3) mod 10; 

sum = 10 - checksum;

if sum == 10; then sum = 0; => must be y = 0;

if sum == y; then return NUMBER_VALID; else return NUMBER_INVALID;

weight[] = {1,3,7,9,1,1,3,7,9,1}; => balance
```


## NIP number

The NIP number consists of 9 digits and the last 10 is the checksum. You can find out more about the NIP number on the Internet. How to calculate the checksum? It is very simple ...

```
1 2 3 4 5 6 7 8 9 10 
a b c d e f g h i     -> next digits in the NIP number
x x x x x x x x x  y  -> the balance of each digit, y -> checksum
```

To calculate the checksum, multiply each digit by balance, add the products to each other and calculate the checksum mod 11

```
checksum = (a*6 + b*5 + c*7 + d*2 + e*3 + f*4 + g*5 + h*6 + i*7) mod 11; 

if checksum == 10; then checksum = 0; => must be y = 0;

if checksum == y; then return NUMBER_VALID; else return NUMBER_INVALID;

weight[] = {6,5,7,2,3,4,5,6,7}; => balance
```

## REGON number

REGON number consists of 7, 9 or 14 digits, where the last of digits is a checksum. As with the numbers NIP and PESEL, digits from the REGON number are multiplied by the weight, the products are added to each other and the sum calculated modulo 11

```
weight7[]  = {2,3,4,5,6,7};
weight9[]  = {8,9,2,3,4,5,6,7 };
weight14[] = {2,4,8,5,0,9,7,3,6,1,2,4,8};
if checksum == 10; then checksum = 0; 
```

The calculation is made as for the other numbers.


## IBAN number

All instruction here: [IBAN validation](https://romek.info/ut/banki.html)
