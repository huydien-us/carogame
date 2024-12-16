#pragma once
#include "Header.h"
#include "Data.h"
#include <Windows.h>

struct _POINT {
    int x, y, c;
};

void setUpConsole();
void GotoXY(int, int);				//Di chuyển con trỏ đến vị trí x,y
void CenterWindow();				//Căn giữa màn hình console
void hideScrollBars();				//Ẩn thanh cuộn
void setConsoleColor(int, int);		//Cài đặt màu nền
void clearConsole();				//Xóa màn hình console
void disableMaximize();				//Vô hiệu hóa phóng to màn hình
void showCursor(bool);				//Ẩn hoặc hiện con trỏ
void setFontInfo();					//Cài đặt font chữ
void disableMouseInput();			//Vô hiệu hóa chuột
int getConsoleInput();				//Lấy lệnh từ bàn phím

//thêm hàm âm thanh

void setColor(int);					//Cài đặt màu
void SetColor(int, int);




