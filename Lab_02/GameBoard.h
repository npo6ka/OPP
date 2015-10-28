#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameBoardCell.h"
#include "ship.h"

#include <list>
#include <array>
#include <algorithm>



class GameBoard {
    int _BoardSize;                         // размер игрового поля
    static const int _4DeckShipCount = 1;   // число 4-х палубных
    static const int _3DeckShipCount = 2;   // число 3-х палубных
    static const int _2DeckShipCount = 3;   // число 2-х палубных
    static const int _1DeckShipCount = 4;   // число 1-х палубных
    deque<deque<GameBoardCell>> _board;
    array<list<Ship *>, 4> MasShip;
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

    bool SetShip(const int x, const int y, const Direction dir, const int size) {
        list <GameBoardCell *> mas;
        for (int i = 0; i < size; i++) {
            if (dir == HORIZONTAL) {
                if (_board[x+i-1][y-1].GetShip() == NULL) {
                    mas.push_back(&_board[x+i-1][y-1]);
                } else return 0;
            } else {
                if (_board[x-1][y+i-1].GetShip() == NULL) {
                    mas.push_back(&_board[x-1][y+i-1]);
                } else return 0;
            }
        }
        Ship *buf = new Ship(size, mas, dir);
        MasShip[size-1].push_back(buf); 
        return 1;
    }
    bool DelShip (const int x, const int y) {
        if (x <= 0 || x >= _BoardSize || y <= 0 || y >= _BoardSize) {
            return 0;
        } else {
            Ship *sh = _board[x-1][y-1].GetShip();   
            int size = sh->GetSize()-1;
            auto it = search_n (MasShip[size].begin(), MasShip[size].end(), 1, sh,
                    [](Ship *i, Ship *j) -> bool {
                        return (i == j);
                    }
                );
            if (it != MasShip[size].end()) {
                MasShip[size].erase(it);
            } else return 0;
            sh->DestroyShip();
            delete(sh);
            return 1;
        }
    }

    int GetSize () {
        return _BoardSize;
    }

    bool ValidBoard() {
        int CountShip[4];
        for (int i = 0; i < GetSize(); i++) {
            for (int j = 0; j < GetSize(); j++) {
                if (_board[i][j].GetShip()) {
                    CountShip[_board[i][j].GetShip()->GetSize() - 1]++;
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

    //???
    Stat GetStat(const int x, const int y) {
        return _board[x][y].GetStat();
    }

    //???
    Ship* GetShip(const int x, const int y, const Direction div, const int size) {
        if (x <= _BoardSize && y < _BoardSize && _board[x][y].GetShip() != NULL) {
            return _board[x][y].GetShip();
        }
    }
};

#endif //GAMEBOARD_H