/*

array of 10 integers v1.c

Write a program that reads in 10 integers, then
(The numbers here are just an example):

Prints out the lowest value:
Minimum: 5
Prints out the highest value:
Maximum: 12
Prints out the sum of all the values
Sum: 78
Prints out the average (make sure you use %g with printf to round properly):
Average: 15.6
Prints out the numbers, sorted
Sorted: 1 4 5
Prints out the median
Median: 4.2
Requirements: Minimum, maximum, sum, average and median must be
calculated using separate functions you write, not directly in main.
Here how the sum function could look like (more in the lecture):

int sum(int numbers[], int count)
{
...
}

The functions must be called:

minimum with return type int
maximum with return type int
sum with return type int
average with return type float
median with return type float

Approach: Try to work on one part at a time, same as last week.
I recommend starting with reading in ten numbers and printing them back
to make sure that part is working before you continue.
Then write functions for each calculation (sum etc.) one at a time.
Don’t start on multiple things at once, build often, test often!

Tip: For the sorting have a look at qsort,
which already exists in the standard library.
You should be able to find an example that use it easily.
If you want to sort manually then bubble sort might be the easiest.

*/

#include <stdio.h>
#include <limits.h>	// For INT_MAX and INT_MIN

// Function to print array
void ShowArray(char text[],int arr[],int n)
{
    int i;

    printf("\n%s",text);
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


// function to sort the array in ascending order
void Array_sort(int *array , int n)
{
    int i=0 , j=0 , temp=0;			// declare some local variables

    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
            if(array[j]>array[j+1])	// swap array[j] and array[j+1]
            {
                temp        = array[j];
                array[j]    = array[j+1];
                array[j+1]  = temp;
            }
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


// Main program to test above functions
int main(void)
{	// Loading 10 elements of array is boring, so let's put it this way
	int arr[] = {12,13,1,10,34,2,25,8,17,5};	// try different one
	int n = sizeof(arr)/sizeof(arr[0]);		// a way to get n, number of elements in array
	int i;

	printf("\n Array arr[] has n = %d elements. \n", n);	// print number of elements in array

	ShowArray(" Array is: ",arr,n);

	printf("\n\n The smallest integer in array is %d \n",minimum(arr,n));

	printf("\n The largest integer in array is %d \n",maximum(arr,n));

	printf("\n The sum of all integers in array is %d \n",sum(arr,n));

	printf("\n The average of all integers in array is %f \n",average(arr,n));

	Array_sort(arr,n);

	ShowArray("\n Array sorted by bubble sort is: \n\n",arr,n);

	printf("\n The median of all integers in array is %f \n",median(arr,n));


	return 0;
}
