/*

	decom.c		by 	Dragan Milicev

Detect and remove the comments in a C source file

	with

	detab.c		by 	Dragan Milicev

Removes whitespaces (space characters and tabs) from the end of lines in file
and replaces the remaining tabs with space characters.
Attention is paid to tab stops.

-----------------------------------------------------------------------------
Run from command line:
detab detab.c 4
-----------------------------------------------------------------------------
OUTPUT:

 In the input file "detab.c" are:

   16171 characters

     409 rows

     673 tabs that have been replaced with space

       0 spaces taken from the ends of rows

       0 removed tabs from the ends of rows

       0 removed whitespaces (space characters and tabs) from the ends of rows

 The output file is: "detab.c.txt"

Press any key to continue . . .
-----------------------------------------------------------------------------


Version with fgets() i fputs() and functions
trim_string_end()
detab_string()
detab_file().

The trim_string_end() function has been added to remove whiteness
(space and tabs) at the end of string s, and it counters
num_deleted_spaces,
num_replaced_tabs,
num_deleted_whiteness.

U main() se obradjuju argumenti programa (FileName.ekstenzija i tabWidth)
a funkciji detab_file() se prosledjuju imena ulaznog i izlaznog fajla, tabWidth
i pointeri na brojace karaktera, redova i tabulatora.

main() processes program arguments (FileName.extension and tabWidth)
and the names of the input and output files and tabWidth
are passed to the detab_file() function,
as well as pointers to counters of characters, lines and tabs.

The tab moves the cursor from its current position to the next tab stop.

tabWidth is the distance between two adjacent tab stops
expressed by the number of space characters.
Most often, tabWidth = 4, and can be 2, 4, 6, 8, or any other positive value.

If the tab is on the i-th line index,
is replaced by the appropriate number of space characters by formula:

	nb = tabWidth-(i%tabWidth)

to the next tab stop.

If tabWidth = 4, tab stops are on lines with indexes:

		  1		    2		  3		    4		  5		    6		  7		    8
012345678901234567890123456789012345678901234567890123456789012345678901234567890
	4	8	12	16	20	24	28	32	36	40	44	48	52	56	60	64	68	72	76  80 ... index

Integer division:
x%y = x	, 										if x<y
x%y = 0 ,										if x=y
x%y = an integer residue in division x with y,	if x>y

Tab on index i changes with nb = tabWidth-(i%tabWidth) space characters.
to get to the next tab stop:
index				       nb										           tab stop
   0, changes with tabWidth-(i%tabWidth) = 4-( 0%4) = 4-0 = 4 space to get to the  4. index
   1, changes with tabWidth-(i%tabWidth) = 4-( 1%4) = 4-1 = 3 space to get to the  4. index
   2, changes with tabWidth-(i%tabWidth) = 4-( 2%4) = 4-2 = 2 space to get to the  4. index
   3, changes with tabWidth-(i%tabWidth) = 4-( 3%4) = 4-3 = 1 space to get to the  4. index

   4, changes with tabWidth-(i%tabWidth) = 4-( 4%4) = 4-0 = 4 space to get to the  8. index
   5, changes with tabWidth-(i%tabWidth) = 4-( 5%4) = 4-1 = 3 space to get to the  8. index
   6, changes with tabWidth-(i%tabWidth) = 4-( 6%4) = 4-2 = 2 space to get to the  8. index
   7, changes with tabWidth-(i%tabWidth) = 4-( 7%4) = 4-3 = 1 space to get to the  8. index

   8, changes with tabWidth-(i%tabWidth) = 4-( 8%4) = 4-0 = 4 space to get to the 12. index
   9, changes with tabWidth-(i%tabWidth) = 4-( 9%4) = 4-1 = 3 space to get to the 12. index
  10, changes with tabWidth-(i%tabWidth) = 4-(10%4) = 4-2 = 2 space to get to the 12. index
  11, changes with tabWidth-(i%tabWidth) = 4-(11%4) = 4-3 = 1 space to get to the 12. index

  12, changes with tabWidth-(i%tabWidth) = 4-(12%4) = 4-0 = 4 space to get to the 16. index
  13, changes with tabWidth-(i%tabWidth) = 4-(13%4) = 4-1 = 3 space to get to the 16. index
  14, changes with tabWidth-(i%tabWidth) = 4-(14%4) = 4-2 = 2 space to get to the 16. index
  15, changes with tabWidth-(i%tabWidth) = 4-(15%4) = 4-3 = 1 space to get to the 16. index
...

An example of a program call:
detab FileName 4

In the text file FileName
tabs are replaced by space characters
and writes the result to a FileName.txt file

If tabWidth is not specified or tabWidth = 0, it does not replace tabs.

*/

