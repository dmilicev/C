/*

sorting array of integers v1.c

Sorting array of integers in different ways,
in ascending or descending order

- Bubble sort

- Selection sort

- Insertion sort

- quick sort

*/

#include <stdio.h>
#include <limits.h>	// For INT_MAX and INT_MIN
#include <time.h>	// for random numbers, for function rand()

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

// Function to print three smallest elements
void print3smallest(int arr[], int arr_size)
{
	int i, first, second, third;

	if (arr_size < 3)
	{
		printf("\n Invalid input. There should be atleast three elements in array. \n");
		return;
	}

// 1) Initialize the smallest three elements as plus infinite.
//    first = second = third = +Infinity

	first = second = third = INT_MAX;

	printf("\n How algorithm work: \n");
	printf("\n  i  arr[i]       first     second        third \n");	// header

// 2) Iterate through all elements of array.

	for (i = 0; i < arr_size ; i ++)
	{
		if (arr[i] < first)			// Let current array element be arr[i]
		{							// If current element is smaller than first
			third = second;			// then update third, second and first
			second = first;			// This order of assignment is important
			first = arr[i];
		}
		else if (arr[i] < second)	// If arr[i] is in between first and second
		{							// then update second
			third = second;
			second = arr[i];
		}
		else if (arr[i] < third)	// If arr[i] smaller then third
			third = arr[i];			// then update third

		// print how algorithm work
		printf("\n %2d  %4d %12d  %12d  %12d \n",i,arr[i],first,second,third);
	}

// 3) Print first, second and third.

	printf("\n Three smallest elements are: %3d %3d %3d \n", first, second, third);
}


// function returns the smallest element of the array of arr_size integers
int minimum(int arr[], int arr_size)
{
	// Let's suppose that the smallest element of array is the largest possible integer
	int i, smallest=INT_MAX;

	for (i = 0; i < arr_size ; i++)	// we go through the whole arrray
		if (arr[i] < smallest)		// if current element arr[i] is smaller than smallest
			smallest=arr[i];		// then arr[i] becomes the smallest

	return smallest;
}


// function returns the largest element of the array of arr_size integers
int maximum(int arr[], int arr_size)
{
	// Let's suppose that the largest element of array is the smallest possible integer
	int i, largest=INT_MIN;

	for (i = 0; i < arr_size ; i++)	// we go through the whole arrray
		if (arr[i] > largest)		// if current element arr[i] is larger than largest
			largest=arr[i];			// then arr[i] becomes the largest

	return largest;
}


// function returns the sum of all elements of the array of arr_size integers
int sum(int arr[], int arr_size)
{
	int i, sum=0;	// The starting value of the sum is zero

	for (i = 0; i < arr_size ; i++)	// we go through the whole arrray
		sum=sum+arr[i];				// new sum is old sum plus current element arr[i]

	return sum;
}


// function returns the average of all elements of the array of arr_size integers
float average(int arr[], int arr_size)
{
	int i, sum=0;	// The starting value of the sum is zero
	float average;

	for (i = 0; i < arr_size ; i++)	// we go through the whole arrray
		sum=sum+arr[i];				// new sum is old sum plus current element arr[i]

	average=sum/arr_size;

	return average;
}


// function to calculate the median of the array
float median(int array[],int n)
{
    float median=0;

    // if number of elements are even
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    // if number of elements are odd
    else
        median = array[n/2];

    return median;
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


// function selectionSort to sort the array in ascending order
// https://www.geeksforgeeks.org/selection-sort/
void selectionSort(int arr[], int n)
{
    int i, j, min_index;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
		// Find the minimum element in unsorted array
        min_index = i;
        for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_index])	// arr[j] > arr[min_index] for descending order
				min_index = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
    }
}


// function insertionSort to sort the array in ascending order
// https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
	{
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key)	// arr[j] < key for descending order
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}


// comparator function for qsort
// https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/
int comparator_function_for_qsort(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );

//  return ( *(int*)b - *(int*)a );	// for descending order
}


void make_array_of_n_integers_beetween_min_and_max(int array[], int n, int min, int max)
{
	int i;

//int rand(void) creates a pseudo-random number in the range of 0 to RAND_MAX
//RAND_MAX is defined in stdlib.h and is the largest number rand will return (same as INT_MAX).	for (i=0; i<n; i++)

//	for positive and negative numbers beetween min and max

    for(i=0;i<n;i++)
		array[i] = (rand() % (max + 1 - min)) + min;

//		array[i] = rand() % max;	// for only positive numbers beetween 0 and max
}


// Main program to test above functions
int main(void)
{
	int arr[10];						// array of 10 integers
	int n = sizeof(arr)/sizeof(arr[0]); // a way to get n, number of elements in array arr[]
	int i, min=-100, max=100;			// min and max are minimum and maximum value of random integers

	srand(time(NULL));	// Initialization for random numbers, should only be called once.

	make_array_of_n_integers_beetween_min_and_max(arr,n,min,max);

	// print number of elements in array, min and max
	printf("\n Array arr[] has n = %d integers between min = %d and max = %d \n", n, min, max);

	ShowArray("\n Unsorted array of random integers between min and max is: \n\n",arr,n);

	printf("\n\n The smallest integer in array is %d \n",minimum(arr,n));

	printf("\n The largest integer in array is %d \n",maximum(arr,n));

	printf("\n The sum of all integers in array is %d \n",sum(arr,n));

	printf("\n The average of all integers in array is %f \n",average(arr,n));

	printf("\n ------------------------------------------------------------ \n");

	bubbleSort(arr,n);

	ShowArray("\n Array sorted by bubble sort is: \n\n",arr,n);

	printf("\n The median of all integers in array is %f \n",median(arr,n));

	printf("\n ------------------------------------------------------------ \n");

// since the array is already sorted we need to recreate the unsorted array
	make_array_of_n_integers_beetween_min_and_max(arr,n,min,max);

	ShowArray("\n Unsorted array of random integers between min and max is: \n\n",arr,n);

	selectionSort(arr,n);

	ShowArray("\n Array sorted by selection sort is: \n\n",arr,n);

	printf("\n ------------------------------------------------------------ \n");

// since the array is already sorted we need to recreate the unsorted array
	make_array_of_n_integers_beetween_min_and_max(arr,n,min,max);

	ShowArray("\n Unsorted array of random integers between min and max is: \n\n",arr,n);

	insertionSort(arr,n);

	ShowArray("\n Array sorted by insertion sort is: \n\n",arr,n);

	printf("\n ------------------------------------------------------------ \n");

// since the array is already sorted we need to recreate the unsorted array
	make_array_of_n_integers_beetween_min_and_max(arr,n,min,max);

	ShowArray("\n Unsorted array of random integers between min and max is: \n\n",arr,n);

	qsort(arr, n, sizeof(int), comparator_function_for_qsort);

	ShowArray("\n Array sorted by qsort is: \n\n",arr,n);

	printf("\n ------------------------------------------------------------ \n");


	return 0;
}
