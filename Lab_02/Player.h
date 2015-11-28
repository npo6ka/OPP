#include "GameBoard.h"
#include <string>

class Player {
    GameBoard _myBoard;
    GameBoard _opBoard;
    string    _nick;
protected:
    GameBoard*  getMyBoard(void);
    GameBoard*  getOpBoard(void);
public:
    Player(void) {}
    ~Player(void) {}
    int changeNick(const string);
    void clearBoards(void);
    void resetBoards(void);  
    bool autoSetShips(void);
    bool checkBoard(void);
    int getStatShot(const int, const int);
    int setStatShot(const int, const int, const int);
};

class PlayerComp: public Player {
    static int count;
public:
    PlayerComp(void);
};

class PlayerUser: public Player {
    static int count;
public:
    PlayerUser(void);
    bool setShip(const int, const int, const Direction, const int);
    bool delShip(const int, const int);
};