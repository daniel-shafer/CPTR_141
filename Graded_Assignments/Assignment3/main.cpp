/*****************************************************************************
 Program file name:Assignment#3 		OS:Windows         		Assignment#:3
 Programmer:Daniel_Shafer			Class:CPTR_141 	Intro to Programming 	Date:4/17/2015
 Compiler: GNU GCC

 Assistance/references:Textbook
 Description: This program converts letters into a number value. Similar to a rotary phone dial.
 Inputs: Any letter from A-Z, capital or lower case. Invalid symbols
 Outputs: Number values that corresponds to the letter. * for invalid symbols.
 Special Comments: Can't use 1 or 0 since there is no alphabetical character to represent them.

~~~~~~~~~~~~~~~~~~~~~~~~~~Grading Criteria~~~~~~~~~~~~~~~~~~~~~~~~~~

 Total Grade: 10.0/10.0

*****************************************************************************/
#include <iostream>
#include <stdio.h> // needed to include getchar()
// There's a way to do this with just cin, actually.

using namespace std;

int main()
{

    char c; // declare c to use as input.


    // Excellent introduction.
    cout << "Hello!!! \nThis program works like a Old Rotary phone Dialing system." << endl; // description of program for user to know what to do.
    cout << "Please enter any letter from A-Z. \nAvoid entering numbers, or strange symbols." << endl;
    cout << "Enter # followed by enter when you are done.\n* = Improper input such as number, or symbol." << endl;
    cout << "Enter the letters that correspond to desired number.\n2=ABC 3=DEF 4=GHI 5=JKL 6=MNO 7=PQRS 8=TUV 9=WXYZ" << endl;
    cout << "\nNumber - ";

    while (c != '#') // While statement to keep running program accepting c's. Ends with # then enter.
    {
        c = getchar(); // talks the letter inputs and assigns them to c

        switch (toupper(c)) // Converts c to its numerical value.
        {


            case 'A': case 'B': case 'C': // stacked to use all three before break is hit.
                cout << "2";
                break;
            case 'D': case 'E':case 'F':
                cout << "3";
                break;
            case 'G': case 'H': case 'I':
                cout << "4";
                break;
            case 'J': case 'K': case 'L':
                cout << "5";
                break;
            case 'M': case 'N': case 'O':
                cout<< "6";
                break;
            case 'P': case 'Q': case 'R': case 'S':
                cout << "7";
                break;
            case 'T': case 'U': case 'V':
                cout << "8";
                break;
            case 'W': case 'X': case 'Y': case 'Z':
                cout << "9";
                break;
            case '\n': // needed to avoid default being triggered by enter.
                cout << " ";
                break;
            case '#': // needed to avoid default being triggered by #.
                cout << " ";
                break;
            default :
                cout << "*";
                break;


        }
    }


    // You can just cout << endl; if you want to.
    cout <<"" << endl; // added to clean up. Adds a space at the end of program.


    return 0;
}
