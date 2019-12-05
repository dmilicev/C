/*

prime numbers between a and b v1.c

Write a subroutine in programming language C that determine
whether the given number is prime number.

Write a program that at a given interval [a, b]
counts how many prime numbers there are.

*/

#include <stdio.h>
#include <math.h>   				// because we use sqrt()

int Number_of_iterations;			// global variable, counter of iterations

// Function:
// If the number is prime, function returns that number, otherwise returns 0
int IsPrimeNumber_1(int number)
{
    int i;							// counter for loop
									// i<number !!!
    for(i=2; i<number; i++)			// it is enough to go to the number !
        if(number % i == 0)			// if the number is divisible by i,
            return 0;				// it is not prime number

    Number_of_iterations=i;			// global variable, counter of iterations
    return number;					// number is prime number
}


// Better function:
// If the number is prime, function returns that number, otherwise returns 0
int IsPrimeNumber_2(int number)
{
    int i;							// counter for loop
									// i<=number/2 !!!
    for(i=2; i<=number/2; i++)		// it is enough to go to the number/2 !
        if(number % i == 0)			// if the number is divisible by i,
            return 0;				// it is not prime number

    Number_of_iterations=i;			// global variable, counter of iterations
    return number;					// number is prime number
}


// Best function, least iterations:
// If the number is prime, function returns that number, otherwise returns 0
int IsPrimeNumber_3(int number)
{
    int i;							// counter for loop
									// i<=sqrt(number) !!!
    for(i=2; i<=sqrt(number); i++) 	// it is enough to go to the root of the number !
        if(number % i == 0)			// if the number is divisible by i,
            return 0;				// it is not prime number

    Number_of_iterations=i;			// global variable, counter of iterations
    return number;					// number is prime number
}


int main(void)
{									//  low and high are the limits of the interval
    int i,low,high,number,sum_of_prime_numbers,prime_numbers_counter;

    printf("\n\n Enter the limits of the interval low high : ");
    scanf("%d %d",&low,&high);


    printf("\n\n Function IsPrimeNumber_1 :\n");
    printf("\n Prime numbers in interval [%d,%d] are: \n\n",low,high);

	sum_of_prime_numbers=0;			// reset counter
	prime_numbers_counter=0;		// reset counter
	Number_of_iterations=0;			// reset counter

    for(i=low;i<=high;i++)
        if( IsPrimeNumber_1(i) ) {  // if number is prime number
            printf("%4d ",i);
            sum_of_prime_numbers = sum_of_prime_numbers + i;
            prime_numbers_counter++;
        }

    printf("\n\n Sum of %d prime numbers in interval [%d,%d] is %d \n",
			prime_numbers_counter,low,high,sum_of_prime_numbers);

    printf("\n Function IsPrimeNumber_1 executed %d iterations. \n",
			Number_of_iterations);



    printf("\n\n Function IsPrimeNumber_2 :\n");
    printf("\n Prime numbers in interval [%d,%d] are: \n\n",low,high);

	sum_of_prime_numbers=0;			// reset counter
	prime_numbers_counter=0;		// reset counter
	Number_of_iterations=0;			// reset counter

    for(i=low;i<=high;i++)
        if( IsPrimeNumber_2(i) ) {  // if number is prime number
            printf("%4d ",i);
            sum_of_prime_numbers = sum_of_prime_numbers + i;
            prime_numbers_counter++;
        }

    printf("\n\n Sum of %d prime numbers in interval [%d,%d] is %d \n",
			prime_numbers_counter,low,high,sum_of_prime_numbers);

    printf("\n Function IsPrimeNumber_2 executed %d iterations. \n",
			Number_of_iterations);



    printf("\n\n Function IsPrimeNumber_3 :\n");
    printf("\n Prime numbers in interval [%d,%d] are: \n\n",low,high);

	sum_of_prime_numbers=0;			// reset counter
	prime_numbers_counter=0;		// reset counter
	Number_of_iterations=0;			// reset counter

    for(i=low;i<=high;i++)
        if( IsPrimeNumber_3(i) ) {  // if number is prime number
            printf("%4d ",i);
            sum_of_prime_numbers = sum_of_prime_numbers + i;
            prime_numbers_counter++;
        }

    printf("\n\n Sum of %d prime numbers in interval [%d,%d] is %d \n",
			prime_numbers_counter,low,high,sum_of_prime_numbers);

    printf("\n Function IsPrimeNumber_3 executed %d iterations. \n",
			Number_of_iterations);


    return 0;
}
