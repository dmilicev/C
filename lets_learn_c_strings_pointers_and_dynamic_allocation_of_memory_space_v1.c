/*

 c_strings_pointers_and_dynamic_allocation_of_memory_space.c

The idea is that this program should cover everything about strings,
pointers and dynamic allocation of memory space.

The program has many comments because it is intended for beginners.

I want to encourage beginners in programming to study this program
regardless of the fact that it consists of almost 1000 lines.
Half of these lines belong to the comments and explanations.

The point of the functions is to divide a big problem
into several smaller problems.
Each function should solve only one problem and nothing more.
Functions should therefore not have more than a couple dozen lines of code.
The features of the functions are arguments (parameters, input values)
and the value returned by the function to the part of the program
from which it was called.
If we pass to the function the pointers to the variables as arguments,
function then has the ability to change the value of the arguments
beyond its scope, and in that case it does not even have to have
its own return value.
Our conversations should soon come down to questions about how to write
a function that receives those arguments and has that return value.

Please understand that English is not my native language and
please feel free to correct me about it.

Feel free to let me know if you think I left out something about it,
or if you find some bugs in this program.

This program will be updated according to your suggestions.

Author Dragan Milicev
https://www.facebook.com/dmilicev
You can find all my C programs at Dragan Milicev's pastebin:
https://pastebin.com/u/dmilicev

An example of C strings
https://www.tutorialspoint.com/cprogramming/c_strings.htm

An example of dynamically allocating memory space
https://www.tutorialspoint.com/cprogramming/c_memory_management.htm

An example of working with pointers, explanation of **variable.
https://www.tutorialspoint.com/cprogramming/c_pointers.htm

// While * means the address of a variable in C programming language,
// what does ** mean then?
// https://www.quora.com/While-*-means-the-address-of-a-variable-in-C-programming-language-what-does-**-mean-then#
// **x is a pointer to a pointer:
//  *x points to an address
// **x is the value at that address.

int *ptr1;
means to declare "pointer to int 'ptr1', where ptr1 is the name of the pointer.
int **ptr2;
means to declare "pointer to pointer to int 'ptr2'." ptr2 still only holds one address in it.
What the stars signify is that the address in ptr2 points to another address,
which you may want to dereference to get a value, or put a value.


// ----------Functions for working with characters (ctype.h)-----------------

int isalpha(int c)
// checks if the passed character is alphabetic (letter)
https://www.tutorialspoint.com/c_standard_library/c_function_isalpha.htm

int isdigit(int c)
// checks if the passed character is a decimal digit character (digit)
https://www.tutorialspoint.com/c_standard_library/c_function_isdigit.htm

int isalnum(int c)
// checks if the passed character is alphanumeric (letter or digit)
https://www.tutorialspoint.com/c_standard_library/c_function_isalnum.htm

int isspace(char c)
// checks whether the passed character is white-space.
// examines whether c is any of the following characters:
// ' ' , '\t' , '\n' , '\v' , '\f' , '\r'
https://www.tutorialspoint.com/c_standard_library/c_function_isspace.htm

int isupper(int c)
// checks whether the passed character is uppercase letter (capital letter)
https://www.tutorialspoint.com/c_standard_library/c_function_isupper.htm

int islower(int c)
// checks whether the passed character is a lowercase letter
https://www.tutorialspoint.com/c_standard_library/c_function_islower.htm

int ispunct(int c)
// checks whether the passed character is a punctuation character.
// A punctuation character is any graphic character (as in isgraph)
// that is not alphanumeric (as in isalnum).
https://www.tutorialspoint.com/c_standard_library/c_function_ispunct.htm

int tolower(int c)
// converts a given letter to lowercase
https://www.tutorialspoint.com/c_standard_library/c_function_tolower.htm

int toupper(int c)
// converts lowercase letter to uppercase
https://www.tutorialspoint.com/c_standard_library/c_function_toupper.htm


// ----------Functions for working with strings (string.h)-------------------

char *strcpy(char *dest, const char *src)
// copies the string pointed to, by src to dest,
// assuming in advance that there is enough space in string dest	!!! VERY IMPORTANT !!!
https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm
If the destination of the strcpy call doesn't have enough memory
to contain the result, strcpy cals lead to severe bugs.

char *strcat(char *dest, const char *src)
// appends the string pointed to by src to the end of the string pointed to by dest
// assuming in advance that there is enough space in string dest	!!! VERY IMPORTANT !!!
// (ConcATenate)
https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm
Implementation of strcat()
https://www.programiz.com/c-programming/examples/concatenate-string
If the destination of the strcat call doesn't have enough memory
to contain the result, strcat cals lead to severe bugs.
A better example of using strcat is to allocate an array dynamically.
https://www.stev.org/post/csomesimpleexamplesofusingstrcat

char *strncat(char *dest, const char *src, size_t n)
// appends the string pointed to by src to the end of the string
// pointed to by dest up to n characters long
// dest is pointer to the destination array, which should contain a C string,
// and should be large enough to contain the concatenated resulting string
// which includes the additional null-character.	!!! VERY IMPORTANT !!!
https://www.tutorialspoint.com/c_standard_library/c_function_strncat.htm

int strcmp(const char *str1, const char *str2)
// compares the string pointed to, by str1 to the string pointed to by str2.
// compares strings a and b and returns:
                //  -1 if a<b
                //   0 if a=b
                //   1 if a>b
// (CoMPare)
https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm

int strncmp(const char *str1, const char *str2, size_t n)
//  compares at most the first n bytes of str1 and str2.
https://www.tutorialspoint.com/c_standard_library/c_function_strncmp.htm

int strcmpi(const char * str1, const char * str2 )
// same as strcmp function
// only that all the letters are converted to lowercase for comparison
https://www.geeksforgeeks.org/strcmpi-function-in-c/

char *strchr(const char *str, int c)
// searches for the first occurrence of the character c (an unsigned char)
// in the string pointed to by the argument str.
// returns a pointer to the first occurrence of the character c in the string str,
// or NULL if the character is not found.
https://www.tutorialspoint.com/c_standard_library/c_function_strchr.htm

char *strstr(const char *haystack, const char *needle)
// finds the first occurrence of the substring needle in the string haystack.
// The terminating '\0' characters are not compared.
https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm

size_t strlen(const char *str)
// computes the length of the string str up to,
// but not including the terminating null character.
// (LENght)
https://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm

char *strpbrk(const char *str1, const char *str2)
// finds the first character in the string str1 that matches any character
// specified in str2. This does not include the terminating null-characters.
// If there are none, return NULL.
https://www.tutorialspoint.com/c_standard_library/c_function_strpbrk.htm


// ----------Functions for dynamic allocation of memory space----------------

void *malloc(size_t size)
// allocates the requested memory and returns a pointer to it.
https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm

void *calloc(size_t nitems, size_t size)
// allocates the requested memory and returns a pointer to it.
// The difference in malloc and calloc is that malloc does not set
// the memory to zero where as calloc sets allocated memory to zero.
https://www.tutorialspoint.com/c_standard_library/c_function_calloc.htm

void *realloc(void *ptr, size_t size)
//attempts to resize the memory block pointed to by ptr that was
// previously allocated with a call to malloc or calloc.
https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm

void free(void *ptr)
// golden rule - for every call to malloc, there should be a corresponding free
// deallocates the memory previously allocated by a call to calloc, malloc, or realloc.
https://www.tutorialspoint.com/c_standard_library/c_function_free.htm

// ----------Begin of program------------------------------------------------

*/


