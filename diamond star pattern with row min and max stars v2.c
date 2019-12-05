/*
 diamond star pattern with row min and max stars v2.c

 This code was obtained by processing the code
  diamond star pattern with number of rows v1.c

 Below is a picture of full diamond.

 In program, we input
	minimum number of asterisks in row, min_na, and
	maximum number of asterisks in row, max_na

Then we draw cut out (abbreviated) diamond
and count number of used asterisks.

For whole diamond,
min_na = 1
max_na = some number bigger than min_na

 If number_of_rows is even number, we have to add 1 to be odd number.
 This is because diamond must be simetrical.

----*-
---*-*-
--*-*-*-
-*-*-*-*-
*-*-*-*-*-
-*-*-*-*-
--*-*-*-
---*-*-
----*-

row	 spaces 		*

 0.	 	  4		    1
 1.	   	3		    2
 2.	   	2		    3
 3.	   	1		    4
 4.    	0		    5

 5.		  1		    4
 6.		  2		    3
 7.		  3		    2
 8.		  4		    1


	Upper half of diamond

For number of spaces in a row we have to find relation with r and nr, (nr/2 - r).

For number of "*-" in a row we have to find relation with r, (r+1).

	Lower half of diamond

For number of spaces in a row we have to find relation with r and nr, (r - nr/2).

For number of "*-" in a row we have to find relation with r and nr, (nr-r).


If number_of_rows nr is even number, we increment it for 1, to be odd number,
because diamond must be simetrical.

Example of cutted diamond:

min_na = 3
max_na = 5

--*-*-*-
-*-*-*-*-
*-*-*-*-*-
-*-*-*-*-
--*-*-*-

 r	row	 spaces		*

 0	 3.	 	2		3
 1	 4.	   	1		4
 2	 5.	   	0		5
 3	 6.	   	1		4
 4	 7.    	2		3


min_na = 3
max_na = 6

---*-*-*-
--*-*-*-*-
-*-*-*-*-*-
*-*-*-*-*-*-
-*-*-*-*-*-
--*-*-*-*-
---*-*-*-

 r	row	 spaces		*

 0	 3.	 	3		3
 1	 4.	   	2		4
 2	 5.	   	1		5
 3	 6.	   	0		6
 4	 7.    	1		5
 5	 8.    	2		4
 6	 9.    	3		3


min_na = 2
max_na = 4

--*-*-
-*-*-*-
*-*-*-*-
-*-*-*-
--*-*-

 r	row	 spaces		*

 0	 2.	 	2		2
 1	 3.	   	1		3
 2	 4.	   	0		4
 3	 5.	   	1		3
 4	 6.    	2		2

We print diamond from 3. row with 3 asterisks.
Diamond have maximum 5 asterisks in row.

*/

#include "stdio.h"

int main(void)
{
/*
	i		loop counter
	r   	row,
	nr  	number_of_rows,
	ns  	number_of_spaces,
	na  	number_of_asterisks
	min_na	minimum number of asterisks in row
	max_na	maximum number of asterisks in row
*/
	int i, r, nr, ns, na, min_na, max_na;

	printf("\n Enter minimum number of asterisks in row,      min_na = ");
	scanf("%d", &min_na);			// try 1, 2, 3

	printf("\n Enter maximum number of asterisks in row (>%d)  max_na = ", min_na);
	scanf("%d", &max_na);			// try 5, 6, 10

	printf("\n");					// print new row

	for (r=0; r<2*(max_na-min_na)+1; r++)	// print rows one by one row
	{
		if(r<min_na+1)				// Upper half of diamond
		{
			ns = min_na-r-1;		// calculate ns and na
			na = r+min_na;
		}
		else						// Lower half of diamond
		{
			ns = r-min_na+1;		// calculate ns and na
			na = -r+2*max_na-1;
		}

		for (i=0; i<=ns; i++)		// print ns spaces
			printf("-");

		for (i=0; i<=na; i++)		// print na asterisks
			printf("*-");

		printf("\n");				// print new row
	}

	return 0;						// This is the simplest and most comprehensive code.
}
