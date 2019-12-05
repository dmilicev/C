/*

    lets_learn_c_matrices_with_integers_v1.c

Work in C with matrices with integers.

The idea is that this program should cover everything about matrices in C.

The point of the functions is to divide a big problem
into several smaller problems.
Each function should solve only one problem and nothing more.
Functions should therefore not have more than a couple dozen lines of code.
The features of the functions are arguments (parameters, input values)
and the value returned by the function to the part of the program
from which it was called.
If we pass to the function the pointers to the variables as arguments,
function then has the ability to change the value of the arguments
beyond its scope, and in that case it does not even have to have
its own return value.
Our conversations should soon come down to questions about how to write
a function that receives those arguments and has that return value.

Please understand that English is not my native language and
please feel free to correct me about it.

Feel free to let me know if you think I left out something,
or if you find some bugs in this program.

This program will be updated according to your suggestions.

Author Dragan Milicev
https://www.facebook.com/dmilicev
You can find all my C programs at Dragan Milicev's pastebin:
https://pastebin.com/u/dmilicev

-----------------------------------------------------------------------------

Let's understand what matrices are:

( Yes, it's math, but it's not scary )


https://en.wikipedia.org/wiki/Matrix_(mathematics)

http://www.maths.surrey.ac.uk/explore/emmaspages/option1.html

https://www.wikihow.com/Understand-the-Basics-of-Matrices

 Matrix calculator
https://matrixcalc.org/en/
https://www.symbolab.com/solver/matrix-calculator

 Determinant calculator
https://matrixcalc.org/en/det.html

https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:mat-intro/a/intro-to-matrices

https://www.mathplanet.com/education/algebra-2/matrices/how-to-operate-with-matrices

https://www.mathsisfun.com/algebra/matrix-introduction.html

https://www.sanfoundry.com/c-programming-examples-matrix/

https://www.math24.net/properties-matrices/

https://brilliant.org/wiki/matrices/

https://math.oregonstate.edu/home/programs/undergrad/CalculusQuestStudyGuides/vcalc/matrix/matrix.html

https://www.ditutor.com/matrix/matrices.html

tutorialspoint.com did not process matrices in programming language C,
but did it in programming language R (you may be interested in looking)
https://www.tutorialspoint.com/r/r_matrices.htm


*/


#include <stdio.h>
#include <stdlib.h> 	// for exit()

#define MAX_SIZE 30


// Displays a matrix M [] [] that has r rows and c columns
void display_matrix( char *text, int M[][MAX_SIZE], int r, int c )
{
    int i, j;

    printf("\n%s\n\n",text);

    for(i=0;i<r;i++) {					// print matrix M[][]
        for(j=0;j<c;j++)
            printf(" %4d",M[i][j]);

        printf("\n\n");   				// new row of matrix
    }
}


// Forms an matrix M [] [] that has r rows and c columns
// The elements of matrix are ordinal numbers.
void form_matrix( int M[][MAX_SIZE], int r, int c )
{
    int i, j;

    for(i=0;i<r;i++)			// for all rows
        for(j=0;j<c;j++)			// for all columns
            M[i][j] = i*c + j+1;
}


// Displays the matrix M without row WhichRow. It does not change the matrix M.
void display_matrix_without_WhichRow( int M[][MAX_SIZE], int r, int c, int WhichRow )
{
    int i,j;

    printf("\n");

    for(i=0;i<r;i++){   		// for all rows
        for(j=0;j<c;j++){   		// for all columns
            if(i != WhichRow-1)			// WhichRow-1 is index of that row
                printf("%4d",M[i][j]);
        }
        if(i != WhichRow-1)
            printf("\n\n");
    }
}


// Display matrix without column WhichColumn. It does not change the matrix M.
void display_matrix_without_WhichColumn( int M[][MAX_SIZE], int r, int c, int WhichColumn )
{
    int i,j;

    printf("\n");

    for(i=0;i<r;i++){   		// for all rows
        for(j=0;j<c;j++){   		// for all columns
            if(j != WhichColumn-1){
                printf("%4d",M[i][j]);
            }
        }
        printf("\n\n");
    }
}


// Display matrix without main diagonal. It does not change the matrix M.
// The displayed matrix has the same number of rows r, the number of columns is 1 smaller.
void display_matrix_without_main_diagonal( int M[][MAX_SIZE], int r, int c )
{
    int i, j;

    printf("\n");

    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            if( i != j )   // if this is not an element of the main diagonal of the matrix M
                printf(" %4d",M[i][j]);

        printf("\n\n");     // new row of matrix M
    }
}


