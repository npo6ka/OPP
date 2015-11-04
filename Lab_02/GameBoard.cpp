#include "GameBoard.h"

const int GameBoard::ShipCount[MAX_SIZE_SHIP] = {4,3,2,1};


void GameBoard::Generate() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _board[i][j] = new GameBoardCell(i, j);
        }
    }
}
void GameBoard::Remove() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            delete(_board[i][j]);
        }
    }
}
bool GameBoard::RankingShip(int const count) {
    ClearBoard();
    for (int i = MAX_SIZE_SHIP - 1; i >= 0; i--) {
        int x, y, BufX, BufY;
        Direction dir;
        for (int j = ShipCount[i]-1; j >= 0; j--) {
            BufX = x = rand() % BOARD_SIZE;
            BufY = y = rand() % BOARD_SIZE;
            dir = Direction(rand() % 2);
            while (!(SetShip(x, y, dir, i+1) || SetShip(x, y, (Direction)(!dir), i+1))) {
                if ((y += OPTIMAZE) >= BOARD_SIZE) {
                    y -= BOARD_SIZE;
                    if ((x += OPTIMAZE) >= BOARD_SIZE) x -= BOARD_SIZE;
                } 
                if (y == BufY && x == BufX) {
                    if (count > 0) {
                        return RankingShip(count - 1);
                    } else return 0;
                }
            }
        }
    }
    if (!ValidBoard()) {
        if (count > 0) {
            return RankingShip(count - 1); 
        } else return 0;
    } else return 1; 
}

GameBoard::GameBoard() {
    Generate();
}
GameBoard::~GameBoard() {
    Remove();
}

GameBoardCell* GameBoard::GetCell(const int x, const int y) const {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return NULL;
    } else { 
        return _board[x][y];
    }
}
Ship* GameBoard::GetShip(const int x, const int y) const {
    GameBoardCell *cell = GetCell(x, y);
    if (cell != NULL) {
        return cell->GetShip();
    } else return NULL;
}
list<Ship *> GameBoard::GetListShip(const int size) const {
    if (size >= 0 && size <= MAX_SIZE_SHIP) {
        return MasShip[size];
    } else {
        list<Ship *> ship;
        return ship; 
    }
}

void GameBoard::PrintBoard() const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << GetCell(i, j)->GetStat();
        }
        cout << endl;
    }
    cout << endl;
}

bool GameBoard::AddShipAtList(Ship* const buf) {
    if (buf != NULL) {
        MasShip[buf->GetSize()-1].push_back(buf);
        return 1;
    } else return 0;
}
bool GameBoard::RemoveShipOfList(Ship* const sh) {
    int size = sh->GetSize()-1;
    auto it = search_n (MasShip[size].begin(), MasShip[size].end(), 1, sh,
            [](Ship *i, Ship *j) -> bool {
                return (i == j);
            }
        );
    if (it != MasShip[size].end()) {
        MasShip[size].erase(it);
        return 1;
    } else return 0;
}
void GameBoard::ClearListShip() {
    for (int j = 0; j < MAX_SIZE_SHIP; j++) {
        MasShip[j].clear();
    }
}

bool GameBoard::SetShip(const int x, const int y, const Direction dir, const int size) {
    list <GameBoardCell *> mas;
    if (size > MAX_SIZE_SHIP) return 0;
    if (dir == HORIZONTAL) {
        if (y + size >= BOARD_SIZE) return 0;
        for (int i = 0; i < size; i++) {
            if (GetCell(x, y+i) != NULL && GetShip(x, y+i) == NULL) {
                mas.push_back(GetCell(x, y+i));
            } else return 0;
        }
    } else {
        if (x + size >= BOARD_SIZE) return 0;
        for (int i = 0; i < size; i++) {
            if (GetCell(x+i, y) != NULL && GetShip(x+i, y) == NULL) {
                mas.push_back(GetCell(x+i, y));
            } else return 0;
        }         
    }
    Ship *buf = new Ship(size, mas, dir);
    if (!CheckShip(buf)) {
        delete(buf);
        return 0;
    }
    return AddShipAtList(buf);
}
bool GameBoard::DelShip (const int x, const int y) {
    if (GetShip(x, y) == NULL) {
        return 0;
    } else {
        Ship *sh = GetShip(x, y);   
        if (RemoveShipOfList(sh)) {
            delete(sh);
            return 1;
        } else return 0;
    }
}

bool GameBoard::CheckShip(Ship* const sh) const{
    const int x = sh->GetX();
    const int y = sh->GetY();
    const int size = sh->GetSize();
    if (sh->GetDir() == HORIZONTAL) {
        for (int i = y-1; i < y + size + 1; i++) {
            if (GetShip(x-1, i) || GetShip(x+1, i)) return 0;
        }
        if (GetShip(x, y-1) || GetShip(x, y + size)) return 0;
    } else {
        for (int i = x-1; i < x + size + 1; i++) {
            if (GetShip(i, y-1) || GetShip(i, y+1)) return 0;
        }
        if(GetShip(x-1, y) || GetShip(x + size, y)) return 0;
    }
    return 1;
}

void GameBoard::ClearBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            GetCell(i, j)->ClearCell();
        }
    }
    ClearListShip();
}

bool GameBoard::ValidBoard() const {
    list<Ship *> BufShip;
    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
        BufShip = GetListShip(i);
        if (BufShip.size() != ShipCount[i]) return 0; 
        for (auto& it: BufShip) {
            if (!CheckShip(it)) return 0;
        }
    }
    return 1;
}

bool GameBoard::GenerateShip() {
    srand(clock()+time(0));
    return RankingShip(AMOUNT_GENERATION);
}