/*

	print speed in c v1.c

	https://cboard.cprogramming.com/c-programming/143087-what-fastest-printing-console.html

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

/* Pack sieve array.  Don't encode even numbers, and start the array
 * with 3, the first non-even prime.  If you count 1 as prime, it can
 * be added as a special case like 2 below so it doesn't mess up the
 * mapping.
 * Next step is to pack from 1 character per prime to 1 bit per prime.
 * Since longs are 32 bits, divide again by 32 to get the word index and mask
 * off the low 5 bits (0-31) to get the amount to shift to find the bit
 * which corresponds to a given prime.
 */
#define WORD_FROM_VAL(x) (((x) - 3)/ 64)
#define BIT_FROM_VAL(x)  ((((x) -3)/ 2) & 0x1f)

#define PRIME_5_MILLION 86028121
int arr[5000000];
int size=PRIME_5_MILLION/(2 * sizeof(unsigned long) * CHAR_BIT);

int main() {
   double start,end;
   int q;
   start=clock();
   int i,j,m=0;
   int sieve_end = floor(sqrt(PRIME_5_MILLION)+0.1);

   unsigned long *sieve = calloc(size, sizeof(unsigned long));

   /* Up to 50,000 numbers to test, each up to 7 digits plus \r\n (or \n depending
    * on OS, but don't worry too much about an extra 50KB) */
   char *input = malloc (50001 * 9 + 1);
   char *output = malloc (50000 * 10 + 1);

   int curr_prime;
   for (curr_prime = 3; curr_prime <= sieve_end; curr_prime += 2)
   {
      if (!(sieve[WORD_FROM_VAL(curr_prime)] & (1UL << BIT_FROM_VAL(curr_prime))))
      {
         for(j = curr_prime*curr_prime; j < PRIME_5_MILLION; j+=curr_prime*2)
         {
            sieve[WORD_FROM_VAL(j)] |= 1UL << BIT_FROM_VAL(j);
         }
      }
   }
   end=clock();
   printf("\n%f",(end-start)/CLOCKS_PER_SEC);
   start=clock();
   arr[m++] = 2; /* Special case for 2 */
   for (i=3; i<=PRIME_5_MILLION; i+=2) {
      if (!(sieve[WORD_FROM_VAL(i)] & (1UL << BIT_FROM_VAL(i))))
         arr[m++]=i;
   }
   free(sieve);
   end=clock();
   printf("\n%f\n",(end-start)/CLOCKS_PER_SEC);

   int rc = fread(input, 1, 50001*9+1, stdin);
   input[rc] = '\0';

   const char *inp = input;
   char *outp = output - 1;
   char *outp_saved = output;
   unsigned in_num;
   unsigned out_num;
   unsigned out_num2;

   /* Skip first number */
   while (!isdigit(*inp)) inp++;
   while ( isdigit(*inp)) inp++;

   while (*inp)
   {
      /* Skip CR-LF */
      while (*inp && !isdigit(*inp)) inp++;

      /* Convert string to unsigned int */
      for (in_num = 0;*inp && isdigit(*inp); inp += 1)
      {
         in_num *= 10;
         in_num += *inp - '0';
      }
      if (in_num)
      {
         /* Turn prime count into prime value */
         out_num = arr[in_num-1];

         /* Move output pointer ahead, print in reverse */
         for (out_num2 = out_num; out_num2; outp += 1)
            out_num2 /= 10;

         /* At end of space for number, add CR-LF pair */
         outp_saved = outp+1;
         *outp_saved = '\n';

         /* Print digits in reverse order from least to most significant
          * so when they're read normally order is correct */
         for ( ; out_num; out_num /= 10)
            *outp-- = (out_num % 10) + '0';
         outp = outp_saved;
      }
   }
   fwrite(output, 1, outp - output + 1, stdout);

   return 0;
}
