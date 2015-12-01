#pragma once
#include "Player.h"

class Visitor {
public:
    virtual void PrintCell(shared_ptr<GameBoardCell>) = 0;
    virtual void PrintShip1(shared_ptr<Ship>) = 0;
    virtual void PrintShip2(shared_ptr<Ship>) = 0;
    virtual void PrintShip3(shared_ptr<Ship>) = 0;
    virtual void PrintShip4(shared_ptr<Ship>) = 0;
    virtual void PrintFrame() = 0;
};

class Print: public Visitor {
    void PrintCell(shared_ptr<GameBoardCell>);
    void PrintShip1(shared_ptr<Ship>);
    void PrintShip2(shared_ptr<Ship>);
    void PrintShip3(shared_ptr<Ship>);
    void PrintShip4(shared_ptr<Ship>);
    void PrintFrame() {};
};