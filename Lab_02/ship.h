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
    Direction _Dir;
public:
    Ship (int SizeShip,  list <GameBoardCell *> BufShip, Direction dir):
        _SizeShip(SizeShip), _BufShip(BufShip), _Dir(dir) {
        for (auto& it: _BufShip) {
            it->SetStat(DECK);
            it->SetShip(this);
        }
    }
    ~Ship() {
        for (auto& it: _BufShip) {
            it->SetStat(EMPTY);
            it->SetShip(NULL);
        }
    }

    int GetSize() {
        return _SizeShip;
    }
    int GetDir() {
        return _Dir;
    }
    int GetX() {
        return _BufShip.front()->GetPosX();
    }
    int GetY() {
        return _BufShip.front()->GetPosY();
    }    
};

#endif //SHIP_H