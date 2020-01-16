#include<iostream>
#include<windows.h>

using namespace std;

// ==================== FULL SCREEN ==========================
void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
//=============================HAM GOTOXY==========================
void gotoxy(int x, int y) // Di chuyen toa do con tro trong he toa do De-cat
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
//=====================TRA VE VI TRI X CUA CON TRO==============================
int wherex()
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
return screen_buffer_info.dwCursorPosition.X;
}
//=========================TRA VE VI TRI Y CUA CON TRO============================
int wherey( void )
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
return screen_buffer_info.dwCursorPosition.Y;
}
//==============================AN CO TRO MAN HINH CONSOLE=======================
void AnConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//==============================HIEN CON TRO MAN HINH CONSOLE================
void HienConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// =============================== DOI MAU CHU =================================
void ChangeColor(int k)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);
}
// ================================ TOA DO ====================================
struct toado
{
	int x;
	int y;	
};
