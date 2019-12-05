/*

	hollow rectangle pattern v2.c

	Demonstrates print speed on screen.

    https://www.geeksforgeeks.org/puts-vs-printf-for-printing-a-string/

	Note: puts() and putchar() are 10 times faster then printf()

	Also note that puts() moves the cursor to next line.
	If you do not want the cursor to be moved to next line,
	then you can use following variation of puts().

	fputs(str, stdout);

	In #include <windows.h> are defined cursor position functions
	for tracking cursor all the time:
	gotoxy(x,y) , wherex() , wherey()

 	The beginning of the coordinate system is in the upper left UL corner
	of the window and there is a point (x, y) = (0.0).
	x is column, y is row.

	Characteristic points of console window and rectangle are:
	TL top left 	(x, y) = ( 0, 0)
	TR top right 	(x, y) = (79, 0) = ( MAX_COLUMNS,           0 )
	BL bottom left 	(x, y) = (0, 25) = ( 0          ,    MAX_ROWS )
	BR bottom right	(x, y) = (79,25) = ( MAX_COLUMNS,    MAX_ROWS )

	Rectangle is defined with 4 arguments,
	by TL point (xTL,yTL) , width and height
	(xTL , yTL, xTL + width , yTL + height)

*/

#include <stdio.h>
#include <conio.h>					// for getch()
#include <string.h>                 // for puts()
#include <time.h>					// for clock()
#include <windows.h>
// tracking cursor all the time, for cursor position functions
// gotoxy(x,y) , wherex() , wherey()

#define SECOND 1000			        // time for delay() in milliseconds
#define MAX_COLUMNS	79				// in command window
#define MAX_ROWS	25				// in command window
#define T 	0			// for delay(T); , wait, for better view, T = 1000 for 1 second


/*
// wait (do nothing) for time in milliseconds
void delay(int milliseconds)
{
    clock_t start_time = clock();	// get start time

    // looping (do nothing) till required time is not acheived
    while ( clock() < start_time + milliseconds )
		;							// do nothing
}
*/

// place cursor at position (x, y) = ( column, row)
void gotoxy( int column, int row )
{
	COORD coord;

	coord.X = column;
	coord.Y = row;

	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), coord );
}

// return x coordinate (column) of current cursor position
// on failure return -1
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (!GetConsoleScreenBufferInfo( GetStdHandle(STD_OUTPUT_HANDLE), &csbi ) )
		return -1;

	return csbi.dwCursorPosition.X;
}

// return y coordinate (row) of current cursor position
// on failure return -1
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (!GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi ) )
		return -1;

	return csbi.dwCursorPosition.Y;
}

// Function to print hollow rectangle with char ch, with puts(), 10 times faster
// from current cursor position
// rows     must be between 2 and MAX_ROWS-2 because of 2 horizontal edges
// columns  must be between 2 and MAX_COLUMNS-2 because of 2 vertical edges
void print_hollow_rectangle_puts(char ch, int howMuchColumns, int howMuchRows)
{
    int i;
    char str1[MAX_COLUMNS+1];		// str1 is string for first and last line of rectangle
    char str2[MAX_COLUMNS+1];		// str2 is string for middle lines of rectangle

    if( howMuchRows < 2 )					// 2 for two horizontal edges of the rectangle
        howMuchRows = 2;

    if( howMuchColumns < 2 )				// 2 for two vertical edges of the rectangle
        howMuchColumns = 2;

    if( howMuchRows > MAX_ROWS - 2 )		// 2 for two horizontal edges of the rectangle
        howMuchRows = MAX_ROWS - 2;

    if( howMuchColumns > MAX_COLUMNS - 2 )	// 2 for two vertical edges of the rectangle
        howMuchColumns = MAX_COLUMNS -2;
								// creating string for first and last line of rectangle
    str1[0] = ch;					// TL (top-left) character
    for (i = 1; i < howMuchColumns-1; i++)	// middle characters of top line
        str1[i] = ch;
    str1[i] = ch;					// TR (top-righth) character
    str1[i+1] = '\0';				// end of first and last line string
								// creating string for middle lines of rectangle
    str2[0] = ch;					// first left character of middle lines
    for (i = 1; i < howMuchColumns-1; i++) // middle characters of middle lines are blanko (space, ' ')
        str2[i] = ' ';
	str2[i] = ch;					// last right character of middle lines
    str2[i+1] = '\0';				// end of middle lines string
								// print rectangle
    puts(str1);						// print string for first line of rectangle

    for (i = 0; i < howMuchRows-2; i++)	// print string for middle lines of rectangle
        puts(str2);

    puts(str1);						// print string for last line of rectangle
}