// Display matrix without side diagonal. It does not change the matrix M.
// The displayed matrix has the same number of rows r, the number of columns is 1 smaller.
void display_matrix_without_side_diagonal( int M[][MAX_SIZE], int r, int c )
{
    int i, j;

    printf("\n");

    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            // should also be i+j != n-1, but this is also true in the case with rectangular matrices where r<c
            if( i+j != r-1 )   // if this is not an element of the main diagonal of the matrix M
                printf(" %4d",M[i][j]);

        printf("\n\n");     // new row of matrix M
    }
}


// Delete row WhichRow from matrix M. The new matrix has one fewer rows.
// function gets an address of r (int *r) to be able to change it
void delete_WhichRow_in_matrix( int M[][MAX_SIZE], int *r, int c, int WhichRow )
{
    int i,j,r1=0;                   // r1 is the row index of the new matrix

    for(i=0;i<*r;i++){              // for all rows
        for(j=0;j<c;j++){           // for all columns
            if(i != WhichRow-1){   	// if it's not the row we're deleting
                M[r1][j] = M[i][j]; // we put the elements in the new matrix
            }
        }
        if(i != WhichRow-1)        	// if it's not the row we're deleting
            r1++;                   // increase the row index of the new matrix
    }
    (*r)--; 	// since we deleted one row, we reduce the number of rows of the new matrix
}


// // Delete column WhichColumn in matrix. The new matrix has one fewer columns.
void delete_WhichColumn_in_matrix( int M[][MAX_SIZE], int r, int *c, int WhichColumn )
{
    int i,j,k1;                         // k1 is the column index of the new matrix

    for(i=0;i<r;i++){                   // for all rows
        k1=0;                           // at the beginning of each row, index of the column is zero
        for(j=0;j<*c;j++){              // for all columns
            if(j != WhichColumn-1){     // if it's not the column we're deleting
                M[i][k1++] = M[i][j];   // we put the elements in the new matrix
            }
        }
    }
    (*c)--;		// since we deleted one column, we reduce the number of columns of the new matrix
}


// Delete row WhichRow and column WhichColumn in matrix M
// The new matrix has a smaller number of rows and a number of columns.
// Function gets address of r (int *r) and c (int *c) to be able to change them.
void delete_WhichRow_and_WhichColumn( int M[][MAX_SIZE], int *r, int *c, int WhichRow, int WhichColumn )
{
    int i,j,r1=0,k1;  // k1 and r1 are the index for the columns and rows of the new matrix

    for(i=0;i<*r;i++){              	// for all rows

        for(j=0;j<*c;j++){           	// for all columns
            if(i != WhichRow-1){
                M[r1++][j]=M[i][j];
            }
        }
        if(i != WhichRow-1)
            printf("\n");
    }

    (*r)--;	// since we deleted one row, we reduce the number of rows of the new matrix
    (*c)--;	// since we deleted one column, we reduce the number of columns of the new matrix
}


// Display matrix without row WhichRow and column WhichColumn. It does not change the matrix M.
void display_matrix_without_WhichRow_and_WhichColumn( int M[][MAX_SIZE], int r, int c, int WhichRow, int WhichColumn )
{
    int i,j;

    printf("\n\n");

    for(i=0;i<r;i++){             		// for all rows

        for(j=0;j<c;j++){           	// for all columns
            if(i != WhichRow-1 )
                if(j != WhichColumn-1)
                    printf("%4d",M[i][j]);
        }
        if(i != WhichRow-1)
            printf("\n\n");
    }
}


// Deletes the main diagonal of the matrix M[r][c] having r rows and c columns.
// New matrix without main diagonal has the same number of rows,
// and the number of columns is 1 less.
// Function gets address of c (int *c) to be able to change it.
void delete_main_diagonal_of_matrix( int M[][MAX_SIZE], int r, int *c )
{
    int i, j, k1;	// k1 is the number of columns of the matrix M with the main diagonal ejected

    for(i=0;i<r;i++){

        k1=0;   	// initial value for the column counter of the new matrix

        for(j=0;j<*c;j++)
            if( i != j )   // if this is not an element of the main diagonal of the matrix M[][]
                M[i][k1++] = M[i][j];  // and increase k1, number of columns of new matrix
    }

    (*c)--;     						// reduce the number of columns
}


