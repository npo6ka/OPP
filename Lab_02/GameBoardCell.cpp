#include "GameBoardCell.h"

GameBoardCell::GameBoardCell(int x, int y) : _x(x), _y(y), _state(EMPTY), _sh(NULL)  {}

GameBoardCell::GameBoardCell(const GameBoardCell &obj) {
    this->SetPos(obj.GetPosX(), obj.GetPosY());
    this->SetStat(obj.GetStat());
}

void GameBoardCell::SetPos(const int x, const int y) {
    _x = x;
    _y = y;
}

void GameBoardCell::SetStat (const Stat st) {
    _state = st;
}

void GameBoardCell::SetShip (Ship* const sh) {
    _sh = sh;
}

void GameBoardCell::ClearCell () {
    _sh = NULL;
    _state = EMPTY;
}

int GameBoardCell::GetPosX () const {
    return _x;
}

int GameBoardCell::GetPosY () const {
    return _y;
}

Ship* GameBoardCell::GetShip () const {
    return _sh;
}

Stat GameBoardCell::GetStat () const {
    return _state;
}
