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
    GameBoardCell(int, int);
    ~GameBoardCell(void) {};
    void SetPos(const int, const int);
    void SetStat (const Stat);
    void SetShip (Ship* const);
    void ClearCell (void);
    int GetPosX(void) const;
    int GetPosY(void) const;
    Ship* GetShip(void) const;
    Stat GetStat(void) const;
};

#endif //GAMECELL_H