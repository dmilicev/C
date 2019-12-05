/*

	char patterns v1.c


	https://codedost.com/c/number-patterns-c/

	https://www.programiz.com/c-programming/examples/pyramid-pattern

	https://www.includehelp.com/c-programs/c-program-to-print-stars-in-series-pyramid-using-looping.aspx

	https://www.faceprep.in/pattern-programs-in-c/


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/


#include <stdio.h>

/*

*

* *

* * *

* * * *

*/
void left_triangle(int number_of_rows)
{
	int row, column;

	for(row=0; row<=number_of_rows; row++)
	{
		for(column=0; column<row; column++)
			printf("*-");

		printf("\n\n");		// new row
	}
}


/*

* * * *

* * *

* *

*

*/
void inverted_left_triangle(int number_of_rows)
{
	int i, j, k = 0;

	for(i = number_of_rows; i >= 1; --i)
	{
		for(j = 1; j <= i; ++j)
			printf("*-");

		printf("\n\n");
	}
}


/*

      *

    * *

  * * *

* * * *

*/
void right_triangle(int number_of_rows)
{
	int i, j, k;

	for(i=0; i<number_of_rows; i++)
	{
		for(j=number_of_rows; j>i+1; j--)
			printf("--");

		for(k=0 ; k<=i; k++)
			printf("*-");

		printf("\n\n");
	}
}


/*

* * * *

  * * *

    * *

      *

*/
void inverted_right_triangle(int number_of_rows)
{
	int i, row, ns, nd;		// ns number of spaces, nd number of digits

	for (row=0; row<number_of_rows; row++)	// print rows one by one row
	{
		ns = 2*row;					// calculate ns number of spaces
		nd = number_of_rows-row;	// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		for (i=0; i<nd; i++)		// print nd "%d "
			printf("*-");

		printf("\n\n");				// print new row
	}
}


/*

   *

  * *

 * * *

* * * *

*/
void pyramid(int number_of_rows)
{
	int i, row, ns, nd;		// ns number of spaces, nd number of digits

	for (row=0; row<number_of_rows; row++)	// print rows one by one row
	{
		ns = number_of_rows-row-1;	// calculate ns number of spaces
		nd = row+1;					// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		for (i=0; i<nd; i++)		// print nd "%d "
			printf("*-");

		printf("\n\n");				// print new row
	}
}


/*

* * * *

 * * *

  * *

   *

*/
void inverted_pyramid(int number_of_rows)
{
	int i, row, ns, nd;		// ns number of spaces, nd number of digits

	for (row=0; row<number_of_rows; row++)	// print rows one by one row
	{
		ns = row;						// calculate ns number of spaces
		nd = number_of_rows-row;		// calculate nd number of digits

		for (i=0; i<ns; i++)			// print ns spaces " "
			printf("-");

		for (i=0; i<nd; i++)			// print nd "%d "
			printf("*-");

		printf("\n\n");					// print new row
	}
}


/*

   *

  * *

 * * *

* * * *

* * * *

 * * *

  * *

   *

*/
void diamond(int number_of_rows)
{
	pyramid(number_of_rows);
	inverted_pyramid(number_of_rows);
}


int main(void)
{
	int number_of_rows = 5;

	printf("\n\t\t left_triangle() \n");
	left_triangle(number_of_rows);
	printf("\n");

	printf("\n\t\t inverted_left_triangle() \n\n");
	inverted_left_triangle(number_of_rows);
	printf("\n");

	printf("\n\t\t right_triangle() \n\n");
	right_triangle(number_of_rows);
	printf("\n");

	printf("\n\t\t inverted_right_triangle() \n\n");
	inverted_right_triangle(number_of_rows);
	printf("\n");

	printf("\n\t\t pyramid() \n\n");
	pyramid(number_of_rows);
	printf("\n");

	printf("\n\t\t inverted_pyramid() \n\n");
	inverted_pyramid(number_of_rows);
	printf("\n");

	printf("\n\t\t diamond \n\n");
	diamond(number_of_rows);
	printf("\n");


	return(0);
}
