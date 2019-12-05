/*

	even or odd number v1.c

	With function evenNumber()

Even number is divisible by 2.

*/

#include <stdio.h>

// Returns 1 if number is even, otherwise if number is odd returns 0.
int evenNumber(int number)
{
    // Even number is divisible by 2
    if (number % 2 == 0)
        return 1;
    else
        return 0;
}

int main(void)
{
    int i, number;

    printf("\n Enter the number: ");
    scanf("%d", &number);

    for(i=number-10; i<=number+10; i++)
        if( evenNumber(i) )
            printf("\n %d. is even \n",i);
        else
            printf("\n %d. is odd0 \n",i);

    printf("\n\n");

    return 0;
}
