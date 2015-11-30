#include "Player.h"
#include "vector"
class Game {
    int _quantityUsers;
    int _quantityComp;
    vector<shared_ptr<Player>> _players;
public:
    Game(const int, const int);
    ~Game();


};