/*****************************************************************************
 Program file name:Easter_Calc           OS:windows         		Assignment #:2
 Programmer:Daniel_Shafer			Class:CPTR_141 	Intro to programming	Date:4/10/2015
 Compiler: GNU GCC

 Assistance/references:text/lectures
 Description: The Program uses the given info to calculate the day easer falls on every year.
 Inputs: year
 Outputs: month and day of easter

 Special Comments:

~~~~~~~~~~~~~~~~~~~~~~~~~~Grading Criteria~~~~~~~~~~~~~~~~~~~~~~~~~~

// Some limitations of the code that you missed:
// This code will not work for years after 4099, or for any input besides a numerical 4 digit year.

 Total Grade: 9.0/10.0

*****************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int A, B, C,D,E,F,G,H,I,K,M,N; // declaration of variables.
    int Easter_day;
    int Easter_Month;
    int year;

    // The program should declare its purpose in addition to asking the user to input a year(-1 point)
    // eg, cout << "This program outputs the date of Easter for the year you give" << endl;
    cout << "Please enter the year. Format 2015. (Must be after 1582)" << endl; // prompt for year


    {
    cin >> year;  // impute for year
    A=year%19;    // This is the given algorithm to calculate the day of easter every year after 1582.
    B=year/100;
    C=year%100;
    D=B/4;
    E=B%4;
    F=(B+8)/25;
    G=(B-F+1)/3;
    H=(19*A+B-D-G+15)%30;
    I=C/4;
    K=C%4;
    M=(32+2*E+2*I-H-K)%7;
    N=(A+11*H+22*M)/451;
    Easter_Month=(H+M-7*N+114)/31; // 3=march, 4=April
    Easter_day=1+(H+M-7*N+114)%31;

    if (year >= 1582){

        // Nice usage of switch case. In this case, since you only have two options,
        // it's usually cleaner to just have a nested set of if-statements.
    switch (Easter_Month) // Converts output for month to say the actual month the numerical value stands for.
    {
        case 3:
            cout << "March " << Easter_day << endl; // final out put say saying day month
            break;
        case 4:
            cout << "April " << Easter_day << endl; // final out put say saying day month
            break;

        default: // used to protect against unexpected value. ends program with return 0.
            return 0;
    }
    }
    else {
        cout << "Invalid input." << endl; // protects against most invalid inputs.
    }
    }
    return 0; // ends program after one cycle.
}

