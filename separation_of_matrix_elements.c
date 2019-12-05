/*

	separation_of_matrix_elements.c		by Dragan Milicev

	Printing various elements of a matrix relative to diagonals using functions.


An input square matrix M[i][j] of integers of dimension 5 x 5 is given.
Separate various elements of matrix to an array.

Given matrix 5 x 5 is :

   1   2   3   4   5

   6   7   8   9  10

  11  12  13  14  15

  16  17  18  19  20

  21  22  23  24  25


Output array for main diagonal is:		1  7  13  19  25

i is index of rows.
j is index of columns.


elements of the main diagonal have the property: i = j


elements above the main diagonal have the property: i < j


elements of the first diagonal above the main diagonal have the property: j-i = 1

elements of the second diagonal above the main diagonal have the property: j-i = 2

elements of the third diagonal above the main diagonal have the property: j-i = 3

the elements of the fourth diagonal above the main diagonal have the property: j-i = 4


elements below the main diagonal have the property: i > j


elements of the first diagonal below the main diagonal have the property: i-j = 1

elements of the second diagonal below the main diagonal have the property: i-j = 2

elements of the third diagonal below the main diagonal have the property: i-j = 3

elements of the fourth diagonal below the main diagonal have the property: i-j = 4




elements of the side diagonal have the property: i+j = n-1


elements above the side diagonal have the property: i+j < n-1


elements of the first diagonal above the side diagonal have the property: i+j = 3

elements of the second diagonal above the side diagonal have the property: i+j = 2

elements of the third diagonal above the side diagonal have the property: i+j = 1

elements of the fourth diagonal above the side diagonal have the property: i+j = 0


elements below the side diagonal have the property: i+j >= n


elements of the first diagonal below the side diagonal have the property: i+j = 5

elements of the second diagonal below the side diagonal have the property: i+j = 6

elements of the third diagonal below the side diagonal have the property: i+j = 7

elements of the fourth diagonal below the side diagonal have the property: i+j = 8



You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

	https://www.facebook.com/dmilicev

*/

#include <stdio.h>

// These are global variables, which means they are seen by all functions

int M[5][5]={ 1,  2,  3,  4,  5,
              6,  7,  8,  9, 10,
             11, 12, 13, 14, 15,
             16, 17, 18, 19, 20,
             21, 22, 23, 24, 25  };

int i, j, n=5, arr[25], num;


void PrintMatrix(void)
{

    printf("\n********************************\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%4d",M[i][j]);

        printf("\n\n");
    }
}


void PrintArray(void)
{
    for(i=0;i<num;i++)
            printf("%3d",arr[i]);

    printf("\n");
}


// elements of the main diagonal have the property: i = j
void MainDiagonaleElements(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i == j )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the main diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the side diagonal have the property: i+j = n-1
void SideDiagonaleElements(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == n-1 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Side diagonal elements, there are num = %d \n\n", num);
    PrintArray();
}


// elements above the main diagonal have the property: i < j
void ElementsAboveMainDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i < j )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements above the main diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the first diagonal above the main diagonal have the property: j-i = 1
void ElementsFirstDiagonalAboveMain(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( j - i == 1 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the first diagonal above the main, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the second diagonal above the main have the property: j-i = 2
void ElementsSecondDiagonalAboveMain(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( j - i == 2 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the second diagonal above the main, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the third diagonal above the main have the property: j-i = 3
void ElementsThirdDiagonalAboveMain(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( j - i == 3 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the third diagonal above the main, there are num = %d \n\n", num);
    PrintArray();
}


// the elements of the fourth diagonal above the main diagonal have the property: j-i = 4
void ElementsFourthDiagonalAboveMain(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( j - i == 4 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the fourth diagonal above the main, there are num = %d \n\n", num);
    PrintArray();
}


// elements below the main diagonal have the property: i > j
void ElementsBelowMainDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i > j )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements below the main diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the first diagonal below the main diagonal have the property: i-j = 1
void ElementsFirstDiagonalBelowMain(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i - j == 1 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the first diagonal below the main, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the second diagonal below the main diagonal have the property: i-j = 2
void ElementsSecondDiagonalBelowMain(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i - j == 2 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the second diagonal below the main, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the third diagonal below the main diagonal have the property: i-j = 3
void ElementsThirdDiagonalBelowMain(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i - j == 3 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the third diagonal below the main, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the fourth diagonal below the main diagonal have the property: i-j = 4
void ElementsFourthDiagonalBelowMain(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i - j == 4 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the fourth diagonal below the main, there are num = %d \n\n", num);
    PrintArray();
}


// elements below the side diagonal have the property: i+j >= n
void ElementsBelowSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j >= n )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements below the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements above the side diagonal have the property: i+j < n-1
void ElementsAboveSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j < n-1 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements above the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the first diagonal above the side diagonal have the property: i+j = 3
void ElementsFirstDiagonaleAboveSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == 3 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the first diagonal above the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the second diagonal above the side diagonal have the property: i+j = 2
void ElementsSecondDiagonaleAboveSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == 2 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the second diagonal above the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the third diagonal above the side diagonal have the property: i+j = 1
void ElementsThirdDiagonaleAboveSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == 1 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the third diagonal above the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the fourth diagonal above the side diagonal have the property: i+j = 0
void ElementsFourthDiagonaleAboveSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == 0 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the fourth diagonal above the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the first diagonal below the side diagonal have the property: i+j = 5
void ElementsFirstDiagonaleBelowSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == 5 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the first diagonal below the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the second diagonal below the side diagonal have the property: i+j = 6
void ElementsSecondDiagonaleBelowSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == 6 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the second diagonal below the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the third diagonal below the side diagonal have the property: i+j = 7
void ElementsThirdDiagonaleBelowSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == 7 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the third diagonal below the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}


// elements of the fourth diagonal below the side diagonal have the property: i+j = 8
void ElementsFourthDiagonaleBelowSideDiagonal(void)
{
    num = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if ( i+j == 8 )
            {
                arr[num] = M[i][j];
                num++;
            }
        }
    }

    printf("\n Elements of the fourth diagonal below the side diagonal, there are num = %d \n\n", num);
    PrintArray();
}




int main(void)
{

    PrintMatrix();

    MainDiagonaleElements();

    ElementsAboveMainDiagonal();


    ElementsFirstDiagonalAboveMain();

    ElementsSecondDiagonalAboveMain();

    ElementsThirdDiagonalAboveMain();

    ElementsFourthDiagonalAboveMain();


    ElementsBelowMainDiagonal();


    ElementsFirstDiagonalBelowMain();

    ElementsSecondDiagonalBelowMain();

    ElementsThirdDiagonalBelowMain();

    ElementsFourthDiagonalBelowMain();


    PrintMatrix();


    SideDiagonaleElements();


    ElementsAboveSideDiagonal();


    ElementsFirstDiagonaleAboveSideDiagonal();

    ElementsSecondDiagonaleAboveSideDiagonal();

    ElementsThirdDiagonaleAboveSideDiagonal();

    ElementsFourthDiagonaleAboveSideDiagonal();


    ElementsBelowSideDiagonal();


    ElementsFirstDiagonaleBelowSideDiagonal();

    ElementsSecondDiagonaleBelowSideDiagonal();

    ElementsThirdDiagonaleBelowSideDiagonal();

    ElementsFourthDiagonaleBelowSideDiagonal();


    PrintMatrix();


    printf("\n\n");
    //system("PAUSE");

    return 0;
}
