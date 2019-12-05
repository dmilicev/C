/*

	lets_learn_structures_in_c_v1.c


	Example of work with structures in C.


	https://www.tutorialspoint.com/cprogramming/c_structures.htm

	https://www.geeksforgeeks.org/structures-c/

	https://www.learn-c.org/en/Function_arguments_by_reference


	https://www.programiz.com/c-programming/c-structures

	https://www.programiz.com/c-programming/c-structures-pointers

	https://www.programiz.com/c-programming/c-structure-function


	https://fresh2refresh.com/c-programming/c-structures/

	https://fresh2refresh.com/c-programming/c-structure-using-pointer/

	https://fresh2refresh.com/c-programming/c-nested-structure/


	You can find all my C programs at Dragan Milicev's pastebin:

    https://pastebin.com/u/dmilicev

	https://www.facebook.com/dmilicev

*/

#include <stdio.h>
#include <string.h>

#define LEFT        75      // left arrow
#define	TP_NO		0		// default value, there is no contact of the rectangle with the wall

struct Rectangle {
	int num;
	float fnum;
	char ch;
	char str[100];
};

// the function receives the value of the structure and therefore cannot modify its elements
int function_arguments_by_value( struct Rectangle R )
{

	printf("\n before change in function_arguments_by_value \n");
	printf("\n R.num = %d \n", R.num );
	printf("\n R.fnum = %.2f \n", R.fnum );
	printf("\n R.ch = %c \n", R.ch );
	printf("\n R.str = %s \n\n", R.str );

    R.num = 456;			// let's change values
	R.fnum = 56.78;
	R.ch = 'B';
	strcpy( R.str, "This is new string from function_arguments_by_value()." );

	printf("\n after change in function_arguments_by_value() \n");
	printf("\n R.num = %d \n", R.num );
	printf("\n R.fnum = %.2f \n", R.fnum );
	printf("\n R.ch = %c \n", R.ch );
	printf("\n R.str = %s \n\n", R.str );

    return 0;
}

// the function gets the address of the structure and therefore can modify its elements
int function_arguments_by_reference( struct Rectangle *R )
{

	printf("\n before change in function_arguments_by_reference() \n", (*R).num );
	//printf("\n R.num = %d \n", (*R).num );
	// or, we have a shorthand syntax for that:
	printf("\n R.num = %d \n", R->num );
	printf("\n R.fnum = %.2f \n", R->fnum );
	printf("\n R.ch = %c \n", R->ch );
	printf("\n R.str = %s \n\n", R->str );

	//(*R).num = 768;

	// or, we have a shorthand syntax for that:

	R->num = 768;			// let's change values
	R->fnum = 56.78;
	R->ch = 'B';
	strcpy( R->str, "This is new string from function_arguments_by_reference()." );

	//printf("\n after change in function_arguments_by_reference() R.num = %d \n", (*R).num );

	// or, we have a shorthand syntax for that:

	printf("\n after change in function_arguments_by_reference() \n");
	printf("\n R.num = %d \n", R->num );
	printf("\n R.fnum = %.2f \n", R->fnum );
	printf("\n R.ch = %c \n", R->ch );
	printf("\n R.str = %s \n\n", R->str );

    return 0;
}


/*
Reminder:

	struct Rectangle {
		int num;
		float fnum;
		char ch;
		char str[100];
	};
*/
int main()
{
	struct Rectangle R;

    R.num = 123;						// initial values
	R.fnum = 12.34;
	R.ch = 'A';
	strcpy( R.str, "This is string in main()" );

	printf("\n main() before function_arguments_by_value() \n");
	printf("\n R.num = %d \n", R.num );
	printf("\n R.fnum = %.2f \n", R.fnum );
	printf("\n R.ch = %c \n", R.ch );
	printf("\n R.str = %s \n\n", R.str );


	function_arguments_by_value( R );

	printf("\n main() after function_arguments_by_value() \n");
	printf("\n R.num = %d \n", R.num );
	printf("\n R.fnum = %.2f \n", R.fnum );
	printf("\n R.ch = %c \n", R.ch );
	printf("\n R.str = %s \n\n", R.str );


	printf("\n\n Notice that nothing was changed in main() \n after function_arguments_by_value() \n\n");

	function_arguments_by_reference( &R );

	printf("\n main() after function_arguments_by_reference() \n");
	printf("\n R.num = %d \n", R.num );
	printf("\n R.fnum = %.2f \n", R.fnum );
	printf("\n R.ch = %c \n", R.ch );
	printf("\n R.str = %s \n\n", R.str );

	printf("\n\n Notice that everything was changed in main() \n after function_arguments_by_reference() \n\n");


    return 0;
}
