/*

    keyboard_ascii_codes_with_kbhit()_v1.c

	While no key is pressed, it reports that no key is pressed.

	When a key is pressed, it displays its ASCII code.

	Also try function keys and key combinations
	with Shift, Control and Alt keys.


	Note that we use new functions _getch() and _kbhit()
	instead of old functions        getch() and   kbhit ().

	_kbhit()

	https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/kbhit?view=vs-2019

	_getch()

	https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/getch-getwch?view=vs-2019


	You can find all my C programs at Dragan Milicev's pastebin:

		https://pastebin.com/u/dmilicev

		https://www.facebook.com/dmilicev

*/


#include <stdio.h>
#include <conio.h>				// for kbhit()
#include <time.h>				// for clock()

#define WAIT_TIME 100


// wait (do nothing) for time in milliseconds ( 1000 for 1 second )
void wait(int milliseconds)
{
    clock_t start_time = clock();	// get start time

    // looping (do nothing) till required time is not acheived, ; means do nothing
    while ( clock() < start_time + milliseconds );
}


int main(void)
{
    int i = 0, ch;				// ch is pressed key that we will analyze
    int end = 0;				// = 0 because it's not the end of the program yet

    while(!end)
	{
		while( !_kbhit() )		// rotates in that loop until some key is pressed
		{
            if( i<100 )			// we only show i that something would happen
                i++;			// on the screen while no key was pressed
            else
                i=0;

            printf("\n No key was pressed. i = %d \n", i );

			wait(WAIT_TIME);
        }

        ch = _getch();				// Now a key is pressed and we read it.

        switch( ch ) {				// We analyze which key is pressed:

            case 27 :      			// ESC for end of program
                    printf("\n Pressed is ESCAPE key to end program \t\t %d \t %c \n", ch, ch);
                    end = 1;		// to end program
                    break;

            case  0 :       		// if a function key with a leading 0 is pressed
                    ch = _getch();	// let's empty that 0 and show which key is pressed
                    printf("\n Pressed is function key with a leading   0 \t %d \t %c \n", ch, ch);
					break;

            case 224 :      		// if a function key with a leading 224 is pressed
                    ch = _getch();	// let's empty that 224 and show which key is pressed
                    printf("\n Pressed is function key with a leading   224 \t %d \t %c \n", ch, ch);
                                break;
            default :				// show all other pressed keys
                    printf("\n Pressed is key \t\t %d \t %c \n", ch, ch);
                    break;
		} // switch( ch )

		wait(20*WAIT_TIME);			// pause for better view

	} // while(!end)

    return 0;
}
