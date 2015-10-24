//Создать иерархию классов и запрограммировать компьютерную игру “Морской бой”. Игровое поле разбивается на клетки. Палуба корабля занимает одну клетку. Кораблем считается совокупность смежных клеток. Допускаются четыре категории кораблей: одно-, двух-, трех- и четырехпалубные. Двух-, трех- и четырехпалубные корабли могут иметь всевозможные конфигурации и ориентации на игровом поле. Не допускается размещение кораблей в смежных клетках.
#include<iostream>
 
using namespace std;
 
// множество состояний одной клетки
enum CellState { Empty, Deck, Miss, HitDeck };
// множество состояний корабля
enum ShipState { Destroyed, ShipHit, Safe };
 
// класс - клетка игрового поля
class GameBoardCell {
private:
    int _x, _y;         // координаты клетки
    CellState _state;   // состояние клетки
public:
    GameBoardCell(int x = 0, int y = 0, CellState state = Empty)
    {
        _x = x;
        _y = y;
        _state = state;
    }
 
    // функция устанавливает x-кординату клети
    void SetX(int x)
    { _x = x; }
 
    // функция устанавливает y-кординату клети
    void SetY(int y)
    { _y = y; }
 
    // функция устанавливает состояние клети
    void SetState(CellState state)
    { _state = state; }
 
    // функция возвращает состояние текуйщей клетки
    CellState GetState()
    { return _state; }
 
    // функция возвращает x текуйщей клетки
    int GetX()
    { return _x; }
 
    // функция возвращает y текуйщей клетки
    int GetY()
    { return _y; }
 
    // функция - проверка попадания в клетку
    bool TryHit(int x, int y)
    { return x == _x && y == _y && _state != HitDeck; }
 
    // функция печати одной клетки, в зависимости от ее состояния
    void Print()
    {
        if (_state == Empty)
            cout << ' ';
        else if (_state == HitDeck)
            cout << 'x';
        else if (_state == Deck)
            cout << 'd';
        else
            cout << '*';
    }
};
 
// заранее объявим, чтобы можно было указывать в качестве аргумент функций класса Ship
class GameBoard;
 
// класс - корабль
class Ship
{
private:
    GameBoardCell* _cells;  // клетки корабля
    ShipState _state;   // состояние корабля
    int _size;
public:
    Ship()
    {
        _cells = NULL;
        _size = 0;
    }
 
    void Create(GameBoard& gameBoard, int size, int x, int y, bool horizontal);
    ~Ship();
 
    // функция вощвращает состояние корабля, выполнив проверку целостности всех палуб
    ShipState GetState();
 
    // функция выстрела по корабрю, возвращает состояние корябля, после выстрела
    void Shoot(GameBoard& gameBoard, int x, int y);
 
    bool TryHit(int x, int y);
};
 
// класс - игровое поле
class GameBoard {
private:
    static const int _size = 10;            // размер игорового поля
    static const int _4DeckShipCount = 1;   // число 4-х палубных
    static const int _3DeckShipCount = 2;   // число 3-х палубных
    static const int _2DeckShipCount = 3;   // число 2-х палубных
    static const int _1DeckShipCount = 4;   // число 1-х палубных
    static const int _shipsCount = _4DeckShipCount + _3DeckShipCount + _2DeckShipCount + _1DeckShipCount;   // число кораблей
    GameBoardCell _cells[_size][_size]; // клетки игрового поля
    Ship _ships[_shipsCount];   // корабли
 
    // функция создание игрового поля
    void Generate();
public:
    GameBoard()
    { Generate(); }
 
    ~GameBoard() { }
 
    // функция установки статуса клетки игровго поля
    void SetState(int x, int y, CellState state)
    { _cells[y][x].SetState(state); }
 
    // функция возвращает является ли клетка палубой
    bool IsDeck(int x, int y)
    { return _cells[y][x].GetState() == Deck || _cells[y][x].GetState() == HitDeck; }
 
    // функция печати игрового поля
    void Print();
 
    // функция возвращает число кдеток игровой области
    int GetCount()
    { return _size * _size; }
 
    // функция возвращает размер игровой области
    int GetSize()
    { return _size; }
 
    // функция - выстрел в игрове поле
    void Shoot(int x, int y);
 
    // функция провекри - уничтожены ли все корабли на поле
    bool AllShipsDestroyed();
};
 
int main(int argc, char** argv)
{
    GameBoard gameBoard;
    gameBoard.Print();
    do {
        cout << "Enter x coord: " << endl;
        int x;
        cin >> x;
        cout << "Enter y coord: " << endl;
        int y;
        cin >> y;
        gameBoard.Shoot(x, y);
        gameBoard.Print();
    } while (!gameBoard.AllShipsDestroyed());
    return 0;
}
 
 
void Ship::Create(GameBoard& gameBoard, int size, int x, int y, bool horizontal)
{
    _size = size;
    _cells = new GameBoardCell[size];
    // заполняем клетки в зависимости от начала координат корябля и его направления
    for (int i = 0; i < size; i++)
    {
        if (horizontal) {
            _cells[i].SetX(x + i);
            _cells[i].SetY(y);
            gameBoard.SetState(x + i, y, Deck);
        } else {
            _cells[i].SetX(x);
            _cells[i].SetY(y + i);
            gameBoard.SetState(x, y + i, Deck);
        }
    }
}
 
