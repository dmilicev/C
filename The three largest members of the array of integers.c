#include <stdio.h>

void ShowArray(int a[],int n){
    int i;

    printf("\n");

    for(i=0;i<n;i++)
	    printf("%3d", a[i]);

    printf("\n");
}


void main(void){

    int a[]={4,2,9,7,8,6,5,1,3};			// the array we work with, try different one
    int n;                  				// n is the number of members of the array
	int Imax1=0, Imax2=0, Imax3=0;			// indexes of first three max elements
	int i,j;								// loop counters

	n = sizeof(a)/sizeof(int);			// way to get n

	ShowArray(a,n);

	for(j=0;j<2;j++){
		for(i=0;i<n;i++)
			if(a[Imax1]<a[i])
				Imax1=i;

		for(i=0;i<n;i++)
			if(Imax2!=Imax1 && a[Imax2]<a[i])
				Imax2=i;

		for(i=0;i<n;i++)
			if(Imax3!=Imax1 && Imax3!=Imax2 && a[Imax3]<a[i])
				Imax3=i;
	}

	printf("\n First three max elements are: %2d , %2d , %2d \n",a[Imax1],a[Imax2],a[Imax3]);
}
