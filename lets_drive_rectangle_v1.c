/*

	lets_drive_rectangle_v1.c

It drives a rectangle in eight directions.

Author Dragan Milicev
https://web.facebook.com/dmilicev

Tested on Windows 7.
Let me know of any errors (bugs) in the code you encountered, please.

To see Ascii codes for keyboard keys try
 key_codes_with_getch()_v1.c
https://pastebin.com/CTb71BSc

To see demonstrations of print speed in console window try
 hollow rectangle pattern v2.c
https://pastebin.com/c0jWaxas

You can find all my C programs at Dragan Milicev's pastebin:
    https://pastebin.com/u/dmilicev


The solid rectangle can be driven in 8 directions:

UP          up arrow
DOWN        down arrow
LEFT        left arrow
RIGHT       right arrow

UP_LEFT     Home        or  Q, q
DOWN_LEFT   End         or  A, a
UP_RIGHT    Page Up     or  W, w
DOWN_RIGHT  Page Down   or  S, s

Key Escape ESC for quit.


Example of keyboard control.
Also numeric keypad can be used.

Example of work with pointers.

Example of passing a variable to the function by reference,
so the function can change the value of that variable because
it has address (pointer) of variable in memory.

 	The beginning of the coordinate system is in the upper left UL corner
	of the window and there is a point ( x, y ) = ( column, row ) = ( 0, 0 )
	x is column, y is row.
	Columns increase to the right and rows increase downwards,
	starting with TL top left point of the console window (0, 0).

	Characteristic points of console window and rectangle are:
	TL top left 	(x, y) = ( 0, 0) = ( 0          ,           0 )
	TR top right 	(x, y) = (80, 0) = ( MAX_COLUMNS,           0 )
	BL bottom left 	(x, y) = (0, 25) = ( 0          ,    MAX_ROWS )
	BR bottom right	(x, y) = (80,25) = ( MAX_COLUMNS,    MAX_ROWS )

	If MAX_COLUMNS 80 and MAX_ROWS 25 exceed the your console window box,
	try reducing them a little by changing the lines of code

	#define MAX_COLUMNS	80
    #define MAX_ROWS	25

	Rectangle is defined with 4 arguments,
	by top left TL point ( xTL, yTL ) and width and height (from TL point)

	rectangle ( xTL , yTL, width , height )

	width  is from xTL to the right
	height is from yTL to the down

*/



// ----------BEGIN OF PROGRAM--------------------------------------------------

#include <stdio.h>
#include <conio.h>          // for _getch() and _getche()
#include <string.h>         // for puts()
#include <time.h>			// for clock()
#include <windows.h>
// tracking cursor all the time, for cursor position functions
// gotoxy(x,y) , wherex() , wherey(), showcursor(), hidecursor()

#define SECOND 1000			// time for delay() in milliseconds
#define MAX_COLUMNS	80		// of the console window
#define MAX_ROWS	25		// of the console window
#define T 	        0		// for delay(T), waiting for better view, T=1000 for 1 second

#define UP          72      // up arrow
#define DOWN        80      // down arrow
#define LEFT        75      // left arrow
#define RIGHT       77      // right arrow

#define UP_LEFT     71      // Home
#define UP_RIGHT    73      // Page Up
#define DOWN_LEFT   79      // End
#define DOWN_RIGHT  81      // Page Down
#define ESC         27



// ----------CURSOR CONTROL FUNCTIONS------------------------------------------

// make console cursor invisible
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 20;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

// make console cursor invisible
void showcursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 20;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

// place cursor at position ( x, y ) = ( column, row )
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

// END OF-----CURSOR CONTROL FUNCTIONS------------------------------------------


// ----------FUNCTIONS TO PRINT HOLLOW AND SOLID RECTANGLE----------------------

