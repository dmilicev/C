/*
	for loop increment decrement operators v1.c

	Corrected code.

I understood the misunderstanding and corrected my code to make it clearer.

i is loop counter,
numberOfPasses is the loop execution counter.

These are different things.

Notice that their values are displayed as they are inside the loop body.

	for ( i=0 ; i++ < 10 )

	for ( i=0 ; ++i <=10 )

What is the difference between these two for loops?

What will be the outcome of this?

In C program, Code::Blocks reports error:
expected ';' before ')' token

because there is no increment part in for loops.

for ( init; condition; increment )
{
   statement(s);
}

for loop must have two ; between brackets ()
	for( ; ; )

So let's write like this

	for ( i=0 ; i++ < 10 ; )

	for ( i=0 ; ++i <=10 ; )

or

	for ( i=0 ; i < 10 ; i++ )

	for ( i=0 ; i <= 10 ; ++i )

Let's write simple printfs that will answer these questions.

We have debugger, but this is simlpliest and fastest way to find answers.

Let's use this method in the future to find the answers ourselves.

Look this:

https://www.2braces.com/c-questions/for-loop-questions-c-3

*/

#include "stdio.h"

int main(void)
{
	// i is loop counter, numberOfPasses is the loop execution counter
	int i, numberOfPasses;

	printf("\n");
	numberOfPasses = 0;			// reset numberOfPasses for next counting

	for ( i=0 ; i++ < 10 ; )
	{
		numberOfPasses++;		// we count passes through loop
		printf("\n 1. for loop: i = %2d  ,  numberOfPasses = %2d", i, numberOfPasses);
	}

	printf("\n");
	numberOfPasses = 0;			// reset numberOfPasses for next counting

	for ( i=0 ; ++i <=10 ; )
	{
		numberOfPasses++;		// we count passes through loop
		printf("\n 2. for loop: i = %2d  ,  numberOfPasses = %2d", i, numberOfPasses);
	}

	printf("\n");
	numberOfPasses = 0;			// reset numberOfPasses for next counting

	for ( i=0 ; i < 10 ; i++ )
	{
		numberOfPasses++;		// we count passes through loop
		printf("\n 3. for loop: i = %2d  ,  numberOfPasses = %2d", i, numberOfPasses);
	}

	printf("\n");
	numberOfPasses = 0;			// reset numberOfPasses for next counting

	for ( i=0 ; i <= 10 ; ++i )
	{
		numberOfPasses++;		// we count passes through loop
		printf("\n 4. for loop: i = %2d  ,  numberOfPasses = %2d", i, numberOfPasses);
	}

	printf("\n");

	return 0;
}
