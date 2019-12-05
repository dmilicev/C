/*
	ascii table by columns v1.c

	Prints ASCII characters in columns.

	ASCSII is American Standard Code for Information Interchange

	http://www.asciitable.com/

	https://theasciicode.com.ar/

	http://ascii-table.com/ansi-escape-sequences.php


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>

// function to print ascii table by columns
void ascii_table_by_columns(void)
{
	int row, column, c=0, number_of_columns=8, number_of_rows, buffer;

    printf("\n\n\t\t   ASCII table by columns \n\n\n\n");

    // we calculate the number of rows based on the number of columns
    number_of_rows = (255 / number_of_columns) + 1;

    for(row = 0; row < number_of_rows; row++)  // we print rows one by one
    {
        c = row;

        for(column = 1; column <= number_of_columns; column++)  // we print columns
        {
             buffer = c;	// we remember c in the buffer

            // Instead of characters that cannot be displayed (ascii 7, 8, 10, 13),
            if(c == 7 || c == 8 || c == 10 || c == 13 )
			{
				c=32;									// we print a blank space
            }

             if(c <= 255)								// print character c till 255
             {
                  printf("%6d%2c", buffer, (char)c);
                  c = buffer;							// return c from buffer
                  c = c + number_of_rows;				// calculating c in next column
             }
        }

        printf("\n\n");
    }
}


int main(void)
{

	ascii_table_by_columns();


	printf("\n\n");

	//system("PAUSE");
	getch();

	return 0;
}
