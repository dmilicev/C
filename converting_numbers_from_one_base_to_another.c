/*
	Unfinished...
	It will be continued...

	converting_numbers_from_one_base_to_another.c	by Dragan Milicev


	There are 4 bases of numbers that we work with:	2, 8, 10, 16.

	2
	Binary number system is a base 2 number system.
	It uses only two symbols i.e. 0 and 1 to represent all numbers.

	8
	Octal number system is a base 8 number system.
	It uses 8 symbols to represent all its numbers i.e. 01234567

	10
	Decimal number system is a base 10 number system.
	It uses 10 symbols to represent all its numbers i.e. 0123456789

	16
	Hexadecimal number system is a base 16 number system.
	It uses 16 symbols to represent all numbers i.e. 0123456789ABCDEF

	There 12 functions for conversions:

	2-8		2-10	2-16
	8-10	8-16
	10-16

	16-10	16-8	16-2
	10-8	10-2
	8-2

	In case you want to work with long binary numbers like 20 bits or 30 bit,
	you can use string variable to store the binary numbers.

	Functions convert string numbers to string numbers or
	numbers to numbers, so there are 12 * 2 = 24 functions.

//  1. 2-8, (strings)
//  2. 2-8, (numbers), DONE
//  3. 2-10, (strings) DONE
//  4. 2-10, (numbers) DONE
//  5. 2-16, (strings)
//  6. 2-16, (numbers), impossible because hexadecimal letters cannot be represented by integer

//  7. 8-10, (strings)
//  8. 8-10, (numbers)
//  9. 8-16, (strings)
// 10. 8-16, (numbers), impossible because hexadecimal letters cannot be represented by integer

// 11. 10-16, (strings) DONE
// 12. 10-16, (numbers), impossible because hexadecimal letters cannot be represented by integer

// 13. 16-10, (strings) DONE
// 14. 16-10, (numbers), impossible because hexadecimal letters cannot be represented by integer
// 15. 16-8, (strings)
// 16. 16-8, (numbers), impossible because hexadecimal letters cannot be represented by integer
// 17. 16-2, (strings)
// 18. 16-2, (numbers), impossible because hexadecimal letters cannot be represented by integer

// 19. 10-8, (strings)
// 20. 10-8, (numbers)
// 21. 10-2, (strings), DONE
// 22. 10-2, (numbers), DONE

// 23. 8-2, (strings), DONE
// 24. 8-2, (numbers), DONE


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>
#include <string.h>
#include <math.h>			// for function pow()

#define MAX_SIZE 100



// 1. 2-8, (strings), binary to octal
// Function to convert string of a Binary Number to an string of Octal Number
// https://www.knowprogram.com/c-programming/convert-octal-to-binary-and-binary-to-octal/
// With decimal point:
// https://www.geeksforgeeks.org/convert-binary-number-octal/
char *BinToOct_Strings( char *binNumS, char *octNumS )
{
// ... add code ...
	return octNumS;
} // BinToOct_Strings()


// 2. 2-8, (numbers), binary to octal
// Function to convert an Binary Number to Octal Number
// https://www.programiz.com/c-programming/examples/octal-binary-convert
// https://codeforwin.org/2015/08/c-program-to-convert-binary-to-octal-number-system.html
// https://www.sanfoundry.com/c-program-convert-binary-octal/
int BinToOct( long long binaryNumber, long long* octalNumber )
{
    int decimalNumber = 0, i = 0;
    //long long octalNumber = 0;

    *octalNumber = 0;						// reset octalNumber

    while(binaryNumber != 0)
    {
        decimalNumber += (binaryNumber%10) * pow(2,i);
        i++;
        binaryNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        *octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return *octalNumber;
} // BinToOct()


// 3. 2-10, (strings), binary to decade
// Function to convert string of a Binary Number to a string of Decade Number
char *BinToDec_Strings( char *binNumS, char *convertedNumS )
{
    int i;
    int dec_value = 0;
    int base = 1;					// Initializing base value to 1, i.e 2^0
    int len = strlen(binNumS);

    strcpy(convertedNumS,"");		// empty string convertedNumS

    for ( i=len-1; i>=0; i--) {

        if ( *(binNumS+i) == '1' )
            dec_value += base;

        base = base * 2;
    }

    sprintf(convertedNumS,"%d",dec_value);	// convert dec_value to string

	return convertedNumS;
} // BinToDec_Strings


// 4. 2-10, (numbers), binary to decade
// Function to convert Binary Number to Decade Number
long long BinToDec( long long binNum, long long* decNum )
{
    int base = 1;		// Initializing base value to 1, i.e 2^0
    int last_digit;

    *decNum = 0;	// reset decNum

    while( binNum ) {
        last_digit = binNum % 10;

        binNum = binNum / 10;

        *decNum += last_digit * base;

        base = base * 2;
    }

	return *decNum;
} // BinToDec


// 5. 2-16, (strings)
// 6. 2-16, (numbers), impossible because hexadecimal letters cannot be represented by integer

// 7. 8-10, (strings)
// 8. 8-10, (numbers)
// 9. 8-16, (strings)
// 10. 8-16, (numbers), impossible because hexadecimal letters cannot be represented by integer


// 11. 10-16, (strings), decade to hexadecimal
// Function to convert string of a Decade Number to a string of a Hexadecimal Number
// https://www.geeksforgeeks.org/program-decimal-hexadecimal-conversion/
char *DecToHex_Strings( char *decNumS, char *convertedNumS )
{
    int temp;					// temp is temporary variable to store remainder
    int i=0;					// i is counter for string decNumS
    int j;						// j is counter for reverse order
    int k=0;					// k is counter for convertedNumS
	int dec_num = atoi(decNumS);// convert string decNumS to integer dec_num
	int len;					// lenght of convertedNumS
	char mem_char;

    strcpy(convertedNumS,"");	// empty string convertedNumS

    while( dec_num != 0 )
    {
        temp  = 0; 				// temporary variable to store remainder

        temp = dec_num % 16; 	// storing remainder in temp variable

        if( temp < 10 )			// check if temp < 10
            *(convertedNumS + (i++) ) = temp + 48;
        else
            *(convertedNumS + (i++) ) = temp + 55;

        dec_num = dec_num / 16;
    }

   	*(convertedNumS+i) = '\0';	// terminate the string convertedNumS

	len = strlen(convertedNumS);

    for( i=0,j=len-1; i<len/2; i++,j-- )	// reverse string convertedNumS
	{
		mem_char = *(convertedNumS+i);
		*(convertedNumS+i) = *(convertedNumS+j);
		*(convertedNumS+j) = mem_char;
	}

	return convertedNumS;
} // DecToHex_Strings


// 12. 10-16, (numbers), impossible because hexadecimal letters cannot be represented by integer


// 13. 16-10, (strings), hexadecimal to decade
// Function to convert string of a Hexadecimal Number to a string of Decade Number
// https://www.geeksforgeeks.org/program-hexadecimal-decimal/
char *HexToDec_Strings( char *hexNumS, char *convertedNumS )
{
    int base = 1; 				// Initializing base value to 1, i.e 16^0
    int i, dec_val = 0;
	int len=strlen(hexNumS);

    strcpy(convertedNumS,"");	// empty string convertedNumS

    for( i=len-1; i>=0; i-- )	// Extracting characters as digits from last character
    {
		// if character lies in '0'-'9', converting it to integral 0-9
		// by subtracting 48 from ASCII value.
        if( *(hexNumS+i)>='0' && *(hexNumS+i)<='9' )
        {
            dec_val += (*(hexNumS+i) - 48) * base;
            base = base * 16;	// incrementing base by power
        }

        // if character lies in 'A'-'F' , converting it to integral 10-15
        // by subtracting 55 from ASCII value
        else if( *(hexNumS+i)>='A' && *(hexNumS+i)<='F' )
        {
            dec_val += ( *(hexNumS+i) - 55) * base;
            base = base * 16;	// incrementing base by power
        }
    }

    sprintf(convertedNumS, "%d", dec_val );	// convert dec_val to string

	return convertedNumS;
} // BinToDec_Strings


// 14. 16-10, (numbers), impossible because hexadecimal letters cannot be represented by integer
// 15. 16-8, (strings)
// 16. 16-8, (numbers), impossible because hexadecimal letters cannot be represented by integer
// 17. 16-2, (strings)
// 18. 16-2, (numbers), impossible because hexadecimal letters cannot be represented by integer

// 19. 10-8, (strings)
// 20. 10-8, (numbers)


// 21. 10-2, (strings), decade to binary
// Function to convert string of a Decade Number to a string of Binary Number
// https://www.includehelp.com/c-programs/c-program-to-convert-number-from-decimal-to-binary.aspx
// https://codereview.stackexchange.com/questions/192390/convert-binary-string-to-decimal-number
char *DecToBin_Strings( char *decNumS, char *convertedNumS )
{
    int number, i, j=0, r ;		// i for bin[], j for convertedNumS, r for reverse order
    int bin[MAX_SIZE];

    strcpy(convertedNumS,"");	// empty string convertedNumS

	number = atoi(decNumS);		// convert string to integer

    i=0;              			// initialize index to zero

    while( number>0 )
    {
        bin[i] = number % 2;
        number = number / 2;
        i++;
    }

	// print values of bin[r] in reverse order to convertedNumS
    for( r=i-1; r>=0; r-- )
        sprintf( convertedNumS + (j++), "%d", bin[r] );

	*(convertedNumS+j) = '\0';	// terminate the string convertedNumS

	return convertedNumS;
} // BinToDec_Strings


// 22. 10-2, (numbers), decade to binary
// Function to convert Decade Number to Binary Number
// https://www.programiz.com/c-programming/examples/binary-decimal-convert
// https://www.w3resource.com/c-programming-exercises/for-loop/c-for-loop-exercises-41.php
long long DecToBin( long long decNum, long long* binNum )
{
    int remainder, i=1, step=1;

    *binNum = 0;		// reset binNum

    while (decNum!=0)
    {
        remainder = decNum % 2;
        decNum /= 2;
        *binNum += remainder * i;
        i *= 10;
    }
	return *binNum;
} // BinToDec


// 23. 8-2, (strings) octal to binary
// Function to convert string of an Octal Number to Binary Number string
// https://www.geeksforgeeks.org/program-to-convert-octal-number-to-*binary-number/
char *OctToBin_Strings( char *octNumS, char *convertedNumS )
{
	int i = 0;

	strcpy(convertedNumS,"");		// empty string convertedNumS

    while (octNumS[i]) {
        switch (octNumS[i]) {
        case '0':
            strcat(convertedNumS,"000");
            break;
        case '1':
            strcat(convertedNumS,"001");
            break;
        case '2':
            strcat(convertedNumS,"010");
            break;
        case '3':
            strcat(convertedNumS,"011");
            break;
        case '4':
            strcat(convertedNumS,"100");
            break;
        case '5':
            strcat(convertedNumS,"101");
            break;switch (octNumS[i])
        case '6':
            strcat(convertedNumS,"110");
            break;
        case '7':
            strcat(convertedNumS,"111");
            break;
        default:
            printf("\n Invalid Octal Digit %c \n", octNumS[i] );
			strcpy(convertedNumS,"");
			return(convertedNumS);			// on error return empty string
            break;
        } // switch (octNumS[i])

        i++;

    } // while (octNumS[i])

    return convertedNumS;
} // OctToBin_Strings()


// 24. 8-2, (numbers), octal to binary
// Function to convert an Octal Number to Binary Number
// https://www.programiz.com/c-programming/examples/octal-binary-convert
// https://www.geeksforgeeks.org/program-to-convert-octal-number-to-binary-number/
// another way:
// https://codeforwin.org/2015/08/c-program-to-convert-octal-to-binary-number-system.html
long long OctToBin(long long octalNumber, long long* binaryNumber )
{
    int decimalNumber = 0, i = 0;
    //long long binaryNumber = 0;

    *binaryNumber = 0;						// reset binaryNumber

    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }
    i = 1;
    while (decimalNumber != 0)
    {
        *binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }
    return *binaryNumber;
} // OctToBin()



int main(void)
{
	// numbers in the form of a string, string numbers
	char binNumS[MAX_SIZE] = "1010";// binary      number can have  2 digits 01
	char octNumS[MAX_SIZE] = "70";	// octal       number can have  8 digits 01234567
	char decNumS[MAX_SIZE] = "26";	// decimal     number can have 10 digits 0123456789
	char hexNumS[MAX_SIZE] = "1A";	// hexadecimal number can have 16 digits 0123456789ABCDEF
	char convertedNumS[MAX_SIZE] = "";

	// numbers
	long long binNum = 1011;
	long long octNum = 71;
	long long decNum = 12;
	long long LongLongNum = 11;


/*
	// 1. 2-8, binary to octal (strings)
	printf("\n\t 1. 2-8, binary to octal (strings) \n");
	BinToOct_Strings( binNumS, convertedNumS );
	printf("\n binary %s = %s octal (strings) \n", binNumS, convertedNumS );
	printf("\n binary %s = %s octal (strings) \n\n", binNumS, BinToOct_Strings(binNumS,convertedNumS) );
*/

	// 2. 2-8, binary to octal (numbers)
	printf("\n\t 2. 2-8, binary to octal (numbers) \n");
	octNum = BinToOct( binNum, &octNum );
	printf("\n binary %lld = %lld octal \n", binNum, octNum );
	printf("\n binary %lld = %lld octal \n\n", binNum, BinToOct(binNum,&octNum) );

	// 3. 2-10, binary to decade (strings)
	printf("\n\t 3. 2-10, binary to decade (strings) \n");
	BinToDec_Strings( binNumS, convertedNumS );
	printf("\n binary %s = %s decade \n", binNumS, convertedNumS );
	printf("\n binary %s = %s decade \n\n", binNumS, BinToDec_Strings(binNumS,convertedNumS) );

	// 4. 2-10, binary to decade (numbers)
	printf("\n\t 4. 2-10, binary to decade (numbers) \n");
	LongLongNum = BinToDec( binNum, &LongLongNum );
	printf("\n binary %lld = %lld decade \n", binNum, LongLongNum );
	printf("\n binary %lld = %lld decade \n\n", binNum, BinToDec(binNum,&LongLongNum) );


	// 11. 10-16, decade to hexadecimal (strings)
	printf("\n\t 11. 10-16, decade to hexadecimal (strings) \n");
	DecToHex_Strings( decNumS, convertedNumS );
	printf("\n decade %s = %s hexadecimal \n", decNumS, convertedNumS );
	printf("\n decade %s = %s hexadecimal \n\n", decNumS, DecToHex_Strings(decNumS,convertedNumS) );

	// 13. 16-10, hexadecimal to decade (strings)
	printf("\n\t 13. 16-10, hexadecimal to decade (strings) \n");
	HexToDec_Strings( hexNumS, convertedNumS );
	printf("\n hexadecimal %s = %s decade \n", hexNumS, convertedNumS );
	printf("\n hexadecimal %s = %s decade \n\n", hexNumS, HexToDec_Strings(hexNumS,convertedNumS) );


	// 21. 10-2, decade to binary (strings)
	printf("\n\t 21. 10-2, decade to binary (strings) \n");
	DecToBin_Strings( decNumS, convertedNumS );
	printf("\n decade %s = %s binary \n", decNumS, convertedNumS );
	printf("\n decade %s = %s binary \n\n", decNumS, DecToBin_Strings(decNumS,convertedNumS) );

	// 22. 10-2, decade to binary (numbers)
	printf("\n\t 22. 10-2, decade to binary (numbers) \n");
	LongLongNum = DecToBin( decNum, &LongLongNum );
	printf("\n decade %lld = %lld binary \n", decNum, LongLongNum );
	printf("\n decade %lld = %lld binary \n\n", decNum, DecToBin(decNum,&LongLongNum) );

	// 23. 8-2, octal to binary (strings)
	printf("\n\t 23. 8-2, octal to binary (strings) \n");
	OctToBin_Strings( octNumS, convertedNumS );
	printf("\n octal %s = %s binary (strings) \n", octNumS, convertedNumS );
	printf("\n octal %s = %s binary (strings) \n\n", octNumS, OctToBin_Strings(octNumS,convertedNumS) );

	// 24. 8-2, octal to binary (numbers)
	printf("\n\t 24. 8-2, octal to binary (numbers) \n");
	LongLongNum = OctToBin(octNum, &LongLongNum);
	printf("\n octal %lld = %lld binary \n", octNum, LongLongNum );
	printf("\n octal %lld = %lld binary \n\n", octNum, OctToBin(octNum,&LongLongNum) );


    return 0;
}
