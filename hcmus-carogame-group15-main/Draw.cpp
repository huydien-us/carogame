#include "Draw.h"
using namespace std;

/*0 = Black    8 = Gray
1 = Blue       9 = Light Blue
2 = Green      10 = Light Green
3 = Aqua       11 = Light Aqua
4 = Red        12 = Light Red
5 = Purple     13 = Light Purple
6 = Yellow     14 = Light Yellow
7 = White   15 = Bright White
*/

//vẽ bảng
void printBoard(int left, int top, int width, int height, int color)
{
	setConsoleColor(15, color);
	GotoXY(left, top);
	putchar(201);
	for (int i = 1; i < width; i++)
	{
		putchar(205);
	}
	putchar(187);


	for (int i = 1; i < height; i++)
	{
		GotoXY(left, top + i);
		putchar(186);
		GotoXY(left + width, top + i);
		putchar(186);
	}
	GotoXY(left, top + height);
	putchar(200);
	for (int i = 1; i < width; i++)
	{
		putchar(205);
	}
	putchar(188);
}

//in thanh loading
void Loading() {
	char a = 176, b = 219;
	setColor(0);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading...\n\n";
	cout << "\t\t\t\t\t\t";
	setColor(0);
	for (int i = 0; i < 25; i++) {
		putchar(a);
	}
	cout << "\r";
	cout << "\t\t\t\t\t\t";
	for (int j = 0; j < 25; j++) {
		putchar(b);
		Sleep(80);
	}
	showCursor(0);
}

//vẽ bàn cờ
void veBanCo(int m, int n) {
	int x = 36, y = 2;
	// Vẽ dòng đầu tiên
	GotoXY(x, y);
	cout << (char)218;
	for (int i = 0; i < n - 1; i++) {
		cout << (char)196 << (char)196 << (char)196 << (char)194;
	}
	cout << (char)196 << (char)196 << (char)196 << (char)191;

	// Vẽ phần thân bảng
	for (int i = 0; i < m - 1; i++) {
		// Vẽ các dấu | và khoảng trống
		GotoXY(x, y + 2 * i + 1);
		for (int j = 0; j < n + 1; j++) {
			cout << (char)179 << "   ";
		}

		// Vẽ các đường ngang và giao điểm
		GotoXY(x, y + 2 * i + 2);
		cout << (char)195;
		for (int j = 0; j < n - 1; j++) {
			cout << (char)196 << (char)196 << (char)196 << (char)197;
		}
		cout << (char)196 << (char)196 << (char)196 << (char)180;
	}

	// Vẽ dòng | cuối cùng
	GotoXY(x, y + 2 * (m - 1) + 1);
	for (int j = 0; j < n + 1; j++) {
		cout << (char)179 << "   ";
	}

	// Vẽ dòng cuối cùng
	GotoXY(x, y + 2 * m);
	cout << (char)192;
	for (int i = 0; i < n - 1; i++) {
		cout << (char)196 << (char)196 << (char)196 << (char)193;
	}
	cout << (char)196 << (char)196 << (char)196 << (char)217;
}

//in hình chữ nhật có màu
void printColoredRectangle(int left, int top, int width, int height, int color)
{
	GotoXY(left, top);
	setConsoleColor(BRIGHT_WHITE, color);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) putchar(219);
		GotoXY(left, top + i + 1);
	}
}

//in chữ CARO lớn
void printLogo(int x)
{
	
	unsigned char logo[] = {
		32, 219, 219, 219, 219, 219, 219, 187, 32, 219, 219, 219, 219, 219, 187, 32, 219, 219, 219, 219, 219, 219, 187, 32, 32, 219, 219, 219, 219, 219,219, 187, 32,
219, 219, 201, 205, 205, 205,205, 188, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 201, 205, 205, 205, 219, 219, 187,
219, 219, 186, 32, 32, 32, 32,32, 219, 219, 219, 219, 219, 219, 219, 186, 219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 186, 32, 32, 32, 219, 219, 186,
219, 219, 186, 32, 32, 32, 32,32, 219, 219, 201, 205, 205, 219, 219, 186, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 186, 32, 32, 32, 219, 219, 186,
200, 219, 219, 219, 219, 219, 219, 187, 219, 219, 186, 32, 32, 219, 219, 186, 219, 219, 186, 32, 32, 219, 219, 186, 200, 219, 219, 219, 219, 219, 219, 201, 188,
32, 200, 205, 205, 205, 205, 205, 188, 200, 205, 188, 32, 32, 200, 205, 188, 200, 205, 188, 32, 32, 200, 205, 188, 32, 200, 205, 205, 205, 205, 205, 188, 32
	};
	printColoredRectangle(39, 2, 41, 10, 0);
	SetColor(0, x);
	int top = 4, left = 43;
	int num_lines = 6, num_chars = 33;
	for (int i = 0; i < num_lines; i++)
	{
		GotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
			putchar(logo[i * num_chars + j]);
	}
}

//hiệu ứng nhấp nháy logo
void Logo_Animation(int x)
{
	printLogo(15); 	Sleep(150);
	printLogo(0);	Sleep(150);
	printLogo(15);	Sleep(150);
	printLogo(0);	Sleep(150);
	printLogo(15);	Sleep(150);
	printLogo(0);	Sleep(150);
	printLogo(15);	Sleep(150);
	printLogo(0);	Sleep(150);
	printLogo(15);	Sleep(150);
	printLogo(0);	Sleep(150);
	printLogo(15);	Sleep(150);
}

