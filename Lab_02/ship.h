#ifndef SHIP_H
#define SHIP_H
#include <list>

#include "GameBoardCell.h"
#include <deque>

#define MAX_SIZE_SHIP 4

enum SizeShip{
    DECK1 = 1,
    DECK2 = 2,
    DECK3 = 3,
    DECK4 = 4
};

enum Direction {
    HORIZONTAL = 0,
    VERTICAL   = 1,
};

class Ship {
    list <GameBoardCell *> _BufShip; 
    int state;
    Direction _Dir;
public:
    Ship (const list <GameBoardCell *>, const Direction);
    ~Ship(void);
    virtual int GetSize(void) const = 0;
    Direction GetDir(void) const;
    int GetX(void) const;
    int GetY(void) const;  
};

class Ship1: public Ship {
public:
    Ship1 (const list <GameBoardCell *>, const Direction);
    ~Ship1() {}
    int GetSize(void) const;
};

class Ship2: public Ship {
public:
    Ship2 (const list <GameBoardCell *>, const Direction);
    ~Ship2() {}

    int GetSize(void) const;
};

class Ship3: public Ship {
public:
    Ship3 (const list <GameBoardCell *>, const Direction);
    ~Ship3() {}
    int GetSize(void) const;
};

class Ship4: public Ship {
public:
    Ship4 (const list <GameBoardCell *>, const Direction);
    ~Ship4() {}
    int GetSize(void) const;
};

#endif //SHIP_H