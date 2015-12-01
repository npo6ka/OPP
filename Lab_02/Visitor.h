#pragma once
#include "HandlerCmd.h"

class Visitor {
public:
    virtual void PrintCell(shared_ptr<GameBoardCell>, bool) = 0;
    virtual void PrintShip1(shared_ptr<Ship>, bool) = 0;
    virtual void PrintShip2(shared_ptr<Ship>, bool) = 0;
    virtual void PrintShip3(shared_ptr<Ship>, bool) = 0;
    virtual void PrintShip4(shared_ptr<Ship>, bool) = 0;
    virtual void PrintFrameForCmd(void) = 0;
    virtual void PrintMsg(string) = 0;
    //virtual void PrintFrame() = 0;
};

class Print: public Visitor {
    void PrintCell(shared_ptr<GameBoardCell>, bool);
    void PrintShip1(shared_ptr<Ship>, bool);
    void PrintShip2(shared_ptr<Ship>, bool);
    void PrintShip3(shared_ptr<Ship>, bool);
    void PrintShip4(shared_ptr<Ship>, bool);
    void PrintFrameForCmd(void);
    void PrintMsg(string);
    //void PrintFrame() {};
};