#include <stdio.h>
#include <stdlib.h>     // for malloc(), calloc(), realloc(), free()
#include <conio.h>      // for _getch() i _getche()
#include <string.h>     // for string functions
#include <ctype.h>      // for char functions

#define MAX_SIZE 100


// choice_1, copy string source to string destination
// string_copy() is a safe function because it takes care that
// the destination string has enough memory space
// to be copied to it the entire source string
char *string_copy( char **destination, char **source ) {

// Pointers ...
// While * means the address of a variable in C programming language,
// what does ** mean then?
// https://www.quora.com/While-*-means-the-address-of-a-variable-in-C-programming-language-what-does-**-mean-then#
// **x is a pointer to a pointer:
//  *x points to an address
// **x is the value at that address.
// We use ** destination to allow this function
// to change the value of the destination variable
// in the part of the program from which it was called.

// !!! VERY IMPORTANT NOTE !!!
// function strcpy() copies the source to destination,
// assuming in advance that there is enough space
// in destination for whole source.

// In our example, this is not the case.

// We are copying source to destination and because of that,
// and we don't need a value of destination any more.
// Because of that, we can to perform dynamic allocation of memory space
// of destination to fit the entire source.
// Let's do it:

    *destination = (char *)malloc( strlen( *source ) + 2 * sizeof(source) );

// *destination is value of **destination.
// After allocating memory space, it must be checked that allocation has succeeded!
// If malloc() returned a value of NULL, this is an indication of a failed allocation.

    if( *destination == NULL )
    {
        fprintf(stderr, "\n\n malloc() error! \n\n");
        exit(EXIT_FAILURE);
    }

// Only now the pointer *destination points to a memory space
// large enough to fit the entire *source
// and only now can we copy *source to *destination

	strcpy( *destination, *source );

	return ( *destination );
}


