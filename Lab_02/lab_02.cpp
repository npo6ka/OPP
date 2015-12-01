//#include "Player.h"
#include "Visitor.h"

//#include "GameBoard.h"
//#include "Ship.h"
#include <deque>


void Valid(const GameBoard buf) {
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
    /* проверка поля
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

    board1.clear();
    board1.print();

    GameBoard board2;
    board2.print();
    int x = 5, y = 5; 
    board2.setStatShot(x, y, board1.getStatShot(x, y));
    board1.print();
    board2.print();
    board2.setStatShot(x-1, y, board1.getStatShot(x-1, y));
    board1.print();
    board2.print();
    board2.setStatShot(x+2, y, board1.getStatShot(x+2, y));
    board1.print();
    board2.print();
    board2.setStatShot(x+1, y, board1.getStatShot(x+1, y));
    board1.print();
    board2.print();
    board2.setStatShot(x+3, y, board1.getStatShot(x+3, y));
    board1.print();
    board2.print();
    */
    /*PlayerComp buf;
    PlayerUser use;
    buf.changeNick("sdgdfgdfggd");
    use.setShip(2,3,HORIZONTAL, 3);
    use.setShip(6,6,VERTICAL, 1);
    use.delShip(6, 6);
    use.clearBoards();
    use.getStatShot(2, 5);
    use.getStatShot(1, 1);
    use.resetBoards();
    buf.autoSetShips();
    buf.checkBoard();
    buf.clearBoards();
    buf.checkBoard();
    buf.setStatShot(5, 4, 3);*/
    
    shared_ptr<Visitor> vis (new Print());
    GameBoard board1;
    board1.generateShips();
    board1.drawBoard(vis);

    return 0;
}
