#include "controller.h"

Controller::Controller()
{
    qDebug() << "Constructeur Controller";

    interface = new Interface(this);

}

void Controller::createNewGame(){

    int n_case_x;
    int n_case_y;

    std::cout << "Choisissez la taille de la grille :" << std::endl;
    std::cout << "1) 100*100" << std::endl;
    std::cout << "2) 200*200" << std::endl;
    std::cout << "3) 300*300" << std::endl;

    std::string answer;

    std::cin >> answer;
    if(answer == "1"){
        n_case_x = 100;
        n_case_y = 100;
    }
    else if(answer == "2"){
        n_case_x = 200;
        n_case_y = 200;
    }
    else if(answer == "3"){
        n_case_x = 300;
        n_case_y = 300;
    }

    //Si il y avait un ancien jeu lancé on le détruit


    game = new Game(interface, n_case_x, n_case_y);
    interface->showWindow();
    interface->Draw();

    startTreatEvent();
}

Game *Controller::getGame(){
    return game;
}

void Controller::startTreatEvent(){

    while(1){

        sf::Event event;
        event = interface->waitEvent();

        game->Event(event, interface->getWindow());
    }
}