// choice_2, concatenate source to destination
// string_concatenate() is a safe function because it takes care that
// the destination string has enough memory space
// to be copied to it the entire source string and destination string
char *string_concatenate( char **destination, char **source ) {

// Pointers ...
// While * means the address of a variable in C programming language,
// what does ** mean then?
// https://www.quora.com/While-*-means-the-address-of-a-variable-in-C-programming-language-what-does-**-mean-then#
// **x is a pointer to a pointer:
//  *x points to an address
// **x is the value at that address.
// We use **destination to allow this function
// to change the value of the variable destination
// in the part of the program from which it was called.

// !!! VERY IMPORTANT NOTE !!!
// function strcat() concatenate source to destination,
// assuming in advance that there is enough space
// in destination to fit destination and source.

// In our example, this is not the case, and so

// We are concatenate source to destination,
// and we need a value of destination.
// Because of that, let's first declare a new variable mem_string_1
// which does not currently point to anything, so we initialize it to NULL.

	char *mem_string_1 = NULL;

// Pointer mem_string_1 points to a memory space of 0 bytes.
// We want it to point to a memory space of sufficient size to store destination

	mem_string_1 = malloc( strlen(*destination) + 1 * sizeof(**destination) );

// Instead of counting the characters in the new string, we use function strlen().
// Let's check if dynamic memory allocation for variable mem_string_1 succeeded

	if (mem_string_1 == NULL)
	{
		fprintf(stderr, "\n\n malloc() error ! \n\n");
		exit(EXIT_FAILURE);
	}

// Let's remember value of destination in the new variable mem_string_1
// ( instead of standard function strcpy() we may use our safe function
// string_copy() and in that case there is no need to worry about
// the destination having enough memory for the entire source
// and in that case you can ignore (put in comment or delete)
// the following code lines that are between // -------------------- //)

	strcpy(mem_string_1, *destination);

// ----------------------------------------------------------------------- //

// *destination is value of **destination.
// *destination means value that is on the address destination.
// Now we have value of *destination in mem_string_1,
// so we can perform dynamic memory reallocation for destination

// Let's expand the memory space of variable destination with dynamic memory allocation
// to fit value of destination and value of source
// There are two ways to do this:

	// *destination = malloc( strlen(*destination) + strlen(*source) + 1 * sizeof(**destination) );

// or

	*destination = realloc( *destination, strlen(*destination) + strlen(*source) + 1 * sizeof(**destination) );

// Let's check if dynamic memory allocation for variable mem_string_1 succeeded

	if (*destination == NULL)
	{
		fprintf(stderr, "\n\n malloc() or realloc() error ! \n\n");
		exit(EXIT_FAILURE);
	}

// ----------------------------------------------------------------------- //


// Let's return the value from mem_string_1 to the extended *destination

	strcpy( *destination, mem_string_1 );


// Let's concatenate the value of *source to *destination

	strcat(*destination, *source);

// The mem_string_1 variable is no longer needed, so remember to free up it's memory space !

	free(mem_string_1);	// golden rule - for every call to malloc, there should be a corresponding free

	return( *destination );
}


