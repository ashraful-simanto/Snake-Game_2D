#include <conio.h>
#include <vector>
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int lenght = 2;
int lenghtmax = 2;

int x1 = 180;
int y1 = 300;

//int fx2,fy2,fy3,fx3,fx4,fy4;

char direc = '-';
char last = '-';
int speed=150;

int foodcnt=0;
bool flag=false;
bool play = true;
int rgb = 0;

int fruitx1,fruitx2,fruitx3,fruitx4,fruitx5,fruitx6,fruitx7,fruitx8;
int fruity1,fruity2,fruity3,fruity4,fruity5,fruity6,fruity7,fruity8;
bool eaten1 = false,eaten2 = false,eaten3 = false,eaten4 = false,eaten5 = false,eaten6 = false,eaten7 = false,eaten8 = false;

vector<int> snakex;
vector<int> snakey;

int i = 1;
int imax = 0;

char score[50];
int score1;

void fruit();
void graphic();
void move();
void start();
void update();

int main()
{
	start();

	while (play == true)
	{
		update();

		if (x1 >= 550 || x1 <50 || y1 >= 550 || y1 < 50) // inside the boundary
		{
			play = false; // game over
		}

		if (lenghtmax > 3 || direc != '-' && direc != 'w' && direc != 'a' && direc != 's' && direc != 'd' && direc != 'W' && direc != 'A' && direc != 'S' && direc != 'D')
		{
			for (lenght = lenghtmax; lenght >= 0; lenght--)
			{
				if (x1 == snakex[i] && y1 == snakey[i])
				{
					play = false; // hit by itself
				}

				i--;
			}

			i = imax;
		}
	}

	if (play == false)
	{
		cleardevice();
		setcolor(YELLOW);
		rectangle(160,160,430,430);

		setcolor(GREEN);
		rectangle(165,165,425,425);
        setcolor(YELLOW);
		rectangle(170,170,420,420);


        setcolor(RED);
        rectangle(220,230,360,260);
		outtextxy(250, 240, "GAME OVER");

		setcolor(YELLOW);
		outtextxy(255,305 , score);
		setcolor(GREEN);
        outtextxy(210, 360, "TRY BETTER NEXT TIME");
		getch();

	}
}

void start()
{
	sprintf(score, "SCORE : %d ", score1);


	initwindow(600, 600, "SNAKE GAME 2D");


	setcolor(WHITE);
	outtextxy(10, 0, score);

	fruitx1 = rand() % 55;  //  fruit red 1
	fruity1 = rand() % 55;
	fruity1 = fruity1 * 10;
	fruitx1 = fruitx1 * 10;

	if(fruity1 <=50){
		fruity1 +=50;
	}

		if(fruitx1 <=50){
		fruitx1+=50;
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx1, fruity1, fruitx1 + 10, fruity1 + 10);
	floodfill(fruitx1 + 5, fruity1 + 5, RED);

	fruitx2 = rand() % 55;     // fruit red 2
	fruity2 = rand() % 55;
	fruity2 = fruity2 * 10;
	fruitx2 = fruitx2 * 10;

	if(fruity2 <=50){
		fruity2 +=50;
	}

		if(fruitx2 <=50){
		fruitx2+=50;
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx2, fruity2, fruitx2 + 10, fruity2 + 10);
	floodfill(fruitx2 + 5, fruity2 + 5, RED);

	fruitx3 = rand() % 55;  //  fruit red 3
	fruity3 = rand() % 55;
	fruity3 = fruity3 * 10;
	fruitx3 = fruitx3 * 10;

	if(fruity3 <=50){
		fruity3 +=50;
	}

		if(fruitx3 <=50){
		fruitx3+=50;
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx3, fruity3, fruitx3 + 10, fruity3 + 10);
	floodfill(fruitx3 + 5, fruity3 + 5, RED);

	fruitx4 = rand() % 55;  //  fruit blue 1
	fruity4 = rand() % 55;
	fruity4 = fruity4 * 10;
	fruitx4 = fruitx4 * 10;

	if(fruity4 <=50){
		fruity4 +=50;
	}

		if(fruitx4 <=50){
		fruitx4+=50;
	}
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	rectangle(fruitx4, fruity4, fruitx4 + 10, fruity4 + 10);
	floodfill(fruitx4 + 5, fruity4 + 5, BLUE);

	fruitx5 = rand() % 55;  //  fruit blue 2
	fruity5 = rand() % 55;
	fruity5 = fruity5 * 10;
	fruitx5 = fruitx5 * 10;

	if(fruity5 <=50){
		fruity5 +=50;
	}

		if(fruitx5 <=50){
		fruitx5+=50;
	}
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	rectangle(fruitx5, fruity5, fruitx5 + 10, fruity5 + 10);
	floodfill(fruitx5 + 5, fruity5 + 5, BLUE);

	fruitx6 = rand() % 55;  //  fruit green 1
	fruity6 = rand() % 55;
	fruity6 = fruity6 * 10;
	fruitx6 = fruitx6 * 10;

	if(fruity6 <=50){
		fruity6 +=50;
	}

		if(fruitx6 <=50){
		fruitx6+=50;
	}
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	rectangle(fruitx6, fruity6, fruitx6 + 10, fruity6 + 10);
	floodfill(fruitx6 + 5, fruity6 + 5, GREEN);

	fruitx7 = rand() % 55;  //  fruit yellow 1
	fruity7 = rand() % 55;
	fruity7 = fruity7 * 10;
	fruitx7 = fruitx7 * 10;

	if(fruity7 <=50){
		fruity7 +=50;
	}

		if(fruitx7 <=50){
		fruitx7+=50;
	}
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	rectangle(fruitx7, fruity7, fruitx7 + 10, fruity7 + 10);
	floodfill(fruitx7 + 5, fruity7 + 5, YELLOW);

	//if(flag)


        	fruitx8 = rand() % 55;  //   bonus fruit 1
	fruity8 = rand() % 55;
	fruity8 = fruity8 * 10;
	fruitx8 = fruitx8 * 10;

	if(fruity8 <=50){
		fruity8 +=50;
	}

		if(fruitx8 <=50){
		fruitx8+=50;
	}




}