#include <stdio.h>
#include <stdlib.h>					// for exit()
#include <string.h>					// for strcpy()

#define MAX_STRING_LEN 1024			// maximum length of one row in a file


// Removes whitespaces (spaces and tabs) from the end of string s.
// There can be only one character for a new line '\ n' in string s,
// and only at the end of string s,
// and then that newline character remains at the end of the trimmed string.
void trim_string_end( char s[],
					  int *num_deleted_spaces,
					  int *num_replaced_tabs,
					  int *num_deleted_whiteness){

    int n = strlen(s);				// n is the length of string s (final character '\0' is not counted)
									// n is the sequence number of the last character in the string, whose index is n-1
	while(n > 0){					// from the end of the string to the beginning, to the left

		if  (s[n-1]==' '){			// if the last character is space
			(*num_deleted_spaces)++;
			(*num_deleted_whiteness)++;
			s[n-1]='\0';			// delete it
		}else if (s[n-1]=='\t'){	// if the last character is a tab
			(*num_replaced_tabs)++;
			(*num_deleted_whiteness)++;
			s[n-1]='\0';			// delete it
		}else						// if not space or tab
			break;					// break while loop

		n--;						// pass to the next character to the left
	}
} // trim_string_end()


// detab_string() in string s replaces the tabs with the appropriate number of space characters.
// Returns the number of replaced tabs num_tab.
// tabWidth is the distance between tab stops expressed by the number of space characters.
int detab_string(char s[], int tabWidth){
	char as[MAX_STRING_LEN];		// auxiliary string
	char *pointer_as = &as[0];		// or:	char *pointer_as = as;
	int num_tab = 0; 				// counter for tabs
	int len = strlen(s);			// length of string s (number of characters in string s)
    int nb = 0;	// the number of space characters that we change the specific tab at the index location i
	int i = 0; 						// i is the index for the main string s
	int j = 0; 						// j is the index for auxiliary string sp
    int k;                      	// counter for loop

// Copy s to as, then read from as and write to s.
// The length of the string s when we replace the tabs
//  with space characters will be larger than the initial one.
// The worst case is that the string s consists only of a tab.
// New, larger length of string s is
// lenght_s = lenght_s - num_tab + num_tab * tabWidth + 1; 	// +1 for '\0'
// So let's first count the number of tabs in string s and calculate its new length.
// Then check if the new length of s is greater than MAX_STRING_LEN.
// If so, we allocate the new memory required for strings s and as.

									// count the number of tabs in string s
	while(s[i]!='\0'){				// we read s from start to end

		if( s[i++] == '\t') 		// if the character is read from the s[i] tab
			num_tab++;				// we count the tabs
	}

	i = 0;							// reset loop counter

	// calculate new length of string s, considering the worst case scenario
	// is that all tabs have been replaced with numTabs * tabWidth characters
	len = len - num_tab + num_tab * tabWidth + 1;

	// If so, we reallocate the new memory required for strings s and as.
	if( len > MAX_STRING_LEN ){

		s = realloc( s, len * sizeof(char) + 1 );

		// Let's check if dynamic memory allocation for variable s succeeded
		if ( s == NULL )
		{
			fprintf(stderr, "\n\n string s realloc() error ! \n\n");
			exit(EXIT_FAILURE);
		}

		pointer_as = realloc( pointer_as, len * sizeof(char) + 1 );

		// Let's check if dynamic memory allocation for variable as succeeded
		if ( pointer_as == NULL )
		{
			fprintf(stderr, "\n\n string as realloc() error ! \n\n");
			exit(EXIT_FAILURE);
		}

	} // if( len > MAX_STRING_LEN )

	strcpy(as,s);					// Now, it is safe to copy s to as.

	while(as[j]!='\0'){				// we read as from start to end

		if( as[j] == '\t') {		// if the character is read from the as[j] tab

			// calculate the number of space characters that we change the specific tab
			nb = tabWidth-(i%tabWidth);

			for( k=0; k<nb; k++ )	// in s we change that '\t' with nb space characters
				s[i++]=' ';			// for each space character, we increment the index i of s

			j++;					// go to next ch in sp
		}else 						// all other characters from sp that aren't tab,
			s[i++]=as[j++];			// we place unchanged in s
	}
	s[i]='\0';						// end the string s

	return num_tab;					// returns the tab number in the string s

} // int detab_string()