// choice_3, concatenate n characters of source to destination
// string_n_concatenate() is a safe function because it takes care that
// the destination string has enough memory space to be copied to it
// the entire source string and first n characters of destination string
char *string_n_concatenate( char **destination, char **source, int n ) {

// Pointers ...
// While * means the address of a variable in C programming language,
// what does ** mean then?
// https://www.quora.com/While-*-means-the-address-of-a-variable-in-C-programming-language-what-does-**-mean-then#
// **x is a pointer to a pointer:
//  *x points to an address
// **x is the value at that address.
// We use **destination to allow this function
// to change the value of the variable destination
// in the part of the program from which it was called.

// !!! VERY IMPORTANT NOTE !!!
// function strncat() appends the string pointed to by src to the end of the string
// pointed to by dest up to n characters long.
// dest is pointer to the destination array, which should contain a C string,
// and should be large enough to contain the concatenated resulting string
// which includes the additional null-character.	!!! VERY IMPORTANT !!!

// In our example, this is not the case, and so

// We are concatenate first n characters from source to destination,
// and we need a value of destination.
// Because of that, let's first declare a new variable mem_string_1
// which does not currently point to anything, so we initialize it to NULL.

	char *mem_string_1 = NULL;

// Pointer mem_string_1 points to a memory space of 0 bytes.
// We want it to point to a memory space of sufficient size to store destination

	mem_string_1 = malloc( strlen(*destination) + 1 * sizeof(**destination) );

// Instead of counting the characters in the new string, we use function strlen().
// Let's check if dynamic memory allocation for variable mem_string_1 succeeded

	if (mem_string_1 == NULL)
	{
		fprintf(stderr, "\n\n malloc() error ! \n\n");
		exit(EXIT_FAILURE);
	}

// Let's remember value of destination in the new variable mem_string_1

	strcpy(mem_string_1, *destination);

// *destination means value that is on the address destination.
// Now we have value of *destination in mem_string_1,
// so let's expand the memory space of variable destination with dynamic memory allocation
// to fit value of destination and first n characters from source
// There are two ways to do this:

	//*destination = malloc( strlen(*destination) + n * sizeof(**source) );

// or

	*destination = realloc( *destination, strlen(*destination) + n * sizeof(**source) );

// Let's check if dynamic memory allocation for variable mem_string_1 succeeded

	if (*destination == NULL)
	{
		fprintf(stderr, "\n\n malloc() or realloc() error ! \n\n");
		exit(EXIT_FAILURE);
	}

// Let's return the value from mem_string_1 to the extended *destination

	strcpy(*destination, mem_string_1);

// Concatenate first n characters of *source to *destination

	strncat(*destination, *source, (size_t)n );

// The mem_string_1 variable is no longer needed, so remember to free up it's memory space !

	free(mem_string_1);	// golden rule - for every call to malloc, there should be a corresponding free

	return( *destination );
}


// choice_7, convert upper case to lower case and vice versa with own meny
// argument char *string_1 is not necessary
void choice_7( char *string_1, char *string_2 ) {

    int i=0;
    char choice;

  printf("\n\n 1. Convert uppercase and lowercase in string_2 ");
    printf("\n 2. Convert string_2 to lowercase ");
    printf("\n 3. Convert string_2 to uppercase ");
  printf("\n\n    Choose (1-3)  ?  ");

    choice = _getche();

    switch(choice) {
        case '1':						// Convert uppercase and lowercase in string_2

            while( string_2[i] != '\0') {
                if ( isupper(string_2[i] ))
                    string_2[i] = tolower( string_2[i] );
                else
                    string_2[i] = toupper( string_2[i] );

                i++;
            }
            break;

        case '2':						// Convert string_2 to lowercase
            while( string_2[i] != '\0') {
                if ( isupper(string_2[i] ))
                    string_2[i] = tolower( string_2[i] );

                i++;
            }
            break;

        case '3':						// Convert string_2 to uppercase

            while( string_2[i] != '\0') {
                if ( islower(string_2[i] ))
                    string_2[i] = toupper( string_2[i] );
                i++;
            }
            break;

        default:
            printf("\n\n You have to choose (1-3) ! \n\n");
    }
}


