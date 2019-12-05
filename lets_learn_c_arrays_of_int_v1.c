/*

 lets_learn_c_arrays_of_int_v1.c

 Work with C arrays from meny.

The idea is that this program should cover everything about
C arrays with int numbers.

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

An example of C arrays
https://www.tutorialspoint.com/cprogramming/c_strings.htm

*/


#include <stdio.h>


// Displays an array of n integers
void display_array_of_integers( char text[], int array[], int n ) {

    int i;

    printf("\n\n%s ( size = %d )\n\n", text, n );

    for( i=0; i<n ; i++ )				// display of array items
        printf("%4d", array[i] );

    printf("\n");
}


// We return all 10 array elements to be the same as their indexes
void reset_array( int array[], int *n ) {

    int i;

    *n = 10;                    // the function has an address of n, so it can change it

    for( i=0; i<*n ; i++ )
        array[i] = i;           // we set the value of the array element
}


// called from meny_1, choice_1, choice_2 and choice_3
// From the end of the array to the left to the desired index,
// it moves the array members one place to the right.
// To the vacancy thus made insert new_number into index place.
// https://www.geeksforgeeks.org/c-program-to-insert-an-element-in-an-array/
// https://codeforwin.org/2015/07/c-program-to-insert-element-in-array.html
void insert_new_number_into_array_on_index_k( int array[], int *n , int new_number, int k) {

    int i;

    if( k>(*n) || k<0 )             // If index k of element is not valid
    {
        printf("\n Invalid index of new element! Please enter index between 0 to %d \n", (*n) );
    }
    else
    {
        for( i=(*n); i>=k; i-- )    // Make room for new array element by shifting to right
        {
            array[i] = array[i-1];
        }

        array[k] = new_number;      // Insert new element at given position
                                    // the function has an address of n, so it can change it
        (*n)++;                     // increment *n because we add an array element
    }
}


// meny_1, inserting a new number into the array, call insert_new_number_into_array_on_index_k()
int meny_1( int array[], int *n ) {

    int choice, new_number, k;		// new_number will be in the place with index k

    while( 1 ) {    		        // an endless loop that exits with the choice 0 or Escape

        //system("CLS");              // clear command window

        display_array_of_integers( " Array is: ", array, *n );	// Displays an array of n integers

    printf("\n\n +------------------------------------------------------+ \n"
               " | meny_1: INSERTING A NEW NUMBER INTO THE ARRAY        | \n"
               " +------------------------------------------------------+ \n"
               " |  1. Enter a number at the beginning of the array     | \n"
               " |                                                      | \n"
               " |  2. Enter a number at the end of the array           | \n"
               " |                                                      | \n"
               " |  3. Enter a number in a place with index k           | \n"
               " |                                                      | \n"
               " |  0. ESC or 0 for previous meny                       | \n"
               " +------------------------------------------------------+ \n"
               "\n\n Izaberite (1-3)  ?  ");

        switch( choice = getche() ) {   // based on the choices we call the appropriate functions

            case '1':                   // Enter a number at the beginning of the array
                    printf("\n\n Enter a number you wish to add at the beginning of the array: ");
                    scanf("%d",&new_number);
                    insert_new_number_into_array_on_index_k( array, n , new_number, 0 );
                    break;

            case '2':                   // Enter a number at the end of the array
                    printf("\n\n Enter a number you wish to add at the end of the array: ");
                    scanf("%d",&new_number);
                    insert_new_number_into_array_on_index_k( array, n , new_number, (*n) );
                    break;

            case '3':                   // Enter a number in a place with index k
                    printf("\n\n Enter a number you wish to add in the array: ");
                    scanf("%d",&new_number);
                    printf("\n\n Enter the index k of the place where you want \n to insert the new element of the array: k = ");
                    scanf("%d",&k);
                    insert_new_number_into_array_on_index_k( array, n , new_number, k );
                    break;

            case '0' :                  // 0 for previous meny
                    return( (int)choice );
                    break;

            case 27  :                  // Escape for previous meny
                    return( (int)choice );
                    break;

            case  0  :                  // if a function key is pressed
                    choice = getche(); 	// let's empty that 0

            case -32 :                  // if a special function key is pressed
                    choice = getche(); 	// let's empty that -32
                    break;

            default:					// if entered character is not from the meny
                    if( choice < '0' || choice > '6' ) {
                        printf("\n\n You have to choose (0-9) !!! \n");
                        //system("PAUSE");
                    }
                    break;
        } // switch( choice )
    } // while( 1 )

    return( choice );
}


