/*
	diamond
*/

#include <stdio.h>

int main(void)
{
	int i, j;
	int rows = 8;

	for (i = -rows + 1; i < rows; i++)
	{
		printf("%*s", abs(i), "");

		for (j = (rows - abs(i)) * 2 - 1; j > 0; j--)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
