#include "Ship.h"

Ship::Ship (): _status(-1), _dir(UNK) {}
Ship::~Ship() {
    for (auto& it: _bufCells) {
        it->clearCell();
    }
}

void Ship::setDir(Direction dir) {
    _dir = dir;
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
    _bufCells.splice(_bufCells.end(), cells); //совмещаем листы
    if (_bufCells.size() >= 0 && _bufCells.size() <= getSize()) { //сумма ячеек не должна превышать размер карабля
        if (_bufCells.size() == 1) return 1; //если однопалубник, всё проще
        if (resetDir() == UNK) return 0; //просчитываем новое направление карабля 
        sortCell();
        return checkShip();
    } else return 0;
}

void Ship::setShipInCells() {   
    for (auto& it:_bufCells) {
        it->setShip(shared_from_this());
    }
}

list<shared_ptr<GameBoardCell>> Ship::getCells() const{
    return _bufCells;
}
Direction Ship::getDir() const {
    return _dir;
}
int Ship::getX() const {
    if (_bufCells.size()) {
        return _bufCells.front()->getPosX();
    } else return -1;
}
int Ship::getY() const {
    if (_bufCells.size()) {
        return _bufCells.front()->getPosY();
    } else return -1;
}    


bool Ship::checkShip() {
    if (getDir()) {
        for (list<shared_ptr<GameBoardCell>>::iterator it = _bufCells.begin(); *it != _bufCells.back();) {
                if ((*it)->getPosY() != _bufCells.back()->getPosY()) return 0; //т.к. направление вертикальное, все корабли должны иметь одинаковую координату по У
                if ((*it)->getPosX()+1 != (*(++it))->getPosX()) return 0; //а каждая последующая ячейка имеет координату Х на 1 больше, чем предыдущая
        }
        
    } else { 
        for (list<shared_ptr<GameBoardCell>>::iterator it = _bufCells.begin(); *it != _bufCells.back();) {
                if ((*it)->getPosX() != _bufCells.back()->getPosX()) return 0; //т.к. направление горизонтальное, все корабли должны иметь одинаковую координату по Х
                if ((*it)->getPosY()+1 != (*(++it))->getPosY()) return 0; //а каждая последующая ячейка имеет координату У на 1 больше, чем предыдущая
        }
    }
    return 1;
}
bool Ship::checkFull() {
    if (_bufCells.size() == getSize() && checkShip()) {
        return 1;
    } else return 0;
}
bool Ship::checkDestShip() {
    for (auto& it: getCells()) {
        if (!it->getStat()) return 0;
    }
    return 1;
}
void Ship::clearShip() {
    for (auto& it: _bufCells) {
        it->clearCell();
    }
    _bufCells.clear();
    setDir(UNK);
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
unsigned int Ship1::getSize(void) const {
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
unsigned int Ship2::getSize(void) const{
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
unsigned int Ship3::getSize(void) const {
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
unsigned int Ship4::getSize(void) const {
    return DECK4;
}

