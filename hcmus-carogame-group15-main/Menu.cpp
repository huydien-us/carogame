#include "Menu.h"
#include "FileHandle.h"
int current_option;			//Lựa chọn hiện tại
//Tên các lựa chọn
const string options[9] = { "NEW GAME", "LOAD", "HELP", "ABOUT US", "EXIT", /*" PvP ", "PvE(easy)", "PvE(hard)"*/ "BACK" };

//màn hình menu chính
void mainScreen()
{
	unordered_map<string, void(*)()> function_map = {
		{options[0], newGameMenu},
		{options[1], loadScreen},
		{options[2], helpScreen},
		{options[3], aboutUS},
		{options[4], exitScreen},
		//{options[5], playPvP},
		//{options[6], playPvEe},
		//{options[7], playPvEh},
		{options[8], backMenu} };
	setConsoleColor(BRIGHT_WHITE, RED);
	clearConsole();
	bool loadMenu = 1;
	while (true)
	{
		if (loadMenu)
			mainMenu();
		switch (getConsoleInput())
		{
		case 2:
			changeOption(0, 1);
			loadMenu = 0;
			break;
		case 5:
			changeOption(1, 1);
			loadMenu = 0;
			break;
		case 6:
			if (current_option == 0)
				loadMenu = 0;
			else
				loadMenu = 1;
			function_map[options[current_option]]();
			break;
		default:
			loadMenu = 0;
		}
	}

	clearConsole();

}

void subScreen()
{
	subMenu();


}

//hàm lựa chọn
void changeOption(bool direction, bool flag) //0: lên, 1: xuống
{
	int top = 16;
	if ((direction == 0 && (current_option == 5 || current_option == 0))
		|| (direction == 1 && (current_option == 4 || current_option == 8)))
	{
		return;
	}
	setConsoleColor(BRIGHT_WHITE, BLACK);
	GotoXY(60 - (int)options[current_option].length(), top + current_option % 5 * 2);
	cout << "                     ";
	GotoXY(60 - (int)options[current_option].length() / 2, top + current_option % 5 * 2);
	cout << options[current_option];
	if (flag)
	{
		printColoredRectangle(54, top + current_option % 5 * 2, 12, 1, BRIGHT_WHITE);
		GotoXY(60 - (int)options[current_option].length() / 2, top + current_option % 5 * 2);
		setConsoleColor(BRIGHT_WHITE, BLACK);
		cout << options[current_option];
		GotoXY(49, top + current_option % 5 * 2);
		putchar(32); putchar(32); putchar(32); putchar(32);
		GotoXY(69, top + current_option % 5 * 2);
		putchar(32); putchar(32); putchar(32); putchar(32);
	}
	(direction == 1) ? current_option++ : current_option--;
	if (flag)
	{
		printColoredRectangle(54, top + current_option % 5 * 2, 12, 1, BLACK);
		GotoXY(60 - (int)options[current_option].length() / 2, top + current_option % 5 * 2);
		setConsoleColor(BLACK, BRIGHT_WHITE);
		cout << options[current_option];
		setConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
		GotoXY(49, top + current_option % 5 * 2);
		putchar(62); putchar(62); putchar(62); putchar(62);
		setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		GotoXY(67, top + current_option % 5 * 2);
		putchar(60); putchar(60); putchar(60); putchar(60);
	}
}

//menu chính
void mainMenu()
{
	printBoard(4, 1, 112, 26, 0);
	printLogo(15);
	bigLeftMario(84, 10, LIGHT_GREEN);
	bigRightMario(19, 10, LIGHT_RED);
	current_option = 4;
	changeOption(0, 0);
	changeOption(0, 0);
	changeOption(0, 0);
	changeOption(0, 1);
}

void subMenu()
{
	printBoard(29, 9, 61, 6, 0);
	printColoredRectangle(30, 10, 60, 5, LIGHT_GREEN);
	setConsoleColor(BRIGHT_WHITE, BLACK);
	GotoXY(50, 12);
	cout << "Press C to continue";
}

void backMenu()
{
	clearConsole();
}

