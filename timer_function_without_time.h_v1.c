/*

	timer_function_without_time.h_v1.c		by Dragan Milicev

	Idea is to make timer function without the use of timer.h header file.

	In function
	void my_sleep( int milliseconds )
	I use 3 nested for loops i, j and k,
	to make the required time delay during the run.

	But, required time delay depends on the speed of your machine's processor.

	So I temporarily use header file time.h to set my function to the speed of my processor.
	You do the same.

	Setup:

	Important information for your computer processor is CLOCKS_PER_SEC.
	The program will print to you its value, which you will write
	instead of CLOCKS_PER_SEC in function my_sleep(milliseconds);

	main() is set to have a time delay of 10 seconds.

	Change the #define SETUP_NUMBER 400
	until you get an approximate time of 10,000 milliseconds.

	Write the resulting value of SETUP_NUMBER
	into the function my_sleep(milliseconds);

	After this setup, you will get the my_sleep(milliseconds);
	function which will work accurately enough on your computer
	without heder file time.h .


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

	https://www.facebook.com/dmilicev

*/

#include <stdio.h>
#include <time.h>

#define SETUP_NUMBER 400

void my_sleep( int milliseconds )
{
	int i, j, k;

	for(i=0; i<milliseconds; i++)
		for(j=0; j<SETUP_NUMBER; j++)
			for(k=0; k<CLOCKS_PER_SEC; k++);
}

int main () {

	clock_t start_t, end_t, total_t;
	int milliseconds = 10000;	// main() is set to have a time delay of 10 seconds.

	start_t = clock();

	printf("\n Starting of the my_sleep(%d) function, start_t = %ld \n", milliseconds, start_t );

	printf("\n Wait 10 seconds ... \n");

	my_sleep(milliseconds);		// to delay (wait, sleep) 10 seconds

	end_t = clock();

	printf("\n End of the my_sleep(%d) function, end_t = %ld \n", milliseconds, end_t );

	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

	printf("\n Total time taken by CPU: %ld \n", total_t  );

	printf("\n start_t = %ld \t end_t = %ld \t total_t = %ld \n", start_t, end_t, total_t  );

	printf("\n CLOCKS_PER_SEC = %5ld \n", CLOCKS_PER_SEC );

	printf("\n SETUP_NUMBER   = %5d \n", SETUP_NUMBER );


	return(0);
}