// Function to print hollow rectangle with char ch, with puts, 10 times faster
// from cursor position row, column
// rows     must be between 2 and MAX_ROWS-2
// columns  must be between 2 and MAX_COLUMNS-2
void print_hollow_rectangle_puts_column_row(char ch, int column, int row, int howMuchColumns, int howMuchRows)
{
    int i;
    char str1[MAX_COLUMNS+1];		// str1 is string for first and last line of rectangle
    char str2[MAX_COLUMNS+1];		// str2 is string for middle lines of rectangle

    if( column + howMuchColumns < 2 )		// 2 for two vertical edges of the rectangle
        howMuchColumns = 2;

    if( row + howMuchRows < 2 )				// 2 for two horizontal edges of the rectangle
        howMuchRows = 2;

    if( column + howMuchColumns > MAX_COLUMNS )	// if right side od rectangle greather then
        howMuchColumns = MAX_COLUMNS - column;	// MAX_COLUMNS, then trunc it

    if( row + howMuchRows > MAX_ROWS - 2 )		// if bottom side od rectangle greather then
        howMuchRows = MAX_ROWS - row;			// MAX_ROWS, then trunc it

								// creating string for first and last line of rectangle
    str1[0] = ch;					// TL (top-left) character
    for (i = 1; i < howMuchColumns-1; i++)	// middle characters of top line
        str1[i] = ch;
    str1[i] = ch;					// TR (top-righth) character
    str1[i+1] = '\0';				// end of first and last line string

								// creating string for middle lines of rectangle
    str2[0] = ch;					// first left character of middle lines
    for (i = 1; i < howMuchColumns-1; i++) // middle characters of middle lines are blanko (space, ' ')
        str2[i] = ' ';
	str2[i] = ch;					// last right character of middle lines
    str2[i+1] = '\0';				// end of middle lines string

								// print rectangle
    gotoxy( column, row );			// move cursor to (column, row)
    fputs(str1, stdout);			// print string for first line of rectangle without '\n'

    for (i = 0; i < howMuchRows-2; i++)
    {
		gotoxy( column, row+i+1 );	// move cursor to (column, row+i+1)
        fputs(str2, stdout);		// print string for middle lines of rectangle without '\n'
    }

	gotoxy( column, row+i+1 );		// move cursor to (column, row+i+1)
    fputs(str1, stdout);			// print string for last line of rectangle without '\n'
}


int main()
{
/*
	i								is iterator
	xTL, yTL 						are coordinates of top-left (TL) corner of the rectangle
	width							is width of rectangle from TL corner
	height							is height of rectangle from TL corner
	plusMinus						is flag for sign
	number_of_printed_rectangles	is counter
	when_to_change_sign 			is counter
	ch								is character for rectangle border

*/
	int i, xTL=0, yTL=0, width=MAX_COLUMNS, height=MAX_ROWS;
	int plusMinus=1, number_of_printed_rectangles=0, when_to_change_sign=0;
	char ch='A';

/*
    // print ruler
    puts("          1         2         3         4         5         6         7        ");
    puts("0123456789012345678901234567890123456789012345678901234567890123456789012345678");
*/

	for (i = 0; i < 100; i++)					// repeat loop more times
    {
			system("CLS");						// clear the screen

			print_hollow_rectangle_puts_column_row(ch++, xTL, yTL, width, height);

			number_of_printed_rectangles++;		// count printed rectangles

			xTL    = xTL    + plusMinus *  5;	// calculate new arguments for next rectangle
			yTL    = yTL    + plusMinus *  2;
			width  = width  - plusMinus * 10;
			height = height - plusMinus *  4;

			when_to_change_sign++;				// increase counter when_to_change_sign

			if( when_to_change_sign == 5 )		// then we change sign plus or minus
			{
				plusMinus = -plusMinus;			// sign + for implosion, - for explosion
				when_to_change_sign = 0;		// reset counter when_to_change_sign
			}

			if(ch=='Z')		// if ch reach 'Z' then start again from 'A'
				ch='A';
							// #define T 	0	(default value)
			//delay(T);		// you can change T at the beginning: #define T new_value
    }

	_getch();	// with getch() was error: "Drawing operation was attempted when there was no current window"
	gotoxy(0, MAX_ROWS);	// move cursor to first column of penultimate row
	printf("\n There are %d printed triangles.\n", number_of_printed_rectangles);
    return 0;
}