void update()
{
	sprintf(score, "SCORE : %d ", score1);

	delay(speed);

	snakex.push_back(x1);
	snakey.push_back(y1);

	fruit();

	move();

	graphic();

}

void move() // all move related things
{
	if (kbhit())
	{
		direc = getch();
	}

	if (direc == 'w' && last == 's' || direc == 'W' && last == 'S')
	{
		direc = last;
	}

	if (direc == 'a' && last == 'd' || direc == 'A' && last == 'D')
	{
		direc = last;
	}

	if (direc == 's' && last == 'w' || direc == 'S' && last == 'W')
	{
		direc = last;
	}

	if (direc == 'd' && last == 'a' || direc == 'D' && last == 'A')
	{
		direc = last;
	}

	last = direc;

	if (direc == 's' || direc == 'S')
	{
		y1 = y1 + 10;
	}

	if (direc == 'a' || direc == 'A')
	{
		x1 = x1 - 10;
	}

	if (direc == 'w' || direc == 'W')
	{
		y1 = y1 - 10;
	}

	if (direc == 'd' || direc == 'D')
	{
		x1 = x1 + 10;
	}

	else{
        direc=last;
	}

}

void graphic() // the graphic
{
	cleardevice();

	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	rectangle(0, 0, 600, 30);
    floodfill(5, 5, GREEN);

    setcolor(YELLOW);
    rectangle(50,50,550,550);
        setcolor(GREEN);
    rectangle(48,48,552,552);
        setcolor(YELLOW);
    rectangle(46,46,554,554);



	setcolor(WHITE);
	outtextxy(10, 10, score);

	setcolor(WHITE);
	outtextxy(250, 10, "SNAKE GAME 2D by Ashraful( 34 ) & Rubayet( 30 )");

	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx1, fruity1, fruitx1 + 10, fruity1 + 10); // fruit red 1
	floodfill(fruitx1 + 5, fruity1 + 5, RED);

		setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx2, fruity2, fruitx2 + 10, fruity2 + 10); // fruit red 2
	floodfill(fruitx2 + 5, fruity2 + 5, RED);

			setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx3, fruity3, fruitx3 + 10, fruity3 + 10); // fruit red 3
	floodfill(fruitx3 + 5, fruity3 + 5, RED);

		setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	rectangle(fruitx4, fruity4, fruitx4 + 10, fruity4 + 10); // fruit blue 1
	floodfill(fruitx4 + 5, fruity4 + 5, BLUE);

			setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	rectangle(fruitx5, fruity5, fruitx5 + 10, fruity5 + 10); // fruit blue 2
	floodfill(fruitx5 + 5, fruity5 + 5, BLUE);

				setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	rectangle(fruitx6, fruity6, fruitx6 + 10, fruity6 + 10); // fruit green 1
	floodfill(fruitx6 + 5, fruity6 + 5, GREEN);

				setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	rectangle(fruitx7, fruity7, fruitx7 + 10, fruity7 + 10); // fruit yellow 1
	floodfill(fruitx7 + 5, fruity7 + 5, YELLOW);


	if(flag && rgb == 0){
            				setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	rectangle(fruitx8, fruity8, fruitx8 + 20, fruity8 + 20); // bonus fruit
	floodfill(fruitx8 + 5, fruity8 + 5, RED);
	rgb = 1;

	}else if(flag && rgb == 1)
	{
	            				setcolor(GREEN);
	setfillstyle(SOLID_FILL,GREEN);
	rectangle(fruitx8, fruity8, fruitx8 + 20, fruity8 + 20); // bonus fruit
	floodfill(fruitx8 + 5, fruity8 + 5, GREEN);
	rgb = 2;
	}else if(flag && rgb == 2)
	{
        				setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(fruitx8, fruity8, fruitx8 + 20, fruity8 + 20); // bonus fruit
	floodfill(fruitx8 + 5, fruity8 + 5, BLUE);
	rgb = 0;
	}

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(x1, y1, x1 + 10, y1 + 10); // head
	floodfill(x1 + 5, y1 + 5, WHITE);

	for (int lenght = lenghtmax; lenght > 0; lenght--)
	{
		setcolor(GREEN);
		setfillstyle(SOLID_FILL, GREEN);
		rectangle(snakex[i], snakey[i], snakex[i] + 10, snakey[i] + 10); // tail
		floodfill(snakex[i] + 5, snakey[i] + 5, GREEN);
		i--;
	}

	imax++;
	i = imax;

}