void newGameMenu()
{
	showCursor(true);
	clearConsole();

	setConsoleColor(BRIGHT_WHITE, BLACK);
	StartGame();
	GotoXY(36, 3);
	//system("color F0");
	int _COMMAND;
	if (std::ifstream("save.txt").good()) {
		char choice;
		GotoXY(30, 0);
		setColor(BLACK);
		cout << "Do you want to load the previous game? (Y/N): ";
		cin >> choice;
		choice = toupper(choice);

		if (choice == 'Y') {
			LoadGame();
		}
		else {
			StartGame();
		}
	}
	else {
		StartGame();
	}
	while (true) {
		_COMMAND = toupper(_getch());

		if (_COMMAND == 27) {
			ExitGame();
			//return 0;
		}
		if (_COMMAND == 'K') {
			SaveGame();
			//return 0;
		}

		if (_COMMAND == 'L') {
			LoadGame();
		}

		if (_COMMAND == 'P') {
			PauseGame();
		}



		if (_COMMAND == 'A') MoveLeft();
		else if (_COMMAND == 'W') MoveUp();
		else if (_COMMAND == 'S') MoveDown();
		else if (_COMMAND == 'D') MoveRight();
		else if (_COMMAND == 13 && !_GAME_OVER) {  // Kiểm tra nếu game chưa kết thúc trước khi đánh

			int currentRow = (_Y - TOP) / 2;
			int currentCol = (_X - LEFT) / 4;


			if (_A[currentRow][currentCol].c == 0) {
				_A[currentRow][currentCol].c = (_TURN ? 1 : 2);
				if (_TURN == 1) {
					setColor(LIGHT_RED);
					cout << 'X';
				}
				else {
					setColor(LIGHT_GREEN);
					cout << 'O';
				}
				//cout << (_TURN ? 'X' : 'O');

				switch (ProcessFinish(TestBoard())) {
				case -1: case 1: case 0:
					if (AskContinue() != 'Y') {
						ExitGame(); //return 0;
					}
					else {
						_TURN = true;
						StartGame();
					}
					break;

				}
			}
		}
	}
}

void helpScreen()
{
	showCursor(false);
	clearConsole();

	setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	GotoXY(18, 4);
	cout << "USE                     TO MOVE";
	GotoXY(30, 3);
	setConsoleColor(LIGHT_RED, BRIGHT_WHITE);
	cout << " W ";
	GotoXY(26, 5); cout << " A ";
	GotoXY(30, 5); cout << " S ";
	GotoXY(34, 5);	cout << " D ";

	setConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
	GotoXY(63, 4);
	cout << "USE                  TO PLACE";
	GotoXY(73, 3);
	putchar(220); putchar(220); putchar(220); putchar(220); putchar(220);
	GotoXY(73, 4);
	setConsoleColor(LIGHT_GREEN, BRIGHT_WHITE);
	putchar(32); putchar(17); putchar(196); putchar(217); putchar(32);

	printBoard(10, 1, 98, 5, BLACK);

	setConsoleColor(BLACK, BRIGHT_WHITE);
	GotoXY(48, 1);
	cout << "  CONTROL  ";

	printBoard(10, 7, 98, 19, BLACK);

	setConsoleColor(BLACK, BRIGHT_WHITE);
	GotoXY(49, 7);
	cout << "  RULES  ";

	setConsoleColor(BRIGHT_WHITE, GRAY);
	GotoXY(13, 10);
	putchar(06); cout << "Two players play against each other on 12x12 grid using the   and   symbol.";
	GotoXY(13, 13);
	putchar(06); cout << "The player representing   gets to take the first turn followed by the player representing  .";
	GotoXY(13, 14);
	cout << "Players take turn placing their symbol on an open intersection on the board.";
	GotoXY(13, 17);
	putchar(06); cout << "You have to race to create an unbroken row of five symbols while blocking your opponent to";
	GotoXY(13, 18);
	cout << "prevent them from creating five in a row. The one managing to create five in a row first wins";
	GotoXY(13, 19);
	putchar(06); cout << "the round.";
	GotoXY(13, 22);
	putchar(06); cout << "The row can be horizontal, vertical, or diagonal as long as it is unbroken. ";

	setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	GotoXY(73, 10); cout << "X";
	GotoXY(37, 13); cout << "X";
	setConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
	GotoXY(79, 10); cout << "O";
	GotoXY(103, 13); cout << "O";

	printColoredRectangle(55, 28, 8, 1, BLACK);
	GotoXY(57, 28);
	setConsoleColor(BLACK, BRIGHT_WHITE);
	cout << "BACK";
	GotoXY(51, 28);
	setConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
	cout << ">>>";
	GotoXY(64, 28);
	setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	cout << "<<<";
	while (getConsoleInput() != 6) {}
	mainScreen();
}

