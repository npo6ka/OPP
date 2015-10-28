#include "GameBoard.h"
#include "Ship.h"

#include <deque>

int main(int argc, char** argv)
{
    GameBoard asdf(10);
    asdf.SetShip(1, 4, HORIZONTAL, 3);
    //GameBoardCell cell(1, 2);
    deque<deque<int>> mas;
    mas.resize(10);
    for (int i = 0; i < 10; i++) {
        mas[i].push_back(1);
    }

    for (auto& it: mas) {

    }
    return 0;
}