Ship::~Ship()
{
    // очистим память, если она была выделена.
    if (_size)
        delete _cells;
}
 
ShipState Ship::GetState()
{
    // считаем число попаданий
    int hitCount = 0;
    for (int i = 0; i < _size; i++)
        if (_cells[i].GetState() == HitDeck)
            hitCount++;
 
    // сверяем число попаданий с числом палуб
    if (hitCount == 0)  // если не попали - корабль цел
        _state = Safe;
    else if (hitCount < _size)  // если попали но меньше раз, чем число палуб, то ранен
        _state = ShipHit;
    else
        _state = Destroyed; // иначе уничтожен
 
    return _state;
}
 
void Ship::Shoot(GameBoard& gameBoard, int x, int y)
{
    for (int i = 0; i < _size; i++)
        if (_cells[i].TryHit(x, y))
        {
            _cells[i].SetState(HitDeck);
            gameBoard.SetState(x, y, HitDeck);
            break;
        }
    if (GetState() == Destroyed)
    {
        for (int i = 0; i < _size; i++)
        {
            int localX = _cells[i].GetX();
            int localY = _cells[i].GetY();
            if (localX - 1 >= 0 && localY - 1 >= 0 && !gameBoard.IsDeck(localX - 1, localY - 1))
                gameBoard.SetState(localX - 1, localY - 1, Miss);
            if (localX - 1 >= 0 && !gameBoard.IsDeck(localX - 1, localY))
                gameBoard.SetState(localX - 1, localY, Miss);
            if (localX - 1 >= 0 && localY + 1 < gameBoard.GetSize() && !gameBoard.IsDeck(localX - 1, localY + 1))
                gameBoard.SetState(localX - 1, localY + 1, Miss);
 
            if (localY - 1 >= 0 && !gameBoard.IsDeck(localX, localY - 1))
                gameBoard.SetState(localX, localY - 1, Miss);
            if (localY + 1 < gameBoard.GetSize() && !gameBoard.IsDeck(localX, localY + 1))
                gameBoard.SetState(localX, localY + 1, Miss);
 
            if (localX + 1 < gameBoard.GetSize() && localY - 1 >= 0 && !gameBoard.IsDeck(localX + 1, localY - 1))
                gameBoard.SetState(localX + 1, localY - 1, Miss);
            if (localX + 1 < gameBoard.GetSize() && !gameBoard.IsDeck(localX + 1, localY))
                gameBoard.SetState(localX + 1, localY, Miss);
            if (localX + 1 < gameBoard.GetSize() && localY + 1 < gameBoard.GetSize() && !gameBoard.IsDeck(localX + 1, localY + 1))
                gameBoard.SetState(localX + 1, _cells[i].GetY() + 1, Miss);
        }
    }
}
 
bool Ship::TryHit(int x, int y)
{
    for (int i = 0; i < _size; i++)
        if (_cells[i].TryHit(x, y))
            return true;
    return false;
}
 
void GameBoard::Generate()
{
    // заполняем игровое поле пустыми клетками
    for (int i = 0; i < _size; i++)
        for (int j = 0; j < _size; j++)
            _cells[i][j].SetState(Empty);
    int idx = 0;
    // расставяем 4-х палубные
    _ships[idx++].Create(*this, 4, 0, 0, true);
    // расставяем 3-х палубные
    _ships[idx++].Create(*this, 3, 0, 2, false);
    _ships[idx++].Create(*this, 3, 8, 1, false);
    // расставяем 2-х палубные
    _ships[idx++].Create(*this, 2, 3, 9, true);
    _ships[idx++].Create(*this, 2, 2, 6, true);
    _ships[idx++].Create(*this, 2, 6, 5, true);
    // расставяем 1-х палубные
    _ships[idx++].Create(*this, 1, 4, 2, true);
    _ships[idx++].Create(*this, 1, 8, 8, true);
    _ships[idx++].Create(*this, 1, 0, 8, true);
    _ships[idx++].Create(*this, 1, 6, 0, true);
}
 
void GameBoard::Print()
{
    for (int i = 0; i < _size; i++)
    {
        cout << "|";
        for (int j = 0; j < _size; j++)
        {
            _cells[i][j].Print();
            cout << "|";
        }
        cout << endl;
    }
}
 
void GameBoard::Shoot(int x, int y)
{
    // просмотрим все корабли
    for (int i = 0; i < _shipsCount; i++)
        // проверим попадание
        if (_ships[i].TryHit(x, y))
        {
            // если попадаем - стреляем по кораблю
            _ships[i].Shoot(*this, x, y);
            break;
        }
        else
        {
            // иначе засчитываем промах
            _cells[y][x].SetState(Miss);
        }
}
 
bool GameBoard::AllShipsDestroyed()
{
    // обход всех кораблей
    for (int i = 0; i < _shipsCount; i++)
        // если хотя бы один не уничтожен, вернем false
        if (_ships[i].GetState() != Destroyed)
            return false;
    return true;    // иначе true
}