// meny_2, choice_1
// Modifying one element of array that has index
void modifying_one_element_of_array_that_has_index( int array[], int n, int index ) {

    int NewValue;

    while( 1 ) {                        // endless loop to control number entry

        printf("\n\n Enter the index of the element you want to modify ");
        scanf("%d",&index);

        if( index<0 || index>n )
            printf("\n\n Enter the index between 0 i %d !\n\n", n );
        else
            break;                      // a good index is entered and we exit the infinite loop while (1)
    }

    printf("\n\n Element to modify is array[%d] = %d . Change it with: ", index, array[index] );
    scanf("%d",&NewValue);

    array[index] = NewValue;
}



// meny_2, choice_2
// modifying all occurrences of OldValue in array with NewValue
// Returns 0 if NewValue does not exist in the array, otherwise returns number_of_elements_modified
int modifying_all_occurrences_of_OldValue_in_array_with_NewValue( int array[], int n, int OldValue, int NewValue ) {

    int i, number_of_elements_modified=0;

    for( i=0; i<n; i++ )                        // we move through the whole array

        if( array[i] == OldValue ) {            // if we have found the value we need to change
            array[i] = NewValue;                // we assign it a new value
            number_of_elements_modified++;      // we increase the number of changed elements
        }
    return( number_of_elements_modified );
}


// meny_2, Modifying of elements of array
int meny_2( int array[], int *n ) {

    int choice, index, OldValue, NewValue;

    while( 1 ) {                                // an infinite loop that exits with choice 0

        //system("CLS");                      // clear console window

        display_array_of_integers( " Array is: ", array, *n );

    printf("\n\n +----------------------------------------------------------+ \n"
               " | meny_2:     MODIFYING OF ELEMENTS OF ARRAY               | \n"
               " +----------------------------------------------------------+ \n"
               " |  1. Modifying one array element                          | \n"
               " |                                                          | \n"
               " |  2. Modifying all occurrences of an value in array       | \n"
               " |                                                          | \n"
               " |  0. ESC or 0 for previous meny                           | \n"
               " +----------------------------------------------------------+ \n"
               "\n\n Choose (1-3)  ?  ");

        switch( choice = getche() ) {       // based on the choices we call the appropriate functions

            case '1':                       // Modifying one array element

                    modifying_one_element_of_array_that_has_index( array, *n, index );
                    break;

            case '2':                       // Modifying all occurrences of an element in an array
                    printf("\n\n Enter the value of the element you want to modify ");
                    scanf("%d",&OldValue);

                    printf("\n\n Enter the NewValue value of the element %2d you want to modify ", OldValue );
                    scanf("%d",&NewValue);

                    modifying_all_occurrences_of_OldValue_in_array_with_NewValue( array, *n, OldValue, NewValue );
                    break;

            case '0':                       // 0 for previous meny
            case 27 :                       // ESC for previous meny
                    return( choice );
                    break;

            case  0  :                      // if a function key is pressed
                    choice = getche(); 	    // let's empty that 0

            case 224 :                      // if a special function key is pressed
                    choice = getche(); 	    // let's empty that 224
                    break;

            default:					    // if entered character is not from the meny
                    if( choice < '0' || choice > '6' ) {
                        printf("\n\n You have to choose (0-9) !!! \n");
                        //system("PAUSE");
                    }
                    break;

        } // switch( choice ) {

    } // while( 1 )

    return( choice );
}


