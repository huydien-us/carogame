#pragma once
#include "Header.h"
#include "Common.h"
#include "Draw.h"
#include "Control.h"


#include <unordered_map>
#include <filesystem>
//bool exitGame;				//Cờ thoát game

void mainScreen();								//Màn hình chính
void mainMenu();									//Menu
void subMenu();
void subScreen();
void newGameMenu();								//Menu New Game
void loadScreen();								//Màn hình load file
void helpScreen();								//Màn hình hướng dẫn
void aboutUS();									//Màn hình giới thiệu
void exitScreen();								//Màn hình thoát
void backMenu();									//Trở về Menu chính
void changeOption(bool, bool);					//Thay đổi lựa chọn
