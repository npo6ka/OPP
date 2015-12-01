#ifndef SHIP_H
#define SHIP_H
#include <list>

#include "GameBoardCell.h"
#include <deque>

#define MAX_SIZE_SHIP 4

class Visitor;

enum SizeShip{
    DECK1 = 1,
    DECK2 = 2,
    DECK3 = 3,
    DECK4 = 4
};

enum Direction {
    UNK        = -1,
    HORIZONTAL =  0,
    VERTICAL   =  1,
};

class Ship: public enable_shared_from_this<Ship>{
    list <shared_ptr<GameBoardCell>> _bufCells;
    Direction _dir;
    int _status;

    void setDir(Direction dir);
    Direction resetDir();
    void sortCell();   
protected:
    bool tryAddCell(list <shared_ptr<GameBoardCell>> cells);
public:
    Ship ();
    virtual ~Ship(void);

    virtual void drawShip(shared_ptr<Visitor>)= 0;
    virtual bool addCells(list <shared_ptr<GameBoardCell>> cells) = 0;
    void setShipInCells();
    
    list<shared_ptr<GameBoardCell>> getCells(void) const;
    virtual SizeShip getSize(void) const = 0;
    Direction getDir(void) const;
    int getX(void) const;
    int getY(void) const;
            
    bool checkShip(void);
    bool checkFull(void);
    bool checkDestShip(void);
    void clearShip(void);
};

class Ship1: public Ship {
public:
    Ship1 ();
    Ship1 (const list <shared_ptr<GameBoardCell>>);
    ~Ship1() {}
    bool addCells(list <shared_ptr<GameBoardCell>>);
    SizeShip getSize(void) const;
    void drawShip(shared_ptr<Visitor>);
};

class Ship2: public Ship {
public:
    Ship2 ();
    Ship2 (const list <shared_ptr<GameBoardCell>>);
    ~Ship2() {}
    bool addCells(list <shared_ptr<GameBoardCell>>);
    SizeShip getSize(void) const;
    void drawShip(shared_ptr<Visitor>);
};

class Ship3: public Ship {
public:
    Ship3 ();
    Ship3 (const list <shared_ptr<GameBoardCell>>);
    ~Ship3() {}
    bool addCells(list <shared_ptr<GameBoardCell>>);
    SizeShip getSize(void) const;
    void drawShip(shared_ptr<Visitor>);
};

class Ship4: public Ship {
public:
    Ship4 ();
    Ship4 (const list <shared_ptr<GameBoardCell>>);
    ~Ship4() {}
    bool addCells(list <shared_ptr<GameBoardCell>>);
    SizeShip getSize(void) const;
    void drawShip(shared_ptr<Visitor>);
};

#endif //SHIP_H