// Delete side diagonal of matrix M[r][c] having r rows and c columns.
// New matrix without side diagonal has the same number of rows,
// and the number of columns is 1 less.
// Function gets address of c (int *c) to be able to change it.
void delete_side_diagonal_of_matrix( int M[][MAX_SIZE], int r, int *c )
{
    int i, j, k1; 	// k1 is the number of columns of the matrix M with the side diagonal ejected

    for(i=0;i<r;i++){

        k1=0;   	// initial value for the column counter of the new matrix

        for(j=0;j<*c;j++)
            // should also be i+j != n-1, but this is also true in the case with rectangular matrices where r<c
            if( i+j != r-1 )   // if this is not an element of the side diagonal of the matrix M[][]
                M[i][k1++] = M[i][j];  // and increase k1, number of columns of new matrix
    }

    (*c)--;     // reduce the number of columns
}


// In matrix M, rows r1 and r2 swap places.
void swap_places_of_rows_r1_and_r2( int M[][MAX_SIZE], int r, int c, int r1, int r2 )
{
    int j, mem;		// mem is a temporary memory (cache) for the integer

    r1--;   // Convert row number to index
    r2--;   // Convert row number to index

    for(j=0;j<c;j++){      	// repeat c times:
        mem = M[r1][j];     // elements of two rows r1 and r2 interchange places
        M[r1][j] = M[r2][j];
        M[r2][j] = mem;
    }
}


// In matrix M, columns c1 and c2 swap places.
void swap_places_of_columns_c1_and_c2( int M[][MAX_SIZE], int r, int c, int c1, int c2 )
{
    int i, mem;

    c1--;   // Convert column number to index
    c2--;   // Convert column number to index

    for(i=0;i<r;i++){      	// repeat r times:
        mem = M[i][c1];     // elements of two columns r1 and r2 interchange places
        M[i][c1] = M[i][c2];
        M[i][c2] = mem;
    }
}



