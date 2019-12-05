/*
	count letters and words in string v1.c
*/

#include<stdio.h>

int main(void)
{
	int i = 0;						// loops counter
	int countLetters = 0;			// counter for letters
	int countWords = 0;				// counter for words

	char str[] = "count how many words and letters there are";	// string to be analyzed

	while (str[i] != '\0')			// from beginning to end of string
	{
		if ( str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' )
		{							// if str[i] is letter, this is a new word and
			countWords++;			// increment countWords

			while(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' )
			{						// then, while str[i] is letter
				countLetters++; 	// increment countLetters
				i++; 				// go to next character
			}
		}
		else						// if str[i] is not letter
			i++;					// go to next character
	}

	printf("\n %s \n",str);

	printf("\n countWords = %d \n",countWords);

	printf("\n countLetters = %d \n",countLetters);

	return 0;
}
