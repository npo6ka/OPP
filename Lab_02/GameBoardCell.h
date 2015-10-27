#ifndef GAMECELL_H
#define GAMECELL_H

#include<iostream>
 
using namespace std;

enum Stat{
    EMPTY   = 0,
    MISS    = 1,
    DECK    = 2,
    HITDECK = 3
};

class Ship;

class GameBoardCell {
    Stat  _state;
	Ship* _sh;
    int   _x;
    int   _y;
public:
    GameBoardCell(int x, int y);
    ~GameBoardCell() {
        cout << "del cell" << _x << " "<< _y << endl;
    };
    void SetPos(const int x, const int y);
    void SetStat (const Stat st);
    void SetShip (Ship* const sh);
    int GetPosX() const;
    int GetPosY() const;
    Ship* GetShip() const;
    Stat GetStat() const;
};

#endif //GAMECELL_H