// meny_3, choice_1
// deleting one array element whose index is index_of_the_element_to_delete
// https://codeforwin.org/2015/07/c-program-to-delete-element-from-array.html
void deleting_one_array_element_whose_index_is( int array[], int *n ) {

    int i, index_of_the_element_to_delete;

    while( 1 ) {                    // endless loop to control number entry

        printf("\n\n Enter the index of the element you want to delete ");
        scanf("%d",&index_of_the_element_to_delete);

        if( index_of_the_element_to_delete < 0 || index_of_the_element_to_delete > (*n)-1 )
            printf("\n\n Enter a number between 0 i %d !\n\n", (*n)-1 );
        else
            break;                  // a good number is entered and we exit the infinite loop while (1)
    }

    for( i=index_of_the_element_to_delete; i<(*n)-1; i++ )  // Copy next element value to current element
    {
        array[i] = array[i+1];
    }

    (*n)--;                         // the function has an address of n, so it can change it
}


// meny_3, choice_2
// deleting all occurrences of value in array
// Returns 0 if value does not exist in array, otherwise returns number_of_deleted_elements
int deleting_all_occurrences_of_value_in_array( int array[], int *n ) {

    int i=0, value, new_n=0, number_of_deleted_elements=0;

    printf("\n\n Enter the value of the element you want to delete ");
    scanf("%d",&value);

    while( i < *n ) {                           // we move through the whole array
        if( array[i] == value )                 // if we find value we need to delete
            number_of_deleted_elements++;       // increase number of deleted elements
        else
            array[new_n] = array[i];

        i++;                                    // we go to the next element by increasing the index
        new_n = i - number_of_deleted_elements; // calculate new number of elements in array
    }
                                                // the function has an address of n, so it can change it
    *n = new_n;                                 // *n becomes new number of elements in array

    return( number_of_deleted_elements );
}


// meny_3, DELETING THE ARRAY ELEMENTS
int meny_3( int array[], int *n ) {

    int choice, value;

    while( 1 ) {    // an infinite loop that exits with choice 0

        //system("CLS");          // clear console window

        display_array_of_integers( " Array is: ", array, *n );

    printf("\n\n +----------------------------------------------------+ \n"
               " | meny_3:     DELETING THE ARRAY ELEMENTS            | \n"
               " +----------------------------------------------------+ \n"
               " |  1. Deleting one array element                     | \n"
               " |                                                    | \n"
               " |  2. Deleting all occurrences of value in an array  | \n"
               " |                                                    | \n"
               " |  0. ESC or 0 for previous meny                     | \n"
               " +----------------------------------------------------+ \n"
        "\n\n\t Choose (1-3)  ?  ");

        switch( choice = getche() ) {  // based on the choices we call the appropriate functions

        case '1':     // deleting one array element whose index is index_of_the_element_to_delete
                deleting_one_array_element_whose_index_is( array, n );
                break;

        case '2':     // Deleting all occurrences of value in an array
                deleting_all_occurrences_of_value_in_array( array, n );
                break;

            case '0' :                      // 0 to end of work
                    return(choice);
                    break;

            case 27  :                      // ESC to end of work
                    return(choice);
                    break;

            case  0  :                      // if a function key is pressed
                    choice = getche(); 	    // let's empty that 0
                    break;

            case 224 :                      // if a special function key is pressed
                    choice = getche(); 	    // let's empty that 224
                    break;

            default:					    // if entered character is not from the meny
                    if( choice < '0' || choice > '2' ) {
                        printf("\n\n You have to choose (0-2) !!! \n");
                        //system("PAUSE");
                    }
                    break;

        } // switch( choice = getche() )

    } // while( 1 )

    return( choice );
}


// interchanging places two elements ( i-th and j-th ) of an array
// Returns 0 if the i-th or j-th element does not exist, otherwise it returns 1
// ( called from main meny )
int interchanging_places_two_elements_of_an_array( int array[], int n ) {

    int i, j, mem;

    printf("\n\n Enter the index of first element you want to interchange ");
    scanf("%d",&i);

                // checking that the element with index i exists in the array
    if( i<0 || i>n-1 ) {
        printf("\n\n Element with index %d does not exist in array ! \n\n", i );
        return(0);
    }

    printf("\n\n Enter the index of second element you want to interchange ");
    scanf("%d",&j);

                // checking that the element with index j exists in the array
    if( j<0 || j>n-1 ) {
        printf("\n\n Element with index %d does not exist in array ! \n\n", j );
        return(0);
    }
                                // we interchange places of the i-th and j-th elements of the array
    mem = array[i];             // the value of the i-th is stored in the memory mem
    array[i] = array[j];        // i-th becomes j-th
    array[j] = mem;             // j-th becomes mem ( it becomes old i-th )

    return(1);
}


