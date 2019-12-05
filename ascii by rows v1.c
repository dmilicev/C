/*
	ascii by rows v1.c

	Prints ASCII characters in rows.

	ASCSII is American Standard Code for Information Interchange

	http://www.asciitable.com/

	https://theasciicode.com.ar/

	https://en.wikipedia.org/wiki/Box-drawing_character

	http://ascii-table.com/ansi-escape-sequences.php


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>

int main(void)
{
	int row, column, character=32;

	printf("\n\t\t\t Ascii table by rows \n\n\n");

    for (row=1; row<=23; row++)
    {
        for (column=1; column<=10; column++)
        {
            if(character<=255)
				printf("%5d%2c", character, (char) character);

            character++;
        }
        printf("\n\n");
    }

	printf("\n");

	//system("PAUSE");
	getch();
	return 0;
}