// choice_8, character testing in string_2
// argument char *string_1 is not necessary
void choice_8( char *string_1, char *string_2 ) {

    int i=0;

//`` This is for displaying all ascii characters,
// for example of working with pointers
// and for example of dynamically allocating memory space.
// Turn off next lines for default string_2		( put next lines in comment / *      * /  )
// Note that such nested comments are not allowed !
// Also don't forget to put in comment line at the end of this function
//	free(p_all_ascii_characters);

// We declare pointer p_all_ascii_characters which does not currently point to anything,
// so we initialize it to NULL.
	char *p_all_ascii_characters = NULL;

// Pointer p_all_ascii_characters points to a memory space of 0 bytes.
// We want it to point to a memory space of sufficient size to place
// our string with all ascii characters in that memory space.
// That is why we dynamically allocate such space (there are two ways to do that):

// 1. we need to reserve memory space
// Instead of counting the characters in the new string, we use function strlen().

	p_all_ascii_characters = (char *)malloc( strlen( "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:""zxcvbnm,./ZXCVBNM<>? ┘░▒▓" ) + 2 );

// 2. or we need to reallocate (change) memory space
// Instead of counting the characters in the new string, we use function strlen().

	//p_all_ascii_characters = (char *)realloc( (char *)p_all_ascii_characters, strlen( "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:""zxcvbnm,./ZXCVBNM<>? ┘░▒▓" ) + 2 );

// After allocating memory space, it must be checked that allocation has succeeded !
// If malloc() or realloc() returned a value of NULL, this is an indication of a failed allocation.

    if( p_all_ascii_characters == NULL )
    {
        fprintf(stderr, "\n\n malloc() or realloc() error ! \n\n");
        exit(EXIT_FAILURE);
    }

// The memory space whose address is pointer p_all_ascii_characters can now be filled with our string
    strcpy( p_all_ascii_characters, "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:""zxcvbnm,./ZXCVBNM<>? ┘░▒▓" );

// let string_2 point to that same memory space p_all_ascii_characters

    string_2 = p_all_ascii_characters;

// Now is
// string_2 = "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:""zxcvbnm,./ZXCVBNM<>? ┘░▒▓"
// but this is only in this function because string_2 is here a local variable.
// When we exit this function, string_2 will again have its old value,
// which it had before calling this function.
// This is a property of a local variable.

//`` This was for displaying all ascii characters,
// for example of working with pointers
// and for example of dynamically allocating memory space.
// Turn off above lines for default string_2	( put them in comment / *      * /  )
// Also don't forget to put in comment line at the end of this function
//	free(p_all_ascii_characters);

    printf("\n\n");

    while( string_2[i] != '\0' ) {
        if(isalpha( string_2[i] ) )
            printf("\n  %4d   %c  letter \n", string_2[i], string_2[i] );
        else if( isdigit( string_2[i] ) )
            printf("\n  %4d   %c  digit \n", string_2[i], string_2[i] );
        else if(isalnum(string_2[i]))
            printf("\n  %4d   %c  letter or digit \n", string_2[i],  string_2[i] );
        else if(isspace(string_2[i]))
            printf("\n  %4d   %c   space \n", string_2[i], string_2[i] );
        else if(isupper(string_2[i]))
            printf("\n  %4d   %c  capital letter \n", string_2[i], string_2[i] );
        else if(islower(string_2[i]))
            printf("\n  %4d   %c  lowercase letter \n", string_2[i], string_2[i] );
        else if(ispunct(string_2[i]))
            printf("\n  %4d   %c  punctuation mark \n", string_2[i], string_2[i] );
        else
            printf("\n  %4d   %c  none of the above \n", string_2[i], string_2[i] );

        i++;
    }

    printf("\n\n");

// Don't forget to free up dynamically allocated memory space !
    free(p_all_ascii_characters); // golden rule - for every call to malloc, there should be a corresponding free

    system("PAUSE");
}



