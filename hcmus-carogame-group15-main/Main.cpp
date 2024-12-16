#include "Header.h"
#include "Common.h"
#include "Data.h"
#include "Draw.h"
#include "Control.h"
#include "Menu.h"
#include "FileHandle.h"

using namespace std;

int main() {
    setUpConsole();
    _getch();
    system("color F0");
    printBoard(4, 1, 112, 26, 0);
    mainScreen();
    _getch();
}