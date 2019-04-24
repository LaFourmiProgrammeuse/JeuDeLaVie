#ifndef INTERFACE_H
#define INTERFACE_H

class Controller;

#include <SFML/Graphics.hpp>
#include <QMutex>

#include "controller.h"

class Interface
{
public:
    Interface(Controller *controller);

    void Draw();
    void showWindow();
    void killWindow();

    void setWindowActive(bool active);

    sf::Event waitEvent();

    sf::RenderWindow *getWindow();

    QMutex mutex;

private:
    sf::RenderWindow *window = nullptr;

    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 640;

    Controller *controller;

};

#endif // INTERFACE_H
