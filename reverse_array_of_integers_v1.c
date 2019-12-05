/*

	reverse_array_of_integers_v1.c		by Dragan Milicev


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>


// Displays an arr of n integers
void display_array_of_integers( char text[], int arr[], int n ) {

    int i;

    printf("%s ( n = %d )\n\n", text, n );

    for( i=0; i<n ; i++ )	// display of n array items
        printf("%4d", arr[i] );

    printf("\n");
}

// swap two integers using pointers
void swap_two_integers( int *pointer_a, int *pointer_b )
{
    int mem_int;    		// memory to store integer

    mem_int = *pointer_a;
    *pointer_a = *pointer_b;
    *pointer_b = mem_int;
}

// reverse array of integers
void reverse_array_of_integers_1( int arr[], int n )
{
	int i, j, mem_int;	    // n is number of integers in arr[]

	// reverse array
	for( i=0,j=n-1; i<n/2; i++,j-- )
	{
		mem_int    = arr[i];
		arr[i]   = arr[j];
		arr[j] = mem_int;
	}
}

// reverse array of integers calling function swap_two_integers()
void reverse_array_of_integers_2( int arr[], int n )
{
	int i, j;

	// reverse array
	for( i=0,j=n-1; i<n/2; i++,j-- )
	{
        swap_two_integers( &arr[i], &arr[j] );
	}
}

int main()
{                                                       // n is number of integers in arr[]
	int i, j, n, mem_int;	                            // mem_int is memory to store integer
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };      // array of integers

	// a way to get n, number of elements in arr[]
	// ( This only works in main() because there is arr[] declared )

	//n = sizeof(arr) / sizeof(arr[0]);
	// or
	//n = sizeof(arr) / sizeof(*arr);
	// or
    n = sizeof(arr) / sizeof(int);

	display_array_of_integers( "\n Before:  ", arr, n );

	// reverse array
	for( i=0, j=n-1; i<n/2; i++,j-- )
	{
		mem_int = arr[i];
		arr[i] = arr[j];
		arr[j] = mem_int;
	}

    // Pointers ...
    // arr == &arr[0]
    // *arr == arr[0]
    // pointer_to_arr[i] == &arr[i]

	display_array_of_integers( "\n After:  ", arr, n );


	reverse_array_of_integers_1( arr, n );

	display_array_of_integers( "\n After calling function reverse_array_of_integers_1()  ", arr, n );


	reverse_array_of_integers_2( arr, n );

	display_array_of_integers( "\n After calling function reverse_array_of_integers_2()  ", arr, n );


    return 0;
}
