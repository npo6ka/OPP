#include "GameBoard.h"

#include <deque>

int main(int argc, char** argv)
{
    GameBoard asdf(10);
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
