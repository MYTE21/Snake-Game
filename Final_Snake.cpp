#include <bits/stdc++.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
using namespace std;

void check();
void End();
void win();
void Instruction();
void Continue();
void MainManu();

int m[500],n[500],snake_size=5;//snake_size is size of snake.
clock_t start,stop;

int d;
int score = 0;

int main()
{
freopen("GameData.txt","r",stdin); // File to read the high score
cin >> d;

int gd=DETECT,gm,ch,maxx,maxy,x=13,y=14,p,q,spd=150;
initgraph(&gd,&gm,"..\bgi");

/** Starting Screen*/

for(int lo=10;lo<=12;lo++)
{
    setcolor(lo); //Set the Color of menu background!.
    settextstyle(6,0,6); //font,0,size
    outtextxy(50,50," SNAKE GAME ");
    delay(500);

    setcolor(WHITE);
    settextstyle(2,0,8);
    outtextxy(80,200,"Loding.");
    delay(100);
    outtextxy(80,200,"Loding..");
    delay(100);
    outtextxy(80,200,"Loding...");
    delay(100);
    outtextxy(80,200,"Loding....");
    delay(100);
    outtextxy(80,200,"Loding.....");
    delay(100);

    cleardevice();
}

MainManu();  // Main Menu Screen

// Maximum point of the Ground
maxx=getmaxx();
maxy=getmaxy();

//randomize();

srand(time(0));
p=rand()%maxx; //food postion x;
int temp=p%13;
p=p-temp;
q=rand()%maxy; //food position y;
temp=q%14;
q=q-temp;

start=clock();
int w = 0,a=4,i=0,j,t;// a is key map,up,down,right,left.What is a, b , c & d?
int bonus=500;
bool isbonus = false;

//Game logic
while(1)
{
 if(score >0 && score%5==4) isbonus = true;
 else{ bonus = 500;
 isbonus = false;
 }
 if(!isbonus || bonus == 0){
 setcolor(BLACK);
 outtextxy(250,10,"Hurry!! 888");
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,WHITE);
 circle(p,q,5); //x position,y position,size
 floodfill(p,q,WHITE);
 }
 else
 {
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,WHITE);
 circle(p,q,5);
 floodfill(p,q,WHITE);

 char spp[1000];
 setcolor(BLACK);
 sprintf(spp,"Hurry!! %d",bonus);
 outtextxy(250,10,"Hurry!! 888");
 setcolor(MAGENTA);
 outtextxy(250,10,spp);
// clears
 }
   if( kbhit() )
   {
     ch=getch(); if(ch==0) ch=getch();
     if(ch==72&& a!=2)
         a=1; //down
     if(ch==80&& a!=1)
         a=2; //up
     if(ch==75&& a!=4)
         a=3; //left
     if(ch==77&& a!=3)
         a=4; //right
      }
       else
     {
     if(ch==27)
         break;
     }


       if(i<20)
        {
 		   m[i]=x;
 		   n[i]=y;
 		   i++;
	       }

		 if(i>19)

		 {
	 		  for(j=snake_size-2;j>=0;j--){
		 		  m[j+1]=m[j];
		 		  n[j+1]=n[j];
	 		 		  }

		   m[0]=x;
		   n[0]=y;

		   setcolor(RED); ///Head
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],RED);

		   setcolor(BLUE); /// From j=1 to tail
		   for(j=1;j<snake_size;j++)
            {
		   setfillstyle(SOLID_FILL,BLACK);
		   //cleardevice();
           circle(m[j],n[j],5);
		   floodfill(m[j],n[j],BLUE);
		   //cleardevice();
		 	}

            delay(spd);

           setcolor(BLACK);///mathar position black banaitesi
           setfillstyle(SOLID_FILL,BLACK);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],BLACK);

		   setcolor(BLACK);///lezer jaigata black banaitesi
		   setfillstyle(SOLID_FILL,BLACK);
		   circle(m[snake_size-1],n[snake_size-1],5);
		   floodfill(m[j],n[j],BLACK);

		   }
     stop=clock();
     t=(stop-start)/CLK_TCK;
     settextstyle(3,0,3);
     setcolor(YELLOW);
     char arr[1000];
     sprintf(arr,"HIGHSCORE %d",(int)d);
     outtextxy(400,00,arr);
     sprintf(arr,"SCORE %d",score);
     outtextxy(00,00,arr);
     sprintf(arr,"Press Alt to pause");
     outtextxy(200,420,arr);
     check();

    if(x==p&&y==q) {
     setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
 circle(p,q,5);
 floodfill(p,q,BLACK);


    snake_size++;score++,spd;

    if(score%5==0 && score>0)score+=bonus;

		 		      if(snake_size>400) win();
     p=rand()%maxx; temp=p%13;   p=p-temp;
     q=rand()%maxy; temp=q%14;   q=q-temp;
		 		    }
    if(a==1)  y =  y-14; if(y<0) { temp=maxy%14;y=maxy-temp;}
    if(a==2)  y =  y+14; if(y>maxy) y=0;
    if(a==3)  x =  x-13; if(x<0) { temp=maxx%13;x=maxx-temp;}
    if(a==4)  x =  x+13; if(x>maxx) x=0;
    if(a==0){  y = y+14 ;  x=x+13; }
    if(isbonus){
    if(bonus>0)
    bonus-=10;
    if(bonus==0){
         setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLUE);
 circle(p,q,15);
 floodfill(p,q,BLACK);
    }
    }
    if(spd <10) spd = 10;
		 }

 }

