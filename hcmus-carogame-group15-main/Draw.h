#pragma once
#include "Header.h"
#include "Common.h"


void printBoard(int left, int top, int width, int height, int color);					//in viền bảng
void Loading();																			//in thanh loading
void veBanCo(int, int);																	//vẽ bàn cờ
void printColoredRectangle(int left, int top, int width, int height, int color);		//in hình chữ nhật có màu
void printLogo(int);																	//in chữ CARO lớn
void Logo_Animation(int);																//hiệu ứng nhấp nháy Logo
void printAbout(int);																	//in chữ About
void printLoadGame(int);																//in chữ Load game
void printThanks(int x);																//in chữ Thanks for playing!																//vẽ mặt đất

//void DrawBoard();
void rightAmongUs(int x, int y, int color, int color_1, int color_2, int color_3);
void leftAmongUs(int x, int y, int color, int color_1, int color_2, int color_3);
void Bot(int left, int top, int color1, int color2, int color3, int color4);
void smallleftAmongUs(int x, int y, int color);
void smallrightAmongUs(int x, int y, int color);
void bigLeftMario(int x, int y, int color);
void bigRightMario(int x, int y, int color);
void ingameX(int x, int y, int color1, int color2);
void ingameO(int x, int y, int color1, int color2);
void ingameWin(int x, int y, int n);
void ingameHelp(int x, int y);
