/*

	generator_of_random_numbers_v1.c

	Generate random integer numbers between lower and upper, including them.


	https://www.geeksforgeeks.org/generating-random-number-range-c/


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

	https://www.facebook.com/dmilicev

*/

#include <stdio.h>
#include <time.h>			// for random numbers, for function rand()
//#include <stlib.h>		// RAND_MAX is defined in stdlib.h


// generate and return random integer number between lower and upper, including them.
int get_random_integer_from_lower_to_uppper(int lower, int upper)
{
	// generate and return random number between 0 and upper-1
	//return( rand() % upper );

	// generate and return random number between 1 and upper
	//return( rand() % upper + 1 );

	// generate and return random integer number between lower and upper
	return( (rand() % (upper - lower + 1)) + lower );
}


int main()
{
	int i;
	time_t t;	// for random number generator, don't forget to #include <time.h>

    // Intializes random number generator, should only be called once!
	srand((unsigned) time(&t));

	for(i=0;i<20;i++)		// print 20 random integers to test function
		printf("\n random number: %2d ", get_random_integer_from_lower_to_uppper(1,10) );


    return 0;
}
