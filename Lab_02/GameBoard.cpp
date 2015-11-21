//#include "GameBoard.h"
//
//const int GameBoard::_ShipCount[MAX_SIZE_SHIP] = {4,3,2,1};
//

//ship->addCells(list<GameBoardCell *> (1, _board[5][2]));

//void GameBoard::Generate() {
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            _board[i][j] = new GameBoardCell(i, j);
//        }
//    }
//}
//void GameBoard::Remove() {
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            GetCell(i,j)->ClearCell();
//        }
//    }
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            GetCell(i,j)->ClearCell();
//            delete(_board[i][j]);
//        }
//    }
//}
//bool GameBoard::RankingShip(int const count) {
//    ClearBoard();
//    for (int i = MAX_SIZE_SHIP - 1; i >= 0; i--) {
//        int x, y, BufX, BufY;
//        Direction dir;
//        for (int j = _ShipCount[i]-1; j >= 0; j--) {
//            BufX = x = rand() % BOARD_SIZE;
//            BufY = y = rand() % BOARD_SIZE;
//            dir = Direction(rand() % 2);
//            while (!(SetShip(x, y, dir, i+1) || SetShip(x, y, (Direction)(!dir), i+1))) {
//                if ((y += OPTIMAZE) >= BOARD_SIZE) {
//                    y -= BOARD_SIZE;
//                    if ((x += OPTIMAZE) >= BOARD_SIZE) x -= BOARD_SIZE;
//                } 
//                if (y == BufY && x == BufX) {
//                    if (count > 0) {
//                        return RankingShip(count - 1);
//                    } else return 0;
//                }
//            }
//        }
//    }
//    if (!ValidBoard()) {
//        if (count > 0) {
//            return RankingShip(count - 1); 
//        } else return 0;
//    } else return 1; 
//}
//
//GameBoard::GameBoard() {
//    Generate();
//}
//GameBoard::~GameBoard() {    
//    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
//        _MasShip[i].clear();
//    }
//    Remove();
//}
//GameBoard::GameBoard(const GameBoard &obj) {
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            this->_board[i][j] = new GameBoardCell(*obj.GetCell(i, j));
//        }
//    }
//    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
//        for (auto& it: obj.GetListShip(i)) {
//            SetShip(it->GetX(), it->GetY(), it->GetDir(), it->GetSize());
//        }
//    }
//}
//
//GameBoardCell* GameBoard::GetCell(const int x, const int y) const {
//    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
//        return NULL;
//    } else { 
//        return _board[x][y];
//    }
//}
//shared_ptr<Ship> GameBoard::GetShip(const int x, const int y) const {
//    GameBoardCell *cell = GetCell(x, y);
//    if (cell != NULL) {
//        return cell->GetShip();
//    } else return NULL;
//}
//list<shared_ptr<Ship>> GameBoard::GetListShip(const int size) const {
//    if (size >= 0 && size <= MAX_SIZE_SHIP) {
//        return _MasShip[size];
//    } else {
//        list<shared_ptr<Ship>> ship;
//        return ship; 
//    }
//}
//
//void GameBoard::PrintBoard() const {
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            cout << GetCell(i, j)->GetStat();
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//bool GameBoard::AddShipAtList(const shared_ptr<Ship> &buf) {
//    if (buf != NULL) {
//        _MasShip[buf->GetSize()-1].push_back(buf);
//        return 1;
//    } else return 0;
//}
//
//bool GameBoard::RemoveShipOfList(shared_ptr<Ship> const sh) {
//    int size = sh->GetSize()-1;
//    auto it = search_n (_MasShip[size].begin(), _MasShip[size].end(), 1, sh,
//            [](shared_ptr<Ship> i, shared_ptr<Ship> j) -> bool {
//                return (i == j);
//            }
//        );
//    if (it != _MasShip[size].end()) {
//        _MasShip[size].erase(it);
//        return 1;
//    } else return 0;
//}
//
//void GameBoard::ClearListShip() {
//    for (int j = 0; j < MAX_SIZE_SHIP; j++) {
//        /*for(auto& it: GetListShip(j)) {
//            
//        }*/
//        _MasShip[j].clear();
//    }
//}
//
//shared_ptr<Ship> NewShip1(list <GameBoardCell *> buf, Direction dir) {
//    return shared_ptr<Ship> (new Ship1(buf, dir));
//}
//shared_ptr<Ship> NewShip2(list <GameBoardCell *> buf, Direction dir) {
//    return shared_ptr<Ship> (new Ship2(buf, dir));
//}
//shared_ptr<Ship> NewShip3(list <GameBoardCell *> buf, Direction dir) {
//    return shared_ptr<Ship> (new Ship3(buf, dir));
//}
//shared_ptr<Ship> NewShip4(list <GameBoardCell *> buf, Direction dir) {
//    return shared_ptr<Ship> (new Ship4(buf, dir));
//}
//
//bool GameBoard::SetShip(const int x, const int y, const Direction dir, const int size) {
//    list <GameBoardCell *> mas;
//    if (size > MAX_SIZE_SHIP) return 0;
//    if (dir == HORIZONTAL) {
//        if (y + size >= BOARD_SIZE) return 0;
//        for (int i = 0; i < size; i++) {
//            if (GetCell(x, y+i) != NULL && GetShip(x, y+i) == NULL) {
//                mas.push_back(GetCell(x, y+i));
//            } else return 0;
//        }
//    } else {
//        if (x + size >= BOARD_SIZE) return 0;
//        for (int i = 0; i < size; i++) {
//            if (GetCell(x+i, y) != NULL && GetShip(x+i, y) == NULL) {
//                mas.push_back(GetCell(x+i, y));
//            } else return 0;
//        }         
//    }
//    shared_ptr<Ship> (*NewShip[MAX_SIZE_SHIP])(list <GameBoardCell *> buf, Direction dir) = {NewShip1, NewShip2, NewShip3, NewShip4};
//    shared_ptr<Ship> buf = NewShip[size-1](mas, dir);
//
//    for (auto& it: mas) {
//        it->SetStat(DECK);
//        it->SetShip(buf);
//    }
//    
//    if (CheckShip(buf)) {
//        return AddShipAtList(buf);    
//    } else return 0;
//}
//bool GameBoard::DelShip (const int x, const int y) {
//    if (GetShip(x, y) == NULL) {
//        return 0;
//    } else {
//        return RemoveShipOfList(GetShip(x, y));
//    }
//}
//
//bool GameBoard::CheckShip(shared_ptr<Ship> const sh) const{
//    const int x = sh->GetX();
//    const int y = sh->GetY();
//    const int size = sh->GetSize();
//    if (sh->GetDir() == HORIZONTAL) {
//        for (int i = y-1; i < y + size + 1; i++) {
//            if (GetShip(x-1, i) || GetShip(x+1, i)) return 0;
//        }
//        if (GetShip(x, y-1) || GetShip(x, y + size)) return 0;
//    } else {
//        for (int i = x-1; i < x + size + 1; i++) {
//            if (GetShip(i, y-1) || GetShip(i, y+1)) return 0;
//        }
//        if(GetShip(x-1, y) || GetShip(x + size, y)) return 0;
//    }
//    return 1;
//}
//
//void GameBoard::ClearBoard() {
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            GetCell(i, j)->ClearCell();
//        }
//    }
//    ClearListShip();
//}
//
//bool GameBoard::ValidBoard() const {
//    list<shared_ptr<Ship>> BufShip;
//    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
//        BufShip = GetListShip(i);
//        if (BufShip.size() != _ShipCount[i]) return 0; 
//        for (auto& it: BufShip) {
//            if (!CheckShip(it)) return 0;
//        }
//    }
//    return 1;
//}
//
//bool GameBoard::GenerateShip() {
//    srand(clock()+time(0));
//    return RankingShip(AMOUNT_GENERATION);
//}