//in chữ About
void printAbout(int x)
{
	SetColor(15, x);
	unsigned char about[] = { 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 219, 32, 32, 32,
	32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 176, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 176, 219, 219, 219, 32, 32, 32, 32,
	32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 32, 176, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 32, 219, 219, 219, 219, 32, 219, 219, 219, 219, 219, 219, 219, 32, 32,
	32, 176, 176, 176, 176, 176, 219, 219, 219, 32, 32, 176, 219, 219, 219, 176, 176, 219, 219, 219, 32, 219, 219, 219, 176, 176, 219, 219, 219, 176, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 176, 176, 219, 219, 219, 176, 32, 32, 32,
	32, 32, 219, 219, 219, 219, 219, 219, 219, 32, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 32, 32, 176, 219, 219, 219, 32, 32, 32, 32,
	32, 219, 219, 219, 176, 176, 219, 219, 219, 32, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 32, 32, 176, 219, 219, 219, 32, 219, 219, 219,
	176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 32, 219, 219, 219, 219, 219, 219, 219, 219, 32, 176, 176, 219, 219, 219, 219, 219, 219, 32, 32, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32, 176, 176, 219, 219, 219, 219, 219, 32,
	32, 176, 176, 176, 176, 176, 176, 176, 176, 32, 176, 176, 176, 176, 176, 176, 176, 176, 32, 32, 32, 176, 176, 176, 176, 176, 176, 32, 32, 32, 32, 176, 176, 176, 176, 176, 176, 176, 176, 32, 32, 32, 32, 176, 176, 176, 176, 176, 32, 32
	};
	int top = 1, left = 32;
	int num_lines = 8, num_chars = 50;
	for (int i = 0; i < num_lines; i++)
	{
		GotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
			putchar(about[i * num_chars + j]);
	}
}

//in chữ Load game
void printLoadGame(int x)
{
	SetColor(15, x);
	unsigned char loadgame[] = { 32, 219, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		176, 176, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 176, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 176, 219, 219, 219, 32, 32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 32,
		32, 176, 219, 219, 219, 32, 32, 219, 219, 219, 176, 176, 219, 219, 219, 32, 176, 176, 176, 176, 176, 219, 219, 219, 32, 32, 219, 219, 219, 176, 176, 219, 219, 219, 32, 32, 32, 219, 219, 219, 176, 176, 219, 219, 219, 32, 176, 176, 176, 176, 176, 219, 219, 219, 32, 176, 176, 219, 219, 219, 176, 176, 219, 219, 219, 176, 176, 219, 219, 219, 32, 32, 219, 219, 219, 176, 176, 219, 219, 219,
		32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 219, 32, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 219, 219, 219, 219, 32,
		32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 219, 219, 219, 176, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 219, 219, 219, 176, 176, 219, 219, 219, 32, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 32, 176, 219, 219, 219, 176, 176, 176, 32, 32,
		32, 219, 219, 219, 219, 219, 176, 176, 219, 219, 219, 219, 219, 219, 32, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 32, 176, 176, 219, 219, 219, 219, 219, 219, 219, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 32, 219, 219, 219, 219, 219, 176, 219, 219, 219, 32, 219, 219, 219, 219, 219, 176, 176, 219, 219, 219, 219, 219, 219, 32,
		176, 176, 176, 176, 176, 32, 32, 176, 176, 176, 176, 176, 176, 32, 32, 32, 176, 176, 176, 176, 176, 176, 176, 176, 32, 32, 176, 176, 176, 176, 176, 176, 176, 176, 32, 32, 32, 176, 176, 176, 176, 176, 219, 219, 219, 32, 176, 176, 176, 176, 176, 176, 176, 176, 32, 176, 176, 176, 176, 176, 32, 176, 176, 176, 32, 176, 176, 176, 176, 176, 32, 32, 176, 176, 176, 176, 176, 176, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 32, 176, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 176, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 176, 176, 176, 176, 176, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32
	};
	int top = 3, left = 20;
	int num_lines = 11, num_chars = 80;
	for (int i = 0; i < num_lines; i++)
	{
		GotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
			putchar(loadgame[i * num_chars + j]);
	}
}

//vẽ nhân vật among us bên phải
void rightAmongUs(int x, int y, int color, int color_1, int color_2, int color_3)
{
	// TÃ´ mÃ u
	setColor(color);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			GotoXY(x + 1 + j, y + 4 + i); putchar(219);
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			GotoXY(x + 4 + j, y + 2 + i); putchar(219);
		}
	}
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 5 + i, y + 1); putchar(219);
	}
	setConsoleColor(color, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 8 + i, y + 7); putchar(220);
	}

	setColor(color_1);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 1 + i, y + 6); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			GotoXY(x + 4 + j + 8 * i, y + 8); putchar(219);
			GotoXY(x + 4 + j + 8 * i, y + 8); putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			GotoXY(x + 4 + j + 10 * i, y + 7); putchar(219);
			GotoXY(x + 4 + 11 * i, y + 6); putchar(219);
		}
	}

	// TÃ´ bÃ³ng
	setColor(7);
	GotoXY(x + 3, y + 9); putchar(219);
	GotoXY(x + 11, y + 9); putchar(219);

	// TÃ´ mÃ u kÃ­nh
	for (int i = 0; i < 9; i++) {
		setConsoleColor(WHITE, GRAY);
		GotoXY(x + 8 + i, y + 3); putchar(220);
		setConsoleColor(GRAY, WHITE);
		GotoXY(x + 8 + i, y + 2); putchar(219);
	}

	setColor(0);
	// Váº½ viá»n kÃ­nh vÅ© trá»¥
	GotoXY(x + 7, y + 2); putchar(219);
	GotoXY(x + 7, y + 3); putchar(219);
	for (int i = 0; i < 9; i++) {
		setConsoleColor(color, BLACK);
		GotoXY(x + 8 + i, y + 1); putchar(220);
		setConsoleColor(color, BLACK);
		GotoXY(x + 8 + i, y + 4); putchar(223);
	}
	setColor(0);
	GotoXY(x + 17, y + 2); putchar(219);
	GotoXY(x + 17, y + 3); putchar(219);
	setConsoleColor(color_3, BLACK);
	GotoXY(x + 15, y + 1); putchar(220);
	GotoXY(x + 16, y + 1); putchar(220);
	GotoXY(x + 16, y + 4); putchar(223);

	// Váº½ viá»n
	setConsoleColor(color_2, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 1 + i, y + 3); putchar(220);
		GotoXY(x + 1 + i, y + 7); putchar(223);
	}
	for (int i = 0; i < 9; i++) {
		GotoXY(x + 5 + i, y); putchar(220);
	}

	setConsoleColor(WHITE, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x, y + 4 + i); putchar(219);
	}
	for (int i = 0; i < 7; i++) {
		GotoXY(x + 3, y + 2 + i); putchar(219);
	}
	GotoXY(x + 4, y + 1); putchar(219);
	GotoXY(x + 14, y + 1); putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 4 + i, y + 9); putchar(223);
	}
	GotoXY(x + 7, y + 8); putchar(219);
	GotoXY(x + 11, y + 8); putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 12 + i, y + 9); putchar(223);
	}
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 15, y + 8 - i); putchar(219);
	}
}

