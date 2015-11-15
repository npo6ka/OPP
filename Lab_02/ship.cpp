#include "ship.h"

Ship::Ship (const list <GameBoardCell *> BufShip, const Direction dir):
    _BufShip(BufShip), _Dir(dir) {
    for (auto& it: _BufShip) {
        it->SetStat(DECK);
        it->SetShip(this);
    }
}
Ship::~Ship() {
    for (auto& it: _BufShip) {
        it->SetStat(EMPTY);
        it->SetShip(NULL);
    }
}

Direction Ship::GetDir() const {
    return _Dir;
}
int Ship::GetX() const {
    return _BufShip.front()->GetPosX();
}
int Ship::GetY() const {
    return _BufShip.front()->GetPosY();
}    

Ship1::Ship1 (list <GameBoardCell *> BufShip, Direction dir): Ship(BufShip, dir) {}
int Ship1::GetSize(void) const {
    return DECK1;
}

Ship2::Ship2 (list <GameBoardCell *> BufShip, Direction dir): Ship(BufShip, dir) {}
int Ship2::GetSize(void) const{
    return DECK2;
}

Ship3::Ship3 (list <GameBoardCell *> BufShip, Direction dir): Ship(BufShip, dir) {}
int Ship3::GetSize(void) const {
    return DECK3;
}

Ship4::Ship4 (list <GameBoardCell *> BufShip, Direction dir): Ship(BufShip, dir) {}
int Ship4::GetSize(void) const {
    return DECK4;
}