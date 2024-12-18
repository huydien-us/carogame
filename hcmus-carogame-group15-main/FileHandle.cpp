#include"FileHandle.h"
#include "Control.h"
using namespace std;

//hàm lưu ván game
void SaveGame() {
    ofstream outFile("save.txt");

    if (!outFile) {
        cout << "Error opening file to save game!" << endl;
        return;
    }


    outFile << _TURN << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            outFile << _A[i][j].c << " ";
        }
        outFile << endl;
    }

    outFile.close();
    GotoXY(0, 0);
    cout << "Game saved successfully!" << endl;
    Sleep(1000);
    system("exit");
    system("cls");
}

//hàm tải ván game
void LoadGame() {
    ifstream inFile("save.txt");

    if (!inFile) {
        cout << "No saved game found!" << endl;
        return;
    }
    inFile >> _TURN;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            inFile >> _A[i][j].c;
        }
    }

    inFile.close();
    //cout << "Game loaded successfully!" << endl;
    Sleep(1000);
    DrawBoard();
}