//vẽ nhân vật among us bên trái
void leftAmongUs(int x, int y, int color, int color_1, int color_2, int color_3)
{
	// Tô màu
	setColor(color);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			GotoXY(x + 16 + j, y + 4 + i); putchar(219);
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			GotoXY(x + 4 + j, y + 2 + i); putchar(219);
		}
	}
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 11 + i, y + 1); putchar(219);
	}
	setConsoleColor(color, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 8 + i, y + 7); putchar(220);
	}

	setColor(color_1);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 16 + i, y + 6); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			GotoXY(x + 4 + j + 8 * i, y + 8); putchar(219);
			GotoXY(x + 4 + j + 8 * i, y + 8); putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			GotoXY(x + 3 + j + 10 * i, y + 7); putchar(219);
			GotoXY(x + 3 + 11 * i, y + 6); putchar(219);
		}
	}
	setConsoleColor(color, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 8 + i, y + 7); putchar(220);
	}

	// Tô bóng
	setColor(color_3);
	GotoXY(x + 7, y + 9); putchar(219);
	GotoXY(x + 15, y + 9); putchar(219);

	// Tô màu kính
	for (int i = 0; i < 9; i++) {
		setConsoleColor(WHITE, GRAY);
		GotoXY(x + 2 + i, y + 3); putchar(220);
		setConsoleColor(GRAY, WHITE);
		GotoXY(x + 2 + i, y + 2); putchar(219);
	}

	setColor(0);
	// Vẽ viền kính vũ trụ
	GotoXY(x + 1, y + 2); putchar(219);
	GotoXY(x + 1, y + 3); putchar(219);
	for (int i = 0; i < 9; i++) {
		setConsoleColor(color, BLACK);
		GotoXY(x + 2 + i, y + 1); putchar(220);
		setConsoleColor(color, BLACK);
		GotoXY(x + 2 + i, y + 4); putchar(223);
	}
	setColor(0);
	GotoXY(x + 11, y + 2); putchar(219);
	GotoXY(x + 11, y + 3); putchar(219);
	setConsoleColor(color_2, BLACK);
	GotoXY(x + 2, y + 1); putchar(220);
	GotoXY(x + 3, y + 1); putchar(220);
	GotoXY(x + 2, y + 4); putchar(223);

	// Vẽ viền
	setConsoleColor(color_3, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 4 + i, y + 9); putchar(223);
	}
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 12 + i, y + 9); putchar(223);
	}

	setConsoleColor(color_2, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 18, y + 4 + i); putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 15 + i, y + 3); putchar(220);
		GotoXY(x + 15 + i, y + 7); putchar(223);
	}
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 3, y + 4 + i); putchar(219);
	}
	GotoXY(x + 4, y + 1); putchar(219);
	for (int i = 0; i < 9; i++) {
		GotoXY(x + 5 + i, y); putchar(220);
	}
	GotoXY(x + 14, y + 1); putchar(219);
	GotoXY(x + 7, y + 8); putchar(219);
	GotoXY(x + 11, y + 8); putchar(219);
	for (int i = 0; i < 7; i++) {
		GotoXY(x + 15, y + 8 - i); putchar(219);
	}
}