// Function to print hollow rectangle with char ch, with puts(), 10 times faster than printf()
// from cursor position row, column
// rows     must be between 2 and MAX_ROWS-2    (the smallest rectangle has no interior space, only the sides of the frame)
// columns  must be between 2 and MAX_COLUMNS-2 (the smallest rectangle has no interior space, only the sides of the frame)
void print_hollow_rectangle(char ch, int column, int row, int howMuchColumns, int howMuchRows)
{
    int i;
    char str1[MAX_COLUMNS+1];		            // str1 is string for first and last line of rectangle
    char str2[MAX_COLUMNS+1];		            // str2 is string for middle lines of rectangle

    if( column + howMuchColumns < 1 )		    // 2 for two vertical edges of the rectangle
        howMuchColumns = 2;

    if( row + howMuchRows < 2 )				    // 2 for two horizontal edges of the rectangle
        howMuchRows = 2;

    if( column + howMuchColumns > MAX_COLUMNS )	// if right side od rectangle greather then
        howMuchColumns = MAX_COLUMNS - column;	// MAX_COLUMNS, then trunc it

    if( row + howMuchRows > MAX_ROWS - 1 )		// if bottom side od rectangle greather then
        howMuchRows = MAX_ROWS - row;			// MAX_ROWS, then trunc it


    for (i = 0; i < howMuchColumns; i++)        // creating string for first and last line of rectangle
        str1[i] = ch;

    str1[i+1] = '\0';				            // end of first and last line string

                                                // creating string for middle lines of rectangle
    str2[0] = ch;					            // first left character of middle lines string
    for (i = 1; i < howMuchColumns-1; i++)      // middle characters of middle lines are blanko (space, ' ')
        str2[i] = ' ';
	str2[i] = ch;					            // last right character of middle lines string
    str2[i+1] = '\0';				            // end of middle lines string

                                                // print rectangle
    gotoxy( column, row );			            // move cursor to (column, row)
    fputs(str1, stdout);			            // print string for first line of rectangle without '\n'

    for (i = 0; i < howMuchRows-2; i++)
    {
		gotoxy( column, row+i+1 );	            // move cursor to (column, row+i+1)
        fputs(str2, stdout);		            // print string for middle lines of rectangle without '\n'
    }

	gotoxy( column, row+i+1 );		            // move cursor to (column, row+i+1)
    fputs(str1, stdout);			            // print string for last line of rectangle without '\n'
}


// Function to print solid rectangle with char ch, with puts(), 10 times faster than printf()
// from cursor position column, row
// rows     must be between 2 and MAX_ROWS-2    (the smallest rectangle has no interior space, only the sides of the frame)
// columns  must be between 2 and MAX_COLUMNS-2 (the smallest rectangle has no interior space, only the sides of the frame)
void print_solid_rectangle(char ch, int column, int row, int howMuchColumns, int howMuchRows)
{
    int i;
    char str[MAX_COLUMNS+1];		            // str is string for one line of rectangle

    if( column + howMuchColumns < 1 )
        howMuchColumns = 2;                     // 2 for two vertical edges of the rectangle

    if( row + howMuchRows < 2 )
        howMuchRows = 2;                        // 2 for two horizontal edges of the rectangle

    if( column + howMuchColumns > MAX_COLUMNS )	// if right side od rectangle greather then
        howMuchColumns = MAX_COLUMNS - column;	// MAX_COLUMNS, then reduce it

    if( row + howMuchRows > MAX_ROWS - 1 )		// if bottom side od rectangle greather then
        howMuchRows = MAX_ROWS - row;			// MAX_ROWS, then reduce it

    for (i = 0; i < howMuchColumns; i++)	    // fill string str with characters of one rectangle line
        str[i] = ch;

    str[i] = '\0';				                // end string str

    for (i = 0; i < howMuchRows; i++)           // print solid rectangle
    {
		gotoxy( column, row+i );	            // move cursor to (column, row+i+1)
        fputs(str, stdout);		                // print solid rectangle string  without '\n'
    }
}

// END OF---FUNCTIONS TO PRINT HOLLOW AND SOLID RECTANGLE----------------------


// ----------FUNCTIONS TO MOVE SOLID RECTANGLE---------------------------------

// erase current solid rectangle on that place by overwritting it with char ' '
// print new     solid rectangle one row up
void move_solid_rectangle_up( char ch, int *column, int *row, int *howMuchColumns, int *howMuchRows )
{
    if( *row > 1 )  // if rectangle is below top line of console window frame
    {               // erase current solid rectangle on that place by overwritting it with char ' '
        print_solid_rectangle( ' ', *column, (*row)--, *howMuchColumns, *howMuchRows );
                    // print new solid rectangle one row up
        print_solid_rectangle(  ch, *column, *row, *howMuchColumns, *howMuchRows );
    }
}

