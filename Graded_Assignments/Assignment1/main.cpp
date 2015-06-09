/*****************************************************************************
 Program file name:Assignment1		OS:windows        		Assignment #:1
 Programmer:Daniel_Shafer			Class:CPTR_141 	Data Struct. I			Date:4-1-2015
 Compiler:GNU GCC
 // Your class is Intro to Programming, not Data Struct. I (-1 point)

 Assistance/references:Textbook

 Description:This assignment has us create a simple converter from Fahrenheit to Celsius.

 Inputs:Temperature Fahrenheit

 Outputs:Temperature Celsius

 Special Comments:

~~~~~~~~~~~~~~~~~~~~~~~~~~Grading Criteria~~~~~~~~~~~~~~~~~~~~~~~~~~

 Total Grade: 9.0/10.0

*****************************************************************************/
#include <iostream> // This tells the compiler to use the library iostream which includes the cout, cin objects.

using namespace std;// Works with #include <iostream> to use library.

// There is no need to comment EVERY line of code you write. Commenting all of
// the boilerplate will drive you crazy after a while. Just comment on the
// lines that are important to the program, or on anything that might look
// confusing to someone who was reading your program, or needs elaboration to
// sufficiently explain what you're doing with that part of the program.

int main()  // Says that main is a function with no parameters that returns an int value.
            // I got this form the book and could not think of how to reword the sentence.
{
   float F; //Declares the variable F and allows decimals.
   float Temp; // Declares the variable Temp for final output, and allows decimals.
   float C; // Declares variable C

    // I'm assuming you got this from the book? Either way, nice touch.
    // Cite your source next time (since this isn't usually code a beginner would be expected to know)
    // so I can award creative touches extra credit.
    cout.setf(ios::fixed);      // This sections is not required for the program, but was added to use only two decimals.
    cout.setf(ios::showpoint);  // Helps represent sig figs shown.
    cout.precision(2);          // Show to what precision it will show.

    // You don't need to "double space" your code. This isn't english class.
    // Line breaks are usually used to separate code chunks/blocks, rather than
    // being used every other line. (it's fine to do it the way you did it, but
    // it's convention to do it the other way, and generally looks cleaner)
    cout << "Please enter Temperature in Fahrenheit." << endl; // This is the prompt to ask the user to input a temperature value in Fahrenheit.

    cin >> F; //This takes the value entered and assigns it to F.

    Temp=(F-32)*5/9; // This line does the conversion to solve final Temperature in Celsius.

    cout << Temp << " Degrees Celsius" << endl; // This is the output for the new temperature given.

    // The rest of the program is extraneous to the assignment. The assignment only wanted
    // input from the user in Fahrenheit, and output from the console in Celsius.
    // (no points deducted this time. However, following the assignment requirements
    // is important. Often times going "above and beyond" can break your program in
    // unexpected ways, which is why most teachers/graders discourage it.)
    cout << "Please enter Temperature in Celsius." << endl; // This is the prompt to ask the user to input a temperature value in Celsius.

    cin >> C; //This takes the value entered and assigns it to C.

    Temp=9/5*C+32; // This line does the conversion to solve final Temperature in Fahrenheit.

    cout << Temp << " Degrees Fahrenheit" << endl; // This is the output for the new temperature given.

    return 0; // This line tells the program to end.
}