// Search for the occurrences of a value in an array
// Returns the number_of_occurrences of the requested value in a string
// ( called from main meny )
int search_for_the_occurrences_of_a_value_in_an_array( int array[], int n ) {

    int i=0, value, number_of_occurrences=0;

    printf("\n\n Enter the value you are looking for in the array ");
    scanf("%d",&value);

    while( i < n ) {                    // we move through the entire array

        if( array[i] == value ) {       // if we find the value we are looking for
            number_of_occurrences++;
            printf("\n %2d. found: array[%2d] = %2d \n", number_of_occurrences, i, array[i] ); // the elements found are displayed
        }

        i++;                            // we go to the next element by increasing the index
    }

    if( number_of_occurrences == 0 ) {
        printf("\n\n There is no value %d in array !\n\n", value);
        return (0);
    }
    else
    {
        return( number_of_occurrences );
    }
}


// Main meny
int meny( int array[], int *n ) {

    int i, j;
    int choice;

    while( 1 ) {    // an endless loop that exits with a choice of 0 or Escape

        //system("CLS");          // clear command window

        display_array_of_integers( " The values of the array elements are the same as their indexes:", array, *n );

		printf("\n\n +----------------------------------------------------------------+ \n"
				   " |       MAIN MENY FOR C ARRAYS WITH INTEGERS                     | \n"
                   " +----------------------------------------------------------------+ \n"
                   " | 1. Inserting a new number into the array (own meny_1)          | \n"
                   " | 2. Modification, change of one number by another (own meny_2)  | \n"
                   " | 3. Deleting array element (own meny_3)                         | \n"
                   " | 4. Substitution of place with i-th and j-th number             | \n"
                   " | 5. Search for a number in the array                            | \n"
                   " | 6. Reset the array to initial values                           | \n"
                   " | 0. ESC or 0 to end of work                                     | \n"
                   " +----------------------------------------------------------------+ \n"
                   "\t Your choice is (0-6)  ?  " );

        switch( choice = getche() ) {       // based on the choices we call the appropriate functions

            case '1' :
                    meny_1(array,n);        // Inserting a new number into the array (own meny)
                    break;

            case '2' :
                    meny_2(array,n);        // Modification, change of one number by another
                    break;

            case '3' :
                    meny_3(array,n);        // Deleting array element (own meny)
                    break;

            case '4' :
                    interchanging_places_two_elements_of_an_array( array, *n );     // interchanging places two elements of an array
                    break;

            case '5' :
                    search_for_the_occurrences_of_a_value_in_an_array( array, *n ); // search for the occurrences of a value in an array
                    break;

            case '6' :                  	// Reset the array to initial values
                   reset_array( array, n ); // The 10 elements of an array become the same as their indexes
                   break;

//            case '7' :
//                    meny_7(array,n);
//                    break;

//            case '8' :
//                    meny_8(array,n);
//                    break;

//            case '9' :
//                    meny_9(array,n);
//                    break;

            case '0' :                      // 0 to end of work
                    return(choice);
                    break;

            case 27  :                      // ESC to end of work
                    return(choice);
                    break;

            case  0  :                      // if a function key is pressed
                    choice = getche(); 	    // let's empty that 0

            case 224 :                      // if a special function key is pressed
                    choice = getche(); 	    // let's empty that 224
                    break;

            default:					    // if entered character is not from the meny
                    if( choice < '0' || choice > '6' ) {
                        printf("\n\n You have to choose (0-9) !!! \n");
                        //system("PAUSE");
                    }
                    break;

        } // switch( choice )

    } // while( 1 )

    return( choice );
}



int main(void) {

    int array[100];             // the array of 100 integers we work with
    int n;                 		// n is the number of array elements, will be set in next line

    reset_array( array, &n );   // 10 array elements become the same as their indexes

    meny( array , &n );         // we invoke the main program menu

    return 0;
}
