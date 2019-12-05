/*

	number pattern v1.c

	https://codedost.com/c/number-patterns-c/

	https://www.programiz.com/c-programming/examples/pyramid-pattern

	https://www.includehelp.com/c-programs/c-program-to-print-stars-in-series-pyramid-using-looping.aspx

	https://www.faceprep.in/pattern-programs-in-c/


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

	https://www.facebook.com/dmilicev

*/


#include <stdio.h>


/*

1-

2-3-

4-5-6-

*/
void left_triangle(int number_of_rows)
{
	int row, column, number=1;

	printf("\n\t\t left_triangle() \n");

	for(row=0; row<=number_of_rows; row++)
	{
		for(column=0; column<row; column++)
		{
			printf("%d-", number);
			number++;
		}

		printf("\n\n");	// new row
	}
}


/*

1-2-3-

4-5-

6-

*/
void inverted_left_triangle(int number_of_rows)
{
	int i, j, k = 0, number=1;

	printf("\n\t\t inverted_left_triangle() \n\n");

	for(i = number_of_rows; i >= 1; --i)
	{
		for(j = 1; j <= i; ++j)
		{
			printf("%d-", number);
			number++;
		}

		printf("\n\n");
	}
}


/*
----1-

--2-3-

4-5-6-

*/
void right_triangle(int number_of_rows)
{
	int i, j, number=1;

	printf("\n\t\t right_triangle() \n\n");

	for(i=0 ; i<number_of_rows ; i++)			// print rows
	{
		for(j=2*number_of_rows-i-2 ; j>i ; j--)	// print spaces " "
			printf("-");

		for(j=0 ; j<=i; j++)					// print numbers
		{
			printf("%d-", number);
			number++;
		}
		printf("\n\n");
	}
}


/*

1-2-3-

--4-5-

----6-

*/
void inverted_right_triangle(int number_of_rows)
{
	int i, row, number=1, ns, nd;	// ns number of spaces, nd number of digits

	printf("\n\t\t inverted_right_triangle() \n\n");

	for (row=0; row<number_of_rows; row++)	// print rows one by one row
	{
		ns = 2*row;					// calculate ns number of spaces
		nd = number_of_rows-row;	// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		for (i=0; i<nd; i++)		// print nd "%d "
		{
			printf("%d-", number);
			number++;
		}

		printf("\n\n");				// print new row
	}
}


/*

--1-

-2-3-

4-5-6-

*/
void pyramid(int number_of_rows)
{
	int i, row, number=1, ns, nd;	// ns number of spaces, nd number of digits

	printf("\n\t\t pyramid() \n\n");

	for (row=0; row<number_of_rows; row++)	// print rows one by one row
	{
		ns = number_of_rows-row-1;	// calculate ns number of spaces
		nd = row+1;					// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		for (i=0; i<nd; i++)		// print nd "%d "
		{
			printf("%d-", number);
			number++;
		}

		printf("\n\n");				// print new row
	}
}


/*

1-2-3-

-4-5-

--6-

*/
void inverted_pyramid(int number_of_rows)
{
	int i, row, number=1, ns, nd;	// ns number of spaces, nd number of digits

	printf("\n\t\t inverted_pyramid() \n\n");

	for (row=0; row<number_of_rows; row++)	// print rows one by one row
	{
		ns = row;	// calculate ns number of spaces
		nd = number_of_rows-row;					// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		for (i=0; i<nd; i++)		// print nd "%d "
		{
			printf("%d-", number);
			number++;
		}

		printf("\n\n");				// print new row
	}
}


/*

1-2-3-4-5-6-7-8-9-8-7-6-5-4-3-2-1-
1-2-3-4-5-6-7-8---8-7-6-5-4-3-2-1-
1-2-3-4-5-6-7-------7-6-5-4-3-2-1-
1-2-3-4-5-6-----------6-5-4-3-2-1-
1-2-3-4-5---------------5-4-3-2-1-
1-2-3-4-------------------4-3-2-1-
1-2-3-----------------------3-2-1-
1-2---------------------------2-1-
1-------------------------------1-

*/
void number_pattern_2(int n)
{
	int i, j, k, start;

	printf("\n\t\t number_pattern_2() \n\n");

	k = n;

	for(i=0; i<n; i++)
	{
		start = 0;

		for(j=0; j<2*n-1; j++)
		{
			if(j < n)
				start++;
			else
				start--;

			if(j<k || j>2*n-k-2)
				printf("%d-",start);
			else
				printf("--");
		}

		k--;
		printf("\n");
	}
}


