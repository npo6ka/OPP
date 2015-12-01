#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameBoardCell.h"
#include "Ship.h"

#include <array>
#include <algorithm>
#include <time.h>

class Visitor;

#define BOARD_SIZE 10
#define OPTIMAZE (BOARD_SIZE % 3? 3: (BOARD_SIZE % 2? 2: 1))
#define AMOUNT_GENERATION 100

enum statShot{
    INCOR_CORD,
    BUSY,
    MISS,
    SHIP
};

class GameBoard {
    static const int _shipCount[MAX_SIZE_SHIP];
    shared_ptr<GameBoardCell> _board[BOARD_SIZE][BOARD_SIZE];
    array<list<shared_ptr<Ship>>, MAX_SIZE_SHIP> _masShip;

    void generate(void);
    shared_ptr<GameBoardCell> getCell(const int, const int) const;
    shared_ptr<Ship> getShip(const int, const int) const;
    list<shared_ptr<Ship>> getListShip(const int) const;

    bool addShipAtList(const shared_ptr<Ship> &buf);
    bool checkCellsAroundShip(shared_ptr<Ship> const) const;
    bool removeShipOfList(shared_ptr<Ship> const);
    bool rankingShip(int const);
    bool mergeShip(shared_ptr<Ship> &, shared_ptr<Ship> &);
    void drawBoard(shared_ptr<Visitor> vis, bool) const;

public:
    GameBoard(void);
    ~GameBoard(void);
    GameBoard(const GameBoard &);

    void drawMyBoard(shared_ptr<Visitor>) const;
    void drawOpBoard(shared_ptr<Visitor>) const;

    void drowAroundShip(shared_ptr<Ship> const);
    bool setFullShip(const int, const int, const Direction, const int);
    bool setDeckShip(const int, const int, const int);
    bool delShip (const int, const int);
    void reset(void);
    void clear(void);
    bool checkFullBoard(void) const;
    bool empty(void);

    bool generateShips(void);
    
    int getStatShot(const int, const int);
    int setStatShot(const int, const int, const int);
};

#endif //GAMEBOARD_H