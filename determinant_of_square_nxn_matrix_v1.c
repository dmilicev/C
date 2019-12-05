/*

	determinant_of_square_nxn_matrix_v1.c

	n is rang of square matrix M[n][n].

	Calculate determinant of matrix M[n][n] by recursive function determinant().


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>
#include <stdlib.h>		// for exit()
#include <math.h>		// for pow()

#define MAX_SIZE 10


// Displays a square double matrix M[n][n] that has n rows and n columns
void display_square_double_matrix( char *text, double M[][MAX_SIZE], int n )
{
    int i, j;

    printf("\n%s\n\n",text);

    for(i=0;i<n;i++) {					// print matrix M[n][n]
        for(j=0;j<n;j++)
            printf("\t%.2lf", M[i][j]);

        printf("\n\n");   				// new row of matrix
    }
}


// Enter a square double matrix M[n][n] that has n rows and n columns
// https://stackoverflow.com/questions/35970159/accessing-a-2d-array-using-double-pointer-to-function-c-language
// https://www.quora.com/How-can-I-pass-to-2-dimensional-int-array-to-a-function-that-receives-a-double-pointer-to-an-int-in-C-language
void enter_square_double_matrix( char *text, double **M, int *n )
{
    int i, j;

    printf("\n%s\n\n",text);

    printf("\n Enter number of rows and columns of square matrix M[n][n], rang n = ");
    scanf("%d", n );

    for( i=0; i<*n; i++ ) 					// input matrix M[n][n]
	{
        for( j=0; j<*n; j++ )
		{
			printf("\n Enter M[%d][%d] = ", i, j );
			scanf("%lf", &M[i][j] );
			printf("\n M[%d][%d] = %lf \n", i, j, M[i][j] );
		}

        printf("\n");   					// new row of matrix
    }
}


// Recursive definition of determinate using expansion by minors.
// http://paulbourke.net/miscellaneous/determinant/determinant.c
double determinant( double M[][MAX_SIZE], int n )
{
	int i, j, j1, j2;
	double det = 0;
	double Sub[MAX_SIZE][MAX_SIZE];

	if ( n < 1 )				// Error
	{
		printf("\n Error: rang of matrix M[][] is less than 1 !!! \n");
		exit(1);
	}
	else if ( n == 1 )		// Shouldn't get used
	{
		det = M[0][0];
	}
	else if ( n == 2 )
	{
		det = M[0][0] * M[1][1] - M[1][0] * M[0][1];
	}
	else
	{
		det = 0;

		for ( j1=0; j1<n; j1++ )
		{
			for ( i=1; i<n; i++ )
			{
				j2 = 0;

				for ( j=0; j<n; j++ )
				{
					if ( j == j1 )
						continue;

					Sub[i-1][j2] = M[i][j];
					j2++;
				}
			}

			det += pow(-1.0,1.0+j1+1.0) * M[0][j1] * determinant( Sub, n-1 );
		}
	}
	return( det );
} // determinant()


int main()
{
    int i, j, n=3;				// n is rang of square matrix M[n][n]
	double det;
	double M[MAX_SIZE][MAX_SIZE];
	double *ptrM = (double *)M;
/*
	double M[MAX_SIZE][MAX_SIZE] = {
									{ 1.0, 2.0, 3.0 },
									{ 4.0, 5.0, 6.0 },
									{ 7.0, 8.0, 1.0 },
														};
*/

	enter_square_double_matrix("\n Enter matrix M[n][n] : ", &ptrM, &n );

	display_square_double_matrix("\n Square matrix M[n][n] is: ", M, n );

	det = determinant( M, n );

	printf("\n determinant = %.2lf \n", det );


    return 0;
}
