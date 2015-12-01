#pragma once
#include "Player.h"

class Visitor;

class HandlerCmd {
    shared_ptr<Visitor> _vis; 

    void printMsg(string str);
    void printFrameForCmd(void);
    string readCmd(void);
public: 
    HandlerCmd(shared_ptr<Visitor>);
    int handlerCmdPrep(shared_ptr<PlayerUser>);
    int handlerCmdGame(shared_ptr<PlayerUser>);
    int handlerCmdEnd (shared_ptr<PlayerUser>);
};