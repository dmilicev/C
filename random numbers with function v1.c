

https://www.geeksforgeeks.org/generating-random-number-range-c/
  num = (rand() % (upper – lower + 1)) + lower
  
  
  
  
  
/*
	random numbers with function v1.c

Necessary code lines to generate random numbers:

#include<stdlib.h>	// RAND_MAX is defined in stdlib.h
#include<time.h>	// for random number generator

in function main():

	time_t t;	// for random number generator

    // Intializes random number generator, should only be called once.
	srand((unsigned) time(&t));

	// function rand() returns an integer value between 0 and RAND_MAX.
	number = rand();

	number = rand() % 9 + 1;	// generate random number between 1 and 9

*/

#include<stdio.h>
#include<stdlib.h>	// RAND_MAX is defined in stdlib.h
#include<time.h>	// for random number generator

int getRandomNumberBetween1andMax(int max)
{
	return rand() % max +1;
}

int main(void)
{
	int i, number, j;
	time_t t;	// for random number generator

    // Intializes random number generator, should only be called once.
	srand((unsigned) time(&t));

	for(i=0; i<10; i++)				// repeat this 10 times
	{
		// number = rand() % 9 + 1;	// generate random number between 1 and 9
		number = getRandomNumberBetween1andMax(20);

		printf("\n number %d \n",number);
	}

	printf("\n");

	return(0);
}
