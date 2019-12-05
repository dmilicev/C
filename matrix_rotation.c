/*

	matrix_rotation.c		by Dragan Milicev


	Matrix rotation:

- 90 degrees to the right, three versions
- 90 degrees to the left
- around the horizontal axis, two versions
- around the vertical axis, two versions


You can find all my C programs at Dragan Milicev's pastebin:

https://pastebin.com/u/dmilicev

https://www.facebook.com/dmilicev

*/


#include <stdio.h>
#include <stdlib.h> // zbog exit()

#define MAX_SIZE 15


// Displays the matrix M[r][k] that has r rows and k columns
void print_matrix( char *text, int M[][MAX_SIZE], int r, int k )
{
    int i, j;

    printf("\n%s\n\n",text);

    for(i=0;i<r;i++) {
        for(j=0;j<k;j++)
            printf("%4d",M[i][j]);

        printf("\n\n");
    }
    printf("\n");
}


// Create the matrix M[r][k] that has r rows and k columns
// Elements are ordinal numbers.
void create_matrix( int M[][MAX_SIZE], int r, int k )
{
    int i, j;

    for(i=0;i<r;i++)
        for(j=0;j<k;j++)
            M[i][j] = i*k + j+1;
}


// Functions that do not change the matrix M, just displays rotated matrix


// Displays a matrix rotated around a horizontal axis.
void display_matrix_rotated_around_horizontal_axis( int M[][MAX_SIZE], int r, int k )
{
   int i,j;

    for(i=r-1;i>=0;i--){
        for(j=0;j<k;j++){
            printf(" %4d",M[i][j]);
        }
        printf("\n\n");
    }
}


// Displays a matrix rotated around a horizontal axis, version 1.
void display_matrix_rotated_around_horizontal_axis_v1( int M[][MAX_SIZE], int r, int k )
{
   int i,j,ip=r-1,jp;       // ip and jp are indexes for displaying M[ip][jp]

    for(i=0;i<r;i++){
        jp=0;
        for(j=0;j<k;j++)
            printf(" %4d",M[ip][jp++]);
        ip--;
        printf("\n\n");
    }
}


// Displays a matrix rotated around a vertical axis, version 1
void display_matrix_rotated_around_vertical_axis_v1( int M[][MAX_SIZE], int r, int k )
{
   int i,j,ip=0,jp;     // ip and jp are indexes for displaying M[ip][jp]

    for(i=0;i<r;i++){
        jp=k-1;
        for(j=0;j<k;j++)
            printf(" %4d",M[ip][jp--]);
        ip++;
        printf("\n\n");
    }
}


// Displays a matrix rotated around a vertical axis
void display_matrix_rotated_around_vertical_axis( int M[][MAX_SIZE], int r, int k )
{
   int i,j;

    for(i=0;i<r;i++){
        for(j=k-1;j>=0;j--)
            printf(" %4d",M[i][j]);
        printf("\n\n");
    }
}


// Displays the matrix rotated to the right by 90 degrees, version 2.
// The first is the bottom left element and its column is displayed backwards as the first row.
// Columns become rows and are displayed backwards.
void display_matrix_rotated_right_90_degrees_v2( int M[][MAX_SIZE], int r, int k )
{
   int i,j,ip,jp=0;     // ip and jp are indexes for displaying M[ip][jp]

    for(i=0;i<r;i++){
        ip=r-1;
        for(j=0;j<k;j++)
            printf(" %4d",M[ip--][jp]);
        jp++;
        printf("\n\n");
    }
}


// Displays the matrix rotated to the right by 90 degrees, version 1.
// The first is the bottom left element and its column is displayed backwards as the first row.
// Columns become rows and are displayed backwards.
void display_matrix_rotated_right_90_degrees_v1( int M[][MAX_SIZE], int r, int k )
{
    int i,j;

    for(j=0;j<k;j++){
        for(i=r-1;i>=0;i--)
            printf(" %4d",M[i][j]);
        printf("\n\n");
    }
}


// Displays the matrix rotated to the right by 90 degrees.
// The first is the bottom left element and its column is displayed backwards as the first row.
// Columns become rows and are displayed backwards.
void display_matrix_rotated_right_90_degrees( int M[][MAX_SIZE], int r, int k )
{
    int i,j;

    for(i=0;i<k;i++){
        for(j=k-1;j>=0;j--)
            printf(" %4d",M[j][i]);	// ATTENTION, indexes replaced places M[j][i]
        printf("\n\n");
    }
}


// Displays the matrix rotated to the left by 90 degrees.
// The first is the top right element and its first right column is displayed as the first row.
// Columns become rows.
void display_matrix_rotated_left_90_degrees( int M[][MAX_SIZE], int r, int k )
{
   int i,j,ip,jp=k-1;   // ip and jp are indexes for displaying M[ip][jp]

    for(i=0;i<r;i++){
        ip=0;
        for(j=0;j<k;j++)
            printf(" %4d",M[ip++][jp]);
        jp--;
        printf("\n\n");
    }
}


