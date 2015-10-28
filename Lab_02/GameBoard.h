#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameBoardCell.h"
#include "ship.h"

#include <list>



class GameBoard {
    int _BoardSize;       // размер игрового поля
    static const int _4DeckShipCount = 1;   // число 4-х палубных
    static const int _3DeckShipCount = 2;   // число 3-х палубных
    static const int _2DeckShipCount = 3;   // число 2-х палубных
    static const int _1DeckShipCount = 4;   // число 1-х палубных
    deque<deque<GameBoardCell>> _board;
    void Generate() {
        _board.resize(_BoardSize);
        for (int i = 0; i < _BoardSize; i++) {
            for (int j = 0; j < _BoardSize; j++) {
                _board[i].push_back(GameBoardCell(i, j));
            }
        }
    }
public:
    GameBoard(int SizeBoard): _BoardSize(SizeBoard)  {
        Generate();
    }
    ~GameBoard() {}
    void SetShip(const int x, const int y, const Direction div, const int size) {
        /*list <GameBoardCell *> mas;
        for (int i = 0; i < size; i++) {
            if (div == HORIZONTAL) {
                mas.push_back(&_board[x+i][y]);
            } else {
                mas.push_back(&_board[x][y+i]);
            }
        }*/
        Ship sh (size, x, y, div, &_board);

    }
    bool Shot() {

    }
    void DelShip () {

    }
    int GetSize () {
        return _BoardSize;
    }

    bool ValidBoard() {
        int CountShip[4];
        for (int i = 0; i < GetSize(); i++) {
            for (int j = 0; j < GetSize(); j++) {
                if (_board[i][j].GetShip()) {
                    //CountShip[_board[i][j].GetShip().GetSize() - 1]++;
                    if (_board[i+1][j].GetShip() != _board[i][j].GetShip() || 
                        _board[i][j+1].GetShip() != _board[i][j].GetShip() || 
                        _board[i+1][j+1].GetShip() != _board[i][j].GetShip()) {
                        return 0;
                    }
                }
            }
        }
        if (CountShip[0]   != _1DeckShipCount ||
            CountShip[1]/2 != _2DeckShipCount ||
            CountShip[2]/3 != _3DeckShipCount ||
            CountShip[3]/4 != _4DeckShipCount) {
                return 0;
        }
        return true;
    }
    Stat GetStat(const int x, const int y) {
        return _board[x][y].GetStat();
    }
    Ship* GetShip(const int x, const int y, const Direction div, const int size) {
        if (_board[x][y].GetStat() <= MISS && _board[x][y].GetShip() != NULL) {
            return _board[x][y].GetShip();
        }
    }
};

#endif //GAMEBOARD_H