void check(){
   int a;
   for(a=1;a<snake_size;a++)

if(m[0]==m[a] && n[0]==n[a]) End();
   else continue;

   }
void End()

{
    freopen("GameData.txt","w",stdout);

    if(d < score)
    cout << score << endl;
    else cout << d << endl;

    int j,i;
   setcolor(WHITE);
   for(j=0;j<=snake_size;j++){
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }
    settextstyle(3,0,4);
    outtextxy(150,150,"    GAME OVER ");
    getch();
    cleardevice();
    exit(0);
}

void win()
{
int j,i;
setcolor(RED);
   for(i=0;i<5;i++){
   for(j=0;j<=snake_size;j++){
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],RED);
		  }
    delay(500);
    cleardevice();
    delay(500);
		 }
		 setcolor(GREEN);
  settextstyle(4,0,5);
  outtextxy(210,320," YOU WIN ");
  getch();
  exit(0);
}

void Instruction()
{
setcolor(GREEN);//Set color for next texts
settextstyle(6,0,1); // Set text style for next texts;
outtextxy(20,80," Use Arrow Keys To Direct The Snake ");
outtextxy(20,140," Avoid The Head Of Snake Not To Hit Any Part Of Snake");
outtextxy(20,160," Pick The Beats Untill You Win The Game ");
outtextxy(20,200," Press 'Esc' Anytime To Exit ");
outtextxy(20,250," Please wait ");
delay(1000);

setcolor(RED);//Set color for next texts
settextstyle(6,0,1); // Set text style for next texts;
outtextxy(20,250," Press Any Key TO Back To Main Menu ");
int ch=getch();
if(ch==27)
    exit(0);

cleardevice();
MainManu();
}

void MainManu()  // Main Menu of Snake Game
{
setcolor(BLUE);
settextstyle(6,0,5);
outtextxy(180,80,"Main Menu");
setcolor(5);
settextstyle(2,0,8);
outtextxy(80,180,"New Game (Press 1)");
settextstyle(2,0,8);
outtextxy(80,220,"Continue Game (Press 2)");
settextstyle(2,0,8);
outtextxy(80,260,"High Score (Press 3)");
settextstyle(2,0,8);
outtextxy(80,300,"Instruction (Press 4)");
int ch = getch();
if(ch==27)exit(0);
cleardevice();

if(ch == 52)
    {
        Instruction();
    }

    else if(ch == 51)
    {
        setcolor(GREEN);
        settextstyle(6,0,3);
        char arr[1000];
        sprintf(arr,"HIGH SCORE is   :  %d",(int)d);
        outtextxy(80,180,arr);
        setcolor(RED);//Set color for next texts
        settextstyle(6,0,1); // Set text style for next texts;
        outtextxy(20,250," Press Any Key TO Back To Main Menu ");
        ch = getch();
        cleardevice();
        MainManu();
    }

    else if(ch == 50)
        Continue();

    else if(ch == 49)
        cleardevice();
    else
        {cleardevice();
        MainManu();}
}

void Continue()
{
    setcolor(RED);
    settextstyle(6,0,6);
    outtextxy(80,200,"No Data Found");
    settextstyle(4,0,2);
    setcolor(BLUE);
    outtextxy(60,300,"Press Any Key To Back To Main Menu");
    int ch=getch();

    if(ch==27)exit(0);
    cleardevice();
    MainManu();
}


