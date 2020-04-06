#include "interface.h"

Interface::Interface(Controller *controller)
{
    this->controller = controller;
}

void Interface::Draw(){

    mutex.lock();
    controller->getGame()->Draw(*window);
    mutex.unlock();

}

void Interface::showWindow(){ qDebug() << "d";

    if(window == nullptr){
        window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Le jeu de la vie");
        window->setVisible(true);
    }
}

sf::Event Interface::waitEvent(){

    sf::Event event;
    while(window->waitEvent(event)){
        return event;
    }
}

sf::RenderWindow *Interface::getWindow(){
    return window;
}

void Interface::setWindowActive(bool active){
    window->setActive(active);
}

void Interface::killWindow(){

}

