/*

	function_with_double_pointer.c

https://www.quora.com/How-can-I-pass-to-2-dimensional-int-array-to-M-function-that-receives-M-double-pointer-to-an-int-in-C-language


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>
#include <stdlib.h>


void print_matrix( char *text, int **M, int r, int c )
{
	int i, j;

	printf("%s", text );

    for ( i = 0; i < r; i ++ )
	{
        for ( j = 0; j < c; j ++ )
        {
            printf("%2d ", M[i][j] );
        }

        putchar('\n');
    }
}


void input_matrix( char *text, int **M, int r, int c )
{
	int i, j;

	printf("%s", text );

    for ( i = 0; i < r; i ++ )
	{
        for ( j = 0; j < c; j ++ )
        {
            printf("\n Enter M[%d][%d] = ", i, j );
        	scanf("%d", &M[i][j] );
            //printf("\n M[%d][%d] = %2d \n", i, j, M[i][j] );
        }

        putchar('\n');
    }
}


int main(void)
{
	int i, j, r=2, c=2;	// r is number of rows, c is number of columns in matrix M[r][c]

    int **M = malloc( r * sizeof(*M) );		// Create an array of pointers for r rows
    if ( M == NULL )
	{
		fprintf(stderr, "\n\n malloc() error! \n\n");
		exit(EXIT_FAILURE);

	}

    for ( i = 0; i < r; i ++ )
	{
        M[i] = malloc( c * sizeof *(M[i]) );// Create M[i] row
        if ( M[i] == NULL )
		{
			fprintf(stderr, "\n\n malloc() error! \n\n");
			exit(EXIT_FAILURE);
		}

		for ( j = 0; j < c; j ++ )			// Initialize the elements of the row
		{
            M[i][j] = r * i + j;
        }
    }


    input_matrix("\n Enter matrix M[r][c] \n", M, r, c );

    print_matrix("\n Matrix M[r][c] is: \n\n", M, r, c );


    for ( i = 0; i < r; i ++ )				// Now clean up
	{
        free( M[i] );						// Deallocate M[i] row
    }

    free(M);								// Deallocate the array of pointers for r rows

	return 0;
}
