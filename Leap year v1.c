/*

	Leap year v1.c

	With function leapYear()

C program to check if a given year is leap year or not:

Rule 1. Every fourth year is a leap.

Rule 2. The exception to Rule 1 is that every hundredth year is not a leap.

Rule 3. The exception to Rule 2 is that every 400th year is a leap.

*/

#include <stdio.h>

// Returns 1 if year is leap, otherwise returns 0.
int leapYear(int year)
{
    // Return true if year is a multiple of 4 and not multiple of 100.
    // OR year is multiple of 400.
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int main(void)
{
    int i, year;

    printf("\n Enter the year: ");
    scanf("%d", &year);

    for(i=year-10;i<=year+10;i++)
        if( leapYear(i) )
            printf("\n %d. is a leapYear \n",i);
        else
            printf("\n %d. isn't a leapYear \n",i);

    printf("\n\n");

    return 0;
}
