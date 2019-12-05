/*

    converting_arabic_numerals_to_roman_numerals.c


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


void arabic2roman(int arabic, char *roman){

    // Values of roman digits
    int vrednost[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    // Simbols of roman digits
    char* simbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    int i = 0;

    strcpy(roman,"");                  // we empty the string roman

    while (arabic){                    // while the Arabic number is non-zero
        while (arabic/vrednost[i]){    // while arabic contains the highest possible value of Roman digits
            strcat(roman, simbol[i]);  // we add a symbol for this value to a Roman string
            arabic -= vrednost[i];     // we reduce the arabic number by the value of the Roman digit added
        }
        i++;                            // we move on to the next value of the Roman digit
    }
}


int main(void) {

	//int arabic=11000;
	int arabic=2736;
	char roman[100];

	printf("\n arabic to roman \n");

	arabic2roman(arabic, roman );

	printf("\n %d = %s \n", arabic, roman );

	return 0;
}
