#include "Ship.h"

Ship::Ship (): _status(-1), _dir(UNK) {}

Ship::~Ship() {
    for (auto& it: _bufCells) {
        it->clearCell();
    }
}

bool Ship::checkShip() {
    if (getDir() == HORIZONTAL) {
        for (list<shared_ptr<GameBoardCell>>::iterator it = _bufCells.begin(); *it != _bufCells.back();) {
                if ((*it)->getPosX() != _bufCells.back()->getPosX()) return 0;
                if ((*it)->getPosY()+1 != (*(++it))->getPosY()) return 0;
        }
    } else { 
        for (list<shared_ptr<GameBoardCell>>::iterator it = _bufCells.begin(); *it != _bufCells.back();) {
                if ((*it)->getPosY() != _bufCells.back()->getPosY()) return 0;
                if ((*it)->getPosX()+1 != (*(++it))->getPosX()) return 0;
        }
    }
    return 1;
}

void Ship::sortCell() {
    if (_dir == HORIZONTAL) {
        _bufCells.sort([](const shared_ptr<GameBoardCell> first, const shared_ptr<GameBoardCell> second) -> bool {
                        return (first->getPosY() < second->getPosY());  });
    } else {
        _bufCells.sort([](const shared_ptr<GameBoardCell> first, const shared_ptr<GameBoardCell> second) -> bool {
                        return (first->getPosX() < second->getPosX());  });
    }
}
bool Ship::tryAddCell(list <shared_ptr<GameBoardCell>> cells) {
    _bufCells.splice(_bufCells.end(), cells);
    if (_bufCells.size() >= 0 && _bufCells.size() <= getSize()) {
        if (_bufCells.size() == 1) return 1;
        if (resetDir() == UNK) return 0;
        sortCell();
        return checkShip();
    } else return 0;
}
list<shared_ptr<GameBoardCell>> Ship::getCells() {
    return _bufCells;
}
void Ship::clearShip() {
    for (auto& it: _bufCells) {
        it->clearCell();
    }
    _bufCells.clear();
    setDir(UNK);
}
Direction Ship::resetDir() {
    if (_bufCells.size() < 2) {
        setDir(UNK);
    } else {
        if (_bufCells.front()->getPosX() == _bufCells.back()->getPosX()) {
            setDir(HORIZONTAL);
        } else setDir(VERTICAL); 
    }
    return getDir();
}

void Ship::setDir(Direction dir) {
    _dir = dir;
}

Direction Ship::getDir() const {
    return _dir;
}
int Ship::getX() const {
    return _bufCells.front()->getPosX();
}
int Ship::getY() const {
    return _bufCells.front()->getPosY();
}    

bool Ship::setShipInCells() {
    if (_bufCells.size() == getSize() && checkShip()) {
        for (auto& it:_bufCells) {
            it->setShip(shared_from_this());
        }
        return 1;
    } else return 0;
}

Ship1::Ship1 (): Ship() {}
Ship1::Ship1 (list <shared_ptr<GameBoardCell>> bufCells): Ship() {
    addCells(bufCells);
}
bool Ship1::addCells(list <shared_ptr<GameBoardCell>> cells) {
    Ship1 SaveStat = *this;
    if (!tryAddCell(cells)) {
        *this = SaveStat;
        return 0;
    } else return 1; 
}
int Ship1::getSize(void) const {
    return DECK1;
}


Ship2::Ship2 (): Ship() {}
Ship2::Ship2 (list <shared_ptr<GameBoardCell>> bufCells): Ship() {
    addCells(bufCells);
}
bool Ship2::addCells(list <shared_ptr<GameBoardCell>> cells) {
    Ship2 SaveStat = *this;
    if (!tryAddCell(cells)) {
       *this = SaveStat;
        return 0;
    } else return 1; 
}
int Ship2::getSize(void) const{
    return DECK2;
}

Ship3::Ship3 (): Ship() {}
Ship3::Ship3 (list <shared_ptr<GameBoardCell>> bufCells): Ship() {
    addCells(bufCells);
}
bool Ship3::addCells(list <shared_ptr<GameBoardCell>> cells) {
    Ship3 SaveStat = *this;
    if (!tryAddCell(cells)) {
       *this = SaveStat;
        return 0;
    } else return 1; 
}
int Ship3::getSize(void) const {
    return DECK3;
}

Ship4::Ship4 (): Ship() {}
Ship4::Ship4 (list <shared_ptr<GameBoardCell>> bufCells): Ship() {
    addCells(bufCells);
}
bool Ship4::addCells(list <shared_ptr<GameBoardCell>> cells) {
    Ship4 SaveStat = *this;
    if (!tryAddCell(cells)) {
        *this = SaveStat;
        return 0;
    } else return 1; 
}
int Ship4::getSize(void) const {
    return DECK4;
}