void fruit() // fruit things
{
	if (x1 == fruitx1 && y1 == fruity1) // fruit red 1 hit
	{
		eaten1 = true;

	}

	if (eaten1 == true)
	{
		eaten1 = false;
		lenghtmax++;
				foodcnt++;
		score1+=2;
		lenght = lenghtmax;
		fruitx1 = rand() % 55;
		fruity1 = rand() % 55;
		fruity1 = fruity1 * 10;
		fruitx1 = fruitx1 * 10;

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx1 == snakex[i] && fruity1 == snakey[i])
			{
				fruitx1 = rand() % 55;
				fruity1 = rand() % 55;
				fruity1 = fruity1 * 10;
				fruitx1 = fruitx1 * 10;
			}

			i--;
		}

		if (fruity1 <=50)
		{
			fruity1 += 50;
		}
				if (fruitx1 <=50)
		{
			fruitx1 += 50;
		}

		i = imax;


	}

		if (x1 == fruitx2 && y1 == fruity2) // fruit red 2 hit
	{
		eaten2 = true;

	}
	if (eaten2 == true)
	{
		eaten2 = false;
		lenghtmax++;
				foodcnt++;
		score1+=2;
		lenght = lenghtmax;
		fruitx2 = rand() % 55;
		fruity2 = rand() % 55;
		fruity2 = fruity2 * 10;
		fruitx2 = fruitx2 * 10;

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx2 == snakex[i] && fruity2 == snakey[i])
			{
				fruitx2 = rand() % 55;
				fruity2 = rand() % 55;
				fruity2 = fruity2 * 10;
				fruitx2 = fruitx2 * 10;
			}

			i--;
		}

		if (fruity2 <=50)
		{
			fruity2 += 50;
		}
				if (fruitx2 <=50)
		{
			fruitx2 += 50;
		}

		i = imax;


	}

		if (x1 == fruitx3 && y1 == fruity3) // fruit red 3 hit
	{
		eaten3 = true;

	}

	if (eaten3 == true)
	{
		eaten3 = false;
		lenghtmax++;
		score1+=2;
				foodcnt++;
		lenght = lenghtmax;
		fruitx3 = rand() % 55;
		fruity3 = rand() % 55;
		fruity3 = fruity3 * 10;
		fruitx3 = fruitx3 * 10;

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx3 == snakex[i] && fruity3 == snakey[i])
			{
				fruitx3 = rand() % 55;
				fruity3 = rand() % 55;
				fruity3 = fruity3 * 10;
				fruitx3 = fruitx3 * 10;
			}

			i--;
		}

		if (fruity3 <=50)
		{
			fruity3 += 50;
		}
				if (fruitx3 <=50)
		{
			fruitx3 += 50;
		}

		i = imax;


	}

	if (x1 == fruitx4 && y1 == fruity4) // fruit blue 1 hit
	{
		eaten4 = true;

	}

	if (eaten4 == true)
	{
		eaten4 = false;
		lenghtmax++;
				foodcnt++;
		score1+=3;
		lenght = lenghtmax;
		fruitx4 = rand() % 55;
		fruity4 = rand() % 55;
		fruity4 = fruity4 * 10;
		fruitx4 = fruitx4 * 10;

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx4 == snakex[i] && fruity4 == snakey[i])
			{
				fruitx4 = rand() % 55;
				fruity4 = rand() % 55;
				fruity4 = fruity4 * 10;
				fruitx4 = fruitx4 * 10;
			}

			i--;
		}

		if (fruity4 <=50)
		{
			fruity4 += 50;
		}
				if (fruitx4 <=50)
		{
			fruitx4 += 50;
		}

		i = imax;


	}

		if (x1 == fruitx5 && y1 == fruity5) // fruit blue 2 hit
	{
		eaten5 = true;

	}

	if (eaten5 == true)
	{
		eaten5 = false;
		lenghtmax++;
				foodcnt++;
		score1+=3;
		lenght = lenghtmax;
		fruitx5 = rand() % 55;
		fruity5 = rand() % 55;
		fruity5 = fruity5 * 10;
		fruitx5 = fruitx5 * 10;

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx5 == snakex[i] && fruity5 == snakey[i])
			{
				fruitx5 = rand() % 55;
				fruity5 = rand() % 55;
				fruity5 = fruity5 * 10;
				fruitx5 = fruitx5 * 10;
			}

			i--;
		}

		if (fruity5 <=50)
		{
			fruity5 += 50;
		}
				if (fruitx5 <=50)
		{
			fruitx5 += 50;
		}

		i = imax;


	}

			if (x1 == fruitx6 && y1 == fruity6) // fruit green 1 hit
	{
		eaten6 = true;

	}

	if (eaten6 == true)
	{
		eaten6 = false;
		lenghtmax++;
				foodcnt++;
		score1+=5;
		lenght = lenghtmax;
		fruitx6 = rand() % 55;
		fruity6 = rand() % 55;
		fruity6 = fruity6 * 10;
		fruitx6 = fruitx6 * 10;

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx6 == snakex[i] && fruity6 == snakey[i])
			{
				fruitx6 = rand() % 55;
				fruity6 = rand() % 55;
				fruity6 = fruity6 * 10;
				fruitx6 = fruitx6 * 10;
			}

			i--;
		}

		if (fruity6 <=50)
		{
			fruity6 += 50;
		}
				if (fruitx6 <=50)
		{
			fruitx6 += 50;
		}

		i = imax;


	}

			if (x1 == fruitx7 && y1 == fruity7) // fruit yellow 1 hit
	{
		eaten7 = true;

	}

	if (eaten7 == true)
	{
		eaten7 = false;
		lenghtmax++;
		foodcnt++;
		score1+=7;
		lenght = lenghtmax;
		fruitx7 = rand() % 55;
		fruity7 = rand() % 55;
		fruity7 = fruity7 * 10;
		fruitx7 = fruitx7 * 10;

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx7 == snakex[i] && fruity7 == snakey[i])
			{
				fruitx7 = rand() % 55;
				fruity7 = rand() % 55;
				fruity7 = fruity7 * 10;
				fruitx7 = fruitx7 * 10;
			}

			i--;
		}

		if (fruity7 <=50)
		{
			fruity7 += 50;
		}
				if (fruitx7 <=50)
		{
			fruitx7 += 50;
		}

		i = imax;


	}

	if(foodcnt%7==0 && foodcnt>0){
        flag=true;
       // foodcnt-=7;
	}


			if ((x1==fruitx8 && y1==fruity8) || (x1==fruitx8+10 && y1==fruity8 )|| (x1==fruitx8+10 && y1==fruity8+10)|| (x1==fruitx8 && y1==fruity8+10 )) // bonus fruit 1 hit
	{
		eaten8 = true;
		flag=false;
		foodcnt=foodcnt%7;

	}

	if (eaten8 == true)
	{
		eaten8 = false;
		//lenghtmax++;
		score1+=15;
		lenght = lenghtmax;
		fruitx8 = rand() % 55;
		fruity8 = rand() % 55;
		fruity8 = fruity8 * 10;
		fruitx8 = fruitx8 * 10;

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx8 == snakex[i] && fruity8 == snakey[i])
			{
				fruitx8 = rand() % 54;
				fruity8 = rand() % 54;
				fruity8 = fruity8 * 10;
				fruitx8 = fruitx8 * 10;
			}

			i--;
		}

		if (fruity8 <=50)
		{
			fruity8 += 50;
		}
				if (fruitx8 <=50)
		{
			fruitx8 += 50;
		}

		i = imax;

	}
}
