/*

	spiral_matrix_v1.c		by Dragan Milicev


	A spiral  rows x columns  matrix M[r][c]

	starting from the upper left (UL) element M[0][0]

	fills in clockwise with numbers from 1 to r*c.


OUTPUT:

 Enter the number (2 <= rows <= 99) of the rows
 of the matrix M[r][c], rows = 4

 Enter the number (2 <= columns <= 19) of the columns
 of the matrix M[r][c], columns = 4

 Spiral matrix is:

   1   2   3   4

  12  13  14   5

  11  16  15   6

  10   9   8   7


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

	https://www.facebook.com/dmilicev

*/


#include <stdio.h>
#include <stdlib.h>				// for function exit()

#define MAX_ROWS 	52			// maximum number of rows of the matrix M[r][c]
#define MAX_COLUMNS	19			// maximum number of columns of the matrix M[r][c]


// Displays a matrix M[rows][columns]
void print_matrix( char *text, int M[MAX_ROWS][MAX_COLUMNS], int rows, int columns )
{
    int i, j;

    printf("\n%s\n\n", text );

    for( i=0; i<rows; i++ ) {	// print matrix M[][]
        for( j=0; j<columns; j++ )
            printf("%4d", M[i][j] );

        printf("\n\n");   		// new matrix row
    }
    printf("\n");
}


// It sets all elements of the matrix M[rows][columns] to the int number
void set_matrix_elements_to_number( int M[MAX_ROWS][MAX_COLUMNS], int rows, int columns, int number ) {
    int i, j;

    for( i=0; i<rows; i++ )
        for( j=0; j<columns; j++ )
            M[i][j] = number;
}



// Make a spiral  rows x columns  matrix M[r][c]
// starting from the upper left (UL) element M[0][0]
// fills in clockwise with numbers from 1 to rows*columns.
// This problem is simplified by filling in a ring-by-ring matrix.
// We start from the outer edges and fill all four directions separately
// in the order: right, down, left, up.
// Then we fill in the next ring ...
void make_spriral_matrix( int M[MAX_ROWS][MAX_COLUMNS], int rows, int columns )
{
    int number, r, c, r_min, c_min, r_max, c_max;

	// Set all elements of the matrix M[][] to zero to move around the matrix
    // by checking the condition: while( M[r][c] == 0 )

    set_matrix_elements_to_number(M,rows,columns,0);

    // initial values

    number = 1;			// the first number to be written in the matrix M[r][c]
    r = 0;          	// current row
    c = 0;          	// current column
    r_min = 0;      	// minimum row      	// current ring boundaries
    c_min = 0;      	// minimum column		// current ring boundaries
    r_max = rows-1;    	// maximum row
    c_max = columns-1;	// maximum column

    while ( number < rows*columns ){			// number goes from 1 to rows*columns-1

        // to the right
        while( M[r][c] == 0  &&  c <= c_max )
            M[r][c++] = number++;

        // to the down
        r++;	// we increase the current row because we are going down
        c--;    // we are reducing the current column since we last enlarged it unnecessarily
        while( M[r][c] == 0  &&  r <= r_max )
            M[r++][c] = number++;

        // to the left
        r--;    // we are reducing the current row since we last enlarged it unnecessarily
        c--;    // we reduce the current column because we go to the left
        while( M[r][c] == 0  &&  c >= c_min )
            M[r][c--] = number++;

        // to the up
        r--;    // we reduce the current row because we go up
        c++;    // we are enlarging the current column since we last reduced it unnecessarily
        while( M[r][c] == 0  &&  r >= r_min )
            M[r--][c] = number++;

        r_min++;	// we have filled the outer frame of the matrix M and are now reducing it
        c_min++;
        r_max--;
        c_max--;

        r = r_min;	// new starting values for the next inner ring of matrix M
        c = c_min;
    }

	// If rows and columns are odd, the above algorithm leaves an unfilled last number
    // in the center of the matrix M[rows/2][columns/2] so let's fill it now:

    if ( rows%2 && columns%2 )   // if rows and columns are odd
        M[rows/2][columns/2] = rows*columns;
}


int main(void)
{
    int M[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;

    printf("\n Enter the number (2 <= rows <= %d) of the rows \n of the matrix M[r][c], rows  =  ", MAX_ROWS);
    scanf("%d", &rows);
    printf("\n");

    if ( rows < 2 || rows > MAX_ROWS ) {
        printf("\n Due to the view, it does not make sense for the matrix rows \n to be less than 2 or greater than %d !\n", MAX_ROWS);
        exit(1);
    }

    printf(" Enter the number (2 <= columns <= %d) of the columns \n of the matrix M[r][c], columns  =  ", MAX_COLUMNS);
    scanf("%d", &columns);
    printf("\n");

    if ( columns < 2 || columns > MAX_COLUMNS ) {
        printf("\n Due to the view, it does not make sense for the matrix columns \n to be less than 2 or greater than %d !\n", MAX_COLUMNS);
        exit(1);
    }

    make_spriral_matrix( M, rows, columns );

    print_matrix(" Spiral matrix is: ", M, rows, columns);


	return 0;
}
