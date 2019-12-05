// C program to reverse an integer array

#include <stdio.h>

// show array
void ShowArray( int array[],int n )
{
    int i;

    printf("\n\n");

    for(i=0;i<n;i++)
    {
	    printf("%3d", array[i]);
    }
}

void ReverseArray(int array[],int n)
{
	int i,mem;
	for(i=0;i<n/2;i++)
    {
	    mem = array[i];
		array[i] = array[n-i-1];
		array[n-i-1] = mem;
    }
}

int main(void)
{
	int array[]={1,2,3,4,5,6,7,8,9,10};
	int NumberOfArrayElements;

	NumberOfArrayElements = sizeof(array)/sizeof(int);

	printf("\n\n Array is : ");
	ShowArray(array,NumberOfArrayElements);

	ReverseArray(array,NumberOfArrayElements);

	printf("\n\n Reverse array is : ");
	ShowArray(array,NumberOfArrayElements);

	printf("\n\n");
    return 0;
}
