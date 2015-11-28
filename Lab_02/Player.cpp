#include "Player.h"

int PlayerComp::count = 0;
int PlayerUser::count = 0;

GameBoard* Player::getMyBoard() {
    return &_myBoard;
}
GameBoard* Player::getOpBoard() {
    return &_opBoard;
}

int Player::changeNick(const string str) {
    if (str.find_first_not_of
        ("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ_ ") 
        != string::npos) {
            return 0; // неккоректный никнейм
    } else {
        _nick = str;
        return 1; // всё хорошо
    }
}
void Player::clearBoards() {
    getMyBoard()->clear();
    getOpBoard()->clear();
}
void Player::resetBoards() {
    getMyBoard()->reset();
    getOpBoard()->reset();
}
bool Player::autoSetShips() {
    return getMyBoard()->generateShips();
}
bool Player::checkBoard() {
    return getMyBoard()->checkFullBoard() & getOpBoard()->empty();
}
int Player::getStatShot(const int x, const int y) {
    return getMyBoard()->getStatShot(x, y);
}
int Player::setStatShot(const int x, const int y, const int size) {
    return getOpBoard()->setStatShot(x, y, size);
}

PlayerComp::PlayerComp(): Player() {
    changeNick(string ("Computer_" + to_string(++count)));
}

PlayerUser::PlayerUser(): Player() {
    changeNick(string ("User_" + to_string(++count)));
}
bool PlayerUser::setShip(const int x, const int y, const Direction dir, const int size) {
    return getMyBoard()->setFullShip(x, y, dir, size);
}
bool PlayerUser::delShip(const int x, const int y) {
    return getMyBoard()->delShip(x, y);
}