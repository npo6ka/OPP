//#include "GameBoard.h"
#include "Ship.h"

#include <deque>


/*void Valid(const GameBoard const buf) {
    if (buf.ValidBoard()) {
        cout << "Board Valid!" << endl;
    } else  cout << "Board Not valid(" << endl;
}*/

int main(int argc, char** argv)
{
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

    two->clearShip();
    /*GameBoardCell *cell = new GameBoardCell(1, 1);
    list <GameBoardCell *> mas;
    mas.push_back(cell);
    Ship *ship = new Ship1 (mas, HORIZONTAL);
    shared_ptr<Ship> a (ship);
    
    shared_ptr<Ship> b (ship->shared_from_this());

    shared_ptr<Ship> buff (ship);
    shared_ptr<Ship> c (buff);


    ship = c.get();
    delete cell;*/
    /*GameBoard board1;
    board1.PrintBoard();
    board1.SetShip(5, 5, VERTICAL,   4);
    board1.PrintBoard();
    board1.DelShip(5, 5);
    board1.PrintBoard();*/

    

    /*board1.SetShip(2, 7, VERTICAL,   3);
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
    board2.PrintBoard();*/
    return 0;
}
