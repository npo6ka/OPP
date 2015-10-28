#ifndef SHIP_H
#define SHIP_H
#include <list>

#include "GameBoardCell.h"
#include <deque>

enum Direction {
    HORIZONTAL = 0,
    VERTICAL   = 1,
};

class Ship {
    list <GameBoardCell *> _BufShip; 
    int _SizeShip;
public:
    /*Ship(int SizeShip, list <GameBoardCell *> BufShip):
         _SizeShip(SizeShip), _BufShip(BufShip) {}*/

    Ship (int SizeShip, int x, int y, Direction div, deque<deque<GameBoardCell>> *board):
          _SizeShip(SizeShip) {
        for (int i = 0; i < _SizeShip; i++) {
            if (div == HORIZONTAL) {
                _BufShip.push_back(&(*board)[x+i][y]);
            } else {
                _BufShip.push_back(&(*board)[x][y+i]);
            }
        }
        for (auto& it: _BufShip) {
            it->SetStat(DECK);
        }
    }
    ~Ship() {}
    
    bool ShotInShip(int x, int y) {

    }
    void SetShip() {

    }
    
};

#endif //SHIP_H