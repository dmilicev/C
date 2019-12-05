 /*

	print_numbers_in_rows_and_columns_v1.c


	Task is to print numbers from first to last

	in desired numbers of columns

	by rows and by columns.


	Can anyone write a function

		print_numbers_in_columns()

	which works well ?

	My function sometimes works well, but sometimes doesn't
	(has wrong number of columns).

	Thanks in advance for your help.

-------------------------------------------------

These days I'm occupied with rectangles.

The idea is that n numbers should be placed in a rectangle of minimal area.

We know the number of numbers n and the required number of columns.

The area of the rectangle must be equal to or greater than the number n

rows * columns >= n.

From there,

rows >= n / columns 			( integer division ! )

(If rows has decimal places... no)

If calculated rows

rows * column < n

we have to choose the first bigger integer.

But this is not the end. :(

A further problem is that the function (which I found on the Internet, two for loops)

is quite insensitive to changing the number n and the number of columns.

Probably we need to write a new function whose algorithm will be close to human thinking.

When done properly, only then should it be optimized ...

-------------------------------------------------

Upon further reflection, I finally realized that
what I was looking for was in fact impossible !

So, for example, we want to print numbers 1 to 22 in 7 columns.

Row numbers must be calculated.

n = last - first + 1 = 22 - 1 + 1 = 22

area of rectangle >= n

rows * columns >= n

rows >= n / columns				( integer division )

rows >= 22 / 7

rows >= 3 ( and 1 left )

Because

rows * columns = 3 * 7 = 21 < 22

we choose the first bigger integer,

so definitely rows = 4

Let's print the numbers 1 to 22 in 7 columns and 4 rows by columns in pencil on paper :

1 5  9 13 17 21
2 6 10 14 18 22
3 7 11 15 19
4 8 12 16 20

!!!

Unsurprisingly, our numbers are in 4 rows and (only !!!) 6 colons.

We have consumed all the numbers and do not have them for the required seventh column.

Then let's write the numbers in 7 columns and 3 rows ( let rows = 3 ) :

1 4 7 10 13 16 19 22
2 5 8 11 14 17 20
3 6 9 12 15 18 21

As we can see, we filled 7 columns in 3 rows, but we still have numbers left!

Number 22 we failed to insert, it requires an 8th column !

That's why I finally realized that what I was looking for was in fact impossible

and the function actually works fine.

I hope you have at least learned from all my confusion how to think when doing a task.

Pen and paper are the law of thought !

Sorry for your time spent. :(


*/

#include<stdio.h>


// Prints numbers by rows, from first to last, in the required number of columns
int print_numbers_in_rows(int first_number, int last_number, int number_of_columns)
{
    int i, j, number = first_number, number_of_rows;

    // calculate the number_of_rows required
    number_of_rows = (last_number - first_number + 1) / number_of_columns;

printf("\n 1) number_of_rows = %d \n", number_of_rows);		// delete this line

	if ( number_of_rows * number_of_columns < last_number - first_number + 1 )
		number_of_rows++;

printf("\n 2) number_of_rows = %d \n\n", number_of_rows);	// delete this line

    for(i=0; i<number_of_rows; i++)				// loop for rows
    {
        for(j=0; j<number_of_columns; j++)		// loop for columns
        {
            if ( number<=last_number)
				printf("%5d", number++);		// print current number
			else
				return number;
        }

        printf("\n");							// new row
    }
}


// Prints numbers by columns, from first to last, in the required number of columns
void print_numbers_in_columns(int first_number, int last_number, int number_of_columns)
{
    int i, j, count, first, number_of_rows;

	// calculate the number of numbers to be printed
	count = last_number - first_number + 1;

	// calculate the number_of_rows required
	// The idea is that n numbers should be placed in a rectangle of minimal area.
	// We know the number of numbers n and the required number of columns.
	// The area of the rectangle must be equal to or greater than the number n
	//		rows * columns >= n.
	// From there,
	//		rows >= n / columns 	( integer division ! )
	// (If rows has decimal places... no)
	// If calculated rows
	//		rows * column < n
	//	we have to choose the first bigger integer, rows++ .

	number_of_rows = (last_number - first_number + 1) / number_of_columns;

printf("\n 1) number_of_rows = %d \n", number_of_rows);				// delete this line

	if ( number_of_rows * number_of_columns < count )
		number_of_rows++;

printf("\n 2) number_of_rows = %d \n\n", number_of_rows);			// delete this line

    for(i=0, first=first_number; i<number_of_rows; i++, first++ )	// loop for rows
    {
        for( j=first; j<=last_number; j+=number_of_rows )			// loop for columns
        {
        	printf("%5d", j);										// print current number
        }

        printf("\n");	// new row
    }


    /*
	// calculate the number of numbers to be printed
	count = last_number - first_number + 1;

	// calculate the number_of_rows required
	//number_of_rows = ( count / number_of_columns ) + ( (count % number_of_columns)>0 );
	// or:
	number_of_rows = (last_number - first_number ) / number_of_columns + 1;

    for(i=0, first=first_number; i<number_of_rows; i++, first++ )	// loop for rows
    {
        for( j=first; j<=last_number; j+=number_of_rows )			// loop for columns
        {
        	printf("%5d", j);										// print current number
        }

        printf("\n");	// new row
    }
*/
}


int main()
{			// change number_of_columns from 1 to 15 to see how functions works.
//    int first_number=1, last_number=100, number_of_columns=15;
//    int first_number=1, last_number=106, number_of_columns=13;
    int first_number=1, last_number=22, number_of_columns=7;


    printf("\n Numbers from %d to %d by rows in %d columns : \n\n",
			first_number, last_number, number_of_columns );

	print_numbers_in_rows(first_number, last_number, number_of_columns);


    printf("\n\n Numbers from %d to %d by columns in %d columns : \n\n",
			first_number, last_number, number_of_columns );

	print_numbers_in_columns(first_number, last_number, number_of_columns);


	printf("\n");

    return 0;
}
