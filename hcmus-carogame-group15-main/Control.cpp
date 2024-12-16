#include "Header.h"
#include "Common.h"
#include "Data.h"
#include "Control.h"
#include "Draw.h"
#include "Menu.h"
using namespace std;

//Khai báo các biến nhóm hàm Model
_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;
bool _GAME_OVER = false; // Biến kiểm soát game kết thúc

//Hàm bắt đầu game mới
void StartGame() {
    system("cls");
    ResetData();
    _TURN = true;
    
    setColor(BLACK);
    veBanCo(BOARD_SIZE, BOARD_SIZE);

    DrawBoard();                     // In trạng thái các ô
    bigLeftMario(12, 12, LIGHT_RED);
    bigRightMario(95, 12, LIGHT_GREEN);
    ingameX(14, 2, LIGHT_RED, LIGHT_YELLOW);
    ingameO(99, 2, LIGHT_GREEN, LIGHT_YELLOW);
    ingameHelp(38, 27);
    //system("color F0");

    _X = _A[0][0].x;
    _Y = _A[0][0].y;
    GotoXY(_X, _Y); // Đưa con trỏ về ô đầu tiên
}

//Hàm trả về ký tự X hoặc O
void DrawBoard() {
    system("cls");
    bigLeftMario(12, 12, LIGHT_RED);
    bigRightMario(95, 12, LIGHT_GREEN);
    ingameX(14, 2, LIGHT_RED, LIGHT_YELLOW);
    ingameO(99, 2, LIGHT_GREEN, LIGHT_YELLOW);
    ingameHelp(38, 27);
    //setColor(BLACK);
    // Vẽ khung bàn cờ
    veBanCo(BOARD_SIZE, BOARD_SIZE);

    // Vẽ các ký tự trong các ô (X, O, hoặc )
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Vị trí của ký tự 'X' hoặc 'O' trong ô
            GotoXY(_A[i][j].x, _A[i][j].y);

            // In ký tự của ô
            if (_A[i][j].c == 0) {
                cout << ' ';  // Ô trống
            }
            else if (_A[i][j].c == 1) {
                setColor(LIGHT_RED);
                cout << 'X';  // Ô của người chơi X
            }
            else if (_A[i][j].c == 2) {
                setColor(LIGHT_GREEN);
                cout << 'O';  // Ô của người chơi O
            }
        }
    }
}


//Hàm kết thúc game
void ExitGame() {
    system("cls");
    Bot(10, 11, BRIGHT_WHITE, LIGHT_BLUE, LIGHT_BLUE, WHITE);
    printThanks(0);
    printBoard(40, 21, 45, 2, BLACK);
    GotoXY(44, 22);
    setColor(LIGHT_BLUE);
    cout << "Press       to return to main menu!\n";
    GotoXY(50, 22);
    setColor(LIGHT_RED);
    cout << "Enter";
    _getch();
    mainScreen();
}

//Hàm di chuyển sang phải
void MoveRight() {
    if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
        _X += 4;
        GotoXY(_X, _Y);
    }
}

//Hàm di chuyển sang trái
void MoveLeft() {
    if (_X > _A[0][0].x) {
        _X -= 4;
        GotoXY(_X, _Y);
    }
}

//Hàm di chuyển xuống
void MoveDown() {
    if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
        _Y += 2;
        GotoXY(_X, _Y);
    }
}

//Hàm di chuyển lên
void MoveUp() {
    if (_Y > _A[0][0].y) {
        _Y -= 2;
        GotoXY(_X, _Y);
    }
}

//Reset
void ResetData() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _A[i][j].x = 4 * j + LEFT;
            _A[i][j].y = 2 * i + TOP;
            _A[i][j].c = 0;
        }
    }
    _TURN = true;
    _GAME_OVER = false; // Reset
    _X = _A[1][0].x;
    _Y = _A[1][0].y;
}

//Kiểm tra hòa
bool checkDraw(int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].c == 0) {
                return false;
            }
        }
    }
    return true;
}

//Kiểm tra thắng
bool checkWin(int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 4; j++) {
            if (_A[i][j].c == player && _A[i][j + 1].c == player &&
                _A[i][j + 2].c == player && _A[i][j + 3].c == player &&
                _A[i][j + 4].c == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].c == player && _A[i + 1][j].c == player &&
                _A[i + 2][j].c == player && _A[i + 3][j].c == player &&
                _A[i + 4][j].c == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 0; j < BOARD_SIZE - 4; j++) {
            if (_A[i][j].c == player && _A[i + 1][j + 1].c == player &&
                _A[i + 2][j + 2].c == player && _A[i + 3][j + 3].c == player &&
                _A[i + 4][j + 4].c == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 4; j < BOARD_SIZE; j++) {
            if (_A[i][j].c == player && _A[i + 1][j - 1].c == player &&
                _A[i + 2][j - 2].c == player && _A[i + 3][j - 3].c == player &&
                _A[i + 4][j - 4].c == player) {
                return true;
            }
        }
    }

    return false;
}

//Kiểm tra bàn cờ
int TestBoard() {
    if (checkDraw(0)) return 0;
    else if (checkWin(1)) return -1;
    else if (checkWin(2)) return 1;
    return 2;
}

//In kết quả
int ProcessFinish(int pWhoWin) {
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
    switch (pWhoWin) {
    case -1:
        printColoredRectangle(13, 2, 12, 8, BRIGHT_WHITE);
        ingameWin(1, 3, LIGHT_RED);
        _GAME_OVER = true;
        break;
    case 1:
        printColoredRectangle(98, 2, 12, 8, BRIGHT_WHITE);
        ingameWin(85, 3, LIGHT_GREEN);
        _GAME_OVER = true;
        break;
    case 0:
        cout << "It's a draw!\n";
        _GAME_OVER = true;
        break;
    case 2:
        _TURN = !_TURN;
        break;
    }
    GotoXY(_X, _Y);
    return pWhoWin;
}

//Hỏi tiếp tục hay dừng lại
int AskContinue() {    
    printColoredRectangle(37, 27, 50, 3, BRIGHT_WHITE);
    GotoXY(47, 28);
    setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
    cout << "Press 'y/n' to continue/exit: ";
    setConsoleColor(BRIGHT_WHITE, BLACK);
    return toupper(_getch());
}
