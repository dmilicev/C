/*

    BLANKO meny with int v1.c

    There is a problem if you in

    scanf("%d",&choice);

    enter something else than 0-9. In that case, exit with Ctrl-Break.

    This is resolved as follows:

	int choice;
	char terminator;

	printf("\n Enter a number: ");

	// On success, the function scanf() returns the number
	// of items of the argument list successfully read.
	// If scanf didn't read two elements, integer and char, and return 2
	// or if second element terminator isn't enter '\n'
	// then first element isn't integer.
	if( scanf("%d%c", &choice, &terminator) != 2 || terminator != '\n' )
	{
		printf("\n choice = %d is not an integer ! \n");
		return(1);
	}
*/


#include <stdio.h>


// function_1,
void function_1(void) {

    int i;

    printf("\n\n function_1 \n\n");
}


// function_2,
void function_2(void) {

    int i;

    printf("\n\n function_2 \n\n");
}


// function_3,
void function_3(void) {

    int i;

    printf("\n\n function_3 \n\n");
}


// function_4,
void function_4(void) {

    int i;

    printf("\n\n function_4 \n\n");
}


// function_5,
void function_5(void) {

    int i;

    printf("\n\n function_5 \n\n");
}


// function_6,
void function_6(void) {

    int i;

    printf("\n\n function_6 \n\n");
}


// function_7,
void function_7(void) {

    int i;

    printf("\n\n function_7 \n\n");
}


// function_8,
void function_8(void) {

    int i;

    printf("\n\n function_8 \n\n");
}


// function_9,
void function_9(void) {

    int i;

    printf("\n\n function_9 \n\n");
}


// choice_1,
void choice_1(void) {

    int i;

    printf("\n\n Your choice is choice_1 \n\n");

    function_1();

    system("PAUSE");
}


// choice_2,
void choice_2(void) {

    int i;

    printf("\n\n Your choice is choice_2 \n\n");

    function_2();

    system("PAUSE");
}


// choice_3,
void choice_3(void) {

    int i;

    printf("\n\n Your choice is choice_3 \n\n");

    function_3();

    system("PAUSE");
}


// choice_4,
void choice_4(void) {

    int i;

    printf("\n\n Your choice is choice_4 \n\n");

    function_4();

    system("PAUSE");
}


// choice_5,
void choice_5(void) {

    int i;

    printf("\n\n Your choice is choice_5 \n\n");

    function_5();

    system("PAUSE");
}


// choice_6,
void choice_6(void) {

    int i;

    printf("\n\n Your choice is choice_6 \n\n");

    function_6();

    system("PAUSE");
}


// choice_7,
void choice_7(void) {

    int i;

    printf("\n\n Your choice is choice_7 \n\n");

    function_7();

    system("PAUSE");
}


// choice_8,
void choice_8(void) {

    int i;

    printf("\n\n Your choice is choice_8 \n\n");

    function_8();

    system("PAUSE");
}


// choice_9,
void choice_9(void) {

    int i;

    printf("\n\n Your choice is choice_9 \n\n");

    function_9();

    system("PAUSE");
}


int meny(void)
{
    int choice, end=0;
	char terminator;

    while(!end){

	system("CLS");		// clear the screen

    printf("\n\n+--------------------------------------------------+\n"
               "|                                                  |\n"
               "|          MAIN MENY                               |\n"
               "|                                                  |\n"
               "+--------------------------------------------------+\n"
               "|                                                  |\n"
               "| 1. choice_1                                      |\n"
               "|                                                  |\n"
               "| 2. choice_2                                      |\n"
               "|                                                  |\n"
               "| 3. choice_3                                      |\n"
               "|                                                  |\n"
               "| 4. choice_4                                      |\n"
               "|                                                  |\n"
               "| 5. choice_5                                      |\n"
               "|                                                  |\n"
               "| 6. choice_6                                      |\n"
               "|                                                  |\n"
               "| 7. choice_7                                      |\n"
               "|                                                  |\n"
               "| 8. choice_8                                      |\n"
               "|                                                  |\n"
               "| 9. choice_9                                      |\n"
               "|                                                  |\n"
               "| 0. end                                           |\n"
               "|                                                  |\n"
               "+--------------------------------------------------+\n\n"
               " \t Your choice is:  "
               );

        //scanf("%d",&choice);
/*
    There is a problem with function scanf(), if you enter something else than 0-9,
    the program will crash.
    In that case, exit with Ctrl-Break.

    This is resolved as follows:
*/
		// On success, the function scanf() returns the number
		// of items of the argument list successfully read.
		// If scanf didn't read two elements, integer and char, and return 2
		// or if second element terminator isn't enter '\n'
		// then first element isn't integer.
		if( scanf("%d%c", &choice, &terminator) != 2 || terminator != '\n' )
		{
			printf("\n choice = %d is not an integer ! \n");
			printf("\n You have to choose from (0-9) !!! \n\n");
			return(1);
		}

        switch(choice){
            case 1:
					choice_1();  // choice_1
                    break;
            case 2:
					choice_2();  // choice_2
                    break;
            case 3:
					choice_3();  // choice_3
                    break;
            case 4:
					choice_4();  // choice_4
                    break;
            case 5:
					choice_5();  // choice_5
                    break;
            case 6:
					choice_6();  // choice_6
                    break;
            case 7:
					choice_7();  // choice_7
                    break;
            case 8:
					choice_8();  // choice_8
                    break;
            case 9:
					choice_9();  // choice_9
                    break;
            case 0:
                    end = 1;        // exit
                    break;
            default :
                    printf("\n\n \t You have to choose (0-9) ! \n\n");
                    break;
        } // switch(choice)
    } // while(!end)
    return choice;
} // meny()




// Main program
int main(void)
{

	meny();


    return 0;
} // Main program