// The main meny
char meny( char *string_1, char *string_2 ) {

    int n, length_string_1, length_string_2;
    char which_string[MAX_SIZE];
    char ch;
    char choice;

    while( 1 ) {    // endless loop, press 0 or Escape to exit

        //system("CLS");          // clear (erase) console screen

        //length_string_1 = strlen(string_1);
        //length_string_2 = strlen(string_2);

        //printf("\n\n string_1 (%d): %s \n", length_string_1, string_1);
        //printf("\n string_2 (%d): %s \n", length_string_2, string_2);

//ruler
printf("\n                             1         2         3         4         5");
printf("\n    ruler           12345678901234567890123456789012345678901234567890");
    printf("\n p_string_1 (%2d) = |%s| ", strlen(string_1), string_1 );
    printf("\n p_string_2 (%2d) = |%s| ", strlen(string_2), string_2 );

    printf("\n\n +---------------------------------------------------------------------------+ \n");
        printf(" |           THE MAIN MENU                                                   | \n");
        printf(" +---------------------------------------------------------------------------+ \n");
        printf(" |  1.  Copy string_2 to string_1                                            | \n");
        printf(" |  2.  Concatenate string_2 to string_1                                     | \n");
        printf(" |  3.  Concatenate n characters of string_2 to string_1                     | \n");
        printf(" |  4.  Find the first occurrence of character c in string_2                 | \n");
        printf(" |  5.  Find the first occurrence of string t in string_2                    | \n");
        printf(" |  6.  Find the first occurrence of any character from string t in string_2 | \n");
        printf(" |  7.  Convert upper case to lower case and vice versa                      | \n");
        printf(" |  8.  Character testing in string_2                                        | \n");
        printf(" |  9.  Reset both strings to their initial values                           | \n");
        printf(" |  0.  End of work ( or Escape )                                            | \n");
        printf(" +---------------------------------------------------------------------------+ \n");
        printf("    Choose (0-9)  ?  ");

        switch( choice = _getche() ) {  // based on the choices we call the appropriate functions

            case '1' :      // Copy string_2 to string_1

// Arguments of function string_copy() are addresses of variables so that it can
// change them and keep that change even after exiting string_copy()

                    string_copy( &string_1, &string_2 );
                    break;

            case '2' :      // Concatenate string_2 to string_1

// Arguments of function string_concatenate() are addresses of variables so that it can
// change them and keep that change even after exiting string_concatenate()

                    string_concatenate( &string_1, &string_2 );
                    break;

            case '3' :      // Concatenate n characters of string_2 to string_1

                    printf("\n\n How many characters from string_2 do you want to concatenate to string_1 ? ");
                    scanf("%d", &n);

// Arguments of function string_n_concatenate() are addresses of variables so that it can
// change them and keep that change even after exiting string_n_concatenate()

                    string_n_concatenate( &string_1, &string_2, n );
                    break;

            case '4' :      // Find the first occurrence of character c in string_2

                    printf("\n\n What character are you looking for in string_2  ?   ");
                    scanf("%c", &ch);
                    strcpy( string_1, strchr( string_2, ch ) );
                    break;

            case '5' :      // Find the first occurrence of string t in string_2

                    printf("\n\n What string are you looking for in string_2  ?   ");
                    scanf("%s", which_string);
                    strcpy(string_1, strstr( string_2, which_string ) );
                    break;

            case '6' :      // Find the first occurrence of any character from string t in string_2    // choice_6

                    printf("\n\n Enter the string with the characters you are looking for in string_2  ?   ");
                    scanf("%s", which_string);
                    strcpy(string_1, strpbrk(string_2, which_string ) );
                    break;

            case '7' :      // Convert upper case to lower case and vice versa with own meny

                    choice_7( string_1, string_2 );
                    break;

            case '8' :      // Character testing in string_2

                    choice_8( string_1, string_2 );
                    break;

            case '9' :      // Reset both strings to their initial values

                    strcpy( string_1, "First string.");
                    strcpy( string_2, "My name is Dragan Milicev.");
                    break;

            case '0' :    	// End of work ( 0 )

                    printf(" The key %c , code %d , is pressed \n\n", choice , choice);
                    return(choice);
                    break;

            case 27  :  	// End of work ( Escape )

                    printf(" The Escape key whose code is %d , is pressed \n\n", choice );
                    return(choice);
                    break;

            case  0  : 	 	// if a function key is pressed

                    choice = _getche(); 	// let's empty that 0
                    printf(" The function key %c , code %d , is pressed \n\n", choice, choice );
                    system("PAUSE");
                    break;

            case -32 :   	// if a special function key is pressed

                    choice = _getche(); 	// let's empty that 0 or -32
                    printf(" The special function key %c , code %d , is pressed \n\n", choice, choice );
                    system("PAUSE");
                    break;

            default:

                    printf(" The key %c , code %d , is pressed \n\n", choice , choice);
                    if( choice < '0' || choice > '9' ) {	// if no digit is entered
                        printf("\n\n You have to choose (0-9) !!! \n\n");
                        system("PAUSE");
                    }
                    break;

        } // end of switch( choice )

    } // end of while( 1 )

    return(choice);
}





