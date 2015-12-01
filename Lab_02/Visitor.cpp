#include "Visitor.h"
#include <windows.h>

#define WIDTH            80
#define HEIGHT           25
#define HEI_INDENT_BOARD HEIGHT / 5
#define WID_INDENT_BOARD WIDTH / 5
#define SHIFT_FOR_BOARD  WIDTH - WID_INDENT_BOARD - BOARD_SIZE

void gotoxy(short x, short y)
{
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD  coord  = {x, y};
    SetConsoleCursorPosition(StdOut, coord);
}

void Print::PrintCell(shared_ptr<GameBoardCell> cell, bool shift) {
    gotoxy(cell->getPosX() + shift*SHIFT_FOR_BOARD, cell->getPosY() + HEI_INDENT_BOARD);
    if (cell->getStat()) {
        cout << char(178);
    } else cout << char(176);
}
void Print::PrintShip1(shared_ptr<Ship> sh, bool shift) {
    for (auto& it:sh->getCells()) {
        gotoxy(it->getPosX() + shift*SHIFT_FOR_BOARD, it->getPosY() + HEI_INDENT_BOARD);
        if (it->getStat()) {
            cout << char(219);
        } else {
            cout << "#";
        }
    }
    gotoxy(20, 0);
}
void Print::PrintShip2(shared_ptr<Ship> sh, bool shift) {
    for (auto& it:sh->getCells()) {
        gotoxy(it->getPosX() + shift*SHIFT_FOR_BOARD, it->getPosY() + HEI_INDENT_BOARD);
        if (it->getStat()) {
            cout << char(219);
        } else {
            cout << "#";
        }
    }
    gotoxy(20, 0);
}
void Print::PrintShip3(shared_ptr<Ship> sh, bool shift) {
    for (auto& it:sh->getCells()) {
        gotoxy(it->getPosX() + shift*SHIFT_FOR_BOARD, it->getPosY() + HEI_INDENT_BOARD);
        if (it->getStat()) {
            cout << char(219);
        } else {
            cout << "#";
        }
    }
    gotoxy(20, 0);
}
void Print::PrintShip4(shared_ptr<Ship> sh, bool shift) {
    for (auto& it:sh->getCells()) {
        gotoxy(it->getPosX() + shift*SHIFT_FOR_BOARD, it->getPosY() + HEI_INDENT_BOARD);
        if (it->getStat()) {
            cout << char(219);
        } else {
            cout << "#";
        }
    }
    gotoxy(20, 0);
}

void Print::PrintFrameForCmd() {
    gotoxy(0, 20);
    cout << (string (WIDTH * 2, ' '));
    gotoxy(0, 20);
    cout << "Enter command: ";
}

void Print::PrintMsg(string str) {
    gotoxy(19, 10);
    cout << str;
}