/*
--------1-

-------2-2-

------3-3-3-

-----4-4-4-4-

----5-5-5-5-5-

---6-6-6-6-6-6-

--7-7-7-7-7-7-7-

-8-8-8-8-8-8-8-8-

9-9-9-9-9-9-9-9-9-
*/
void triangle_of_numbers_1( int number_of_rows )
{
	int i, row, ns, nd;				// ns number of spaces, nd number of digits

	printf("\n\t\t triangle_of_numbers_1() \n\n");

	for (row=0; row<number_of_rows; row++)	// print rows one by one row
	{
		ns = number_of_rows-row-1;	// calculate ns number of spaces
		nd = row+1;					// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		for (i=0; i<nd; i++)		// print nd "%d "
			printf("%d-", row+1);

		printf("\n\n");				// print new row
	}
}


/*
--------1-

-------1-2-

------1-2-3-

-----1-2-3-4-

----1-2-3-4-5-

---1-2-3-4-5-6-

--1-2-3-4-5-6-7-

-1-2-3-4-5-6-7-8-

1-2-3-4-5-6-7-8-9-
*/
void triangle_of_numbers_2( int number_of_rows )
{
	int i, row, number, ns, nd;		// ns number of spaces, nd number of digits

	printf("\n\t\t pyramid() \n\n");

	for (row=0; row<number_of_rows; row++)	// print rows one by one row
	{
		ns = number_of_rows-row-1;	// calculate ns number of spaces
		nd = row+1;					// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		number = 1;
		for (i=0; i<nd; i++)		// print nd "%d "
		{
			printf("%d-", number);
			number++;
		}

		printf("\n\n");				// print new row
	}
}


/*

----------------1-
--------------1-2-1-
------------1-2-3-2-1-
----------1-2-3-4-3-2-1-
--------1-2-3-4-5-4-3-2-1-
------1-2-3-4-5-6-5-4-3-2-1-
----1-2-3-4-5-6-7-6-5-4-3-2-1-
--1-2-3-4-5-6-7-8-7-6-5-4-3-2-1-
1-2-3-4-5-6-7-8-9-8-7-6-5-4-3-2-1-

*/
void pyramid_pattern_1( int n )		// n is number of rows
{
	int i,row, number, ns, nd;		// ns number of spaces, nd number of digits

	printf("\n\t\t pyramid_pattern_1() \n\n");

	for (row=0; row<n; row++)		// print rows one by one row
	{
		ns = 2*(n-row-1);			// calculate ns number of spaces
		nd = 2*row+1;				// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		number = 0;

		for(i=0; i<nd; i++)			// print nd "%d " numbers
		{
			if( i <= (2*row+1)/2 )
				number++;
			else
				number--;

			printf("%d-", number );
		}
		printf("\n");
	}
}


/*

----------------9-
--------------8-9-8-
------------7-8-9-8-7-
----------6-7-8-9-8-7-6-
--------5-6-7-8-9-8-7-6-5-
------4-5-6-7-8-9-8-7-6-5-4-
----3-4-5-6-7-8-9-8-7-6-5-4-3-
--2-3-4-5-6-7-8-9-8-7-6-5-4-3-2-
1-2-3-4-5-6-7-8-9-8-7-6-5-4-3-2-1-

*/
void pyramid_pattern_2( int n )		// n is number of rows
{
	int i, row, number, middle_number, ns, nd;	// ns number of spaces, nd number of digits

	printf("\n\t\t pyramid_pattern_2() \n\n");

	for (row=0; row<n; row++)		// print rows one by one row
	{
		ns = 2*(n-row-1);			// calculate ns number of spaces
		nd = 2*row+1;				// calculate nd number of digits

		for (i=0; i<ns; i++)		// print ns spaces " "
			printf("-");

		middle_number = n;
		number = middle_number - row - 1;

		for(i=0; i<nd; i++)			// print nd "%d " numbers
		{
			if( i <= (2*row+1)/2 )
				number++;
			else
				number--;

			printf("%d-", number );
		}
		printf("\n");
	}
}



int main(void)
{
	int number_of_rows = 3;

	left_triangle(number_of_rows);
	printf("\n");

	inverted_left_triangle(number_of_rows);
	printf("\n");

	right_triangle(number_of_rows);
	printf("\n");

	inverted_right_triangle(number_of_rows);
	printf("\n");

	pyramid(number_of_rows);
	printf("\n");

	inverted_pyramid(number_of_rows);
	printf("\n");

	number_pattern_2(9);
	printf("\n");

	triangle_of_numbers_1(9);
	printf("\n");

	triangle_of_numbers_2(9);
	printf("\n");

	pyramid_pattern_1(9);
	printf("\n");

	pyramid_pattern_2(9);
	printf("\n");


	return(0);
}
