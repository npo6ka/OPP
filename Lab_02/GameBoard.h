#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameBoardCell.h"
#include "Ship.h"

#include <list>
#include <array>
#include <algorithm>
#include <time.h>

#define BOARD_SIZE 10
#define OPTIMAZE (BOARD_SIZE % 3? 3: (BOARD_SIZE % 2? 2: 1))
#define AMOUNT_GENERATION 100

class GameBoard {
    static const int _ShipCount[MAX_SIZE_SHIP];
    GameBoardCell *_board[BOARD_SIZE][BOARD_SIZE];
    array<list<shared_ptr<Ship>>, MAX_SIZE_SHIP> _MasShip;

    void Generate(void);
    void Remove(void);
    bool RankingShip(int const);

public:
    GameBoard(void);
    ~GameBoard(void);
    GameBoard(const GameBoard &);
    GameBoardCell* GetCell(const int, const int) const;
    shared_ptr<Ship> GetShip(const int, const int) const;
    list<shared_ptr<Ship>> GetListShip(const int) const;

    void PrintBoard(void) const;
    bool AddShipAtList(const shared_ptr<Ship> &buf);
    bool RemoveShipOfList(shared_ptr<Ship> const);
    void ClearListShip(void);

    bool SetShip(const int, const int, const Direction, const int);
    bool DelShip (const int, const int);

    bool CheckShip(shared_ptr<Ship> const) const;

    void ClearBoard(void);

    bool ValidBoard(void) const;

    bool GenerateShip(void);
    
};

#endif //GAMEBOARD_H