// Copies matrix M to matrix M1, r is the number of rows, k is the number of columns
void copy_matrix( int M1[][MAX_SIZE], int M[][MAX_SIZE], int r, int k )
{
    int i,j;

    for(i=0;i<r;i++)
        for(j=0;j<k;j++)
            M1[i][j] = M[i][j];
}


// Functions that change the matrix M when rotating


// Rotates the matrix to the right 90 degrees.
void rotate_matrix_right_90_degrees( int M[][MAX_SIZE], int r, int k )
{
    int M1[MAX_SIZE][MAX_SIZE]; 	// declare a new matrix M1
    int i,j;

    copy_matrix(M1,M,r,k);  		// copy matrix M to matrix M1

    // Form the matrix M again by taking from the matrix M1
    // certain elements and put them in the matrix M.
    for(i=0;i<r;i++)
        for(j=0;j<k;j++)
            M[i][j] = M1[k-1-j][i];
}


// Rotates the matrix to the left 90 degrees.
void rotate_matrix_left_90_degrees( int M[][MAX_SIZE], int r, int k )
{
    int M1[MAX_SIZE][MAX_SIZE]; 	// declare a new matrix M1
    int i,j;

    copy_matrix(M1,M,r,k);			// Copy matrix M to matrix M1

    // Form the matrix M again by taking from the matrix M1
    // certain elements and put them in the matrix M.
    for(i=0;i<r;i++)
        for(j=0;j<k;j++)
            M[i][j] = M1[j][r-1-i];
}


// Rotates the matrix around the horizontal axis.
void rotate_matrix_around_horizontal_axis( int M[][MAX_SIZE], int r, int k )
{
    int M1[MAX_SIZE][MAX_SIZE]; // declare a new matrix M1
    int i,j;

    copy_matrix(M1,M,r,k);  	// Copy matrix M to matrix M1

    // Form the matrix M again by taking from the matrix M1
    // certain elements and put them in the matrix M.
    for(i=0;i<r;i++)
        for(j=0;j<k;j++)
            M[i][j] = M1[r-i-1][j];
}


// Rotates the matrix around the vertical axis.
void rotate_matrix_around_vertical_axis( int M[][MAX_SIZE], int r, int k )
{
    int M1[MAX_SIZE][MAX_SIZE]; // declare a new matrix M1
    int i,j;

    copy_matrix(M1,M,r,k);		// Copy matrix M to matrix M1

    // Form the matrix M again by taking from the matrix M1
    // certain elements and put them in the matrix M.
    for(i=0;i<r;i++)
        for(j=0;j<k;j++)
            M[i][j] = M1[i][k-1-j];
}



int main(void)
{
    int M[MAX_SIZE][MAX_SIZE];
    int i, r=4, c=4;
		// r is the number of rows and c is the number of columns of the matrix M[][]

    create_matrix(M,r,c);
    print_matrix(" Matrix M is: ",M,r,c);

    printf("\n Functions that do not change the matrix M, just displays rotated matrix : \n\n");

    printf(" \n Matrix rotated to the right by 90 degrees is: \n\n");
    display_matrix_rotated_right_90_degrees(M,r,c);

    printf(" \n Matrix rotated to the right by 90 degrees v1 is: \n\n");
    display_matrix_rotated_right_90_degrees_v1(M,r,c);

    printf(" \n Matrix rotated to the right by 90 degrees v2 is: \n\n");
    display_matrix_rotated_right_90_degrees_v2(M,r,c);

    printf(" \n Matrix rotated to the left by 90 degrees is: \n\n");
    display_matrix_rotated_left_90_degrees(M,r,c);

    printf(" \n Matrix rotated around the horizontal axis is: \n\n");
    display_matrix_rotated_around_horizontal_axis(M,r,c);

    printf(" \n Matrix rotated around the horizontal axis v1 is: \n\n");
    display_matrix_rotated_around_horizontal_axis_v1(M,r,c);

    printf(" \n Matrix rotated around the vertical axis is: \n\n");
    display_matrix_rotated_around_vertical_axis(M,r,c);

    printf(" \n Matrix rotated around the vertical axis v1 is: \n\n");
    display_matrix_rotated_around_vertical_axis_v1(M,r,c);

    print_matrix(" Matrix M is: ",M,r,c);


    printf("\n Functions that change the matrix M when rotating : \n\n");

    rotate_matrix_right_90_degrees(M,r,c);
    print_matrix(" Matrix rotated to the right 90 degrees is: ",M,r,c);

    create_matrix(M,r,c);    // reset the matrix M because it was modified
    rotate_matrix_left_90_degrees(M,r,c);
    print_matrix(" Matrix rotated to the left 90 degrees is: ",M,r,c);

    create_matrix(M,r,c);    // reset the matrix M because it was modified
    rotate_matrix_around_horizontal_axis(M,r,c);
    print_matrix(" Matrix rotated around the horizontal axis is: ",M,r,c);

    create_matrix(M,r,c);    // reset the matrix M because it was modified
    rotate_matrix_around_vertical_axis(M,r,c);
    print_matrix(" Matrix rotated around the vertical axis is: ",M,r,c);

    create_matrix(M,r,c);    // reset the matrix M because it was modified
    print_matrix(" Matrix M is: ",M,r,c);


    return 0;
}
