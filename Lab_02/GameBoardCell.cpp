#include "GameBoardCell.h"

GameBoardCell::GameBoardCell(int x, int y) : _x(x), _y(y), _state(EMPTY)  {
     cout << "constructor Cell" << endl;
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

int GameBoardCell::GetPosX() const {
    return _x;
}

int GameBoardCell::GetPosY() const {
    return _y;
}

Ship* GameBoardCell::GetShip() const {
    return _sh;
}

Stat GameBoardCell::GetStat() const {
    return _state;
}
