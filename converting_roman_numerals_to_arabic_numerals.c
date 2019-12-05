/*

    converting_roman_numerals_to_arabic_numerals.c



    As a reminder, the following tables contain Roman numerals:

    I   V   X   L   C   D   M
    1   5   10  50  100 500 1000

    IV  IX  XL  XC  CD  CM
    4   9   40  90  400 900

    Test case:

    2736 = MMDCCXXXVI

    or separated:

           2  7   3   6
    2736 = MM DCC XXX VI

           3   4  4   4
    3444 = MMM CD XL  IV

           3   9  9   9
    3999 = MMM CM XC  IX

MDCCCLXXXVIII = 1000 + 500 + 100 + 100 + 100 + 50 + 10 + 10 + 10 + 5 + 1 + 1 + 1 = 1888

If the value of the left digit is less than the right,
then the value of the left digit is subtracted from the value of the right.

MCMXCIX = M CM XC IX or 1000 + (1000 - 100) + (100 - 10) + (10 - 1) = 1999

MCMXCIX = M CM XC IX or 1000 - 100 + 1000 - 10 + 100 - 1 + 10 = 1999


    I   V   X   L   C   D   M
    1   5   10  50  100 500 1000


    The number of thousands: the number of Ms at the beginning * 1000 is the number of thousands.

    0       1000        2000        3000    4000    5000    ...     11000
    0       1           2           3       4       5       ...     11
            M           MM          MMM     MMMM    MMMMM           MMMMMMMMMMM

    Number of hundreds:       <4 , =4 , >4

    0       100     200     300     400     500     600     700     800     900
    0       1       2       3       4       5       6       7       8       9
            C       CC      CCC     CD      D       DC      DCC     DCCC    CM


    Number of tens:           <4 , =4 , >4

    0       10      20      30      40      50      60      70      80      90
    0       1       2       3       4       5       6       7       8       9
            X       XX      XXX     XL      L       LX      LXX     LXXX    XC


    Number of ones            <4 , =4 , >4

    0       1       2       3       4       5       6       7       8       9
            I       II      III     IV      V       VI      VII     VIII    IX


*/

#include <stdio.h>
#include <string.h>

int get_roman_letter(char string[], int i) {

	int sign_plus_minus = 1;

	if (string[i] == 'I' && (string[i + 1] == 'V' || string[i + 1] == 'X'))
		sign_plus_minus = -1;

	if (string[i] == 'X' && (string[i + 1] == 'L' || string[i + 1] == 'C'))
		sign_plus_minus = -1;

	if (string[i] == 'C' && (string[i + 1] == 'D' || string[i + 1] == 'M'))
		sign_plus_minus = -1;

	return sign_plus_minus;
}

int get_digit(char c) {

	int digit;

	switch (c) {
        case 'I': digit = 1;
            break;
		case 'V': digit = 5;
			break;
		case 'X': digit = 10;
			break;
		case 'L': digit = 50;
			break;
		case 'C': digit = 100;
			break;
		case 'D': digit = 500;
			break;
		case 'M': digit = 1000;
			break;
		default: digit = 0;
			break;
	}
	return digit;
}

int get_arabic_number(char roman[]) {

	int i, number = 0;

	for (i = 0; i < strlen(roman); i++) {
		number += get_roman_letter(roman, i) * get_digit(roman[i]);
	}
	return number;
}


int main(void) {

	int arabic;
	char roman[100];

	strcpy(roman,"MMDCCXXXVI");

	printf("\n roman to arabic \n");

	arabic = get_arabic_number(roman);

	printf("\n %s = %d \n", roman, arabic );

	return 0;
}
