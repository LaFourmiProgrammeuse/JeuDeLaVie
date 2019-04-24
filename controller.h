#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QDebug>

#include <iostream>

class Interface;
class Game;

#include "game.h"
#include "interface.h"

enum States{In_Menu, In_Game};

class Controller
{
public:
    Controller();

    void createNewGame();
    Game *getGame();

    void startTreatEvent();

private:
    Interface *interface;
    Game *game;

    States states;

};

#endif // CONTROLLER_H