//vẽ bot fit hcmus
void Bot(int left, int top, int color1, int color2, int color3, int color4)
{
	// Tô màu
	setColor(color1);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			GotoXY(left + 3 + j, top + 3 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			GotoXY(left + 23 + j, top + 3 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 5; i++) {
		GotoXY(left + i + 12, top);
		putchar(219);
	}
	for (int i = 0; i < 14; i++) {
		GotoXY(left + i + 8, top + 1);
		putchar(219);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 15; j++) {
			GotoXY(left + 7 + j, top + 2 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 14; i++) {
		GotoXY(left + i + 8, top + 6);
		putchar(219);
	}
	for (int i = 0; i < 12; i++) {
		GotoXY(left + i + 8, top + 7);
		putchar(219);
	}
	for (int i = 0; i < 5; i++) {
		GotoXY(left + i + 12, top + 8);
		putchar(219);
	}

	//Vẽ viền
	setConsoleColor(color4, BLACK);
	for (int i = 0; i < 5; i++) {
		GotoXY(left + i + 12, top - 1);
		putchar(220);
	}
	GotoXY(left + 11, top);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(left + i + 8, top);
		putchar(220);
	}
	GotoXY(left + 7, top + 1);
	putchar(219);
	GotoXY(left + 6, top + 2);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(left + 3 + i, top + 2);
		putchar(220);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(left + 2, top + 3 + i);
		putchar(219);
		GotoXY(left + 6, top + 3 + i);
		putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		GotoXY(left + 3 + i, top + 5);
		putchar(223);
	}
	GotoXY(left + 6, top + 5);
	putchar(219);
	GotoXY(left + 7, top + 6);
	putchar(219);
	GotoXY(left + 8, top + 7);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(left + 9 + i, top + 8);
		putchar(223);
	}
	GotoXY(left + 11, top + 8);
	putchar(219);
	for (int i = 0; i < 5; i++) {
		GotoXY(left + 12 + i, top + 9);
		putchar(223);
	}
	GotoXY(left + 17, top + 8);
	putchar(219);
	for (int i = 0; i < 2; i++) {
		GotoXY(left + 18 + i, top + 8);
		putchar(223);
	}
	GotoXY(left + 20, top + 7);
	putchar(219);
	GotoXY(left + 21, top + 6);
	putchar(219);
	GotoXY(left + 22, top + 5);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(left + 23 + i, top + 5);
		putchar(223);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(left + 26, top + 4 - i);
		putchar(219);
		GotoXY(left + 22, top + 4 - i);
		putchar(219);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(left + 22 + i, top + 2);
		putchar(220);
	}
	GotoXY(left + 22, top + 2);
	putchar(219);
	GotoXY(left + 21, top + 1);
	putchar(219);
	for (int i = 0; i < 4; i++) {
		GotoXY(left + 17 + i, top);
		putchar(220);
	}
	GotoXY(left + 17, top);
	putchar(219);

	//Tô mặt
	setConsoleColor(color1, BLACK);
	for (int i = 0; i < 7; i++) {
		GotoXY(left + 11 + i, top + 1);
		putchar(220);
	}
	for (int i = 0; i < 11; i++) {
		GotoXY(left + 9 + i, top + 2);
		putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 13; j++) {
			GotoXY(left + 8 + j, top + 3 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 11; i++) {
		GotoXY(left + 9 + i, top + 5);
		putchar(223);
	}

	//Vẽ mặt
	setColor(color2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			GotoXY(left + 11 + i * 5 + j, top + 3);
			putchar(219);
		}
	}

	// In tên con bot
	setColor(color3);
	string bot_name = "FIT@HCMUS";
	for (int i = 0; i < bot_name.size(); i++) {
		GotoXY(left + 10 + i, top + 6);
		cout << bot_name[i];
	}
}

//in chữ Thanks
void printThanks(int x)
{
	SetColor(15, x);
	unsigned char thanks[] = { 32, 219, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219,
							32, 32, 219, 219, 219, 32, 32, 32, 32, 32, 32, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 32, 32, 32, 32, 32, 32,32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219,
							219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 32, 219, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 32, 32, 219, 219,
							32, 32, 219, 219, 219, 32, 32, 32, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 32, 32, 219, 219,
							32, 32, 219, 219, 219, 32, 32, 32, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 32, 219, 219, 219, 219, 219, 32, 32, 219, 219,
							32, 32, 219, 219, 219, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 32, 32, 32, 219, 219, 219, 32, 32, 32,
							32, 32, 32, 219, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 32, 219, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 32, 219, 219, 219, 219, 32, 219, 219, 219, 219, 219, 32, 219, 219, 219, 219, 32, 219, 219, 219, 219, 219, 32, 219, 219, 219, 219, 219, 219, 32, 32, 219, 219 };
	int top = 10, left = 45;
	int num_lines = 7, num_chars = 63;
	for (int i = 0; i < num_lines; i++)
	{
		GotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
			putchar(thanks[i * num_chars + j]);
	}
}



//vẽ among us mini
void smallleftAmongUs(int x, int y, int color)
{
	// Tô màu
	setColor(color);
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 2 + i, y); putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			GotoXY(x + 1 + j, y + 1 + i); putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 1 + i, y + 4); putchar(219);
		GotoXY(x + 6 + i, y + 4); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 9, y + 2 + i); putchar(219);
	}

	// Vẽ viền
	setConsoleColor(color, BLACK);
	for (int i = 0; i < 5; i++) {
		GotoXY(x - 1 + i, y); putchar(220);
		GotoXY(x - 1 + i, y + 2); putchar(223);
	}
	GotoXY(x - 2, y + 1); putchar(219);
	GotoXY(x + 4, y + 1); putchar(219);
	GotoXY(x + 4, y + 3); putchar(220);

	setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x, y + 2 + i);
		putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 1 + i, y + 5); putchar(223);
	}
	GotoXY(x + 3, y + 4); putchar(219);
	GotoXY(x + 5, y + 4); putchar(219);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 6 + i, y + 5); putchar(223);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 8, y + 1 + i);
		putchar(219);
	}
	GotoXY(x + 9, y + 1); putchar(220);
	GotoXY(x + 9, y + 4); putchar(223);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 10, y + 2 + i); putchar(219);
	}
	GotoXY(x + 7, y); putchar(219);
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 2 + i, y - 1); putchar(220);
	}
	GotoXY(x + 1, y); putchar(219);

	// Tô màu kính
	setColor(7);
	for (int i = 0; i < 5; i++) {
		GotoXY(x - 1 + i, y + 1); putchar(219);
	}
	setConsoleColor(BRIGHT_WHITE, BLACK);
	GotoXY(x - 1, y + 2); putchar(223);
	GotoXY(x - 1, y); putchar(220);
	GotoXY(x, y); putchar(220);
}

