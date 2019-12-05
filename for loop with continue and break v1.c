/*

	for loop with continue and break v1.c

 Problems arise if we change the loop counter within the loop itself !

 See version 2 for better solution :

	for loop without continue and break v2.c

*/

#include "stdio.h"

int main(void)
{
	int i, n=15, min=5, max=10, counter=0;

	printf("\n min = %d , max = %d , n = %d \n\n", min, max, n);

	for (i=0; i<n; i++)
	{
		while( (i<min || i>max) && i<n )
		{
			printf("\n i = %2d , continued \n",i);

			i++;		// go to next i
			continue;	// do nothing
		}

		if(i>n-1)		// exit from for loop
			break;

		counter++;
		printf("\n i = %2d		counter %2d.		* \n", i, counter);
	}

	return 0;
}
