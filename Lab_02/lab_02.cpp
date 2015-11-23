#include "GameBoard.h"
//#include "Ship.h"

#include <deque>


void Valid(const GameBoard const buf) {
    if (buf.checkFullBoard()) {
        cout << "Board Valid!" << endl;
    } else  cout << "Board Not valid(" << endl;
}

int main(int argc, char** argv)
{
    /* Проверка Корабля
    shared_ptr<GameBoardCell> _board[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            _board[i][j] = shared_ptr<GameBoardCell> (new GameBoardCell(i, j));
        }
    }
    shared_ptr<Ship> ship (new Ship4());
    list<shared_ptr<GameBoardCell>> buf;

    buf.push_back(_board[5][2]);
    buf.push_back(_board[4][2]);
    buf.push_back(_board[2][2]);
    buf.push_back(_board[3][2]);

    ship->addCells(buf);
    buf = ship->getCells();
    ship->setShipInCells();

    shared_ptr<Ship> two (_board[5][2]->getShip());

    two->clearShip();*/

    GameBoard board1;

    board1.setFullShip(1, 1, HORIZONTAL, 3);
    board1.print();
    board1.setFullShip(8, 1, HORIZONTAL, 2);
    board1.print();
    board1.setFullShip(5, 1, HORIZONTAL, 2);
    board1.print();
    board1.setFullShip(9, 7, HORIZONTAL, 3);
    board1.print();
    Valid(board1);
    board1.print();
    board1.setFullShip(6, 8, VERTICAL,   2);
    board1.print();
    board1.setFullShip(0, 7, VERTICAL,   1);
    board1.print();
    board1.setFullShip(0, 5, VERTICAL,   1);
    board1.print();
    board1.setFullShip(2, 5, VERTICAL,   1);
    board1.print();
    board1.setFullShip(4, 9, VERTICAL,   1);

    board1.print();
    board1.setDeckShip(8, 5, 4);
    board1.print();
    board1.setDeckShip(7, 5, 4);
    board1.print();
    board1.setDeckShip(6, 5, 4);
    board1.print();
    board1.setDeckShip(5, 5, 4);
    board1.print();

    Valid(board1);
    board1.print();
    Valid(board1);
    board1.print();
    cout << "Del 4 deck ship..." << endl;
    board1.delShip(7, 5);
    board1.print();
    board1.clear();
    board1.print();
    board1.reset();
    board1.print();
    GameBoard board2;
    board2.generateShip();
    Valid(board2);
    board2.print();
    return 0;
}
