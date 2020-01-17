#include<iostream>
#include<windows.h>
#include<conio.h>
#include <cstdlib>
#include <pthread.h>
#include<time.h>
#include<cstdio>
#include <winbgim.h>
#include "draw.h"
#define so_thread 2

using namespace std;

int tamx1 = 31; //block: 1-2-3-4-5-6-tamx1-8-9-10-11-12
int tamy1 = 31;

int dimx = 1;
int dimy = 1;
toado dot;

void prepare()
{
	dot.x = 31;
	dot.y = 30;
	fullscreen();
	veKhung(40,62);
	veBan(40,62,31,31);
	veBi(31,30);

}
bool isGameOver()
{
	if (dot.y > 31) return true;
	return false;	
}
void checkPress(char &c, bool &kytu)
{
	c = getch();
	if (c == -32 || c == 0)
	{
		kytu = 0;
		c = getch();
	}
	else
	{
		kytu = 1;
	}
	if (c == 75 && !kytu  && tamx1 > 7) // left
	{
		tamx1 = tamx1 - 2;
		veBan(40,62,tamx1,tamy1);
		if (dot.y == 30)
		{
			xoaBi(dot.x,dot.y);
			dot.x = dot.x -2;
			veBi(dot.x,dot.y);
//			gotoxy(70,0);
//			cout << "left " << " " << tamx1;
		}
	}
	if (c == 77 && !kytu && tamx1 < 55) // right
	{
		tamx1 = tamx1 + 2;
		veBan(40,62,tamx1,tamy1);
		if (dot.y == 30)
		{
			xoaBi(dot.x,dot.y);
			dot.x = dot.x + 2;
			veBi(dot.x,dot.y);
//			gotoxy(70,0);
//			cout << "right" << " " << tamx1;
		}
		
	}
}
void chayBi(int &dem, clock_t &batdau)
{
	batdau = clock();
	Sleep(2);
	dem = dem + 2;
	if(dem >= 30){
	xoaBi(dot.x,dot.y);
	dot.x = dot.x + 2*dimx;
	dot.y = dot.y - dimy;
	veBi(dot.x,dot.y);
	if (dimx == 1)
	{
		if (dimy == 1)
		{
			if (dot.x + 2 >= 61)
			{
				dimx = -dimx;
			}
			if (dot.y - 1 <= 0)
			{
				dimy = -dimy;
			}
		}
		else
		{
			if (dot.x + 2 >= 61)
			{
				dimx = -dimx;
			}
			if (dot.y + 1 == 31)
			{
				if ((tamx1-6) <= dot.x+2  && (tamx1+4) >= dot.x)
				{
					if (tamx1-6 == dot.x+2)
					{
						dimx = -dimx;
					}
					dimy = -dimy;
				}
			}
		}
	}
	else
	{
		if (dimy == 1)
		{
			if (dot.x - 2 <= 0)
			{
				dimx = -dimx;
			}
			if (dot.y - 1 <= 0)
			{
				dimy = -dimy;
			}
		}
		else
		{
			if (dot.x - 2 <= 0)
			{
				dimx = -dimx;
			}
			if (dot.y + 1 == 31)
			{
				if ((tamx1-6) <= dot.x  && (tamx1+4) >= dot.x-2)
				{
					if (tamx1+4 == dot.x-2)
					{
						dimx = -dimx;
					}
					dimy = -dimy;
				}
			}
		}
	}
	dem = 0;
	}
	dem = dem + ((double)(clock() - batdau)/CLOCKS_PER_SEC)*1000;
}
void Pause()
{
	gotoxy(28,20);
	srand(time(NULL));
	ChangeColor(1+rand()%15);
	cout << "PAUSE";
	Sleep(50);
	gotoxy(28,20);
	ChangeColor(15);
	cout << "     ";
}
void run()
{
	bool pause = 0;
	int dem = 0;
	bool start = 0;
//	pthread_t threads[so_thread];
	char c;
	bool kytu;
	clock_t batdau;
	int thoigian;
	while (!isGameOver() && c != 27)
	{
		batdau = clock();
		if (kbhit() && !ismouseclick(WM_LBUTTONDOWN) && !ismouseclick(WM_RBUTTONDOWN))checkPress(c,kytu);
		while (start && c == 112 && kytu) 
		{
			Pause();
			if (kbhit() && !ismouseclick(WM_LBUTTONDOWN) && !ismouseclick(WM_RBUTTONDOWN))checkPress(c,kytu);
		}
		if (c == 32) start = 1;
		thoigian = (((double)(clock() - batdau)/CLOCKS_PER_SEC)*1000);
//		gotoxy(70,1); cout << thoigian;
		dem = dem+thoigian;
		if (start)chayBi(dem,batdau);
	}
}
