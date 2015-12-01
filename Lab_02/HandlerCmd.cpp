#include "HandlerCMd.h"
#include "Visitor.h"
#include <conio.h>

HandlerCmd::HandlerCmd(shared_ptr<Visitor> vis) {
    _vis = vis;
}

void HandlerCmd::printFrameForCmd() {
    _vis->PrintFrameForCmd();
}

string HandlerCmd::readCmd(void) {
    string str;
    cin >> str;
    if (str.find_first_not_of
        ("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ_ ") 
        != string::npos) {
            return ""; // неккоректный ввод
    } else  return str; // всё хорошо
}

void HandlerCmd::printMsg(string str) {
    _vis->PrintMsg(str);
}

int HandlerCmd::handlerCmdPrep(shared_ptr<PlayerUser> pl) { 
    printFrameForCmd();
    string str = readCmd();
    if (str == "new_ship") {
        int x = 0, y = 0, size = 0;
        Direction dir;
        cin >> x >> y >> str >> size;
        if (x > BOARD_SIZE || x <= 0 || y > BOARD_SIZE || y <=0 || size > MAX_SIZE_SHIP || size <= 0) {
            printMsg("Error input data");
        } else {
            if (str == "HOR" || str =="0" ) dir = HORIZONTAL; 
            else if (str == "VER" || str == "1") dir = VERTICAL;
            else printMsg("Error input data");
            if (!pl->setShip(x, y, dir, size)) printMsg("Error set ship");
        }
    } else if (str == "del_ship") {
        int x = 0, y = 0;
        cin >> x >> y;
        if (x > BOARD_SIZE || x <= 0 || y > BOARD_SIZE || y <= 0) {
            printMsg("Error input data");
        } else if (!pl->delShip(x, y)) printMsg("Error del ship");
    } else if (str == "autoset_ship") {
        if (!pl->autoSetShips()) printMsg("Error auto set ship");
    } else if (str == "ready") {
        return 1; //игрок готов к игре
    } else if (str == "nick_new") {
        cin >> str;
        if (!pl->changeNick(str)) printMsg("Error set nickname ship");
    } else if (str == "clear_board") {
        pl->clearBoards();
    } else if (str == "end") {
        return -1; //игрок покинул игру
    } else printMsg("Error command");
    return 0;
}

int HandlerCmd::handlerCmdGame(shared_ptr<PlayerUser> pl) { 
    printFrameForCmd();
    string str = readCmd();
    if (str == "shot") {
        int x = 0, y = 0;
        cin >> x >> y;
        int stat = pl->getStatShot(x, y);
        if (stat == INCOR_CORD) printMsg("Error input data");
        else if (stat == BUSY) printMsg("Error: cell is busy");
        else return stat;
    } else if (str == "leave") {
        return -1; // игрок покинул игру
    } else printMsg("Error command");
    return 0; 
}

int HandlerCmd::handlerCmdEnd(shared_ptr<PlayerUser> pl) { 
    _getch();
    return 0;
}

