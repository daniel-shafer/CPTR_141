/*****************************************************************************
 Program file name:Assignment_#5		OS:Windows         		Assignment#:5
 Programmer:Daniel_Shafer		Class:CPTR_141 	Intro to programming	  Date:4/29/2015
 Compiler: GNU GCC

 Assistance/references:Textbook, lecture, stack overflow
 Description: uses menu, and recursive functions
 Inputs: options for menu, n for factorial and Fibonacci, n and m for GCD, a b c for quadratic equation.

 Outputs: n!, Fibonacci number, GCD of two values

 Special Comments: can not solve final problem

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

using namespace std;


int main()
{
    unsigned long factorial(int n);             // prototyping equations that are created after the main.
    void factorial_IO();                        // using IO functions creates a function to call their recursive copies.
    unsigned long fibonacci(int n);
    void fibonacci_IO();
    unsigned long GCD(unsigned long n, unsigned long m);
    void GCD_IO();
    void quadratic(int a, int b, int c, float& r1, float& r2);  //&used in call by reference
    void quadratic_IO();
    char option;                                // these are used for the options in the menu and replay choice.
    char choice;

    while(toupper(option) !='N'){ // This is the menu for entering the equations. while lets it loop tell user is done.
        cout<<"\nHello user."<<endl; // it is in the while look so user can see choices each time.
        cout<<"This program has 4 different options to run."<<endl;
        cout<<"A: Generate and output n! from 0 to 12."<<endl;
        cout<<"B: Generate and output the nth Fibonacci number from 1 to 47."<<endl;
        cout<<"C: Find the greatest common divisor of two positive integers, m and n."<<endl;
        cout<<"D: Find and return the real root of a quadratic equation."<<endl;
        cout<<"\nEnter the letter that corresponds to the program you wish to run."<< endl;
            cout << "\n - "; // added to try to keep it looking cleaner.
            cin >> choice;
            cout<<"\n";

        switch (toupper(choice)){ // switch statement to let user choose between which function to run.
            case 'A':
                factorial_IO();
                break;
            case 'B':
                fibonacci_IO();
                break;
            case 'C':
                GCD_IO();
                break;
            case 'D':
                quadratic_IO();
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
unsigned long factorial(int n)  // function uses recursion to calculate factorials
{
    if (n==0){
        return 1;
    }
    else {
          return n*factorial(n-1);  // calls self and adds to stack until n==0 then pulls and multiplies together stack
    }
}
void factorial_IO()
{
    int n;
    cout<<"Please enter a positive integer from 0 to 12 for its factorial."<<endl;
    cin>>n;
   if (n<0){                        // error checking to keep integers options within range.
    cout<<"invalid input"<<endl;
   }
   else if (n<=12){
   cout<< factorial(n)<<endl;
   }
    else{
    cout<< "invalid input"<<endl;
   }
}
unsigned long fibonacci(int n)  // this function uses the  classical style of Fibonacci numbers
{                               // uses recursion and calls self twice
   if( (n==1)||(n==2)){
      return 1;
   }
   else{
      return fibonacci(n-1)+fibonacci(n-2);
   }
}
void fibonacci_IO()
{
    int n;
    cout<<"Please enter a positive integer n, to find f(n) Fibonacci"<<endl;
    cin>>n;
    if (n==0){                          // used to set boundaries for range of function
        cout<<0<<endl;
    }
    else if(n<0){
        cout<<"invalid input"<<endl;
    }
    else if (n<=47){
        cout<<fibonacci(n)<<endl;
    }
    else{
        cout<<"invalid input"<<endl;
    }
}

unsigned long GCD(unsigned long n, unsigned long m) // unsigned lets negative signs not error out the function
{
    if (m == 0){
        return n;
    }
    else{
        return GCD(m,n%m);
    }
}
void GCD_IO()
{
    unsigned long n,m;
    cout<<"Please enter two positive values to find their greatest common divisor."<<endl;
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    cout<<"The GCD= "<<GCD(n,m)<<endl;
}
void  quadratic(int a, int b, int c, float &r1, float &r2)  // unable to find what is not working with this
{
    r1=((-1.0*b+sqrt(pow(b,2.0)-4.0*a*c))/(2.0*a));         // equations seem to work, but always has same output
    r2=((-1.0*b-sqrt(pow(b,2.0)-4.0*a*c))/(2.0*a));
}
void quadratic_IO()
{
    int a,b,c;
    float r1,r2;
    cout<<"Please enter the values of the coefficients of a quadratic equations of\nstyle ax^2+bx+c=0."<<endl;
    cout<<"a= ";
    cin>>a;
    cout<<"b= ";
    cin>>b;
    cout<<"c= ";
    cin>>c;
    if(pow(b,2.0)-4.0*a*c<=0){
        cout<<"imaginary number"<<endl;
    }
    else{
        cout<<"the first root is "<<r1<<endl;
        cout<<"the second root is "<<r2<<endl;
    }

}

