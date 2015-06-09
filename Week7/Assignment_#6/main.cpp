/*****************************************************************************
 Program file name:Assignment_#6		OS:Windows         		Assignment#:6
 Programmer:Daniel_Shafer		Class:CPTR_141 	Intro to programming	  Date:5/15/2015
 Compiler: GNU GCC

 Assistance/references:
 Description:
 Inputs:
 Outputs:

 Special Comments:

~~~~~~~~~~~~~~~~~~~~~~~~~~Grading Criteria~~~~~~~~~~~~~~~~~~~~~~~~~~

 Assignment Requirements ___/3.0

 Code Format/Cosmetics ___/3.0

 Header & Code Comments: ___/2.0

 Output Format/Cosmetics ___/2.0
 ***Does Not Compile***: ___ (-10.0)
 ***Late Work Deduction***: ___ (-0.5/day)
 Total Grade: ___/10.0

*****************************************************************************/
#include <iostream>
#include <cmath> // For using pow
#include <stdio.h>
#include <stdlib.h> // for rand()
#include <iomanip>

using namespace std;


int main()
{
    void letterFreq();                          // prototyping equations that are created after the main.
    void letterFreqIO();
    void bubbleSort();
    void bubbleSortIO();
    void primes();
    void matrixAdd();
    void company();
    void companyIO();
    char option;                                // these are used for the options in the menu and replay choice.
    char choice;

    while(toupper(option) !='N'){       // This is the menu for entering the equations. while lets it loop tell user is done.
        cout<<"\nHello user."<<endl;    // it is in the while look so user can see choices each time.
        cout<<"This program has 4 different options to run."<<endl;
        cout<<"A: Count number of times each letter typed in a string."<<endl;
        cout<<"B: Uses the bubble sort method to sort random values in increasing order."<<endl;
        cout<<"C: Uses the Sieve of Eratosthenes Method to determine all primes less than 1000"<<endl;
        cout<<"D: Adds matrix a to matrix b to create matrix c."<<endl;
        cout<<"E: A function with about 6 employees, and outputs\n   a list of all females with pay rate < $10 per hour."<<endl;

        cout<<"\nEnter the letter that corresponds to the program you wish to run."<< endl;
            cout << "\n - "; // added to try to keep it looking cleaner.
            cin >> choice;
            cout<<"\n";

        switch (toupper(choice)){       // switch statement to let user choose between which function to run.
            case 'A':
                letterFreqIO();
                break;
            case 'B':
                bubbleSortIO();
                break;
            case 'C':
                primes();
                break;
            case 'D':
                matrixAdd();
                break;
            case 'E':
                company();
                break;
            default:                    // catch invalid input.
                break;
        }
        cout<<"Would you like to continue?\n";          // this asks user if they would like to continue to run the program.
        cout<<"Enter Y for yes, or N for no."<<endl;
        cin>>option;
    }
    return 0;
}
void letterFreq(int freq[])
{
    int c;
    while(c!='#'){                          // keeps incrementing while there is not the end character.
        c=getchar();                        // collects input
        for(int b='A'; b<='Z'; b++){        // places a value in that inputs mail box
            if (b==toupper(c)){
                freq[b]++;
            }
        }
    }
}
void letterFreqIO()
{
    int freq[91];                                       // needed to hold up to value 90 for 'Z'
    for (int a='A'; a<='Z'; a++){
        freq[a]=0;                                      // sets everything to 0
    }
    cout<<"Enter a random string and this program will count the number of times each letter in entered. Use # when done."<<endl;
    letterFreq(freq);
    for (int c='A'; c<='Z'; c++){           // outputs all the letters count of being used
        if(freq[c]){
            cout<<char(c)<<" "<<freq[c]<<endl;
        }
    }
}
void bubbleSort(int Sort[])
{
    for(int i=10-1; i>=1; i--){             // works from one end of array while second for loop works on other
        for(int j=0; j<=i-1; j++){          // comparing the random values in those slots
            if(Sort[j]>Sort[i]){
                swap(Sort[j],Sort[i]);      // swap the j position in the array with the i position if statement is true
            }
        }
    }
}
void bubbleSortIO()
{
    int Sort[10];
    for(int a=0; a<10; a++){                                    // generates random numbers with built in rand
        Sort[a]=rand()%101;                                     //http://stackoverflow.com/questions/13896450/rand-returns-the-same-number-each-time-the-program-is-run
    }
    bubbleSort(Sort);
    for (int i=0; i<10; i++){
        cout<<Sort[i]<<endl;                                    // outputs sorted values
    }
}
void primes()                                                   // performs the Sieve method to find prime numbers
{
    int p[50000];                                               // not sure why it is so big. error occurred at any size bellow
    for(int i=0; i<1001; i++){                                  // sets values to 1 so they will read yes to being prime
        p[i]=1;
    }
    p[0]=p[1]=0;                                                // must be set to 0 manually since program will fail with
    for (int a=2; a<=100; a++){
        for(int b=a; b<=500; b++){                              // two for loops to see if there are any factors like 2*2, so 4 is not prime
           p[a*b]=0;
        }
    }
    for(int c=0; c<1001; c++){                                  // reads to see if there are any values in the array that are not NULL or 0
        if (p[c]){
        cout<<c<<endl;                                          // outputs those numbers
        }
    }
}
void matrixAdd()                                                // Adds two pre built Matrix to get a new one
{
    int C[3][3];
    int A[3][3]={1,22,3,0,5,6,5,77,9};                          // giving Matrix A and B values to later be added
    int B[3][3]={50,8,7,36,5,33,3,0,1};
    for(int i=0; i<3; i++){                                     // two for loops for the two parts, rows, and coulombs
        for(int j=0; j<3; j++){
            C[i][j]=A[i][j]+B[i][j];                            // does the matrix addition
        }
    }
    for(int c=0; c<3; c++){
        for(int d=0; d<3; d++){
            cout<<setw(4)<<C[c][d];                             // outputs the matrix C[3][3]
        }
        cout<<endl;                                             // used to end line after each row of matrix
    }
}
void company()                                                  // creates a structure called employee
{
    struct employee {   string name;                            // which has these parts
                        char   gender;
                        int    age;
                        long   ssn;
                        float  pay;
                    };
    employee emp[6]={   {"Jim", 'M', 22, 123456789, 10.60},     // this is where each employee is assigned values for each part
                        {"Lilly", 'F', 25, 987654321,  9.60},
                        {"Sally", 'F', 21, 456123789, 12.50},
                        {"Bob", 'M', 55, 143454749, 10.60},
                        {"Jeff", 'M', 21, 997756341,  100.30},
                        {"Jenifer", 'F', 60, 446725729, 6.50},
                  };
    for (int i=0; i<10; i++){                                   // cycles through looking at parts of emp[i] to see if they fit
        if(emp[i].pay<10){
            if(emp[i].gender=='F'){
                cout<<emp[i].name<<endl;                        // outputs the names of those who are bellow
            }
        }
    }
}
void companyIO()                                                // unneeded since no user input is needed for outputting female pay rates
{

}
