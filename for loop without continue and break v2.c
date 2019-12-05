/*
	Better solution :

	for loop without continue and break v2.c

*/

#include "stdio.h"

int main(void)
{
	int i, n=15, min=5, max=10, counter=0;

	printf("\n min = %d , max = %d , n = %d \n\n", min, max, n);

	for (i=0; i<n; i++)
	{
		if( i<min || i>max )
		{
			printf("\n i = %2d , continued \n",i);
		}
		else
		{
			counter++;
			printf("\n i = %2d		counter %2d.		* \n", i, counter);
		}
	}

	return 0;
}