int main_many(void)
{
    int M[MAX_SIZE][MAX_SIZE];
    int i, r=4, c=4, WhichRow, WhichColumn;
    int choice;		// r and c are the row and column numbers of the matrix M

    form_matrix(M,r,c);

	while( 1 ) {    // an endless loop that exits with a choice of 0 or Escape

        //system("CLS");          // clear command window

        display_matrix(" Matrix is: ",M,r,c);

        printf("\n \t MAIN MENY \n\n"
               "  1  Form matrix of ordinal numbers \n"
               "  2  Display matrix without row r \n"
               "  3  Delete row r in matrix \n"
               "  4  Display matrix without column c \n"
               "  5  Delete column c in matrix \n"
               "  6  Display matrix without row r and column c \n"
               "  7  Delete row r and column c in matrix \n"
               "  8  Display matrix without main diagonal \n"
               "  9  Delete main diagonal in matrix \n"
               "  a  Display matrix without side diagonal \n"
               "  b  Delete side diagonal of matrix \n"
               "  c  Interchange of two row positions \n"
               "  d  Interchange of two column positions \n"
               "  e  Form different matrix of ordinal numbers \n"
               "  0  End of work (0 or Escape ESC) \n\n"
               " \t Your choice is: "
               );

        switch(choice = getche()){

            case '1':         // reset matrix, form matrix of ordinal numbers
                    form_matrix(M,r,c);
                    break;
            case '2':         // Display matrix without row r
                    printf("\n Which row you don't want to show, r = ");
                    scanf("%d", &WhichRow);
                    if ( WhichRow < 0 || WhichRow > r ) {
                        printf("\n Row %d was not entered correctly! \n",WhichRow);
                        exit(1);
                    }
                    display_matrix_without_WhichRow(M,r,c,WhichRow);
                    break;
            case '3':         // Delete row WhichRow in matrix
                    printf("\n Koji red zelis da obrises, r = ");
                    scanf("%d", &WhichRow);
                    delete_WhichRow_in_matrix(M,&r,c,WhichRow);
                    break;
            case '4':         // Display matrix without column c
                    printf("\n Which column you do not want to display, c = ");
                    scanf("%d", &WhichColumn);
                    if ( WhichColumn < 0 || WhichColumn > c ) {
                        printf("\n Column %d was not entered correctly! \n",WhichColumn);
                        exit(1);
                    }
                    display_matrix_without_WhichColumn(M,r,c,WhichColumn);
                    break;
            case '5':         // Delete column WhichColumn in matrix
                    printf("\n Which column do you want to delete, c = ");
                    scanf("%d", &WhichColumn);
                    delete_WhichColumn_in_matrix(M,r,&c,WhichColumn);
                    break;
            case '6':         // Display matrix without row WhichRow and column WhichColumn
                    printf("\n Which row do you want to delete,    r = ");
                    scanf("%d", &WhichRow);
                    printf("\n Which column do you want to delete, c = ");
                    scanf("%d", &WhichColumn);
                    display_matrix_without_WhichRow_and_WhichColumn(M,r,c,WhichRow,WhichColumn);
                    break;
            case '7':         // Delete row WhichRow and column WhichColumn in matrix
                    printf("\n Which row do you want to delete, r = ");
                    scanf("%d", &WhichRow);
                    if ( WhichRow < 0 || WhichRow > r ) {
                        printf("\n Row %d was not entered correctly! \n",WhichRow);
                        exit(1);
                    }
                    printf("\n Which column do you want to delete, c = ");
                    scanf("%d", &WhichColumn);
                    if ( WhichColumn < 0 || WhichColumn > c ) {
                        printf("\n Column %d was not entered correctly! \n",WhichColumn);
                        exit(1);
                    }
                    delete_WhichRow_and_WhichColumn(M,&r,&c,WhichRow,WhichColumn);
                    break;
            case '8':         // Display matrix without main diagonal
                    display_matrix_without_main_diagonal(M,r,c);
                    break;
            case '9':         // Delete main diagonal in matrix
                    delete_main_diagonal_of_matrix(M,r,&c);
                    break;
            case 'a':        // Display matrix without side diagonal
                    display_matrix_without_side_diagonal(M,r,c);
                    break;
            case 'b':        // Delete side diagonal of matrix
                    delete_side_diagonal_of_matrix(M,r,&c);
                    break;
            case 'c':        // Interchange of two row positions
                    printf("\n Enter the first row interchange number, r1 = ");
                    scanf("%d", &WhichRow);
                    if ( WhichRow < 0 || WhichRow > r ) {
                        printf("\n Row %d was not entered correctly! \n",WhichRow);
                        exit(1);
                    }
                    printf("\n Enter the second row interchange number, r2 = ");
                    scanf("%d", &WhichColumn); // the WhichColumn variable was used here to enter the queue
                    if ( WhichColumn < 0 || WhichColumn > r ) {
                        printf("\n Row %d was not entered correctly! \n",WhichColumn);
                        exit(1);
                    }
                    swap_places_of_rows_r1_and_r2(M,r,c,WhichRow,WhichColumn);
                    break;
            case 'd':        // Interchange of two column positions
                    printf("\n Enter the number of the first interchange column, k1 = ");
                    scanf("%d", &WhichRow); // The WhichRow variable for column input was used here
                    if ( WhichRow < 0 || WhichRow > c ) {
                        printf("\n Column %d was not entered correctly! \n",WhichRow);
                        exit(1);
                    }
                    printf("\n Enter the number of the second interchange column, k2 = ");
                    scanf("%d", &WhichColumn);
                    if ( WhichColumn < 0 || WhichColumn > c ) {
                        printf("\n Column %d was not entered correctly! \n",WhichColumn);
                        exit(1);
                    }
                    swap_places_of_columns_c1_and_c2(M,r,c,WhichRow,WhichColumn);
                    break;
            case 'e':        // form different matrix of ordinal numbers
                    printf("\n Enter the number of rows of the new matrix, r = ");
                    scanf("%d", &r);
                    printf("\n Enter the number of columns of the new matrix, c = ");
                    scanf("%d", &c);
                    form_matrix(M,r,c);
                    break;
            case '0' :                      // 0 to end of work
                    return(choice);
                    break;

            case 27  :                      // ESC to end of work
                    return(choice);
                    break;

            case  0  :                      // if a function key is pressed
                    choice = getche(); 	    // let's empty that 0

            case 224 :                      // if a special function key is pressed
                    choice = getche(); 	    // let's empty that 224
                    break;

            default:					    // if entered character is not from the meny
                    if( !(choice<'0' && choice>'9') && !(choice<'a' && choice>'e') ) {
                        printf("\n\n Wrong choose, entered character is not from the meny !!! \n");
                    }
                    break;

        } // switch(choice = getche())
    } // while( 1 )
    return choice;
} // main_many()




int main(void)
{

    main_many();


    return 0;
}
