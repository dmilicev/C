/*
	command line arguments v2.c


	Janaidah Dora's tricky question:

	https://www.facebook.com/JanaidahAndor

	How do you make a program by using do-while or if-else
	by inputing 10 integers and by just declaring one variable.

	Loops must have their own counter and this is the only one
	variable that must be declared.

	Jark Clim,
	https://www.facebook.com/metallicsoul92

	gave me an idea for solving this tricky task.
	The idea is to use the command line arguments,
	which we write when invoking a program,
	to accommodate our 10 variables.

  Command line arguments: main(int argc, char *argv[])

  Do not forget first to compile this program
  and then run exe file from command line,
  exactly with quotes, like this:

  "command line arguments v2.exe" 1 2 3 4 5 6 7 8 9 10

  Exe file name is in quotes because
  name has several words separated by space

  We have to write arguments  1 2 3 4 5 6 7 8 9 10
  to reserve memory space.

  Maybe someone else will have a better solution...

*/


#include <stdio.h>
#include <stdlib.h>		// for function atoi()

int main(int argc, char *argv[])
{
	int i;			// this is the only one declared variable


	if(argc==1){	// if there is no command line arguments

		printf(	"\n Do not forget first to compile this program \n"
				"\n and then run exe file from command line \n"
				"\n exactly with quotes, like this: \n\n"

				"\n \"command line arguments v2.exe\" 1 2 3 4 5 6 7 8 9 10 \n\n"

				"\n Exe file name is in quotes because \n"
				"\n name has several words separated by space. \n\n"
				"\n We have to write arguments  1 2 3 4 5 6 7 8 9 10 \n"
				"\n to reserve memory space. \n\n"
			  );

		printf("\n\n Press any key to exit. \n");
		getch();	// to pause screen
		return 1;	// exit because there is no command line arguments
	}

					// if there are command line arguments:
	printf("\n Number of command line arguments passed, argc = %2d \n", argc);

	for ( i = 0 ; i < argc ; i++)
	  printf("\n %2d. command line argument passed is %2s \n", i, argv[i]);

	for ( i = 1 ; i < argc ; i++)
	{
	  printf("\n Enter %2d. integer ", i);
	  scanf("%s",argv[i]);
	}

	printf("\n\n\t Entered %2d integers are: \n", argc-1);

	// argv[i] are strings ( char *argv[] ) and we have to convert them to integers
	for ( i = 1 ; i < argc; i++)
	{
		printf("\n\n %2d. integer = %2d", i, atoi(argv[i]) );

	}


	printf("\n\n Press any key to exit. \n");
	getch();	// to pause screen

	return 0;
}
