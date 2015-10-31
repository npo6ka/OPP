#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameBoardCell.h"
#include "ship.h"

#include <list>
#include <array>
#include <algorithm>

#define _BoardSize 10

enum ShipCount{
    _1Deck = 4,
    _2Deck = 3,
    _3Deck = 2,
    _4Deck = 1
};

class GameBoard {
    GameBoardCell *_board[_BoardSize][_BoardSize];
    array<list<Ship *>, 4> MasShip;

    void Generate() {
        for (int i = 0; i < _BoardSize; i++) {
            for (int j = 0; j < _BoardSize; j++) {
                _board[i][j] = new GameBoardCell(i, j);
            }
        }
    }
    void Remove() {
        for (int i = 0; i < _BoardSize; i++) {
            for (int j = 0; j < _BoardSize; j++) {
                delete(_board[i][j]);
            }
        }
    }
public:
    GameBoard() {
        Generate();
    }
    ~GameBoard() {
        Remove();
    }

    GameBoardCell* GetCell(const int x, const int y) const {
        if (x < 0 || x > _BoardSize || y < 0 || y > _BoardSize) {
            return NULL;
        } else { 
            return _board[x][y];
        }
    }
    Ship* GetShip(const int x, const int y) const {
        GameBoardCell *cell = GetCell(x, y);
        if (cell != NULL) {
            return cell->GetShip();
        } else return NULL;
    }
    list<Ship *> GetListShip(const int size) const {
        if (size >= 0 && size <= 4) {
            return MasShip[size];
        } else {
            list<Ship *> ship;
            return ship; 
        }
    }

    bool SetShip(const int x, const int y, const Direction dir, const int size) {
        list <GameBoardCell *> mas;
        if (dir == HORIZONTAL) {
            for (int i = 0; i < size; i++) {
                if (GetShip(x, y+i) == NULL) {
                    mas.push_back(GetCell(x, y+i));
                } else return 0;
            }
        } else {
            for (int i = 0; i < size; i++) {
                if (GetShip(x+i, y) == NULL) {
                    mas.push_back(GetCell(x+i, y));
                } else return 0;
            }         
        }
        Ship *buf = new Ship(size, mas, dir);
        MasShip[size-1].push_back(buf); 
        return 1;
    }
    bool DelShip (const int x, const int y) {
        if (GetShip(x, y) == NULL) {
            return 0;
        } else {
            Ship *sh = GetShip(x, y);   
            int size = sh->GetSize()-1;
            auto it = search_n (MasShip[size].begin(), MasShip[size].end(), 1, sh,
                    [](Ship *i, Ship *j) -> bool {
                        return (i == j);
                    }
                );
            if (it != MasShip[size].end()) {
                MasShip[size].erase(it);
            } else return 0;
            delete(sh);
            return 1;
        }
    }

    void PrintBoard() {
        for (int i = 0; i < _BoardSize; i++) {
            for (int j = 0; j < _BoardSize; j++) {
                cout << GetCell(i, j)->GetStat();
            }
            cout << endl;
        }
        cout << endl;
    }

    bool ValidShip(Ship *sh){
        int x = sh->GetX();
        int y = sh->GetY();
        PrintBoard();
        if (sh->GetDir() == HORIZONTAL) {
            for (int i = y-1; i < y + sh->GetSize() + 1; i++) {
                if (GetShip(x-1, i) || GetShip(x+1, i)) return 0;
            }
            if (GetShip(x-1, y) || GetShip(x, y + sh->GetSize())) return 0;
        } else {
            for (int i = x-1; i < x + sh->GetSize() + 1; i++) {
                if (GetShip(i, y-1) || GetShip(i, y+1)) return 0;
            }
            if(GetShip(x-1, y) || GetShip(x + sh->GetSize(), y)) return 0;
        }
        return 1;
    }

    bool ValidBoard() {
        list<Ship *> BufShip;
        for (int i=0; i < 4; i++) {
            BufShip = GetListShip(i);
            for (auto& it: BufShip) {
                if (!ValidShip(it)) return 0;
            }
        }
        return 1;
    }

    

    
   /* bool ValidBoard() {
        int CountShip[4] = {0, 0, 0, 0};
        for (int i = 0; i < _BoardSize; i++) {
            for (int j = 0; j < _BoardSize; j++) {
                if (Ship *sh = GetShip(i, j)) {
                    CountShip[sh->GetSize() - 1]++;
                    if (GetShip(i+1, j  ) != sh || 
                        GetShip(i,   j+1) != sh || 
                        GetShip(i+1, j+1) != sh) {
                        return 0;
                    }
                }
            }
        }
        if (CountShip[0]   != _1Deck ||
            CountShip[1]/2 != _2Deck ||
            CountShip[2]/3 != _3Deck ||
            CountShip[3]/4 != _4Deck) {
                return 0;
        }
        return true;
    }*/
    /*
    //???
    Stat GetStat(const int x, const int y) {
        return _board[x][y].GetStat();
    }*/

    //???
    
};

#endif //GAMEBOARD_H