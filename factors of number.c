#include "stdio.h"

int main(void)
{
	int number, i, sum=0;

	printf("\n Enter a positive integer: ");
	scanf("%d",&number);

	if(number>0)
	{
		printf("\n Factors of %d are: ", number);

		for(i=1; i<=number; i++)
		{
			if (number%i == 0)
			{
				printf("%d ",i);
				sum+=i;
			}
		}

		if( sum>i+1 )
			printf("\n%d is a composite number",number);
		if(sum<=i+1)
			printf("\n%d is a prime number",number);
	}

	return 0;
}
