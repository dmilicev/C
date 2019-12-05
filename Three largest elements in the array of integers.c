// Find three largest elements in the array of integers without sorting array
// https://www.geeksforgeeks.org/find-the-largest-three-elements-in-an-array/
// This code is edited by Ayush Singla(@ayusin51) and Dragan Milicev (dmilicev@gmail.com)

#include <stdio.h>
#include <limits.h>	// For INT_MIN

// Function to print array
void ShowArray(char text[],int arr[],int n)
{
    int i;

    printf("\n%s",text);
    for(i=0;i<n;i++)
	    printf("%5d", arr[i]);

    printf("\n");
}

// Function to print three largest elements
void print3largest(int arr[], int arr_size)
{
	int i, first, second, third;

	if (arr_size < 3)
	{
		printf("\n Invalid input. There should be atleast three elements in array. \n");
		return;
	}

// 1) Initialize the largest three elements as minus infinite.
//    first = second = third = -Infinity

	first = second = third = INT_MIN;

	printf("\n How algorithm work: \n");		// print how algorithm work
	printf("\n  i  arr[i]       first     second        third \n");	// header

// 2) Iterate through all elements of array.

	for (i = 0; i < arr_size ; i ++)
	{
		if (arr[i] > first)			// Let current array element be arr[i]
		{							// If current element is greater than first
			third = second;			// then update third, second and first
			second = first;			// This order of assignment is important
			first = arr[i];
		}
		else if (arr[i] > second)	// If arr[i] is in between first and second then update second
		{
			third = second;
			second = arr[i];
		}
		else if (arr[i] > third)	// If arr[i] greater then third then update third
			third = arr[i];

		// print how algorithm work
		printf("\n %2d  %4d %12d  %12d  %12d \n",i,arr[i],first,second,third);
	}

// 3) Print first, second and third

	printf("\n Three largest elements are: %3d %3d %3d \n", first, second, third);
}


// Driver program to test above function
int main(void)
{
	int arr[] = {12, 13, 1, 10, 34, 5};		// try different one
//	int arr[]={9,2,7,7,8,6,5,1,3};
//	int arr[]={7,2,7,7,8,6,5,1,3};
//	int arr[]={4,2,9,7,8,6,5,1,9};
//	int arr[] = {1,1,1,1,1,1};
//  int arr[] = {1,1};
	int n = sizeof(arr)/sizeof(arr[0]);		// a way to get n, number of elements in array
	int i;

	printf(" n = %d \n", n);				// print number of elements in array

	ShowArray(" Array is: ",arr,n);

	print3largest(arr, n);					// print three largest elements in the array

	return 0;
}