int main(void) {

	printf("\n LET'S LEARN C STRINGS, POINTERS AND DYNAMIC ALLOCATION OF MEMORY SPACE \n");

// p_string_1 is a pointer to char, which does not currently point to anything.
// So we initialize it to NULL. Same p_string_2.
    char *p_string_1 = NULL;
    char *p_string_2 = NULL;

// Example of dynamic allocation of memory space for 10 characters (here not necessary)
    // p_string_1 = (char *) malloc( 10 * sizeof(char) );
    // p_string_2 = (char *) malloc( 10 * sizeof(char) );

// Because we want to copy 14 characters into the first string "First string." ( 14th is '\0'),
// we need to make or reallocate (change) memory space.
// Instead of counting the characters in the new string, we use function strlen().

    p_string_1 = (char *)malloc( strlen( "First string." ) + 2 * sizeof(char) );

// or

    //p_string_1 = (char *)realloc( (char *)p_string_1, strlen( "First string." ) + 2 );

// We want to copy 27 characters into the second string "My name is Dragan Milicev." ( 27th is '\0'),
// we need to make or reallocate (change) memory space.
// Instead of counting the characters in the new string, we use function strlen().

    p_string_2 = (char *)malloc( strlen( "My name is Dragan Milicev." ) + 2 * sizeof(char) );

// or

    //p_string_2 = (char *)realloc ( (char *)p_string_2, strlen( "My name is Dragan Milicev." ) + 2 );

// After allocating memory space, it must be checked that allocation has succeeded!
// If malloc returned a value of NULL, this is an indication of a failed allocation.

    if( p_string_1 == NULL )
    {
        fprintf(stderr, "\n\n malloc() or realloc() error! \n\n");
        exit(EXIT_FAILURE);
    }

    if( p_string_2 == NULL )
    {
        fprintf(stderr, "\n\n malloc() or realloc() error! \n\n");
        exit(EXIT_FAILURE);
    }

// We now have a reserved memory space large enough to fit our strings.
// Let's put them in:

    strcpy( p_string_1, "First string." );
    strcpy( p_string_2, "My name is Dragan Milicev." );

// and start our work with them:

	meny( p_string_1, p_string_2 );      // we invoke the main program meny

// Don't forget to free up dynamically allocated memory space !
// golden rule - for every call to malloc, there should be a corresponding free
    free( p_string_1 );
    free( p_string_2 );

    return 0;
}
