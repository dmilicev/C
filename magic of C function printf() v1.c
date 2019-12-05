/*
	magic of C function printf() v1.c

	Use of \b in function printf()
	to move print cursor left

	printf("\b");	// move cursor one space left (backward)

https://stackoverflow.com/questions/6792812/the-backspace-escape-character-b-unexpected-behavior

*/

#include <stdio.h>
#include <time.h>					// for clock()

#define SHORT_TIME 25				// time for delay() in milliseconds
#define LONG_TIME 30*SHORT_TIME 	// time for delay() in milliseconds

void delay(int milliseconds)
{
    clock_t start_time = clock();	// get start time

    // looping (do nothing) till required time is not acheived
    while (clock() < start_time + milliseconds)
		;							// do nothing
}

// move cursor howMuch spaces left
void moveCursorLeft(int howMuch)
{
	int i;

	for (i=0; i<howMuch; i++)		// repeat howMuch times
	{
		printf("\b");				// move cursor one space left
	}
}

// delete characters howMuch spaces left
void backspace(int howMuch)
{
	int i;

	for (i=0; i<howMuch; i++)		// repeat howMuch times
	{
		printf("\b \b");			// delete one left character
		delay(SHORT_TIME);			// to make process visible
	}
}

// print howMuch characters ch
void characters(char ch, int howMuch)
{
	int i;

	for (i=0; i<howMuch; i++)		// repeat howMuch times
	{
		printf("%c",ch);
		delay(SHORT_TIME);			// to make process visible
	}
}

// printing howMuch digits, cyclic from firstDigit to 9
// 0 (ascii 48), 9 (ascii 57)
void digits(int firstDigit, int howMuch)
{
	int offset=0, counter=0;
	char ch = '0' + firstDigit;		// calculate first character to print

	for (counter=0; counter<howMuch; counter++)		// repeat howMuch times
	{
		printf("%c",ch + offset);	// print character

		offset++;					// next character

        if(ch+offset>'9')			// if we reach character '9'
		{
			offset = 0;				// to begin again
			ch = '0';				// from '0'
		}

		delay(SHORT_TIME);			// to make process visible
	}
}

// printing howMuch small letters, cyclic from ch to 'z'
// a (ascii 97), z (ascii 122)
void smallLetters(char ch, int howMuch)
{
	int offset=0, counter=0;

	for (counter=0; counter<howMuch; counter++)		// repeat howMuch times
	{
		printf("%c",ch+offset);		// print letter

		offset++;					// next letter

        if(ch+offset>'z')			// if we reach letter z
		{
			offset=0;				// to begin again
			ch = 'a';				// from 'a'
		}

		delay(SHORT_TIME);			// to make process visible
	}
}

// printing howMuch capital letters, cyclic from ch to 'Z'
// A (ascii 65), Z (ascii 90)
void capitalLetters(char ch, int howMuch)
{
	int offset=0, counter=0;

	for (counter=0; counter<howMuch; counter++)		// repeat howMuch times
	{
		printf("%c",ch+offset);		// print letter

		offset++;					// next letter

        if(ch+offset>'Z')			// if we reach last letter 'Z'
		{
			offset = 0;				// to begin again
			ch = 'A';				// from 'A'
		}

		delay(SHORT_TIME);			// to make process visible
	}
}

int main(void)
{
	int i, j, row_length = 52, number_of_times = 2;

	printf("\n \t \t Magic of C function printf() \n\n");

	// print ruler
	printf("\n123456789012345678901234567890123456789012345678901234567890\n");

	printf("\n\n");

	characters('*',row_length);			// row_length times printing character '*'

	printf("\n\n");

	digits(1,row_length);				// printing row_length characters, cyclic from 1 to 9

	printf("\n\n");

	smallLetters('a',row_length);		// printing row_length characters, cyclic from 'a'

	printf("\n\n");

	capitalLetters('A',row_length);		// printing row_length characters, cyclic from 'A'

	printf("\n\n\n");

	for (j=0; j<number_of_times; j++)	// do this number_of_times times
	{
		characters('*', row_length);	// printing character '*' row_length times
		delay(LONG_TIME);				// to make process visible
		backspace(row_length);			// delete characters backward

		digits(1, row_length);			// printing row_length characters, cyclic from 1 to 9, row_length times
		delay(20*SHORT_TIME);			// to make process visible
		backspace(row_length);			// delete characters backward

		smallLetters('a', row_length);	// printing row_length characters, cyclic from 'a' to 'z', row_length times
		delay(20*SHORT_TIME);			// to make process visible
		backspace(row_length);			// delete characters backward

		capitalLetters('A', row_length);// printing row_length characters, cyclic from 'A' to 'Z', row_length times
		delay(20*SHORT_TIME);			// to make process visible
		backspace(row_length);			// delete characters backward
	}

	printf("\t \t That's all Folks ! \n\n");

	return 0;
}
