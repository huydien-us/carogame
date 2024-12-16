#pragma once

extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;
extern bool _GAME_OVER;

void StartGame();
void DrawBoard();
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void ExitGame();


void ResetData();
int TestBoard();
bool checkWin(int player);
bool checkDraw(int player);


int ProcessFinish(int pWhoWin);
int AskContinue();



