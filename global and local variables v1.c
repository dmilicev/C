#include<stdio.h>

int a=2,b=5;	// global variables

int sum(int a)
{
	// in this function sum() a is local variable and a=3 because sum(3)
	printf("\n In function sum() \t a=%d \t b=%d \n",a,b);

	return a+b;	// b is global variable and b=5
}

int main()
{
	// global variables
	printf("\n In main() before calling function sum(3) \t a=%d \t b=%d \n",a,b);

	// corrected quotes "%x"
	printf("\n Result is %d \n", sum(3));

	// global variables
	printf("\n In main(), after calling function sum(3) \t a=%d \t b=%d \n",a,b);

	return 0;
}
