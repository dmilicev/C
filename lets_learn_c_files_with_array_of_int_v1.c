/*

	lets_learn_c_files_with_array_of_int_v1.c

Work in C with text and binary files.

The idea is that this program should cover everything about
text and binary files in C.

 C work with files:

Write an array of integers into a text (txt) file.

Read array of integers from text (txt) file.


Write an array of integers into a binary (bin) file.

Read an array of integers from binary (bin) file.


The program has many comments because it is intended for beginners.

I want to encourage beginners in programming to study this program
regardless of the fact that it consists of many lines.
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

Feel free to let me know if you think I left out something,
or if you find some bugs in this program.

This program will be updated according to your suggestions.

Author Dragan Milicev
https://www.facebook.com/dmilicev
You can find all my C programs at Dragan Milicev's pastebin:
https://pastebin.com/u/dmilicev


----------Work with text and binary files in C-------------------------------


https://www.tutorialspoint.com/cprogramming/c_file_io.htm

https://www.tutorialspoint.com/ansi_c/c_working_with_files.htm


----------Writing a text file------------------------------------------------

int fputc(int char, FILE *stream)

Writes a character (an unsigned char) specified by the argument char
to the specified stream and advances the position indicator for the stream.

https://www.tutorialspoint.com/c_standard_library/c_function_fputc.htm

	FILE *fp;
	int ch;

	fputc(ch, fp);

-----------------------------

int fputs( const char *s, FILE *fp );

Writes the string s to the output stream referenced by fp,
but not including the null character.
It returns a non-negative value on success,
otherwise EOF is returned in case of any error.

https://www.tutorialspoint.com/c_standard_library/c_function_fputs.htm

	fputs("This is testing for fputs...\n", fp);

-----------------------------

You can use

int fprintf(FILE *fp,const char *format, ...)

function as well to write a string into a file.
Sends formatted output to a stream.

https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm

	fprintf(fp, "%s %s %s %d", "We", "are", "in", 2019);


----------Reading a text file------------------------------------------------

int fgetc(FILE *stream)

gets the next character (an unsigned char) from the specified stream
and advances the position indicator for the stream.

https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm

	int c;

	c = fgetc(fp);

-----------------------------

char *fgets(char *str, int n, FILE *stream)

reads a line from the specified stream
and stores it into the string pointed to by str.
It stops when either (n-1) characters are read,
the newline character is read,
or the end-of-file is reached, whichever comes first.

https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm

	char str[60];

	fgets (str, 60, fp);

-----------------------------

You can also use

int fscanf(FILE *fp, const char *format, ...)

function to read strings from a file,
but it stops reading after encountering the first space character.
Reads formatted input from a stream.

https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm

	char str1[10], str2[10], str3[10];
	int year;

	fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);



----------Closing a text or binary file--------------------------------------

int fclose(FILE *stream)
Closes the stream. All buffers are flushed.

https://www.tutorialspoint.com/c_standard_library/c_function_fclose.htm

FILE *fp;

fclose(fp);


----------Writing a binary file----------------------------------------------


size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)

or more clearly:

size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

Writes data from the array pointed to, by ptr to the given stream.

https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm

	FILE *fp;
	char str[] = "This is tutorialspoint.com";

	fwrite(str , 1 , sizeof(str) , fp );
	fflush( fp );

-----------------------------

int fflush(FILE *stream)
flushes the output buffer of a stream.

https://www.tutorialspoint.com/c_standard_library/c_function_fflush.htm



----------Reading a binary file----------------------------------------------

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

or more clearly:

size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

reads data from the given stream into the array pointed to, by ptr.

https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm

	FILE *fp;
	char c[] = "this is tutorialspoint";
	char buffer[100];

	fread(buffer, strlen(c)+1, 1, fp);



----------Walk through text or binary file-----------------------------------


long int ftell(FILE *stream)

Returns the current file position of the given stream.
Returns the current value of the position indicator.
If an error occurs, -1L is returned,
and the global variable errno is set to a positive value.

https://www.tutorialspoint.com/c_standard_library/c_function_ftell.htm

    FILE *fp;
    int len;    // or	long int len;

    len = ftell(fp);

-----------------------------------------------------------------------------

int fseek(FILE *stream, long int offset, int whence)

sets the file position of the stream to the given offset.

https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm

offset is the number of bytes to offset from whence.

whence is the position from where offset is added.
It is specified by one of the following constants:

0 SEEK_SET	Beginning of file
1 SEEK_CUR	Current position of the file pointer
2 SEEK_END	End of file

	FILE *fp;

    fseek( fp, 7, SEEK_SET );


-----------------------------------------------------------------------------

void rewind(FILE *stream)

sets the file position to the beginning of the file of the given stream.

https://www.tutorialspoint.com/c_standard_library/c_function_rewind.htm

	FILE *fp;

	rewind(fp);


-----------------------------------------------------------------------------

*/


#include <stdio.h>
#include<stdlib.h>			// for exit()


// print array arr[] of n integers
void print_array( char text[], int arr[], int n )
{
    int i;

    printf("\n\n%s", text );
    for( i=0; i<n; i++ ) {
        printf(" %d", arr[i] );
    }
    printf("\n");
}


