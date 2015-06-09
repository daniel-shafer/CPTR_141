/*****************************************************************************
 Program file name:midterm		OS:Windows         		Assignment#:6/midterm
 Programmer:Daniel_Shafer		Class:CPTR_141 	Intro to programming	  Date:5/5/2015
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

using namespace std;

int main()
{
    double depRate(double resale, double original, double age, double &DepRate);
    void depRate_IO();                                              // prototyping equations that are created after the main.
    void loanTree();                                                // using IO functions creates a function to call their recursive copies.
    void foursum();
    void Swap(int n, int m);
    void Swap_IO();
    long long int cat(int n);
    void cat_IO();
    char option;                                // these are used for the options in the menu and replay choice.
    char choice;

    while(toupper(option) !='N'){                                                           // This is the menu for entering the equations. while lets it loop tell user is done.
        cout<<"\nHello user."<<endl;                                                        // it is in the while look so user can see choices each time.
        cout<<"This program has 5 different options to run."<<endl;
        cout<<"A: Returns annual depreciation rate."<<endl;
        cout<<"B: Outputs questions and results for loan decisions."<<endl;
        cout<<"C: Solves a^4+b^4+c^4+d^4=abcd"<<endl;
        cout<<"D: swaps inputs n and m"<<endl;
        cout<<"F: Returns the nth Catalan number."<<endl;
        cout<<"\nEnter the letter that corresponds to the program you wish to run."<< endl;
            cout << "\n - ";                                                                // added to try to keep it looking cleaner.
            cin >> choice;
            cout<<"\n";

        switch (toupper(choice)){ // switch statement to let user choose between which function to run.
            case 'A':
                depRate_IO();
                break;
            case 'B':
                loanTree();
                break;
            case 'C':
                foursum();
                break;
            case 'D':
                Swap_IO();
                break;
            case 'F':
                cat_IO();
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
double depRate(double resale, double original, double age, double &DepRate)
{
    DepRate=(1.0-pow((resale/original),(1.0/age)));

        return DepRate;                                     // return answer after plugging in variables.
}
void depRate_IO()
{
    cout.setf(ios::fixed);      // This sections is not required for the program, but was added to use only four decimals.
    cout.setf(ios::showpoint);
    cout.precision(4);

    double original,resale,age,DepRate=0;
    cout<<"Please enter the original price."<<endl;
    cin>> original;
    cout<<"Please enter the resale price."<<endl;
    cin>> resale;
    cout<<"Please enter the age."<<endl;
    cin>> age;
    if(original<=0){                                        // keep from dividing by 0
        cout<<" -1"<<endl;
    }
    else if (age<=0){                                        // keep from dividing by 0
        cout<<"-1"<<endl;
    }
    else {
        depRate(resale, original, age, DepRate);        // function call, and pass by reference
        cout<<"The Depreciation rate is "<<DepRate<<endl;
    }
}
void loanTree()                                                                 // basic decision tree
{                                                                               // no IO function needed
    char a;
    cout<<"y for yes, n for no"<<endl;                                          // y or Y = yes everything else = no
    cout<<"Is your income less than $30,000 a year?"<<endl;
    cin>>a;
        if (toupper(a)=='Y'){
            cout<<"Have you been at your current Job less then a year?"<<endl;
            cin>>a;
                if (toupper(a)=='Y'){
                    cout<<"No Loan."<<endl;
                }
                else{
                    cout<<"Do you have a criminal record?"<<endl;
                    cin>>a;
                        if (toupper(a)=='Y'){
                            cout<<"No Loan."<<endl;
                        }
                        else{
                            cout<<"Your eligible for a loan up to $100,000."<<endl;
                        }
                }
        }
        else{
            cout<<"Do you have a criminal record."<<endl;
            cin>>a;
                if (toupper(a)=='Y'){
                    cout<<"No Loan."<<endl;
                }
                else {
                    cout<<"Your eligible for a loan up to $500,000."<<endl;
                }
        }
}
void foursum()                                                  // basic for loops embedded
{
    int t;                                                      // no IO function needed
    for(int a=1; a<10; a++){                                    // no user input needed
        for(int b=1; b<10; b++){
            for(int c=1; c<10; c++){
                for(int d=1; d<10; d++){
                    t=pow(a,4)+pow(b,4)+pow(c,4)+pow(d,4);
                    if (t==a*1000+b*100+c*10+d){
                        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                    }
                }
            }
        }
    }
}
void Swap(int &n, int &m)               // added & for pass by reference
{
    int t;                              // did not need to redeclare n and m
    t=n;
    n=m;
    m=t;
}
void Swap_IO()                        // added whole IO function, test did not call for me to create it.
{
    int n,m;
    cout<<"please enter n"<<endl;
    cin>>n;
    cout<<"please enter m"<<endl;
    cin>>m;
    Swap(n,m);                        // pass by reference
    cout<<"n= "<<n<<endl;
    cout<<"m= "<<m<<endl;
}
long long int cat(int n)                    // recursion,
{
    if (n==0){                              // boundary condition
        return 1;
    }
    else{                                   // recursive definition
        return ((4*n+2)*cat(n-1))/(n+2);
    }
}
void cat_IO()
{
    int n;
    cout<<"please enter a value between 0 and 32"<<endl;    // added to ask user for input
    cin>>n;
    if (n<0){                                               // check to look at bounds
        cout<<"invalid input"<<endl;
    }
    else if (n>32){
        cout<<"invalid input"<<endl;
    }
    else {
        cout<<"The "<<n<<" number would be "<<cat(n)<<endl;
    }
}