void smallrightAmongUs(int x, int y, int color)
{
	//Tô màu
	setColor(color);
	for (int i = 0; i < 7; i++) {
		GotoXY(x + 2 + i, y); putchar(219);
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 8; j++) {
			GotoXY(x + 1 + j, y + 1 + i); putchar(219);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			GotoXY(x + j - 2, y + 2 + i); putchar(219);
		}
	}

	for (int i = 0; i < 3; i++) {
		GotoXY(x + i, y + 4); putchar(219);
		GotoXY(x + 6 + i, y + 4); putchar(219);
	}

	// Vẽ viền
	setConsoleColor(LIGHT_BLUE, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 5 + i, y); putchar(220);
	}
	setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 3; i < 5; i++) {
		GotoXY(x + 5 + i, y); putchar(220);
	}
	setConsoleColor(LIGHT_BLUE, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 5 + i, y + 2); putchar(223);
	}
	setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 3; i < 5; i++) {
		GotoXY(x + 5 + i, y + 2); putchar(223);
	}
	setConsoleColor(BRIGHT_WHITE, BLACK);
	GotoXY(x + 10, y + 1); putchar(219);
	GotoXY(x + 4, y + 1); putchar(219);
	setConsoleColor(LIGHT_BLUE, BLACK);
	GotoXY(x + 4, y + 3); putchar(220);

	setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 8, y + 2 + i);
		putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 6 + i, y + 5); putchar(223);
	}
	GotoXY(x + 5, y + 4); putchar(219);
	GotoXY(x + 3, y + 4); putchar(219);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 1 + i, y + 5); putchar(223);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(x, y + 1 + i);
		putchar(219);
	}
	GotoXY(x - 1, y + 1); putchar(220);
	GotoXY(x - 1, y + 4); putchar(223);
	for (int i = 0; i < 2; i++) {
		GotoXY(x - 2, y + 2 + i); putchar(219);
	}
	GotoXY(x + 1, y); putchar(219);
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 2 + i, y - 1); putchar(220);
	}
	GotoXY(x + 7, y); putchar(219);

	//// Tô màu kính
	setColor(7);
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 5 + i, y + 1); putchar(219);
	}
	setColor(BLACK);
}

void ingameWin(int x, int y, int n) {
	setColor(n);
	unsigned char Win[] = { 32, 219, 219, 219, 219, 219, 32, 219, 219, 219, 32, 219, 219, 219, 219, 219, 32, 219, 219, 219, 219, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32,
32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32,
32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32,
32, 32, 32, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 32, 32, 32, 219, 219, 219, 32, 32, 219, 219, 219, 32,
32, 32, 32, 32, 219, 219, 219, 219, 32, 219, 219, 219, 219, 32, 32, 32, 32, 219, 219, 219, 219, 219, 32, 219, 219, 219, 219, 32, 219, 219, 219, 219, 219
	};
	int top = y, left = x;
	int num_lines = 5, num_chars = 33;
	for (int i = 0; i < num_lines; i++)
	{
		GotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
			putchar(Win[i * num_chars + j]);
	}
}

void ingameX(int x, int y, int color1, int color2) {
	//trắng - đen
	setConsoleColor(15, BLACK);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 1 + i, y);
		putchar(220);
		GotoXY(x + 7 + i, y);
		putchar(220);
	}
	GotoXY(x, y + 1);		putchar(219);
	GotoXY(x + 4, y + 1);	putchar(219);
	GotoXY(x + 6, y + 1);	putchar(219);
	GotoXY(x + 10, y + 1);	putchar(219);
	GotoXY(x, y + 2);		putchar(219);
	GotoXY(x + 10, y + 2);	putchar(219);
	GotoXY(x, y + 3);		putchar(223);
	GotoXY(x + 10, y + 3);	putchar(223);
	GotoXY(x, y + 4);		putchar(219);
	GotoXY(x + 10, y + 4);	putchar(219);
	GotoXY(x + 10, y + 5);	putchar(219);
	GotoXY(x, y + 5);		putchar(219);
	GotoXY(x + 5, y + 5);	putchar(223);
	GotoXY(x, y + 6);		putchar(223);
	GotoXY(x + 10, y + 6);	putchar(223);
	//vàng - đỏ
	setConsoleColor(color1, color2);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 1 + i, y + 1);
		putchar(32);
		GotoXY(x + 7 + i, y + 1);
		putchar(32);
		GotoXY(x + 2 + i, y + 2);
		putchar(32);
		GotoXY(x + 6 + i, y + 2);
		putchar(32);
		GotoXY(x + 3 + i, y + 3);
		putchar(32);
		GotoXY(x + 6 + i, y + 3);
		putchar(32);
		GotoXY(x + 1 + i, y + 4);
		putchar(32);
		GotoXY(x + 7 + i, y + 4);
		putchar(32);
		GotoXY(x + 1 + i, y + 5);
		putchar(220);
		GotoXY(x + 7 + i, y + 5);
		putchar(220);
	}
	GotoXY(x + 1, y + 2);	putchar(220);
	GotoXY(x + 9, y + 2);	putchar(220);
	GotoXY(x + 2, y + 3);	putchar(223);
	GotoXY(x + 8, y + 3);	putchar(223);
	GotoXY(x + 4, y + 4);	putchar(220);
	GotoXY(x + 5, y + 4);	putchar(219);
	GotoXY(x + 6, y + 4);	putchar(220);
	//vàng - đen
	setConsoleColor(color1, BLACK);
	GotoXY(x + 5, y + 2);	putchar(223);
	//đỏ - đen
	setConsoleColor(color2, BLACK);
	GotoXY(x + 1, y + 3);	putchar(220);
	GotoXY(x + 9, y + 3);	putchar(220);
	GotoXY(x + 4, y + 5);	putchar(220);
	GotoXY(x + 6, y + 5);	putchar(220);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 1 + i, y + 6);
		putchar(220);
		GotoXY(x + 7 + i, y + 6);
		putchar(220);
	}
	setConsoleColor(15, BLACK);
}

