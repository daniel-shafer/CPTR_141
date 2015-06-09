/*****************************************************************************
 Program file name:Assignment_#7		OS:Windows         		                    Assignment#:7
 Programmer:Daniel_Shafer		        Class:CPTR_141 	Intro to programming	    Date:5/22/2015
 Compiler: GNU GCC

 Assistance/references: class, text book, friend assisted with looping error
 Description: program saves a file with text user can enter, then calls the file and counts size of words.
 Inputs: decisions, file name, file calls
 Outputs: word count
 Special Comments: if program c is ran before program a creates a file, and b calls the file, there will be an infinite loop.
 would fix with if loop but ran into errors, and don't have the time.

~~~~~~~~~~~~~~~~~~~~~~~~~~Grading Criteria~~~~~~~~~~~~~~~~~~~~~~~~~~

 Assignment Requirements ___/3.0

 Code Format/Cosmetics ___/3.0

 Header & Code Comments: ___/2.0

 Output Format/Cosmetics ___/2.0
 ***Does Not Compile***: ___ (-10.0)
 ***Late Work Deduction***: ___ (-0.5/day)
 Total Grade: ___/10.0

*****************************************************************************/
#include <iostream>     //
#include <fstream>      //
#include <cstdlib>      //
#include <string>       //
#include <iomanip>      // setw();

using namespace std;

void writeDisk()                                                                // creates a file path and lets input be saved to it
{
    const int size = 32767;                                                     // used as max size of file
    char line[size];
    char *filename=new char[size];                                              //sets filename= to char within set size
    ofstream fout;

    cout<<"To write a file to disk, enter its path and filename.extension:\n";
    cin.ignore(10,'\n');
    cin.getline(filename,size);                                                 //takes user input and creates file path
    fout.open(filename);
    if(!fout)                                                                   // error check if fout does not exist
    {
        cerr<<" Failure trying to create disk file: "<<filename;
        system("PAUSE");
        exit(0);
    }
    cout<<"Enter lines of text.\n";
    cout<<"To quit, enter <ctrl-z> by itself on the last line:\n";

    while(!cin.getline(line,size).eof())                                        // gets the input and saves it to variable
        fout<<line<<endl;
    fout.close();                                                               // closes the function
    cin.clear();                                                                // clears to input buffer after file saved
}
void readDisk(int freq[])                                                       // lets user read existing files
{                                                                               // function has no output, but sets a file to be read for function C.
    const int size = 81;                                                        // sets size of input
    char filename[size];
    string word;                                                                // takes each word as a string to be counted
    ifstream fin;                                                               //

    cout<<"Enter path and filename of the file from which to read:\n";
    cin.ignore(10,'\n');                                                        // added to help improve cin.getline
    cin.getline(filename, size);                                                // gets filename to access and count size of words
    fin.open(filename);                                                         // opens the file
    if(!fin)                                                                    // error check if file does not exist, or wont open
    {
        cerr<<"Failure to open disk file: "<<filename;
        system("PAUSE");
        exit(0);
    }
    for(int i=0; i<=29; i++){                                                   // sets all of freq[] to NULL
        freq[i]=0;
    }
    while(fin>>word){                                                           // increments the freq[word.length()] array by one each time is true
        freq[word.length()]++;                                                  // used later for graph of word size usage
    }
    fin.close();                                                                // closes the function
}
void histogram(int freq[])                                                      //creates a graph of the number of times each sized word is used
{
    string line;                                                                // access to were the words were stored in line
    cout<<endl<<"No. of Words -> ";
    for(int i=0; i<=40; i+=5)                                                   // out put of size of each word
        cout<<i<<setw(5);
    line.assign(57, '-');                                                       // used for formating
    cout<<endl<<line<<endl;
    cout<<" of Length:    ";
    for(int i=1; i<=21; i++)                                                    // loop to look at the number of times each part of freq[] is entered
    {
        cout<<i;
        for(int j=1; j<=freq[i]; j++)                                           // ads symbol 219 i times to freq[]
        cout<<char(219);
        cout<<endl<<setw(16);
    }
}
int main()                                                                      //
{                                                                               // deceleration of variables
    int freq[30];                                                               //
    char c;

    while(toupper(c) !='N'){

        cout<<"\nHello user."<<endl;
        cout<<"A: Create new file"<<endl;
        cout<<"B: Read existing file so that the word count can be tallied and graphed\n   for option c."<<endl;
        cout<<"C: If you would like to to bar chart of word-length frequency distribution."<<endl;
        cout<<"\nEnter the letter that corresponds to the program you wish to run."<< endl;
        cout << "\n - ";
        cin >> c;
        cout<<"\n";

        switch (toupper(c)){
            case 'A':
                writeDisk();
                break;
            case 'B':
                readDisk(freq);
                break;
            case 'C':
                histogram(freq);
                break;
            default:
                break;
        }

        cout<<"Would you like to continue?\n";
        cout<<"Enter Y for yes, or N for no."<<endl;
        cin >> c;
    }
    return 0;
}
/*int main()                                                        // given function that was changed to menu style
{
    int freq[30];

    writeDisk();
    readDisk(freq);
    histogram(freq);

    system("PAUSE");
    return 0;
}*/

