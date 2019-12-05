/*

	spiral_square_matrix_v1.c		by Dragan Milicev


	A spiral square matrix of order n x n

	starting from the upper left (UL) element M[0][0]

	fills in clockwise with numbers from 1 to n*n.


 Enter the number (2 <= n <= 19) of the rows (columns)
 of the square matrix M[][], n = 4

 The matrix M rank is n = 4

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
#include <stdlib.h>

#define MAX_SIZE 19			// the highest rank of the matrix M[][]


// Displays a matrix M[][] that has r rows and c columns
void print_matrix( char *text, int M[][MAX_SIZE], int r, int c )
{
    int i, j;

    printf("\n%s\n\n", text );

    for(i=0;i<r;i++) {		// print matrix M[][]
        for(j=0;j<c;j++)
            printf("%4d", M[i][j] );

        printf("\n\n");   	// new matrix row
    }
    printf("\n\n");
}


// It sets all elements of the matrix M[][] having r rows and c columns to the int number
void set_matrix_elements_to_number( int M[][MAX_SIZE], int r, int c, int number ) {
    int i, j;

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            M[i][j] = number;
}


// This problem is simplified by filling in a ring-by-ring matrix.
// We start from the outer edges and fill all four directions separately
// in the order: right, down, left, up.
// Then we fill in the next ring ...
int main(void)
{
    int M[MAX_SIZE][MAX_SIZE], n;
    int number, r, c, r_min, c_min, r_max, c_max;

    printf("\n Enter the number (2 <= n <= %d) of the rows (columns) \n of the square matrix M[][], n = ", MAX_SIZE);
    scanf("%d", &n);
    printf("\n\n");

    if ( n < 2 || n > MAX_SIZE ) {
        printf("\n Due to the view, it does not make sense for the matrix row \n to be less than 2 or greater than %d !\n", MAX_SIZE);
        exit(1);
    }

    printf("\n The matrix M rank is n = %d \n\n",n);

	// Set all elements of the matrix M[][] to zero to move around the matrix
    // by checking the condition: while( M[r][c] == 0 )
    set_matrix_elements_to_number(M,n,n,0);

    //print_matrix(" The matrix M[][] with zeros is: ", M, n, n);

    // initial values
    number = 1;		// the first number to be written in the matrix M[][]
    r = 0;          // current row
    c = 0;          // current column
    r_min = 0;      // minimum row      	// current ring boundaries
    c_min = 0;      // minimum column		// current ring boundaries
    r_max = n-1;    // maximum row
    c_max = n-1;    // maximum column

    while ( number < n*n ){   // number goes from 1 to n*n

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

    // If n is odd, the above algorithm leaves an unfilled last number
    // in the center of the matrix M[n/2][n/2] so let's fill it now:
    if ( n % 2 )   // if n is odd
        M[n/2][n/2] = n*n;

    print_matrix(" Spiral matrix is: ", M, n, n);


	return 0;
}
