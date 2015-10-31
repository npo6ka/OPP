#include "GameBoard.h"
#include "Ship.h"

#include <deque>

int main(int argc, char** argv)
{
    GameBoard asdf;
    asdf.SetShip(0, 3, HORIZONTAL, 3);
    cout << asdf.ValidBoard() << endl;
    asdf.SetShip(0, 2, HORIZONTAL, 1);
    cout << asdf.ValidBoard() << endl;
    asdf.DelShip(3, 2);
    asdf.PrintBoard();
    GameBoardCell cell(1, 2);
    deque<deque<int>> mas;
    mas.resize(10);
    for (int i = 0; i < 10; i++) {
        mas[i].push_back(1);
    }

    for (auto& it: mas) {

    }
    return 0;
}
