/*
	merge_two_arrays_of_integers_v1.c

https://www.geeksforgeeks.org/merge-two-sorted-arrays/


You can find all my C programs at Dragan Milicev's pastebin:

https://pastebin.com/u/dmilicev

https://www.facebook.com/dmilicev

*/

#include <stdio.h>

// Function to print array, n is number of elements in array arr[]
// text[] describes the shown array arr[]
void ShowArray(char text[],int arr[],int n)
{
    int i;

    printf("%s",text);
    for(i=0;i<n;i++)
	    printf("%5d", arr[i]);

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

// function bubbleSort to sort the array in ascending order
// https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(int arr[], int n)
{
    int i, j;

    for (i = 0; i < n-1; i++)
		for (j = 0; j < n-i-1; j++)		// Last i elements are already in place
			if (arr[j] > arr[j+1])		// arr[j] < arr[j+1] for descending order
				swap(&arr[j], &arr[j+1]);
}

void merge_two_sorted_arrays_of_integers( int arr1[], int n1, int arr2[], int n2, int arr3[] )
{
	int i=0, j=0, k=0;				// indexes for arr1[i], arr2[j], arr3[k]

    while (i<n1 && j <n2) 			// Traverse both array
    {								// Check if current element of first array
        if (arr1[i] < arr2[j])		// is smaller than current element of second array.
            arr3[k++] = arr1[i++];	// If yes, store first array element and increment their indexes.
        else
            arr3[k++] = arr2[j++];	// Otherwise do same with second array.
    }

    while (i < n1)					// Store remaining elements of first array
        arr3[k++] = arr1[i++];

    while (j < n2)					// Store remaining elements of second array
        arr3[k++] = arr2[j++];
}


// Main program to test above functions
int main(void)
{
	int arr1[] = {2,4,1,3};
	int arr2[] = {7,9,8,6,10,5};
	int arr3[20];
	int n1 = sizeof(arr1)/sizeof(arr1[0]); 	// a way to get n1, number of elements in array arr1[]
	int n2 = sizeof(arr2)/sizeof(arr2[0]); 	// a way to get n2, number of elements in array arr2[]
	int n3 = n1+n2;							// a way to get n3, number of elements in array arr3[]

	// If arrays are not sorted, we need to sort them first
	ShowArray("\n Unsorted array arr1[] of integers is: \n\n", arr1, n1 );
	bubbleSort( arr1, n1 );
	ShowArray("\n Array arr1[] sorted by bubble sort is: \n\n", arr1, n1 );

	ShowArray("\n Unsorted array arr2[] of integers is: \n\n", arr2, n2 );
	bubbleSort( arr2, n2 );
	ShowArray("\n Array arr2[] sorted by bubble sort is: \n\n", arr2, n2 );

	// now we can merge two sorted arrays arr1[] and arr2[] in arr3[]
	merge_two_sorted_arrays_of_integers( arr1, n1, arr2, n2, arr3 );

	ShowArray("\n Merged array arr3[] of integers is: \n\n", arr3, n3);


	return 0;
}
