#include "Game.h"

Game::Game(const int user, const int comp) {
    for (int i = 0; i < user; i++) {
        _players.push_back(shared_ptr<Player> (new PlayerUser()));
    }
    for (int i = 0; i < comp; i++) {
        _players.push_back(shared_ptr<Player> (new PlayerComp()));
    }
}

