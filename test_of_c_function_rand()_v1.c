/*

	test_of_c_function_rand()_v1.c


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>
#include <stdlib.h>			// for RAND_MAX = 32767
#include <time.h>			// for random numbers, for function rand()


int main()
{							// try n = 10, 100, 1000, RAND_MAX
							// try repeat_times = 1, 10, 100, 1000, RAND_MAX = 32767
	int i, j, n=100, repeat_times=RAND_MAX;
	int random_number, pass_of_loop=0, min_appearance, max_appearance;
	int counter_array[RAND_MAX];			// array to count frequency of random numbers
	time_t t;								// for random number generator


    // Intializes random number generator, should only be called once.
	//srand((unsigned) time(0));
	srand((unsigned) time(&t));

	// reset all n counters in counter_array[] to 0
	for( i=0; i<n; i++ )
		counter_array[i] = 0;

	// counting the pass_of_loop of random numbers
	for( j=0; j<repeat_times; j++ )
	{
		for( i=0; i<n; i++ )
		{
			random_number = rand() % n;		// random number between 0 and n-1
			counter_array[random_number]++;	// increase the corresponding counter
		}

		// count and display loop passes
		printf("\n %8d. pass of loop ", ++pass_of_loop);
	}


	// finding the lowest and highest pass_of_loop
	min_appearance = counter_array[0];			// we assume it is the smallest
	max_appearance = 0;							// we assume it is the largest

	for( i=0; i<n; i++ )
	{
		if( min_appearance > counter_array[i] )
			min_appearance = counter_array[i];

		if( max_appearance < counter_array[i] )
			max_appearance = counter_array[i];
	}


	// print the number of occurrences of random numbers
	for( i=0; i<n; i++ )
		printf("\n %7d %7d ", i, counter_array[i] );

	// print the lowest and highest frequency
	printf("\n\n highest frequency is %7d \n", max_appearance );
    printf("\n lowest frequency is  %7d \n", min_appearance );
	printf("\n %7d    - %7d = %5d \n",
			max_appearance, min_appearance, max_appearance - min_appearance );


    return 0;
}
