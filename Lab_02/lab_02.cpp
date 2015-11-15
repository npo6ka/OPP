#include "GameBoard.h"
#include "Ship.h"

#include <deque>
#include <memory>

void Valid(const GameBoard const buf) {
    if (buf.ValidBoard()) {
        cout << "Board Valid!" << endl;
    } else  cout << "Board Not valid(" << endl;
}

int main(int argc, char** argv)
{
    /*shared_ptr<int> a (new int);
    *a = 5;
    *a = 6;
    */
    GameBoard board1;
    board1.SetShip(5, 5, VERTICAL,   4);
    board1.SetShip(2, 7, VERTICAL,   3);
    board1.SetShip(1, 1, HORIZONTAL, 3);
    board1.SetShip(8, 1, HORIZONTAL, 2);
    board1.SetShip(5, 1, HORIZONTAL, 2);
    board1.PrintBoard();
    Valid(board1);
    board1.PrintBoard();
    board1.SetShip(6, 8, VERTICAL,   2);
    board1.SetShip(0, 7, VERTICAL,   1);
    board1.SetShip(0, 5, VERTICAL,   1);
    board1.SetShip(2, 5, VERTICAL,   1);
    board1.SetShip(4, 9, VERTICAL,   1);
    Valid(board1);
    board1.PrintBoard();
    cout << "Del 4 deck ship..." << endl;
    board1.DelShip(7, 5);
    board1.PrintBoard();

    GameBoard board2;
    board2.GenerateShip();
    Valid(board2);
    board2.PrintBoard();
    return 0;
}
