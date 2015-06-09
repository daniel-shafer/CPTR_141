#include <cstdlib>
#include <iostream>
#include <graphics.h>              	//to include the BGI graphics needed to display this code.
#include <math.h>       		// Needed for the pow function.
#include <windows.h>    		// Needed for Beep functions.

using namespace std;

void redbubbly(int x, int y)        //this is the calling function for the magenta character.
{
   setcolor(MAGENTA);               //this sets the color for the character
   setfillstyle(SOLID_FILL,MAGENTA);
   circle(x+25,y+35,20);
   circle(x+45,y+55,10);
   circle(x+5,y+55,10);             //these are for the dimensions of the circles for the magenta character, set with respect to x and y so that we can move them.
   circle(x,y+25,10);
   circle(x+50,y+25,10);
   circle(x+25,y,15);
   floodfill(x+25,y+35,MAGENTA);    //same thing but for the fill.
   floodfill(x+45,y+55,MAGENTA);
   floodfill(x+5,y+55,MAGENTA);
   floodfill(x,y+25,MAGENTA);
   floodfill(x+50,y+25,MAGENTA);
   floodfill(x+25,y,MAGENTA);
}
void greenbubbly1(int x,int y)      //this is the calling function for the green character.
{
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    circle(x+25,y+35,20);
    circle(x+45,y+55,10);
    circle(x+5,y+55,10);            //these are for the dimensions of the circles for the green character, set with respect to x and y so that we can move them.
    circle(x,y+25,10);
    circle(x+50,y+25,10);
    circle(x+25,y,15);
    floodfill(x+25,y+35,GREEN);
    floodfill(x+45,y+55,GREEN);
    floodfill(x+5,y+55,GREEN);      //same thing but for the fill.
    floodfill(x,y+25,GREEN);
    floodfill(x+50,y+25,GREEN);
    floodfill(x+25,y,GREEN);
}
void squaresun(int x,int y)         //calling function for the square sun character.
{
    setcolor(YELLOW);               //colors the square yellow
    setfillstyle(SOLID_FILL,YELLOW);//fills the square yellow.
    rectangle(x,y,x+40,y+40);       //this is the position of the sun with respect to x and y so that it is movable.
    floodfill(x+20,y+20,YELLOW);    //position of fill also movable.
}
void circlemoon(int x, int y)       //calling function for moon character.
{
    setcolor(BLUE);                 //colors the circle blue
    setfillstyle(SOLID_FILL,BLUE);  //fills the circle with solid blue.
    circle(x,y,40);                 //also in terms of x and y for mobility.
    floodfill(x,y,BLUE);            //mobility for inside of moon.
}
void night()                        //calling function for the night.
{
    readimagefile("night.jpg",0,0,1000,650); //reads the image file titled night and prints it inside the window
}
void day()                          //calling function for the day image.
{
    readimagefile("day.jpg",0,0,1000,650); //reads image file named day and prints it in the window.
}
void space()                        //calling function for the space image
{
    readimagefile("space.jpg",0,0,1000,650); //reads image file named space and prints it in the window
}
void circleworld()                  //calling function for the circular world
{
    readimagefile("circleworld.jpg",0,0,1000,650);//reads image file named circleworld and prints it in the window.
}
void explosion()                    //calling function for the explosion
{
    readimagefile("explosion.jpg",0,0,1000,650);//reads image file named explosion and prints it in the window.
}
void spaceship(int x,int y,int z)   //calling function for the spaceship
{
    readimagefile("spaceship.jpg",x,y,x+120-z,y+70-z);//reads image file named spaceship and prints it at the coordinates shown in terms of x and y for mobility.
}
void spaceship_b(int x,int y,int z) //calling function for the second spaceship
{
    readimagefile("spaceship_b.jpg",x,y,x+150-z,y+150-z);//reads image file named spaceship_b and prints it at the coordinates shown in terms of x and y for mobility.
}
void spaceship_c(int x,int y,int z) //calling function for the third spaceship
{
    readimagefile("spaceship_c.jpg",x,y,x+150-z,y+100-z);//reads image file named spaceship_c and prints it at the coordinates shown in terms of x and y for mobility.
}
void cloud(int x,int y)             //calling function for the cloud
{
    readimagefile("cloud.jpg",x,y,x+100,y+100);//reads image file named cloud and prints it at the coordinates shown in terms of x and y for mobility.
}
int main()
{
   initwindow(1000, 650);           //sets window size

   for(int i=0; i<=500; i++)     //for statement that introduces the variable i so that we can move the moon across the screen and increase the size of the title.
   {
        night();                    //sets background to night by calling night function above.
        circlemoon(1000-2*i,100-.2*i);//calls circlemoon function above and sets movement through for statement above.
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1+.005*i); //increases font size of title by increments of .005i
        setcolor(RED);              //sets title color as red.
        outtextxy(100,100,"BUBBLE MAN"); //actual title being outputted in red default font and increased by .005i
        swapbuffers();              //Swap the memory buffers.
        delay(1);
        clearviewport();            //Erase the active page before writing to it.
   }
	int note []={698,0,698,659,698,0,698,659,698,0,698,659,587,294,392,687,698,988,349,294,294,294,294,294,294,294,294,440,
                    523,440,0,784,698,440,784,698,0,784,784,784,784,440,784,440};
    	int time[]= {750,500,500,500,500,1000,500,500,500,750,500,500,1000,250,250,250,250,500,500,500,500,
                    500,500,500,500,500,500,250,250,500,500,250,250,500,500,500,500,250,250,500,250,250,500,500};
    	for (int i=0; i<44; i++)
    	{
       	 Beep(note[i], .5*time[i]);  // To slow down the tune, multiply
   	}
   for(int i=0;i<=700;i++)          //for statement that allows functions below to move as i increases.
   {
       day();                       //calls the day function above.
       squaresun(1000-i,100-.1*i);  //calls the sun function above and sets movement through variable i
       cloud(300,20);               //calls the cloud function above and prints it in one place.
       if(i>100&&i<300){            //if statement that sets when to call the red character function so it appears out of the house
       redbubbly(240+i,480);
       }
       if(i>300)
       {
           redbubbly(540,480);      //sets red character to stop outside the house
           settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
           setcolor(WHITE);
           outtextxy(520,440,"What a nice day."); //outputs white text near red character
       }
       if(i>500)
       {
           spaceship(540,200,0);     //calls the spaceship function from above and places it at the cords shown if i is greater than 500
           outtextxy(520,440,"What is that?    "); //outputs text next to the red character
       }
       if(i>600)
       {
           setcolor(GREEN);         //if i is greater than 600, then these two diagonal green lines will appear with starting and ending points as shown.
            moveto(590,240);
            lineto(490,460);
            moveto(610,240);
            lineto(680,460);
       }
       swapbuffers();               //swapping buffer memory
       delay(1);
       clearviewport();             //erase the active page before writing to it
   }
	float twelfRoot2 = pow(2, 1.0/12.0);    // Use the twelfth root of 2 for increasing frequencies by half steps.
    int note2 = 1047;                       // Start on the note A = 440 cycles/sec.
    for (int i=1; i<=13; i++)               // Loop over an octave of 13 half steps.
    {
        Beep(note2, 150);                   // Play each note for 500 milliseconds = 1/2 sec.
        note2 = int(twelfRoot2*note2);      // Go up a half step for the next note.
    }
    swapbuffers();
    clearviewport();
    day();                          //calls the day function from above.
    cloud(300,20);                  //calls the cloud function to the cords shown
    redbubbly(540,480);             //calls the red character function to the cords shown
    spaceship(540,200,0);           //calls the spaceship function from above to cords shown
    greenbubbly1(640,480);          //calls the green character function twice for two green characters at the cords shown.
    greenbubbly1(440,480);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(520,440,"Who are you?    "); //outputs white text next to red character
    swapbuffers();
    delay(1000);
    clearviewport();
    day();                          //calls the day function from above.
    spaceship(540,200,0);           //calls spaceship function.
    delay(1000);
    clearviewport();                //erase the active page before writing to it
    for(int i=0; i<=700;i++)        //for statement with variable i for movement below.
        {
            day();                  //calls day function again
            cloud(300,30);
            spaceship(540-i,200,0); //calls spaceship function and moves it according to the expressions of i.
            if(i>450)               //if statement that creates a moving square when i is greater than 450, to appear to come out of spaceship.
            {
                setcolor(RED);      //its a red square
                setfillstyle(SOLID_FILL,RED); //fills square with red
                rectangle(110+(i-450),250+(i-450),120+(i-450),260+(i-450)); //block moves according to i
                floodfill(115+(i-450),255+(i-450),RED);//fill moves according to i
            }
            swapbuffers();
            delay(1);
            clearviewport();
        }
        delay(1000);
    swapbuffers();
    clearviewport();
    for(int i=0;i<=200;i++)       //for statement that allows for movement in the functions below.
    {
        space();                  //calls space function above
        spaceship_b(200,270-i,300);//calls spaceship_b function from above and moves it up with respect to i.
        swapbuffers();   //Swap the memory buffers.
        delay(1);
        clearviewport(); //Erase the active page before writing to it.
    }
	int note3 []= {247,262,247,262,247,262,247,262,247,262,247,262,247,262,247,262,1047,988};       //A,B,A,B,A,B,A,B,A,B,A,B,A,B,A,B,C,B
    int time3 []= {1000,1000,1000,1000,500,500,500,500,250,250,250,250,250,250,250,250,250,500};    //times
    for (int i=0; i<18; i++)
    {
        Beep(note3[i], .5*time3[i]);                                                                // To slow down the tune, multiply
    }
    for(int i=0;i<=300;i++)     //for statement that allows movement for functions below as i increases
    {
        space();                //calls the space function above.
        spaceship_b(200+i*2,50+i,i/2);//calls spaceship_b function above to position that changes with as i increases
        swapbuffers();          //Swap the memory buffers.
        delay(1);
        clearviewport();        //Erase the active page before writing to it.
    }
   for(int i=0; i<=800; i++)    //for statement that allows for movement as i increases for functions below.
    {
        circleworld();          //calls the circleworld function above
        if(i<500)               //if statement for when i is less than 500, spaceship moves to the right with respect to i
        {
            spaceship_c(i,100,0);
        }
        if(i>500&&i<780)        //if statement to call spaceship and red and green bubblies when i is between 500 and 780
        {
            spaceship_c(500+2*(i-500),100,0); //spaceship flies away to the right
            redbubbly(500,170-(500-i)); //red and green bubblies fall from spaceship to ground
            greenbubbly1(580,170-(500-i));

        }
        if(i>780)               //if statement when i is greater than 780, the bubblies are no longer in terms of i, so are stationary.
        {
            redbubbly(500,470);
            greenbubbly1(580,470);
            setcolor(WHITE);
            outtextxy(450,370,"Where are we?"); //outputs text next to the bubblies for dialog
            delay(50);
            outtextxy(550,390,"This is where you are from.");
            delay(100);

        }
        swapbuffers();
        delay(1);
        clearviewport();
   }

    for(int i=0;i<320;i++)      //for statement that allows for movement in the functions below in terms of increasing i.
    {
        if(i<300)               //if statement that calls circleworld, bubbly functions when i is less than 300.
        {
            circleworld();
            redbubbly(500-i,470);//both bubblies move to the left
            greenbubbly1(580-i,470);
        }
        if(i>300)               //if i is greater than 300, then circleworld is called again, and the bubblies are again stationary in front of the house.
        {
            circleworld();
            redbubbly(200,470);
            greenbubbly1(280,470);
            settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
            setcolor(WHITE);
            outtextxy(130,380,"Who are you?");//outputting text for the last time for dialogue between bubblies.
            delay(50);
            outtextxy(230,400,"Luke I am your Father!!!!");
            delay(100);
        }
            swapbuffers();
            delay(1);
            clearviewport();
    }
     for (int n=0;n<2080;n++) // for loop for final credits
    {
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
        setcolor(GREEN);
        setbkcolor(BLUE);
        outtextxy(100,640-n,"Thanks For Watching!");
        outtextxy(100,840-n,"Daniel Shafer as Team Leader/Lead Programmer");
        outtextxy(100,1040-n,"Jesse Noble as Secretary/Credit Programmer");
        outtextxy(100,1240-n,"Julie Barrow as Function Programmer");
        outtextxy(100,1440-n,"Jose Garcia as Sound Programmer");
        outtextxy(100,1640-n,"Nutt Noppakaosaengnimit as Graphics Designer");
        outtextxy(100,1840-n,"And");
        outtextxy(100,2040-n,"Austin Kidder as Documentation");
        swapbuffers();
        delay(5);
        clearviewport();
    }

   closegraph();        //closes window we initiated in the beginning
   return 1;
}