void ingameO(int x, int y, int color1, int color2) {
	//trắng - đen
	setConsoleColor(15, BLACK);
	for (int i = 0; i < 6; i++) {
		GotoXY(x + 2 + i, y);
		putchar(220);
	}
	GotoXY(x, y + 1);		putchar(220);
	GotoXY(x + 9, y + 1);	putchar(220);
	GotoXY(x, y + 2);		putchar(219);
	GotoXY(x + 9, y + 2);	putchar(219);
	GotoXY(x + 9, y + 3);	putchar(219);
	GotoXY(x, y + 3);		putchar(219);
	GotoXY(x + 4, y + 3);	putchar(219);
	GotoXY(x + 5, y + 3);	putchar(219);
	GotoXY(x + 9, y + 4);	putchar(219);
	GotoXY(x, y + 4);		putchar(219);
	GotoXY(x + 9, y + 5);	putchar(219);
	GotoXY(x, y + 5);		putchar(219);
	GotoXY(x + 1, y + 6);	putchar(223);
	GotoXY(x + 8, y + 6);	putchar(223);
	//xanh - xanh
	setConsoleColor(color1, color2);
	for (int i = 0; i < 6; i++) {
		GotoXY(x + 2 + i, y + 1);
		putchar(32);
		GotoXY(x + 2 + i, y + 5);
		putchar(220);
	}
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 1 + i, y + 2);
		putchar(32);
		GotoXY(x + 6 + i, y + 2);
		putchar(32);
		GotoXY(x + 1 + i, y + 3);
		putchar(32);
		GotoXY(x + 6 + i, y + 3);
		putchar(32);
		GotoXY(x + 6 + i, y + 4);
		putchar(32);
		GotoXY(x + 1 + i, y + 4);
		putchar(32);
	}
	GotoXY(x + 4, y + 2);	putchar(219);
	GotoXY(x + 5, y + 2);	putchar(219);
	GotoXY(x + 8, y + 5);	putchar(219);
	GotoXY(x + 1, y + 5);	putchar(219);
	//xanh - đen
	setConsoleColor(color1, BLACK);
	GotoXY(x + 1, y + 1);	putchar(223);
	GotoXY(x + 8, y + 1);	putchar(223);
	GotoXY(x + 4, y + 4);	putchar(223);
	GotoXY(x + 5, y + 4);	putchar(223);
	//xanh - đen
	setConsoleColor(color2, BLACK);
	for (int i = 0; i < 6; i++) {
		GotoXY(x + 2 + i, y + 6);
		putchar(220);
	}
	setConsoleColor(15, BLACK);
}

void bigLeftMario(int x, int y, int color) {
	//đỏ - đỏ
	setConsoleColor(color, color);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 5 + i, y + 1);
		putchar(219);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 7 + i, y + 2);
		putchar(219);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 10 + i, y + 3);
		putchar(219);
	}
	//trắng - đen
	setConsoleColor(15, BLACK);
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 4 + i, y);
		putchar(220);
	}
	GotoXY(x + 2, y + 1);   putchar(220);
	GotoXY(x + 10, y + 1);  putchar(220);
	GotoXY(x + 1, y + 2);   putchar(220);
	GotoXY(x + 2, y + 2);   putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 3 + i, y + 2);
		putchar(220);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 12 + i, y + 2);
		putchar(220);
	}
	GotoXY(x, y + 3);       putchar(223);
	//đỏ - đen
	setConsoleColor(color, BLACK);
	GotoXY(x + 3, y + 1);   putchar(223);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 8 + i, y + 1);
		putchar(223);
	}
	GotoXY(x + 11, y + 2);  putchar(223);
	GotoXY(x + 6, y + 2);   putchar(220);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 1 + i, y + 3);
		putchar(220);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 8 + i, y + 3);
		putchar(220);
	}
	//đỏ - trắng
	setConsoleColor(color, 15);
	GotoXY(x + 4, y + 1);   putchar(220);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 3 + i, y + 3);
		putchar(220);
	}
	GotoXY(x + 6, y + 3);   putchar(220);
	GotoXY(x + 11, y + 10);  putchar(220);
	GotoXY(x + 12, y + 10);  putchar(220);
	//đỏ - da
	setConsoleColor(color, 14);
	GotoXY(x + 5, y + 3);   putchar(220);
	//trắng - đen
	setConsoleColor(15, BLACK);
	GotoXY(x + 14, y + 3);  putchar(219);
	GotoXY(x + 2, y + 4);   putchar(220);
	GotoXY(x + 4, y + 4);   putchar(219);
	GotoXY(x + 6, y + 4);   putchar(219);
	GotoXY(x + 10, y + 4);  putchar(219);
	GotoXY(x + 11, y + 4);  putchar(219);
	GotoXY(x + 7, y + 3);   putchar(223);
	GotoXY(x + 14, y + 4);  putchar(223);
	GotoXY(x + 1, y + 5);   putchar(219);
	GotoXY(x + 1, y + 6);   putchar(223);
	GotoXY(x + 2, y + 6);   putchar(219);
	GotoXY(x + 6, y + 6);   putchar(219);
	GotoXY(x + 7, y + 6);   putchar(219);
	GotoXY(x + 3, y + 7);   putchar(223);
	GotoXY(x + 12, y + 7);  putchar(220);
	GotoXY(x + 4, y + 9);   putchar(223);
	GotoXY(x + 3, y + 10);  putchar(219);
	GotoXY(x + 15, y + 10); putchar(219);
	GotoXY(x + 1, y + 11);  putchar(223);
	GotoXY(x + 2, y + 11);  putchar(220);
	GotoXY(x + 3, y + 11);  putchar(219);
	GotoXY(x + 14, y + 11);  putchar(220);
	GotoXY(x + 15, y + 11);  putchar(223);
	GotoXY(x + 1, y + 13);  putchar(220);
	GotoXY(x + 1, y + 14);  putchar(223);
	GotoXY(x + 6, y + 14);  putchar(219);
	GotoXY(x + 6, y + 13);  putchar(219);
	GotoXY(x + 15, y + 13);  putchar(220);
	GotoXY(x + 15, y + 14);  putchar(223);
	//trắng - da
	setConsoleColor(15, 14);
	GotoXY(x + 5, y + 4);   putchar(219);
	GotoXY(x + 8, y + 4);   putchar(219);
	GotoXY(x + 9, y + 4);   putchar(219);
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 2 + i, y + 5);
		putchar(219);
	}
	GotoXY(x + 9, y + 6);   putchar(219);
	GotoXY(x + 10, y + 6);  putchar(219);
	GotoXY(x + 8, y + 5);   putchar(219);
	GotoXY(x + 11, y + 5);  putchar(219);
	GotoXY(x + 12, y + 5);  putchar(219);
	//đen - đỏ
	setConsoleColor(BLACK, color);
	GotoXY(x + 12, y + 4);  putchar(223);
	GotoXY(x + 13, y + 4);  putchar(223);
	GotoXY(x + 10, y + 7);  putchar(220);
	GotoXY(x + 11, y + 7);  putchar(220);
	GotoXY(x + 4, y + 8);  putchar(219);
	GotoXY(x + 3, y + 9);  putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 6 + i, y + 8);
		putchar(219);
		GotoXY(x + 10 + i, y + 8);
		putchar(219);
		GotoXY(x + 10 + i, y + 9);
		putchar(219);
	}
	GotoXY(x + 13, y + 9);  putchar(219);
	GotoXY(x + 10, y + 10);  putchar(223);
	//da - đen
	setConsoleColor(14, BLACK);
	GotoXY(x + 7, y + 5);   putchar(220);
	GotoXY(x + 9, y + 5);   putchar(223);
	GotoXY(x + 10, y + 5);  putchar(219);
	GotoXY(x + 13, y + 5);  putchar(219);
	GotoXY(x + 8, y + 6);   putchar(223);
	GotoXY(x + 11, y + 6);  putchar(220);
	GotoXY(x + 12, y + 6);  putchar(219);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 3 + i, y + 6);
		putchar(220);
	}
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 4 + i, y + 7);
		putchar(220);
	}
	GotoXY(x + 9, y + 7);  putchar(219);
	GotoXY(x + 3, y + 8);  putchar(219);
	GotoXY(x + 13, y + 8); putchar(219);
	GotoXY(x + 2, y + 9);  putchar(219);
	GotoXY(x + 14, y + 9);  putchar(219);
	GotoXY(x + 1, y + 10);  putchar(219);
	GotoXY(x + 10, y + 11);  putchar(219);
	GotoXY(x + 4, y + 12);  putchar(219);
	GotoXY(x + 8, y + 12);  putchar(219);
	GotoXY(x + 13, y + 12);  putchar(219);
	//trắng - xanh
	setConsoleColor(15, 9);
	GotoXY(x + 5, y + 8);  putchar(219);
	GotoXY(x + 9, y + 8);  putchar(219);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			GotoXY(x + 5 + j, y + 9 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 8 + i, y + 9);
		putchar(223);
		GotoXY(x + 8 + i, y + 10);
		putchar(220);
	}
	GotoXY(x + 4, y + 10);  putchar(220);
	GotoXY(x + 8, y + 11);  putchar(219);
	GotoXY(x + 9, y + 11);  putchar(219);
	GotoXY(x + 9, y + 12);  putchar(219);
	GotoXY(x + 10, y + 12);  putchar(219);
	//đen - xanh
	setConsoleColor(BLACK, 9);
	GotoXY(x + 4, y + 11);  putchar(220);
	GotoXY(x + 11, y + 12);  putchar(220);
	GotoXY(x + 12, y + 12);  putchar(220);
	//vàng - đen
	setConsoleColor(BLACK, 6);
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 2 + i, y + 13);
		putchar(220);
		GotoXY(x + 2 + i, y + 14);
		putchar(223);
	}
	for (int i = 0; i < 8; i++) {
		GotoXY(x + 7 + i, y + 13);
		putchar(220);
		GotoXY(x + 7 + i, y + 14);
		putchar(223);
	}
	setConsoleColor(15, BLACK);
}

