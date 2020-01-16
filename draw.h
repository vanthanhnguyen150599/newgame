#include<iostream>
#include<windows.h>
#include "system.h"

using namespace std;
int tamx = -1;
int tamy = -1;

toado level[10];

// =================== KHOI TAO LEVEL ===================
void initLevel()
{
	// ============== LEVEL 1 ===============
	
	// ============== LEVEL 2 ===============
	
	// ============== LEVEL 3 ===============
	
	// ============== LEVEL 4 ===============
	
	// ============== LEVEL 5 ===============
	
	// ============== LEVEL 6 ===============
	
	// ============== LEVEL 7 ===============
	
	// ============== LEVEL 8 ===============
	
	// ============== LEVEL 9 ===============
	
	// ============== LEVEL 10 ==============
	
}

// =================== VE KHUNG ===================
 void veKhung(int x, int y)
 {
	
	char traitren = 201;
	char phaiduoi = 188;
	char traiduoi = 200;
	char phaitren = 187;
	char ngang = 205;
	char doc = 186;
	AnConTro();
	for(int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (i == 1)
			{
				if (j == 1)
				{
					cout << traitren;
				}
				else
				{
					if (j == y)
					{
						cout << phaitren;
					}
					else
					{
						cout << ngang;
					}
				}
			}
			else
			{
				if (i == x)
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == y)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1 || j == y)
					{
						cout << doc;
					}
					else
					{
						cout << " ";
					}
				}
			}
		}
		gotoxy(wherex()-y, wherey()+1);
//		cout << endl;
	}
 }
 
 //====================== VE BAN HUNG ==================
 void veBan(int x, int y, int m, int n) // x,y la chieu dai + rong cua khung, m la toa do x, n la toa do y
 {
	AnConTro();
	if(tamx != m)
	{
		if (tamx == -1)
		{
			gotoxy(y/2-1-6+1,n);
			ChangeColor(144);
			cout << "            "; // 12
		}
		else
		{
			if (m > tamx) // Phim right
			{
				gotoxy(tamx-6,n);
				ChangeColor(15);
				cout << "  ";
				gotoxy(tamx+5+1,n);
				ChangeColor(144);
				cout << "  ";
			}
			if(m < tamx) // Phim left
			{
				gotoxy(tamx+4,n);
				ChangeColor(15);
				cout << "  ";
				gotoxy(tamx-6-2,n);
				ChangeColor(144);
				cout << "  ";
			}
		}
		tamx = m;
		tamy = n;
	}
 }
 void veBi(int x, int y) // x,y la toa do cua bi
 {
	gotoxy(x,y);
	ChangeColor(192);
	cout << "  ";
 }
 
 // ============================ XOA BI ========================
 void xoaBi(int x, int y)
 {
	gotoxy(x,y);
	ChangeColor(15);
	cout << "  ";
 }
 
 // ===================== VE LEVEL =========================
 void printLevel(int level)
 {
 	
 }
 
 //====================== HIEU UNG CHUYEN CANH ==============
 void chuyenCanh(int x, int y)
 {
 	AnConTro();
	for (int i = 1; i <= x-2; i++)
	{
		gotoxy(1,i);
		for (int j = 1; j <= y-2; j++)
		{
			ChangeColor(240);
			cout << " ";
		}
		Sleep(80);
	}
	for (int i = x-2; i >= 1; i--)
	{
		gotoxy(1,i);
			for (int j = 1; j <= y-2; j++)
		{
			ChangeColor(15);
			cout << " ";
		}
		Sleep(80);
	}
 }
