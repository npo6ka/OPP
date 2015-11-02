#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameBoardCell.h"
#include "ship.h"

#include <list>
#include <array>
#include <algorithm>
#include <time.h>

#define _BoardSize 10
#define CountGeneration 100

class GameBoard {
    static const int ShipCount[4];
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
        if (x < 0 || x >= _BoardSize || y < 0 || y >= _BoardSize) {
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

    void PrintBoard() const {
        for (int i = 0; i < _BoardSize; i++) {
            for (int j = 0; j < _BoardSize; j++) {
                cout << GetCell(i, j)->GetStat();
            }
            cout << endl;
        }
        cout << endl;
    }

    bool SetShip(const int x, const int y, const Direction dir, const int size) {
        list <GameBoardCell *> mas;
        if (dir == HORIZONTAL) {
            for (int i = 0; i < size; i++) {
                if (GetCell(x, y+i) != NULL && GetShip(x, y+i) == NULL) {
                    mas.push_back(GetCell(x, y+i));
                } else return 0;
            }
        } else {
            for (int i = 0; i < size; i++) {
                if (GetCell(x, y+i) != NULL && GetShip(x+i, y) == NULL) {
                    mas.push_back(GetCell(x+i, y));
                } else return 0;
            }         
        }
        Ship *buf = new Ship(size, mas, dir);
        if (!CheckShip(buf)) {
            delete(buf);
            return 0;
        }
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

    bool CheckShip(Ship *sh) const{
        int x = sh->GetX();
        int y = sh->GetY();
        int size = sh->GetSize();
        //PrintBoard();
        if (sh->GetDir() == HORIZONTAL) {
            for (int i = y-1; i < y + size + 1; i++) {
                if (GetShip(x-1, i) || GetShip(x+1, i)) return 0;
            }
            if (GetShip(x-1, y) || GetShip(x, y + size)) return 0;
        } else {
            for (int i = x-1; i < x + size + 1; i++) {
                if (GetShip(i, y-1) || GetShip(i, y+1)) return 0;
            }
            if(GetShip(x-1, y) || GetShip(x + size, y)) return 0;
        }
        return 1;
    }

    void ClearBoard() {
        for (int i = 0; i < _BoardSize; i++) {
            for (int j = 0; j < _BoardSize; j++) {
                GetCell(i, j)->ClearCell();
            }
        }
    }

    bool ValidBoard() const {
        list<Ship *> BufShip;
        for (int i = 0; i < 4; i++) {
            BufShip = GetListShip(i);
            if (BufShip.size() != ShipCount[i]) return 0; 
            for (auto& it: BufShip) {
                if (!CheckShip(it)) return 0;
            }
        }
        return 1;
    }

     bool RankingShip(int count) {
        ClearBoard();
        for (int i = 4 - 1; i >= 0; i--) {
            int x, y, BufX, BufY;
            Direction dir;
            for (int j = ShipCount[i]-1; j >= 0; j--) {
                BufX = x = rand() % _BoardSize;
                BufY = y = rand() % _BoardSize;
                dir = Direction(rand() % 2);
                while (!(SetShip(x, y, dir, ShipCount[i]) || SetShip(x, y, (Direction)(!dir), ShipCount[i]))) {
                    if (++y >= _BoardSize) {
                        y = 0;
                        if (++x >= _BoardSize) x = 0;
                    } 
                    if (y == BufX && x == BufY) break;
                }
                PrintBoard();
            }
        }
        if (!ValidBoard()) {
            if (--count > 0) {
                return GenerateShip(); 
            } else return 0;
        } else return 1; 
    }

    bool GenerateShip() {       
        srand(time(0));
        return RankingShip(CountGeneration);
    }
    
};

#endif //GAMEBOARD_H