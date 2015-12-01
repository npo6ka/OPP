#include "Visitor.h"
#include <windows.h>

void gotoxy(short x, short y)
{
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD  coord  = {x, y};
    SetConsoleCursorPosition(StdOut, coord);
}

void Print::PrintCell(shared_ptr<GameBoardCell> cell) {
    gotoxy(cell->getPosX(), cell->getPosY());
    std::cout << cell->getStat();
}
void Print::PrintShip1(shared_ptr<Ship> sh) {
    std::cout << "print Ship 1: X:" << sh->getX() << " Y: " << sh->getY() << " size: " << sh->getCells().size() << endl;
}
void Print::PrintShip2(shared_ptr<Ship> sh) {
    std::cout << "print Ship 2: X:" << sh->getX() << " Y: " << sh->getY() << " size: " << sh->getCells().size() << endl;
}
void Print::PrintShip3(shared_ptr<Ship> sh) {
    std::cout << "print Ship 3: X:" << sh->getX() << " Y: " << sh->getY() << " size: " << sh->getCells().size() << endl;
}
void Print::PrintShip4(shared_ptr<Ship> sh) {
    std::cout << "print Ship 4: X:" << sh->getX() << " Y: " << sh->getY() << " size: " << sh->getCells().size() << endl;
}