/*
// I found a shorter detab() function on the internet:
void detab( char* in, char* out, int tabWidth, size_t max_len ) {
    size_t i = 0;

    while (*in && i < max_len - 1) {

        if (*in == '\t') {
            in++;
            out[i++] = ' ';

            while (i % tabWidth && i < max_len - 1) {
                out[i++] = ' ';
            }
        } else {
            out[i++] = *in++;
        }
    }

    out[i] = 0;
}
*/


// detab_file () opens the input and output files, performs processing, and closes both files.
// Removes whitespaces (space characters and tabs) from the end of rows in the input file,
// Replaces the remaining tabs with the appropriate number of space characters
// and saves the result to a new output file.
// Calls the trim() and detab_string() functions.
void detab_file(char input_file_name[],
				char output_file_name[],
				int tabWidth,
				int *num_characters,
				int *num_rows,
				int *num_tabs,
				int *num_deleted_spaces,
				int *num_replaced_tabs,
				int *num_deleted_whiteness ){

    FILE* pointer_input_file;
    FILE* pointer_output_file;
    char row[MAX_STRING_LEN];		// one line of text

	// We open the input text file for reading
    if( (pointer_input_file = fopen(input_file_name, "r")) == NULL ) {
        fprintf(stderr, "\n\n Error opening input file %s ! \n\n", input_file_name );
        exit(EXIT_FAILURE);			// interrupt program execution
    }
	// We open the output text file for writing
    if( (pointer_output_file = fopen(output_file_name, "w")) == NULL ) {
        fprintf(stderr, "\n\n Error opening output file %s ! \n\n", output_file_name );
        exit(EXIT_FAILURE);			// interrupt program execution
    }
	// loads one row at a time from the input file and processes it
    while( (fgets(row, MAX_STRING_LEN, pointer_input_file) ) != NULL ) {
		// remove the whites from the end of the row string
		trim_string_end( row,
					     num_deleted_spaces,
					     num_replaced_tabs,
					     num_deleted_whiteness);
		// check maximum row length from file
		if ( strlen(row) > MAX_STRING_LEN ){
			fprintf(stderr, "\n\n %8d. row is longer than %d characters ! \n\n",
					(*num_rows)+1, MAX_STRING_LEN );
			exit(EXIT_FAILURE);		// interrupt program execution
		}
        (*num_characters)+=strlen(row);	// We loaded 1 row and increased the total number of characters
									// fgets() loads and counts and character \n at the end of the line
		(*num_rows)++;				// We loaded 1 row and increased the total number of rows
		(*num_tabs) += detab_string(row,tabWidth);	// counts the total number of tabs
		fputs(row,pointer_output_file);				// writes the processed row to the output file
    }

	// Close the input file
    if( ( fclose(pointer_input_file) ) == EOF ) {
        fprintf(stderr, "\n\n Error closing input file %s ! \n\n", input_file_name);
        exit(EXIT_FAILURE);			// interrupt program execution
    }
//    else
//        printf("\n\n File \"%s\" has been successfully closed. \n\n", input_file_name );

	// Close the output file
    if( ( fclose(pointer_output_file) ) == EOF ) {
        fprintf(stderr, "\n\n Error closing output file %s ! \n\n", output_file_name);
        exit(EXIT_FAILURE);			// interrupt program execution
    }
//    else
//        printf("\n\n File \"%s\" has been successfully closed. \n\n", output_file_name );

} // void detab_file()



