/*

	two_increment_operators_in_one_command_v1.c

	It’s a sequence error and the compiler can choose to do
	whatever it wants with the results.

	RULE:

	Don’t change the value of a variable more than once
	within the same sequence point.

*/

#include<stdio.h>

int main(void)
{
	int x=10;

	printf("\n\n     x = %d ", x);
	printf("\n 1.  x, x++     %d   %d ", x, x++);

	x=10;
	printf("\n\n     x = %d ", x);
	printf("\n 2.  x, ++x     %d   %d ", x, ++x);

	x=10;
	printf("\n\n     x = %d ", x);
	printf("\n 3.  ++x, x     %d   %d ", ++x, x);

	x=10;
	printf("\n\n     x = %d ", x);
	printf("\n 4.  x++, x     %d   %d ", x++, x);

	x=10;
	printf("\n\n     x = %d ", x);
	printf("\n 5.  x++, x++   %d   %d ", x++, x++);

	x=10;
	printf("\n\n     x = %d ", x);
	printf("\n 6.  ++x, ++x   %d   %d ", ++x, ++x);

	x=10;
	printf("\n\n     x = %d ", x);
	printf("\n 7.  ++x, x++   %d   %d ", ++x, x++);

	x=10;
	printf("\n\n     x = %d ", x);
	printf("\n 8.  x++, ++x   %d   %d \n", x++, ++x);


	return 0;
}
