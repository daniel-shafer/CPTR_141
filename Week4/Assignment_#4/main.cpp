/*****************************************************************************
 Program file name:Assignment_#4		OS:Windows         		Assignment#:4
 Programmer:Daniel_Shafer		Class:CPTR_141 	Intro to programming	  Date:4/22/2015
 Compiler: GNU GCC

 Assistance/references:Textbook, lecture, stack overflow
 Description:The goal of this program is the create a menu and use it to access simple programs that we have written.
 Inputs:Choice for Which program to run, variable for computation, answer to question for ending. GCD inputing values to calculate.
 Outputs: GCD, Factorials from 0 to 20, Fibonacci numbers from 0 to 45, calculated numbers to solve first equation,Diophantine's equation solutions.

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
#include <iomanip> // for using setw()
#include <cmath> // For using pow

using namespace std;


int main()
{
    void gcd();         // prototyping equations that are created after the main.
    void factorial();
    void Fibonacci();
    void posdigits();
    void Diophantine();
    char option;        // these are used for the options in the menu and replay choice.
    char choice;



    while(toupper(option) !='N'){ // This is the menu for entering the equations. while lets it loop tell user is done.
        cout<<"\nHello user."<<endl; // it is in the while look so user can see choices each time.
        cout<<"This program has 5 different options to run."<<endl;
        cout<<"A: Find the greatest common divisor of two positive integers, m and n."<<endl;
        cout<<"B: Find n! from [0,20]."<<endl;
        cout<<"C: Generate and output all Fibonacci numbers using data type long."<<endl;
        cout<<"D: Find four positive digits, A,B,C,D, that satisfy the following property: \n   A^B*C^D=ABCD"<<endl;
        cout<<"E: Find at least 8 unique solutions for four positive integers, w,x,y,and z \n   which satisfy the Diophantine equation: W^3+x^3+y^3=z^3"<<endl;
        cout<<"\nEnter the letter that corresponds to the program you wish to run."<< endl;
            cout << "\n - "; // added to try to keep it looking cleaner.
            cin >> choice;
            cout<<"\n";

        switch (toupper(choice)){ // switch statement to let user choose between which function to run.
            case 'A':
                gcd();
                break;
            case 'B':
                factorial();
                break;
            case 'C':
                Fibonacci();
                break;
            case 'D':
                posdigits();
                break;
            case 'E':
                Diophantine();
                break;
            default: // catch invalid input.
                break;
        }
        cout<<"Would you like to continue?\n";          // this asks user if they would like to continue to run the program.
        cout<<"Enter Y for yes, or N for no."<<endl;
        cin>>option;
    }
    return 0;
}
void gcd() // first function
{
    int a,b;
    cout<<"Please enter first value, then hit enter, followed by second value."<<endl;
    cin>> a;
    cin>> b; // takes user input

  while (b!= 0){ // Stock overflow user David Nehme when b = 0 a will be the GCD through the math.
    int c = b;
    b = a % b;      //adjusted.
    a = c;          // uses c as store for value while calculations take place.
  }
    cout<<"The GCD = "<<a<<endl; // outputs numbers
}

void factorial()
{
    long long int c=1.0;  // largest type that would display all digits without adding a new library.

    for(int a = 1; a <= 20; a++) // look to run to solve
        {
        c=c*a;
        if (c==0){
            cout<<1<<endl; // 0 factorial is 1 so added to be correct.
        }
        else{
            cout<<setw(4)<<a<<"! = "<<c<<endl; // added setw() for a cleaner display of solution
        }
    }

}
void Fibonacci()
{
    long a=0;               // starts as 0 in order for t=a+b first run to equal 1
    long b=1;               // Directions have f(0)=1 so that is where it starts, but that disagrees with lots of online info.
    long t;                 // used as value holder for calculations.
    cout << "This program outputs all Fibonacci numbers of type long."<< endl;
    for (int c=0; c<= 45; c++) // c increments while a and b do math.
    {
        t=a+b;
        b=a;
        a=t;

        cout <<setw(3)<<"f("<<setw(2)<<c<<")"<<setw(12)<<t<<endl; // display with spacing for easy user viewing.
    }
}
void posdigits()
{
    int t;
    for (int a=1; a<=9; a++){               // the series of looks change the values of a,b,c,d until the equation is true.
        for (int b=1; b<=9; b++){
            for(int c=1; c<=9; c++){        // only need to use integers from 1 to 9 to work.
                for(int d=1; d<=9; d++){
                    t=pow(a,b)*pow(c,d);    // again t acts as place holder for calculations.
                    if(t==((a*1000)+(b*100)+(c*10)+d)){
                        cout<<"a= "<<a<<endl;       // clean way to display what each value is.
                        cout<<"b= "<<b<<endl;
                        cout<<"c= "<<c<<endl;
                        cout<<"d= "<<d<<endl;
                    }
                }

            }
        }
    }
}
void Diophantine()
{

    cout<<"a b c d"<<endl;              // acts like previous function.
    for (int a=1; a<=10; a++){          // outer does not need to run as much for 8 solutions so adjusted.
        for (int b=a; b<=80; b++){      // some solutions skipped thanks to set up, but still has 8 unique.
            for(int c=b; c<=80; c++){
                for(int d=c; d<=100; d++){
                    if (pow(d,3)>pow(a,3)+pow(b,3)+pow(c,3)){                   // break helps optimize for loops.
                        break;
                    }
                    else{
                        if((pow(d,3)==pow(a,3)+pow(b,3)+pow(c,3))){             //tests to see if equation works.
                            cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                        }
                    }
                }
            }
        }
    }
}
