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
    time_t buf1 = time(0);
    time_t buf2 = clock();
    for (int i=0; i < 10000; i++) {
        //cout << "counter: " << i << endl;
        asdf.GenerateShip();
        //asdf.PrintBoard();
    }
    buf1 = time(0) - buf1;
    buf2 = clock() - buf2;
    cout << "Time:" << buf1 << "  " << buf2 << endl;
    GameBoardCell cell(1, 2);
   
    return 0;
}