int main(int argc, char *argv[]) {

    char input_file_name[MAX_STRING_LEN];
    char output_file_name[MAX_STRING_LEN];
    char row[MAX_STRING_LEN];		// one line of text
    int ch;							// Ascii code of one character
    int num_characters = 0;  		// Total number of characters in the file
    int num_rows = 0;              	// Total number of rows in the file
    int num_tabs = 0;          		// Total number of tabs in the file
	int num_deleted_spaces = 0;		// Total number of spaces taken off the ends of the file rows
	int num_replaced_tabs = 0;		// Total number of tabs removed from the ends of the file rows
    int num_deleted_whiteness = 0; 	// Total number of whitenesses removed from the ends of the file rows
    int tabWidth=0;					// space between tab stops (expressed by space character number)

// number of command line arguments when calling a program
// detab 				, argc = 1, that is the name of the program itself
// detab fajl.txt		, argc = 2, it is the name of the program itself and the name of the input file
// detab fajl.txt 4 	, argc = 3, it is the name of the program itself, the name of the input file, and tabWidth

// Replacing the tab with space characters is only done if argc = 3 and tabWidth > 0
// otherwise only the program description is printed.
// printf("\n argc = %d \n ", argc);
// argv[0] is the name of the program itself,	(detab.exe)
// argv[1] is the name of the input file,		(filename.extension)
// argv[2] is tabWidth,							(4)

	if( argc == 3 ) { 				// if all arguments are specified

		tabWidth = atoi( argv[2] );	// converting string argv[2] to integer gets tabWidth

		if ( tabWidth<0 ) {			// check if tabWidth is a positive number
			fprintf(stderr, "\n ERROR: tabWidth = %d is not a positive number ! \n\n", tabWidth);
			system("PAUSE");
			exit(EXIT_FAILURE);		// interrupt program execution
		}

		// check if strcpy() has enough space in memory
		if ( strlen(argv[1]) > MAX_STRING_LEN - 5 ) {	// -5 for .txt and '\0' for output_file_name
			fprintf(stderr, "\n ERROR: The name of the input file \"%s\" is longer than %d characters ! \n\n",
					argv[1], MAX_STRING_LEN-5);
			system("PAUSE");		// pause closing the screen
			exit(EXIT_FAILURE);		// interrupt program execution
		}
									// form the names of the input and output files
		strcpy(input_file_name,argv[1]);			// from argv[1] we make the name of the input file
		strcpy(output_file_name,input_file_name);	// the name of the output file is as the name of the input
		strcat(output_file_name,".txt");			// with the addition of .txt
	}

	// print the program description if all the FileName and tabWidth arguments are not correctly specified
	if( argc != 3 || tabWidth<=0 ) {
        printf("\n DETAB FileName 4 \n"
               "\n in the text file FileName replaces the tabs with the appropriate \n"
               "\n number of space characters and result is recorded in FileName.txt \n\n");
		system("PAUSE");			// pause closing the screen
        exit(EXIT_FAILURE);			// interrupt program execution
    }

	// call the function with its arguments
	detab_file(	input_file_name,
				output_file_name,
				tabWidth,
				&num_characters,
				&num_rows,
				&num_tabs,
				&num_deleted_spaces,
				&num_replaced_tabs,
				&num_deleted_whiteness );

	// Display the results of processing the input file:
    printf("\n In the input file \"%s\" are: \n\n", input_file_name );
    printf("%8d characters \n\n", num_characters);	// The total number of characters in the input file
    printf("%8d rows \n\n", num_rows );          	// The total number of rows in the input file
    printf("%8d tabs that have been replaced with space \n\n", num_tabs );
    printf("%8d spaces taken from the ends of rows \n\n", num_deleted_spaces );
    printf("%8d removed tabs from the ends of rows \n\n", num_replaced_tabs );
    printf("%8d removed whitespaces (space characters and tabs) from the ends of rows \n\n", num_deleted_whiteness);
	printf(" The output file is: \"%s\" \n\n",output_file_name);

    system("PAUSE");				// pause closing the screen

    return 0;						// return 0, program successfully completed

} // int main()