// erase current solid rectangle on that place by overwritting it with char ' '
// print new     solid rectangle one row down
void move_solid_rectangle_down( char ch, int *column, int *row, int *howMuchColumns, int *howMuchRows )
{                   // if rectangle is above the penultimate bottom line of the console window frame
    if( *row < MAX_ROWS-(*howMuchRows)-1 )
    {               // erase current solid rectangle on that place by overwritting it with char ' '
        print_solid_rectangle( ' ', *column, (*row)++, *howMuchColumns, *howMuchRows );
                    // print new solid rectangle one row down
        print_solid_rectangle(  ch, *column, *row, *howMuchColumns, *howMuchRows );
    }
}

// erase current solid rectangle on that place by overwritting it with char ' '
// print new     solid rectangle one column left
void move_solid_rectangle_left( char ch, int *column, int *row, int *howMuchColumns, int *howMuchRows )
{
    if( *column > 1 )  // if rectangle is right from second column of console window frame
    {               // erase current solid rectangle on that place by overwritting it with char ' '
        print_solid_rectangle( ' ', (*column)--, *row, *howMuchColumns, *howMuchRows );
                    // print new solid rectangle one column left
        print_solid_rectangle(  ch, *column, *row, *howMuchColumns, *howMuchRows );
    }
}

// erase current solid rectangle on that place by overwritting it with char ' '
// print new     solid rectangle one column right
void move_solid_rectangle_right( char ch, int *column, int *row, int *howMuchColumns, int *howMuchRows )
{                   // if rectangle is left from the penultimate right line of the console window frame
    if( *column < MAX_COLUMNS-(*howMuchColumns)-1 )
    {               // erase current solid rectangle on that place by overwritting it with char ' '
        print_solid_rectangle( ' ', (*column)++, *row, *howMuchColumns, *howMuchRows );
                    // print new solid rectangle one column right
        print_solid_rectangle(  ch, *column, *row, *howMuchColumns, *howMuchRows );
    }
}



// erase current solid rectangle on that place by overwritting it with char ' '
// print new     solid rectangle one row up and one column left
void move_solid_rectangle_up_left( char ch, int *column, int *row, int *howMuchColumns, int *howMuchRows )
{                                   // if rectangle is below top line of console window frame
    if( *row > 1 && *column > 1)    // if rectangle is right from second column of console window frame
    {               // erase current solid rectangle on that place by overwritting it with char ' '
        print_solid_rectangle( ' ', (*column)--, (*row)--, *howMuchColumns, *howMuchRows );
                    // print new solid rectangle one row up and one column left
        print_solid_rectangle(  ch, *column, *row, *howMuchColumns, *howMuchRows );
    }
}

// erase current solid rectangle on that place by overwritting it with char ' '
// print new     solid rectangle one row down and one column left
void move_solid_rectangle_down_left( char ch, int *column, int *row, int *howMuchColumns, int *howMuchRows )
{                   // if rectangle is above the penultimate bottom line of the console window frame
                    // if rectangle is right from second column of console window frame
    if( *row < MAX_ROWS-(*howMuchRows)-1 && *column > 1 )
    {               // erase current solid rectangle on that place by overwritting it with char ' '
        print_solid_rectangle( ' ', (*column)--, (*row)++, *howMuchColumns, *howMuchRows );
                    // print new solid rectangle one row down and one column left
        print_solid_rectangle(  ch, *column, *row, *howMuchColumns, *howMuchRows );
    }
}

// erase current solid rectangle on that place by overwritting it with char ' '
// print new     solid rectangle one row down and one column right
void move_solid_rectangle_down_right( char ch, int *column, int *row, int *howMuchColumns, int *howMuchRows )
{                   // if rectangle is above the penultimate bottom line of the console window frame
                    // if rectangle is left from the penultimate right line of the console window frame
    if( *row < MAX_ROWS-(*howMuchRows)-1 && *column < MAX_COLUMNS-(*howMuchColumns)-1 )
    {               // erase current solid rectangle on that place by overwritting it with char ' '
        print_solid_rectangle( ' ', (*column)++, (*row)++, *howMuchColumns, *howMuchRows );
                    // print new solid rectangle one row down and one column right
        print_solid_rectangle(  ch, *column, *row, *howMuchColumns, *howMuchRows );
    }
}

