/*

  Command line arguments: main(int argc, char *argv[])

  Compile program and run exe file like this:

  "command line arguments v1.exe" first second third

*/


#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	printf("\n Number of command line arguments passed: %d \n", argc);

	for ( i = 0 ; i < argc ; i++)
	  printf("\n %d. command line argument passed is %s \n", i+1, argv[i]);


	getch();	// to pause screen

	return 0;
}
