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
    ~Ship() {}

    void DestroyShip() {
        for (auto& it: _BufShip) {
            it->SetStat(EMPTY);
            it->SetShip(NULL);
        }
    }
    bool ValidShip() {
        for (auto& it: _BufShip) {
            if (it->GetShip() != this) {
                return 0;
            }
        }
        return 1;
    }

    int GetSize() {
        return _SizeShip;
    }
    bool ShotInShip(int x, int y) {

    }
    void SetShip() {

    }
    
};

#endif //SHIP_H