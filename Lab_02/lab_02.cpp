#include "GameBoard.h"
#include "Ship.h"

#include <deque>

int main(int argc, char** argv)
{
    GameBoard asdf;
    /*asdf.SetShip(0, 3, HORIZONTAL, 3);
    cout << asdf.ValidBoard() << endl;
    asdf.SetShip(0, 2, HORIZONTAL, 1);
    cout << asdf.ValidBoard() << endl;
    asdf.DelShip(3, 2);*/
    asdf.GenerateShip();
    asdf.PrintBoard();
    GameBoardCell cell(1, 2);
   
    return 0;
}