// erase current solid rectangle on that place by overwritting it with char ' '
// print new     solid rectangle one row up and one column right
void move_solid_rectangle_up_right( char ch, int *column, int *row, int *howMuchColumns, int *howMuchRows )
{                   // if rectangle is below top line of console window frame
                    // if rectangle is left from the penultimate right line of the console window frame
    if( *row > 1 && *column < MAX_COLUMNS-(*howMuchColumns)-1)
    {               // erase current solid rectangle on that place by overwritting it with char ' '
        print_solid_rectangle( ' ', (*column)++, (*row)--, *howMuchColumns, *howMuchRows );
                    // print new solid rectangle one row up and one column right
        print_solid_rectangle(  ch, *column, *row, *howMuchColumns, *howMuchRows );
    }
}

// END OF----FUNCTIONS TO MOVE SOLID RECTANGLE---------------------------------


// ----------KEYBOARD CONTROL--------------------------------------------------

/*
    Keyboard control:

The solid rectangle can be driven in 8 directions:

UP          up arrow
DOWN        down arrow
LEFT        left arrow
RIGHT       right arrow

UP_LEFT     Home        or  Q, q
DOWN_LEFT   End         or  A, a
UP_RIGHT    Page Up     or  W, w
DOWN_RIGHT  Page Down   or  S, s

Key Escape, ESC (27) for quit.
*/
int keyboard_control()
{
    int column=35, row=10, howMuchColumns=6, howMuchRows=5;     // solid rectangle coordinates
    char ch = '*';                                              // char to print rectangle
    int choice;                                                 // for pressed key

    hidecursor();

    print_hollow_rectangle( ch, 0, 0, MAX_COLUMNS, MAX_ROWS ); // print console window frame

    print_solid_rectangle( ch, column, row, howMuchColumns, howMuchRows );

    while( 1 ) {                    // an infinite loop that exits with choice Ecsape, ESC (27)

        choice = _getch();                      // read the keyboard

        if( choice == 0 || choice == 224 )      // if is pressed function key with leading 0 or 224
        {
            choice = _getch();                  // let's empty that 0 or 224

            if( choice == UP )                  // if pressed up arrow
            {
                move_solid_rectangle_up( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == DOWN )                // if pressed down arrow
            {
                move_solid_rectangle_down( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == LEFT )                // if pressed left arrow
            {
                move_solid_rectangle_left( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == RIGHT )               // if pressed right arrow
            {
                move_solid_rectangle_right( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == UP_LEFT )             // if pressed Home
            {
                move_solid_rectangle_up_left( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }


            if( choice == DOWN_LEFT )           // if pressed End
            {
                move_solid_rectangle_down_left( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == UP_RIGHT )            // if pressed Page Up
            {
                move_solid_rectangle_up_right( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == DOWN_RIGHT )          // if pressed Page Down
            {
                move_solid_rectangle_down_right( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

        } // end of: if is pressed function key with leading 0 or 224
        else    // if pressed ordinary keys
        {
            if( choice == 'Q' || choice == 'q' )    // if is pressed ordinary key Q or q
            {
                move_solid_rectangle_up_left( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == 'A' || choice == 'a' )    // if is pressed ordinary key A or a
            {
                move_solid_rectangle_down_left( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == 'W' || choice == 'w' )    // if is pressed ordinary key W or w
            {
                move_solid_rectangle_up_right( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }

            if( choice == 'S' || choice == 's' )    // if is pressed ordinary key S or s
            {
                move_solid_rectangle_down_right( ch, &column, &row, &howMuchColumns, &howMuchRows );
            }


            if( choice == ESC )                     // if is pressed ESC
            {
                showcursor();                       // before exiting function
                return( choice );                   // end work
            }

        } // end of: if pressed ordinary keys

    } // end of: while( 1 )

    showcursor();                                   // before exiting function
    return( choice );                               // have to return something
}

// END OF----KEYBOARD CONTROL--------------------------------------------------


int main(void)
{

    keyboard_control();


    gotoxy( 0, MAX_ROWS );

    return 0;
}
