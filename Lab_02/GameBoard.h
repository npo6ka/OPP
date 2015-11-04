#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameBoardCell.h"
#include "ship.h"

#include <list>
#include <array>
#include <algorithm>
#include <time.h>

#define BOARD_SIZE 10
#define OPTIMAZE (BOARD_SIZE % 3? 3: (BOARD_SIZE % 2? 2: 1))
#define AMOUNT_GENERATION 100

class GameBoard {
    static const int ShipCount[MAX_SIZE_SHIP];
    GameBoardCell *_board[BOARD_SIZE][BOARD_SIZE];
    array<list<Ship *>, MAX_SIZE_SHIP> MasShip;

    void Generate(void);
    void Remove(void);
    bool RankingShip(int const);

    

public:
    GameBoard(void);
    ~GameBoard(void);

    GameBoardCell* GetCell(const int, const int) const;
    Ship* GetShip(const int, const int) const;
    list<Ship *> GetListShip(const int) const;

    void PrintBoard(void) const;

    bool AddShipAtList(Ship* const);
    bool RemoveShipOfList(Ship* const);
    void ClearListShip(void);

    bool SetShip(const int, const int, const Direction, const int);
    bool DelShip (const int, const int);

    bool CheckShip(Ship* const) const;

    void ClearBoard(void);

    bool ValidBoard(void) const;

    bool GenerateShip(void);
    
};

#endif //GAMEBOARD_H