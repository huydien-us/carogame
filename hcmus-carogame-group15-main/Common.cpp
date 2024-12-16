#include "Header.h"
#include "Common.h"
//Cố định màn hình Console
HWND consoleWindow = GetConsoleWindow();
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void setUpConsole()
{
    setFontInfo();
    CenterWindow();
    disableMaximize();
    hideScrollBars();
    showCursor(false);
    disableMouseInput();
}
//Di chuyển con trỏ tới vị trí x,y
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Căn giữa màn hình console
void CenterWindow()
{
	int width = 1216;
	int height = 784;
	int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	MoveWindow(consoleWindow, posX, posY, width, height, TRUE);
}

//Ẩn thanh cuộn
void hideScrollBars()
{
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

//Cài đặt màu nền
void setConsoleColor(int background, int text)
{
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
}

//Xóa màn hình console
void clearConsole()
{
	system("cls");
}

//Vô hiệu hóa phóng to màn hình
void disableMaximize()
{
	SetWindowLong(consoleWindow, GWL_STYLE,
		GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

//Ẩn hoặc hiện con trỏ
void showCursor(bool show)
{
	CONSOLE_CURSOR_INFO info = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &info);
}

//Cài đặt font chữ
void setFontInfo()
{
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = 12;
	info.dwFontSize.Y = 24;
	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
}

//Vô hiệu hóa chuột
void disableMouseInput()
{
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

//Lấy lệnh từ bàn phím
int getConsoleInput()
{
	int c = _getch();
	if (c == 27)                  //ESC
		return 1;
	else if (c == 87 || c == 119) //W, w
		return 2;
	else if (c == 65 || c == 97)  //A, a
		return 3;
	else if (c == 68 || c == 100) //D, d
		return 4;
	else if (c == 83 || c == 115) //S, s
		return 5;
	else if (c == 13)             //Enter
		return 6;
	else if (c == 80 || c == 112) //P, p
		return 7;
	else
		return 0;                 //nút khác

}

//Cài đặt màu
void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

void setColor(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}



