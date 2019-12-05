/*

	array_of_even_and_odd_integers_v1.c

	Task from Adlah Faqih
	https://web.facebook.com/ElFaqih312
	https://web.facebook.com/groups/programmingcgroup/permalink/469167800377949/

Write a C program that asks the user to enter 15 integer numbers
from the keyboard and stores them in an array.
Then separate even and odd numbers of the array.
Put all even numbers first, and then odd numbers.
Print the new array.

Example:

Original array: 1 3 4 5 6 7 8 10 5 13 50 43 44 70 33

Output: 4 6 8 10 50 44 70 1 3 5 7 5 13 43 33


Solution from:
https://www.geeksforgeeks.org/segregate-even-and-odd-numbers/


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>

// Displays an array of n integers
void display_array_of_integers( char text[], int array[], int n ) {

    int i;

    printf("\n\n%s ( size = %d )\n\n", text, n );

    for( i=0; i<n ; i++ )				// display of array items
        printf("%4d", array[i] );

    printf("\n");
}

// Function to swap two integers, with pointers
// https://www.geeksforgeeks.org/c-program-swap-two-numbers/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// return 1 if x is even, otherwise return 0
int IsEven( int x )
{
	if( x%2 == 0 )	// if x even number
		return 1;
	else
		return 0;
}

// Puts all even numbers first, and then odd numbers.
void first_even_then_odd_numbers( int arr[], int n )
{
    int left=0, right=n-1;							// Initialize left and right indexes
													// to first left and last right element
    while ( left<right)								// until they meet
    {
        while ( IsEven(arr[left]) && left<right )	// Increment left index while is even arr[left]
            left++;

        while ( !IsEven(arr[right]) && left<right ) // Decrement right index while is odd arr[right]
            right--;

        if ( left<right )							// if they did not meet
        {
            swap( &arr[left], &arr[right] );		// Swap arr[left] and arr[right]
            left++;									// we reduce the scope
            right--;
        }
    }
}

// Puts all odd numbers first, and then even numbers.
void first_odd_then_even_numbers( int arr[], int n )
{
    int left=0, right=n-1;							// Initialize left and right indexes
													// to first left and last right element
    while ( left<right)								// until they meet
    {
        while ( !IsEven(arr[left]) && left<right )	// Increment left index while is odd arr[left]
            left++;

        while ( IsEven(arr[right]) && left<right )  // Decrement right index while is even arr[right]
            right--;

        if ( left<right )							// if they did not meet
        {
            swap( &arr[left], &arr[right] );		// Swap arr[left] and arr[right]
            left++;									// we reduce the scope
            right--;
        }
    }
}


int main(void)
{
	int array[]={ 1, 3, 4, 5, 6, 7, 8, 10, 5, 13, 50, 43, 44, 70, 33 };
	int n = sizeof(array)/sizeof(array[0]);

	display_array_of_integers("\n Given array is: ", array, n );

	first_odd_then_even_numbers( array, n );
	display_array_of_integers("\n first odd then even array is: ", array, n );

	first_even_then_odd_numbers( array, n );
	display_array_of_integers("\n first even then odd array is: ", array, n );


    return 0;
}
