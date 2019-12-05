#include <stdio.h>

int main()
{
int lim,term,nal,ject;
char terminator;

printf("\n Enter a prelim: ");

// On success, the function scanf() returns the number
// of items of the argument list successfully read.
// If scanf didn't read two elements, integer and char, and return 2
// or if second element terminator isn't enter '\n'
// then first element isn't integer.
if( scanf("%d%c", &lim, &terminator) != 2 || terminator != '\n' )
{
    printf("\n lim = %d is not an integer ! \n");
    return(1);
}

printf("\n Enter a midterm: ");

if( scanf("%d%c", &term, &terminator) != 2 || terminator != '\n' )
{
    printf("\n term = %d is not an integer ! \n");
    return(1);
}

printf("\n Enter a final: ");
if( scanf("%d%c", &nal, &terminator) != 2 || terminator != '\n' )
{
    printf("\n nal = %d is not an integer ! \n");
    return(1);
}

ject=(lim+term+(nal*2))/4;

printf("\n Subject grade:%d \n\n",ject);

if((ject<=96)&&(ject>=100))
{
printf("1.0");
}
else if((ject<=95)&&(ject>=94))
{
printf("remarks is 1.25");
}
else if((ject<=93)&&(ject>=92))
{
printf("remarks is 1.50");
}
else if((ject<=91)&&(ject>=89))
{
printf("remarks is 1.75");
}
else if((ject<=88)&&(ject>=87))
{
printf("remarks is 2.0");
}
else if((ject<=86)&&(ject>=84))
{
printf("remarks is 2.25");
}
else if((ject<=8)&&(ject>=80))
{
printf("remarks is 2.50");
}
else if((ject<=79)&&(ject>=78))
{
printf("remarks is 2.75");
}
else if((ject<=77)&&(ject>=75))
{
printf("remarks is 3.0");
}
else if(ject<=74)
{
printf("5.00");
}
else
{
printf("invalid key");
}

printf("\n\n");

return 0;

}