void aboutUS()
{
	clearConsole();
	printBoard(4, 1, 112, 26, 0);
	printAbout(0);
	
	setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	GotoXY(10, 12);
	cout << ">>>>>";
	GotoXY(25, 12);
	cout << ">>>>>";
	setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
	GotoXY(16, 12);
	cout << "24120229";
	GotoXY(31, 12);
	cout << "  Nguyen Thi Diem Thuy    ";
	Sleep(500);

	setConsoleColor(BRIGHT_WHITE, YELLOW);
	GotoXY(10, 14);
	cout << ">>>>>";
	GotoXY(25, 14);
	cout << ">>>>>";
	setConsoleColor(YELLOW, BRIGHT_WHITE);
	GotoXY(16, 14);
	cout << "24120287";
	GotoXY(31, 14);
	cout << "  Vo Dinh Dinh            ";
	Sleep(500);

	setConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
	GotoXY(10, 16);
	cout << ">>>>>";
	GotoXY(25, 16);
	cout << ">>>>>";
	setConsoleColor(LIGHT_GREEN, BRIGHT_WHITE);
	GotoXY(16, 16);
	cout << "24120286";
	GotoXY(31, 16);
	cout << "  Le Huy Dien             ";
	Sleep(500);

	setConsoleColor(BRIGHT_WHITE, PURPLE);
	GotoXY(10, 18);
	cout << ">>>>>";
	GotoXY(25, 18);
	cout << ">>>>>";
	setConsoleColor(PURPLE, BRIGHT_WHITE);
	GotoXY(16, 18);
	cout << "24120272";
	GotoXY(31, 18);
	cout << "  Tran Nguyen Cong Chung  ";
	Sleep(500);

	setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	GotoXY(10, 20);
	cout << ">>>>>";
	GotoXY(25, 20);
	cout << ">>>>>";
	setConsoleColor(LIGHT_RED, BRIGHT_WHITE);
	GotoXY(16, 20);
	cout << "24120272";
	GotoXY(31, 20);
	cout << "  Trinh Tuan Dat          ";
	Sleep(500);

	printColoredRectangle(70, 14, 35, 4, AQUA);
	setConsoleColor(AQUA, BRIGHT_WHITE);
	GotoXY(86, 14);
	cout << "GVHD";
	GotoXY(75, 16);
	cout << ">>> Truong Toan Thinh <<<";

	printColoredRectangle(55, 28, 8, 1, BLACK);
	GotoXY(57, 28);
	setConsoleColor(BLACK, BRIGHT_WHITE);
	cout << "BACK";
	GotoXY(51, 28);
	setConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
	cout << ">>>";
	GotoXY(64, 28);
	setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	cout << "<<<";
	while (getConsoleInput() != 6) {}
	mainScreen();
}

void loadScreen()
{
	clearConsole();
	system("color F0");
	printBoard(4, 1, 112, 26, 0);
	printLoadGame(0);
	printColoredRectangle(55, 28, 8, 1, BLACK);
	GotoXY(57, 28);
	setConsoleColor(BLACK, BRIGHT_WHITE);
	cout << "BACK";
	GotoXY(51, 28);
	setConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
	cout << ">>>";
	GotoXY(64, 28);
	setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	cout << "<<<";
	while (getConsoleInput() != 6) {}
	mainScreen();
}

void exitScreen()
{
	showCursor(false);
	clearConsole();
	Bot(12, 11, BRIGHT_WHITE, LIGHT_BLUE, LIGHT_BLUE, WHITE);
	printThanks(0);
	//clearConsole();
	_getch();
	exit(0);
}
