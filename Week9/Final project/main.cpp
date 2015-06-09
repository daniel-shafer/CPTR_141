#include <cstdlib>
#include <iostream>
#include <graphics.h>
#include <windows.h>
using namespace std;

void redbubbly(int x, int y)
{
   setcolor(MAGENTA);
   setfillstyle(SOLID_FILL,MAGENTA);
   circle(x+25,y+35,20);
   circle(x+45,y+55,10);
   circle(x+5,y+55,10);
   circle(x,y+25,10);
   circle(x+50,y+25,10);
   circle(x+25,y,15);
   floodfill(x+25,y+35,MAGENTA);
   floodfill(x+45,y+55,MAGENTA);
   floodfill(x+5,y+55,MAGENTA);
   floodfill(x,y+25,MAGENTA);
   floodfill(x+50,y+25,MAGENTA);
   floodfill(x+25,y,MAGENTA);
}
void greenbubbly1(int x,int y)
{
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    circle(x+25,y+35,20);
    circle(x+45,y+55,10);
    circle(x+5,y+55,10);
    circle(x,y+25,10);
    circle(x+50,y+25,10);
    circle(x+25,y,15);
    floodfill(x+25,y+35,GREEN);
    floodfill(x+45,y+55,GREEN);
    floodfill(x+5,y+55,GREEN);
    floodfill(x,y+25,GREEN);
    floodfill(x+50,y+25,GREEN);
    floodfill(x+25,y,GREEN);
}
void squaresun(int x,int y)
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    rectangle(x,y,x+40,y+40);
    floodfill(x+20,y+20,YELLOW);
}
void circlemoon(int x, int y)
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    circle(x,y,40);
    floodfill(x,y,BLUE);
}
void night()
{
    readimagefile("night.jpg",0,0,1000,650);
}
void day()
{
    readimagefile("day.jpg",0,0,1000,650);
}
void space()
{
    readimagefile("space.jpg",0,0,1000,650);
}
void circleworld()
{
    readimagefile("circleworld.jpg",0,0,1000,650);
}
void explosion()
{
    readimagefile("explosion.jpg",0,0,1000,650);
}
void spaceship(int x,int y,int z)
{
    readimagefile("spaceship.jpg",x,y,x+120-z,y+70-z);
}


int main()
{
   initwindow(1000, 650);
   for(int i=0; i<=46; i++)
   {
    int note[]={698,0,698,659,698,0,698,659,698,0,698,659,587,294,392,687,698,988,349,294,294,294,294,294,294,294,294,440,
                523,440,0,784,698,440,784,698,0,784,784,784,784,440,784,440};
    int time[]={750,500,500,500,500,1000,500,500,500,750,500,500,1000,250,250,250,250,500,500,500,500,
                500,500,500,500,500,500,250,250,500,500,250,250,500,500,500,500,250,250,500,250,250,500,500};

        Beep(note[i], time[i]);  // To slow down the tune, multiply

        night();
        circlemoon(1000-23*i,100-.1*23*i);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1+.05*i);
        setcolor(RED);
        outtextxy(100,100,"BUBBLE MAN");
        //swapbuffers();   //Swap the memory buffers.
        //delay(1);
        //clearviewport(); //Erase the active page before writing to it
   }
   /*for(int i=0;i<=700;i++)
   {
       day();
       squaresun(1000-i,100-.1*i);
       if(i>100&&i<300){
        redbubbly(240+i,480);
       }
       if(i>300)
       {
           redbubbly(540,480);
           settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
           setcolor(WHITE);
           outtextxy(520,440,"What a nice day.");
       }
       if(i>500)
       {
           spaceship(540,200,0);
           outtextxy(520,440,"What is that?    ");
       }
       swapbuffers();
       delay(1);
       clearviewport();
   }
    swapbuffers();
    clearviewport();
    day();
    redbubbly(540,480);
    spaceship(540,200,0);
    greenbubbly1(640,480);
    greenbubbly1(440,480);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(520,440,"Who are you?    ");
    swapbuffers();
    delay(3000);
    clearviewport();
    day();
    spaceship(540,200,0);
    delay(3000);
    swapbuffers();
    clearviewport();
*/
   cout << "Close window to terminate . . .\n";
   cin.get();
   closegraph();
   return 1;
}
