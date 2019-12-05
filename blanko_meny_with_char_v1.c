/*

	Blanko Meny with char v1.c

Example for meny.

Can be used to get Ascii codes for keyboard keys.

with char and getch () respectively getche () and getchar () respectively

getch () reads a character from the keyboard and does not display it on the screen
getche () reads a character from the keyboard and displays it on the screen
Both are declared in conio.h and are not standard functions.

getch () reads a character from the keyboard and does not display it on the screen.
After the character must be pressed enter.
It is declared in stdio.h and is a standard feature.

http://www.c-lang.thiyagaraaj.com/archive/c-blog/use-of-getch-getche-and-getchar-in-c
http://programmingclangauge.weebly.com/getchgetchegets-function.html

https://www.daniweb.com/programming/software-development/threads/37195/difference-betn-getch-getche-getchar-functions

getchar
This is a standard function that gets a character from the stdin.

getch
This is a non-standard function that gets a character from the keyboard, does not echo to the screen.

getche This is a non-standard function that gets a character from the keyboard, echoes to screen.

Use getchar if you want to work on all compilers.
Use getch or getche on a system that supports it when you want keyboard input without pressing [Enter].

And note that the return value of all three is int! You need this to properly check for EOF.

*/


#include <stdio.h>
#include <conio.h>  // for getch() and getche()


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


// Main meny
char meny(void) {

    int c_choice;

    while( 1 ) {    // an infinite loop that exits with choice 0 or Ecsape

        system("CLS");          // clear the screen

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

        switch( c_choice = getche() ) {  // based on the choices we call the appropriate functions
            case '1' :
                    choice_1();  // choice_1
                    break;
            case '2' :
                    choice_2();  // choice_2
                    break;
            case '3' :
                    choice_3();  // choice_3
                    break;
            case '4' :
                    choice_4();  // choice_4
                    break;
            case '5' :
                    choice_5();  // choice_5
                    break;
            case '6' :
                    choice_6();  // choice_6
                    break;
            case '7' :
                    choice_7();  // choice_7
                    break;
            case '8' :
                    choice_8();  // choice_8
                    break;
            case '9' :
                    choice_9();  // choice_9
                    break;
            case '0' :                  // Zero to end work
                    printf(" Pressed key is %c and it's code is %d \n\n", c_choice , c_choice);
                    return(c_choice);
                    break;
            case 27  :                  // ESC to end work
                    printf(" Pressed key is Escape and it's code is %d \n\n", c_choice );
                    return(c_choice);
                    break;
            case  0  :                      // if pressed function taster
                    printf(" Pressed is function taster %d", c_choice );
                    c_choice = getche();    // let's empty that 0
                    printf(" and it's code is %d \n\n", c_choice, c_choice );
                    system("PAUSE");
                    break;
            case 224 :                  // if pressed special function taster
                    printf(" Pressed is function taster %d", c_choice );
                    c_choice = getche(); // let's empty that -32
                    printf(" and it's code is %d \n\n", c_choice, c_choice );
                    system("PAUSE");
                    break;
            default:
                    printf(" Pressed key is %c and it's code is %d \n\n", c_choice , c_choice);
                    if( c_choice < '0' || c_choice > '9' ) {  // if no digit is entered
                        printf("\n\n You have to choose from (0-9) !!! \n\n");
                        system("PAUSE");
                    }
                    break;
        } // switch( c_choice )
    } // while( 1 )
    return(c_choice);
}




// Main program
int main(void) {


    meny();


    return 0;
}