void write_to_text_file_array_of_integers( char FileName[], int arr[], int n )
{
    FILE *p_file;
    int i;

    p_file = fopen(FileName, "w");

    if( p_file == NULL ) {
        printf("\n Error opening output text file ! \n");
        exit(1);
    }

	printf("\n");

    // we write one by one integer from array in a text file
    for( i=0; i<n; i++ ) {
		printf("\n Writing to a text file %s  arr[%d] = %d ", FileName, i, arr[i] );
        fprintf( p_file, "%d ", arr[i] );
    }

    fclose(p_file);
}


void read_from_text_file_array_of_integers( char FileName[], int arr[], int n )
{
    FILE *p_file;
    int i;

    p_file = fopen(FileName, "r");

    if( p_file == NULL ) {
        printf("\n Error opening input text file ! \n");
        exit(1);
    }

	printf("\n");

    // we read one by one integer from text file to array of integers arr[]
    for( i=0; i<n; i++ ) {
        fscanf( p_file, "%d ", &arr[i] );	// it must be the same format as when writing
        printf("\n Read from text file %s  arr[%d] = %d", FileName, i, arr[i] );
    }

    fclose(p_file);
}


void write_to_binary_file_array_of_integers( char FileName[], int arr[], int n )
{
    FILE *p_file;
    int i=0;    	// = 0 is required !!!

    p_file = fopen(FileName, "wb");

    if( p_file == NULL ) {
        printf("\n Error opening input binary file ! \n");
        exit(1);
    }

/*
    // we write one by one integers from array arr[] to the binary file
    for( i=0; i<n; i++ ) {
        printf("\n Writing to a binary file arr[%d] = %d", i,arr[i] );
        fwrite( &arr[i], sizeof(arr[i]), 1, p_file );
    }
*/

    // at once we write the whole arr[] of n integers into the binary file
    fwrite( &arr[i], sizeof(arr[i]), n, p_file );
	fflush(p_file);	// when writing to file, it is obligatory fflush !!!

    fclose(p_file);
}


void read_from_binary_file_array_of_integers( char FileName[], int arr[], int n )
{
    FILE *p_file;
    int i=0;    	// = 0 is required !!!

    p_file = fopen(FileName, "rb");

    if( p_file == NULL ) {
        printf("\n Error opening input binary file ! \n");
        exit(1);
    }

/*

IMPORTANT !!!

The feof() function should not be called before attempting a read !
The following code may cause an error :

    while (!feof(p_file))
        fscanf( p_file, "%d", &number );

Code should be like this:

// We read the numbers from the file until we reach the end
// and print them to standard output:

    while( 1 ) {							// endless loop that breaks with break;

        int number;

        fscanf( p_file, "%d ", &number );  	// We are trying to read the number

											// We print the number we readed
        printf(" Readed from binary file : %d \n", number );

        if ( feof(p_file) )                 // If we reach the end of the file, we interrupt
			break;
    }
*/

/*
	// or:
    // we read one by one integer from binary file to array of integers arr[]
    while( 1 ) {    // endless loop that breaks with break;

        fread( &arr[i], sizeof(arr[i]), 1, p_file );
        printf("\n Read from binary file arr[%d] = %d ", i, arr[i] );
        i++;

		if ( feof(fp) )         	// If we reach the end of the file, we interrupt
			break;
    }
*/

/*
	// or:
    // we read one by one integer from binary file to array of integers arr[]
    for( i=0; i<n; i++ ) {
        fread( &arr[i], sizeof(int), 1, p_file );
        printf("\n Read from binary file arr[%d] = %d ", i, arr[i] );
    }
*/

    // we at once load all n integers in arr
    fread( arr, sizeof(arr), n, p_file );

    fclose(p_file);
}




int main(void)
{
    int arr_1[100] = {1,2,3,4};  // array of integers
    int arr_2[100] = {5,6,7,8};
    int n1 = 4;                 // number of integers in array of integers
    int n2 = 4;

// Text file:

    // write to text file array of integers
    write_to_text_file_array_of_integers( "arr_1.txt", arr_1, n1 );
    write_to_text_file_array_of_integers( "arr_2.txt", arr_2, n2 );

    // read from text file array of integers
    read_from_text_file_array_of_integers("arr_1.txt",arr_1,n1);
    read_from_text_file_array_of_integers("arr_2.txt",arr_2,n2);

    // print array
    print_array( " arr_1 from text file is: ", arr_1, n1 );
    print_array( " arr_2 from text file is: ", arr_2, n2 );


// Binary file:

    // write to binary file array of integers
    write_to_binary_file_array_of_integers( "arr_1.bin", arr_1, n1 );
    write_to_binary_file_array_of_integers( "arr_2.bin", arr_2, n2 );

    // read from binary file array of integers
    read_from_binary_file_array_of_integers( "arr_1.bin", arr_1, n1 );
    read_from_binary_file_array_of_integers( "arr_2.bin", arr_2, n2 );

    // print array
    print_array( " arr_1 from binary file is: ", arr_1, n1 );
    print_array( " arr_2 from binary file is: ", arr_2, n2 );


    printf("\n");
    return 0;
}
