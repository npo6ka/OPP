#ifndef GAMECELL_H
#define GAMECELL_H
#include <memory>
#include <iostream>
 
using namespace std;

class Visitor;

enum Stat{
    EMPTY   = 0,
    HIT    = 1,
};

class Ship;

class GameBoardCell: public enable_shared_from_this<GameBoardCell> {
    Stat  _state;
	weak_ptr<Ship> _sh;
    int   _x;
    int   _y;
public:
    GameBoardCell(int, int);
    ~GameBoardCell(void);
    GameBoardCell(const GameBoardCell &);
    void drawCell(shared_ptr<Visitor>, bool);
    void setPos(const int, const int);
    void setStat (const Stat);
    void setShip (shared_ptr<Ship> const);
    void clearCell (void);
    int getPosX(void) const;
    int getPosY(void) const;
    shared_ptr<Ship> getShip(void) const;
    Stat getStat(void) const;
};

#endif //GAMECELL_H