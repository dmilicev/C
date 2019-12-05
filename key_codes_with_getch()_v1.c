/*

	key_codes_with_getch()_v1.c

Can be used to get Ascii codes for keyboard keys.

Tested on Windows 7.

Keys can be:
function key  with leading 224
function key  with leading   0
ordinary key  nothing leading

https://stackoverflow.com/questions/10463201/getch-and-arrow-codes

getch() function returns two keycodes for arrow keys (and some other special keys).
It returns either 0 (0x00) or 224 (0xE0) first,
and then returns a code identifying the key that was pressed.

For the arrow keys, it returns 224 first
followed by 72 (up), 80 (down), 75 (left) and 77 (right).

If the num-pad arrow keys (with NumLock off) are pressed,
getch () returns 0 first instead of 224.

Please note that getch () is not standardized in any way,
and these codes might vary from compiler to compiler.
These codes are returned by MinGW and Visual C++ on Windows.

For MinGW and Visual C++ :
These compilers use the name _getch() instead of getch()
to indicate that it is a non-standard function.


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/


#include <stdio.h>
#include <conio.h>


int main()
{
    int ch;

    printf("\n Press a key to get it's code \t first \t int \t char \n");

    while ( (ch = _getch()) != 27 ) 								// Escape key, ESC, Ascii 27
    {
        if ( ch == 0 )												// special key with first code 0
		{
			printf("\n special key with first code \t   %d ", ch );
			ch = _getch();											// let's empty that 0
			printf("\t %3d \t  %c \n", ch, ch );
		}
        else if (ch == 224)											// special key with first code 224
		{
			printf("\n special key with first code \t %d ", ch );
			ch = _getch();											// let's empty that 224
			printf("\t %3d \t  %c \n", ch, ch );
		}
		else														// ordinary key
		{
			printf("\n ordinary key \t\t\t\t %3d \t  %c \n",  ch, ch );
		}
    }

	printf("\n ordinary key \t\t\t\t %3d \t %c \n",  ch, ch );		// to print ESC key for exit


    return (0);
}
