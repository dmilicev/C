/*
	multiplication of matrices v1.c

	https://en.wikipedia.org/wiki/Matrix_(mathematics)#Matrix_multiplication

*/

#include <stdio.h>

// display mask of matrix elements
void MatrixMask(char text[], int rows, int columns)
{
    int r,c;

    printf("\n\n Matrix %s [%d x %d] is: \n\n", text, rows, columns);

	for(r = 1; r <= rows; r++)   		// for all rows, one by one
	{
		for(c = 1; c <= columns; c++)  	// print row
		{
			printf("  %s[%d%d]  ", text, r, c);
		}

		printf("\n\n");					// new row
	}
}

// display matrix elements
void displayMatrix(char text[], float Matrix[][10], int rows, int columns)
{
	int i, j;

	printf("%s",text);

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			printf(" %10.2f ", Matrix[i][j]);
		}

		printf("\n\n");					// new row
	}
}

// input matrix elements
void enterMatrix(char text[], float Matrix[][10], int rows, int columns)
{
	int i, j;

	printf("%s",text);

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			printf("\n Enter element [%d%d] : ", i+1, j+1);
			scanf("%f", &Matrix[i][j]);
		}
	}
}

// multiplay two matrices, Matrix1[rows1,colums1] and Matrix2[rows2,columns2]
// result is stored in resultMatrix[rows1,columns2]
void multiplyMatrices(float Matrix1[][10], float Matrix2[][10], float resultMatrix[][10],
					  int rows1, int columns1, int rows2, int columns2)
{
	int i, j, k;

	// Initializing elements of matrix resultMatrix to 0.
	for(i = 0; i < rows1; i++)
	{
		for(j = 0; j < columns2; j++)
		{
			resultMatrix[i][j] = 0;
		}
	}

	// Multiplying matrix Matrix1 and Matrix2 and storing in array resultMatrix
	for(i = 0; i < rows1; i++)
	{
		for(j = 0; j < columns2; j++)
		{
			for(k=0; k<columns1; k++)
			{
				resultMatrix[i][j] += Matrix1[i][k] * Matrix2[k][j];
			}
		}
	}
}


int main(void)
{
	float Matrix1[10][10], Matrix2[10][10], resultMatrix[10][10];
	int rows1, columns1, rows2, columns2;

	// Input numbers of rows and colums of matrices
	// If columns of first matrix is not equal to rows of second matrix,
	// asking user to enter the size of matrices again
	do
	{
		printf("\n \t Matrix multiplication \n");
		printf("\n Columns of first matrix must be equal to rows of second matrix !\n");
		printf("\n columns1 must be equal to rows2 ! \n\n");

		printf("\n Enter number of rows for first matrix:        rows1 = ");
		scanf("%d", &rows1);

		printf("\n Enter number of columns for first matrix:  columns1 = ");
		scanf("%d", &columns1);


		printf("\n Enter number of rows for second matrix:       rows2 = ");
		scanf("%d", &rows2);

		printf("\n Enter number of columns for second matrix: columns2 = ");
		scanf("%d", &columns2);

	} while (columns1 != rows2);

	// enter matrices data
	MatrixMask("Matrix1", rows1, columns1);
    enterMatrix("\n Enter elements of Matrix1 \n", Matrix1, rows1, columns1);

	MatrixMask("Matrix2", rows2, columns2);
    enterMatrix("\n Enter elements of Matrix2 \n", Matrix2, rows2, columns2);

    // multiply two matrices
    multiplyMatrices(Matrix1, Matrix2, resultMatrix, rows1, columns1, rows2, columns2);

    // display matrices
    displayMatrix("\n Matrix1 is: \n\n", Matrix1, rows1, columns1);
    displayMatrix("\n Matrix2 is: \n\n", Matrix2, rows2, columns2);
    displayMatrix("\n resultMatrix is: \n\n", resultMatrix, rows1, columns2);

	return 0;
}
