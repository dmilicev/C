/*

	passing_arguments_to_functions.c

	Passing arguments to functions by value and by reference.


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>


// int int_number is passed by reference
// int_number is the address (pointer) where the integer value is located
int function_2( int *int_number )
{
	int i;

	// display variable in function_2()
	printf("\n\n function_2(): display variable in function_2() \n");

	printf("\n function_2(): int_number = %d ", *int_number );

	// change variable in function_2()
	printf("\n\n function_2(): change variable in function_2() \n");

	// int_number is passed by reference, so value on address int_number become 2
	*int_number = 2;

	// display variable in function_2() after changing
	printf("\n\n function_2(): display variable after changing in function_2() \n");

	printf("\n function_2(): int_number = %d ", *int_number );

	printf("\n\n NOTICE that *int_number is changed in function_2() ! \n");


	printf("\n\n");

	return 0;

} // function_2()


// char array_of_characters[50] is passed by reference
// char array_of_strings[5][50] is passed by reference
// int array_of_int[3] is passed by reference
// int int_number is passed by value (will not be changed after returning from function)
int function( char array_of_characters[50],
			  char array_of_strings[5][50],
			  int array_of_int[3],
			  int int_number )
{
	int i;

	// display variables in function()
	printf("\n\n function(): display variables in function() \n");

	printf("\n function(): array_of_characters = |%s| ", array_of_characters );

	for(i=0;i<5;i++)
		printf("\n function(): array_of_strings[%d] = |%s| ", i, array_of_strings[i] );

	for(i=0;i<3;i++)
		printf("\n function(): array_of_int[%d] = %d ", i, array_of_int[i] );

	printf("\n function(): int_number = %d ", int_number );


	// call function_2() from function()
	printf("\n\n function(): call function_2() from function() \n");
	function_2( &int_number );

	// function(): display changed variable in function() after calling function_2()
	printf("\n\n function(): display changed variable in function() after calling function_2() \n");
	printf("\n function(): int_number = %d ", int_number );

	// function(): value int_number is changed by calling function_2()
	// but will not be changed in main because is passed to function() by value (not by reference)
	printf("\n\n function(): display changed variable in function() after calling function_2() \n");

	printf("\n\n function(): NOTICE value int_number is changed by calling function_2() \n but will not be changed in main \n because is passed to function() by value (not by reference) \n");


	// change variables in function()
	printf("\n\n function(): change variables in function() \n");

	sprintf(array_of_characters, "array_of_characters_changed_in_func_1");

	for(i=0;i<5;i++)
		sprintf(array_of_strings[i], "array_of_strings_%d_changed_in_func_1", i+2);

	for(i=0;i<3;i++)
		array_of_int[i] = 1 + i * i;

	int_number = 1;


	// function(): display changed variables in function()
	printf("\n\n function(): display changed variables in function() \n");

	printf("\n function(): array_of_characters = |%s| ", array_of_characters );

	for(i=0;i<5;i++)
		printf("\n function(): array_of_strings[%d] = |%s| ", i, array_of_strings[i] );

	for(i=0;i<3;i++)
		printf("\n function(): array_of_int[%d] = %d ", i, array_of_int[i] );

	printf("\n function(): int_number = %d ", int_number );

	printf("\n\n NOTICE that int_number is changed in function() ! \n");


	printf("\n\n");

	return 0;

} // function()



int main()
{
	char array_of_characters[50];	// one string, array of 50 characters
	char array_of_strings[5][50];	// 5 strings long 50 characters
	int array_of_int[3];			// array of 3 int numbers
	int int_number;					// one int number
	int i;

	// initialize variables in main()
	sprintf(array_of_characters, "User_name");

	for(i=0;i<5;i++)
		sprintf(array_of_strings[i], "User_%d", i+1);

	for(i=0;i<3;i++)
		array_of_int[i] = i * i;

	int_number = 0;

	// display variables in main()
	printf("\n\n main(): display variables in main() \n");

	printf("\n main(): array_of_characters = |%s| ", array_of_characters );

	for(i=0;i<5;i++)
		printf("\n main(): array_of_strings[%d] = |%s| ", i, array_of_strings[i] );

	for(i=0;i<3;i++)
		printf("\n main(): array_of_int[%d] = %d ", i, array_of_int[i] );

	printf("\n main(): int_number = %d ", int_number );


    // call function() from main() with arguments
	printf("\n\n main(): call function() from main() with arguments \n");
	function( array_of_characters,
			  array_of_strings,
			  array_of_int,
			  int_number );


	// main(): display variables after calling function() with arguments
	printf("\n\n main(): display variables after calling function() with arguments \n");

	printf("\n main(): array_of_characters = |%s| ", array_of_characters );

	for(i=0;i<5;i++)
		printf("\n main(): array_of_strings[%d] = |%s| ", i, array_of_strings[i] );

	for(i=0;i<3;i++)
		printf("\n main(): array_of_int[%d] = %d ", i, array_of_int[i] );

	printf("\n main(): int_number = %d ", int_number );

	printf("\n\n NOTICE that int_number isn't changed in main() after calling function() \n because it is passed to function() by value, not by reference ! \n");


    // call function_2() from main() with argument by reference (not by value)
	printf("\n\n main(): call function_2() from main() with argument by reference (not by value) \n");

    // int_number is passed by referenece (not by value)
	// &int_number is the address (pointer) where the integer value is located
	function_2( &int_number );


	// main(): display variable in main() after calling function_2() with argument passed by reference
	printf("\n\n main(): display variable in main() after calling function_2() \n with argument passed by reference \n");

	printf("\n main(): int_number = %d ", int_number );

	printf("\n\n NOTICE that in main() int_number is changed \n because it is passed to function_2() by reference, not by value ! \n");


	printf("\n\n");

    return 0;

} // main()