void bigRightMario(int x, int y, int color) {
	//lá - lá
	setConsoleColor(color, color);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 8 + i, y + 1);
		putchar(219);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 5 + i, y + 2);
		putchar(219);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 2 + i, y + 3);
		putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 3 + i, y + 8);
		putchar(219);
		GotoXY(x + 7 + i, y + 8);
		putchar(219);
		GotoXY(x + 2 + i, y + 9);
		putchar(219);
	}
	GotoXY(x + 11, y + 8);   putchar(220);
	GotoXY(x + 5, y + 9);    putchar(219);
	GotoXY(x + 12, y + 9);   putchar(219);
	//trắng - đen
	setConsoleColor(15, BLACK);
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 8 + i, y);
		putchar(220);
	}
	GotoXY(x + 5, y + 1);    putchar(220);
	GotoXY(x + 13, y + 1);   putchar(220);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 2 + i, y + 2);
		putchar(220);
		GotoXY(x + 10 + i, y + 2);
		putchar(220);
	}
	GotoXY(x + 12, y + 2);   putchar(220);
	GotoXY(x + 13, y + 2);   putchar(219);
	GotoXY(x + 14, y + 2);   putchar(220);
	GotoXY(x + 1, y + 3);    putchar(219);
	GotoXY(x + 8, y + 3);    putchar(223);
	GotoXY(x + 15, y + 3);   putchar(223);
	GotoXY(x + 1, y + 4);    putchar(223);
	GotoXY(x + 9, y + 4);    putchar(219);
	GotoXY(x + 11, y + 4);   putchar(219);
	GotoXY(x + 13, y + 4);   putchar(220);
	GotoXY(x + 2, y + 5);    putchar(219);
	GotoXY(x + 5, y + 5);    putchar(219);
	GotoXY(x + 14, y + 5);   putchar(219);
	GotoXY(x + 3, y + 6);    putchar(219);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 8 + i, y + 6);
		putchar(219);
	}
	GotoXY(x + 13, y + 6);   putchar(219);
	GotoXY(x + 14, y + 6);   putchar(223);
	GotoXY(x + 3, y + 7);    putchar(220);
	GotoXY(x + 12, y + 7);   putchar(223);
	GotoXY(x + 6, y + 7);    putchar(219);
	GotoXY(x + 2, y + 8);    putchar(219);
	GotoXY(x + 12, y + 8);   putchar(219);
	GotoXY(x + 1, y + 9);    putchar(219);
	GotoXY(x + 11, y + 9);   putchar(223);
	GotoXY(x + 13, y + 9);   putchar(219);
	GotoXY(x, y + 10);       putchar(219);
	GotoXY(x + 12, y + 10);  putchar(219);
	GotoXY(x + 14, y + 10);  putchar(219);
	GotoXY(x, y + 11);       putchar(223);
	GotoXY(x + 1, y + 11);   putchar(220);
	GotoXY(x + 5, y + 11);   putchar(219);
	GotoXY(x + 12, y + 11);  putchar(219);
	GotoXY(x + 13, y + 11);  putchar(220);
	GotoXY(x + 14, y + 11);  putchar(223);
	GotoXY(x + 2, y + 12);   putchar(219);
	GotoXY(x + 7, y + 12);   putchar(219);
	GotoXY(x + 11, y + 12);  putchar(219);
	GotoXY(x, y + 13);       putchar(220);
	GotoXY(x + 14, y + 13);  putchar(220);
	GotoXY(x, y + 14);       putchar(223);
	GotoXY(x + 14, y + 14);  putchar(223);
	GotoXY(x + 9, y + 13);   putchar(219);
	GotoXY(x + 9, y + 14);   putchar(219);
	//lá - đen
	setConsoleColor(color, BLACK);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 6 + i, y + 1);
		putchar(223);
	}
	GotoXY(x + 12, y + 1);   putchar(223);
	GotoXY(x + 4, y + 2);    putchar(223);
	GotoXY(x + 9, y + 2);    putchar(220);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 6 + i, y + 3);
		putchar(220);
		GotoXY(x + 13 + i, y + 3);
		putchar(220);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 2 + i, y + 4);
		putchar(220);
		GotoXY(x + 4 + i, y + 4);
		putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 4 + i, y + 7);
		putchar(223);
	}
	GotoXY(x + 5, y + 10);   putchar(220);
	//lá - trắng
	setConsoleColor(color, 15);
	GotoXY(x + 11, y + 1);   putchar(220);
	GotoXY(x + 9, y + 3);    putchar(220);
	GotoXY(x + 11, y + 3);   putchar(220);
	GotoXY(x + 12, y + 3);   putchar(220);
	GotoXY(x + 3, y + 10);   putchar(220);
	GotoXY(x + 4, y + 10);   putchar(220);
	//lá - da
	setConsoleColor(color, 14);
	GotoXY(x + 10, y + 3);   putchar(220);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 6 + i, y + 4);
		putchar(219);
	}
	GotoXY(x + 10, y + 4);   putchar(219);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 3 + i, y + 5);
		putchar(219);
	}
	GotoXY(x + 7, y + 5);   putchar(219);
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 9 + i, y + 5);
		putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 5 + i, y + 6);
		putchar(219);
	}
	//trắng - da
	setConsoleColor(15, 14);

	//đen - lá
	setConsoleColor(BLACK, color);


	//da - đen
	setConsoleColor(14, BLACK);
	GotoXY(x + 6, y + 5);    putchar(223);
	GotoXY(x + 8, y + 5);    putchar(220);
	GotoXY(x + 4, y + 6);    putchar(220);
	GotoXY(x + 7, y + 6);    putchar(223);
	for (int i = 0; i < 3; i++) {
		GotoXY(x + 10 + i, y + 6);
		putchar(220);
	}
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 7 + i, y + 7);
		putchar(220);
	}
	//trắng - xanh
	setConsoleColor(15, 9);
	GotoXY(x + 6, y + 8);    putchar(219);
	GotoXY(x + 10, y + 8);   putchar(219);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			GotoXY(x + 8 + j, y + 9 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 6 + i, y + 9);
		putchar(223);
		GotoXY(x + 6 + i, y + 10);
		putchar(220);
	}
	GotoXY(x + 11, y + 10);    putchar(220);
	for (int i = 0; i < 2; i++) {
		GotoXY(x + 6 + i, y + 11);
		putchar(219);
		GotoXY(x + 5 + i, y + 12);
		putchar(219);
	}
	//đen - xanh
	setConsoleColor(BLACK, 9);
	GotoXY(x + 11, y + 11);   putchar(220);
	GotoXY(x + 3, y + 12);    putchar(220);
	GotoXY(x + 4, y + 12);    putchar(220);
	//vàng - đen
	setConsoleColor(BLACK, 6);
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 1 + i, y + 13);
		putchar(220);
		GotoXY(x + 5 + i, y + 13);
		putchar(220);
		GotoXY(x + 1 + i, y + 14);
		putchar(223);
		GotoXY(x + 5 + i, y + 14);
		putchar(223);
		GotoXY(x + 10 + i, y + 13);
		putchar(220);
		GotoXY(x + 10 + i, y + 14);
		putchar(223);
	}
	setConsoleColor(15, BLACK);
}

void ingameHelp(int x, int y) {
	GotoXY(x, y);
	setColor(BLACK);
	cout << "Press   to go up.";
	GotoXY(x + 24, y);
	cout << "Press   to go down.";
	GotoXY(x, y + 1);
	cout << "Press   to go left.";
	GotoXY(x + 24, y + 1);
	cout << "Press   to go right.";
	GotoXY(x, y + 2);
	cout << "Press   to save game.";
	GotoXY(x + 24, y + 2);
	cout << "Press   to pause game.";
	GotoXY(x + 6, y);
	setColor(LIGHT_GREEN);
	cout << "W";
	GotoXY(x + 30, y);
	setColor(LIGHT_AQUA);
	cout << "S";
	GotoXY(x + 6, y + 1);
	setColor(LIGHT_RED);
	cout << "A";
	GotoXY(x + 30, y + 1);
	setColor(YELLOW);
	cout << "D";
	GotoXY(x + 6, y + 2);
	setColor(GRAY);
	cout << "K";
	GotoXY(x + 30, y + 2);
	setColor(LIGHT_PURPLE);
	cout << "P";
	setColor(BLACK);
}
