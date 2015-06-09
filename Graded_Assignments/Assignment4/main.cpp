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

 Total Grade: 10.0/10.0

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



    // Excellent and informative menu.
    while(toupper(option) !='N'){ // This is the menu for entering the equations. while lets it loop tell user is done.
        // Does *all* of this text need to be reprinted every time I get the menu again? The first line could probably be left out.
        cout<<"\nHello user."<<endl; // it is in the while look so user can see choices each time.
        cout<<"This program has 5 different options to run."<<endl;
        cout<<"A: Find the greatest common divisor of two positive integers, m and n."<<endl;
        cout<<"B: Find n! from [0,20]."<<endl;
        cout<<"C: Generate and output all Fibonacci numbers using data type long."<<endl;
        cout<<"D: Find four positive digits, A,B,C,D, that satisfy the following property: \n   A^B*C^D=ABCD"<<endl;
        cout<<"E: Find at least 8 unique solutions for four positive integers, w,x,y,and z \n   which satisfy the Diophantine equation: W^3+x^3+y^3=z^3"<<endl;
        cout<<"\nEnter the letter that corresponds to the program you wish to run."<< endl;
            // Nice touch
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
            // Do you always want invalid input to be silent?
            // Also, since you ignore invalid input, if I type in a message, I
            // just get spammed with the prompt over and over as it enters
            // every single letter I typed as an option.
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

  // url's are more useful than names of stack overflow members.
  while (b!= 0){ // Stock overflow user David Nehme when b = 0 a will be the GCD through the math.
    int c = b;
    b = a % b;      //adjusted.
    a = c;          // uses c as store for value while calculations take place.
  }
    cout<<"The GCD = "<<a<<endl; // outputs numbers
}

void factorial()
{
    // Unsigned long long int should go even higher, I believe.
    long long int c=1.0;  // largest type that would display all digits without adding a new library.

    for(int a = 1; a <= 20; a++) // look to run to solve
        {
        c=c*a;
        if (c==0){
            cout<<1<<endl; // 0 factorial is 1 so added to be correct.
        }
        else{
            // Nice usage of setw. However, notice how on several of the
            // factorials, you have multiple ending zeroes? That means that the
            // number is running out of precision and it's calculating higher
            // than the data type can properly support. You might wish to make a
            // note of that in the future.
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

        // Very nice formatting of the output. Left aligned is usually more readable, though.
        // One note: F(0) = 0, F(1) = 1, F(2) = 2, so you're one off.
        cout <<setw(3)<<"f("<<setw(2)<<c<<")"<<setw(12)<<t<<endl; // display with spacing for easy user viewing.
    }
}
void posdigits()
{
    int t; // What is t for? It's better to place the comment here rather than hidden where you actually use t.
    // Better yet, many programmers recomment that you don't declare t until you use it.
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

    // Some of these answers are "duplicates", for example
    // 10, 60, 80, 90 is a duplicate of 1, 6, 8, 9 because it's a multiple of that solution.
    // Same for 9, 30, 54, 57 and 3, 10, 18, 19.
    // (You still have 8 unique solutions, however)
    cout<<"a b c d"<<endl;              // acts like previous function.
    for (int a=1; a<=10; a++){          // outer does not need to run as much for 8 solutions so adjusted.
        for (int b=a; b<=80; b++){      // some solutions skipped thanks to set up, but still has 8 unique.
            for(int c=b; c<=80; c++){
                for(int d=c; d<=100; d++){
                    // Premature optimization is the root of all evil (as a general rule).
                    // Is the complexity worth the tradeoff in execution time?
                    if (pow(d,3)>pow(a,3)+pow(b,3)+pow(c,3)){                   // break helps optimize for loops.
                        break;
                    }
                    else{
                        // No nice formatting here?
                        if((pow(d,3)==pow(a,3)+pow(b,3)+pow(c,3))){             //tests to see if equation works.
                            cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                        }
                    }
                }
            }
        }
    }
}
