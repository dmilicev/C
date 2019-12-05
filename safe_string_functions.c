/*

	safe_string_functions.c		by Dragan Milicev


char *safe_strcpy( char **destination, const char *source )

char *safe_strcat( char **destination, const char *source )

char *safe_strncat( char **destination, const char *source, size_t n )


	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

	https://www.facebook.com/dmilicev

*/


#include <stdio.h>
#include <stdlib.h>     // for malloc(), calloc(), realloc(), free()
#include <string.h>     // for string functions


// safe_strcpy() is a safe function because it takes care that
// the destination string has enough memory space
// to be copied to it the entire source string
char *safe_strcpy( char **destination, const char *source )
{
	// Checking that destination has enough space for source + '\0'
	if( strlen(*destination) < strlen(source) + 1 )
		*destination = malloc( strlen(source) + 1 );

	// Checking whether memory reallocation succeeded
	if( *destination == NULL )
	{
		fprintf(stderr, "\n\n realloc() for destination error! \n\n");
		exit(EXIT_FAILURE);
	}

	strcpy( *destination, source );

	return *destination;
} // safe_strcpy()


// safe_strcat() is a safe function because it takes care that
// the destination string has enough memory space
// to be copied to it the entire source string and destination string
char *safe_strcat( char **destination, const char *source )
{
	char *mem_destination = NULL;

	// reserve memory space for the mem_destination string
	// to make room for source and destination string and '\0'
	mem_destination = malloc( strlen(source) + strlen(*destination) + sizeof(char) );

	// Checking whether memory reallocation succeeded
	if( mem_destination == NULL )
	{
		fprintf(stderr, "\n\n realloc() for mem_destination error! \n\n");
		exit(EXIT_FAILURE);
	}

	strcpy( mem_destination, *destination );
	strcat( mem_destination, source );

	*destination = mem_destination;

	return *destination;
} // safe_strcat()


// safe_strncat() is a safe function because it takes care that
// the destination string has enough memory space
// to be copied to it n characters of source string and '\0'
char *safe_strncat( char **destination, const char *source, size_t n )
{
	char *mem_destination = NULL;

	// reserve memory space for the mem_destination string
	// to make room for source and destination string and '\0'
	mem_destination = malloc( strlen(*destination) + n * sizeof(char) + 1 );

	// Checking whether memory reallocation succeeded
	if( mem_destination == NULL )
	{
		fprintf(stderr, "\n\n realloc() for mem_destination error! \n\n");
		exit(EXIT_FAILURE);
	}

	strcpy( mem_destination, *destination );
	strncat( mem_destination, source, n );

	*destination = mem_destination;

	return *destination;
} // safe_strncat()


int main()
{
	char *source = NULL;
	char *destination = NULL;
	int source_size = 20;
	int destination_size = 20;
	int source_len;
	int destination_len;

	printf("\n Safe C strings functions \n");

	printf("\n---------------------------------------------------------\n");

	printf("\n We reserve memory for source to %d \n", source_size );
	source = (char *) malloc((size_t)source_size);	// Initial memory allocation
	if( source == NULL )		// Checking whether memory allocation succeeded
	{
		fprintf(stderr, "\n\n malloc() for source error! \n\n");
		exit(EXIT_FAILURE);
	}

	printf("\n We reserve memory for destination to %d \n", destination_size );
	destination = (char *) malloc((size_t)destination_size);// Initial memory allocation
	if( destination == NULL )	// Checking whether memory allocation succeeded
	{
		fprintf(stderr, "\n\n malloc() for destination error! \n\n");
		exit(EXIT_FAILURE);
	}

	source_len = strlen(source);
	destination_len = strlen(destination);
	printf("\n main: source      (%2d): |%s| ", source_len, source );
	printf("\n main: destination (%2d): |%s| \n", destination_len, destination );


	printf("\n---------------------------------------------------------\n");
	printf("\n safe_strcpy(source, \"1234567890\") \n");

	safe_strcpy( &source, "1234567890" );	// Fill source

	source_len = strlen(source);
	destination_len = strlen(destination);
	printf("\n main: source      (%2d): |%s| ", source_len, source );
	printf("\n main: destination (%2d): |%s| \n", destination_len, destination );

	printf("\n safe_strcpy(destination, source) \n");
	safe_strcpy( &destination, source );	// Fill destination

	source_len = strlen(source);
	destination_len = strlen(destination);
	printf("\n main: source      (%2d): |%s| ", source_len, source );
	printf("\n main: destination (%2d): |%s| \n", destination_len, destination );

	printf("\n---------------------------------------------------------\n");
	printf("\n safe_strcat() function \n");

	printf("\n safe_strcpy(source, \"ABCDEFG\") \n");
	safe_strcpy( &source, "ABCDEFG" );	// Fill source

	printf("\n safe_strcat(destination, source) \n");
	safe_strcat( &destination, source );	// Fill destination

	source_len = strlen(source);
	destination_len = strlen(destination);
	printf("\n main: source      (%2d): |%s| ", source_len, source );
	printf("\n main: destination (%2d): |%s| \n", destination_len, destination );

	printf("\n---------------------------------------------------------\n");
	printf("\n safe_strncat() function \n");

	safe_strncat( &destination, source, 4 );

	source_len = strlen(source);
	destination_len = strlen(destination);
	printf("\n main: source      (%2d): |%s| ", source_len, source );
	printf("\n main: destination (%2d): |%s| \n", destination_len, destination );

	safe_strncat( &destination, "1234567890", 5 );

	source_len = strlen(source);
	destination_len = strlen(destination);
	printf("\n main: source      (%2d): |%s| ", source_len, source );
	printf("\n main: destination (%2d): |%s| \n", destination_len, destination );

	printf("\n---------------------------------------------------------\n");


	free(source);
	free(destination);

    return 0;
}

