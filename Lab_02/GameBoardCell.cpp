#include "GameBoardCell.h"

GameBoardCell::GameBoardCell(int x, int y) : _x(x), _y(y), _state(EMPTY) {}
GameBoardCell::~GameBoardCell() { 
    _sh.reset();
}

GameBoardCell::GameBoardCell(const GameBoardCell &obj) {
    this->setPos(obj.getPosX(), obj.getPosY());
    this->setStat(obj.getStat());
}

void GameBoardCell::setPos(const int x, const int y) {
    _x = x;
    _y = y;
}

void GameBoardCell::setStat (const Stat st) {
    _state = st;
}

void GameBoardCell::setShip (shared_ptr<Ship> const sh) {
    _sh = sh;
}

void GameBoardCell::clearCell () {
    _sh.reset();
    _state = EMPTY;
}

int GameBoardCell::getPosX () const {
    return _x;
}

int GameBoardCell::getPosY () const {
    return _y;
}

shared_ptr<Ship> GameBoardCell::getShip () const {
    return _sh.lock();
}

Stat GameBoardCell::getStat () const {
    return _state;
}
