#include "game.h"

Game::Game(Interface *interface, int n_case_x, int n_case_y)
{

    this->interface = interface;

    this->n_case_x = n_case_x;
    this->n_case_y = n_case_y;

    tile_map = new Matrix<Case>(n_case_x, n_case_y);

    states = Placement;

    camera_pos.x = n_case_x/2;
    camera_pos.y = n_case_y/2;

    game_loop = 0;

    zoom_level_index = DEFAULT_ZOOM;

    //On set-up les informations pour chacun des zooms
    Zoom_Level zoom_level_1;
    zoom_level_1.n_case_x = 20;
    zoom_level_1.n_case_y = 20;
    zoom_level_1.case_size = 32;

    Zoom_Level zoom_level_2;
    zoom_level_2.n_case_x = 40;
    zoom_level_2.n_case_y = 40;
    zoom_level_2.case_size = 16;

    Zoom_Level zoom_level_3;
    zoom_level_3.n_case_x = 80;
    zoom_level_3.n_case_y = 80;
    zoom_level_3.case_size = 8;

    list_zoom_level.append(zoom_level_1);
    list_zoom_level.append(zoom_level_2);
    list_zoom_level.append(zoom_level_3);


    //On set-up la tile_map
    for(int r = 0; r < n_case_y; r++){

        for(int c = 0; c < n_case_x; c++){

            Case _case;
            _case.type_case = 0;

            sf::RectangleShape case_render;
            case_render.setFillColor(sf::Color::White);
            case_render.setOutlineColor(sf::Color::Black);
            case_render.setOutlineThickness(1);
            case_render.setSize(sf::Vector2f(list_zoom_level[DEFAULT_ZOOM].case_size, list_zoom_level[DEFAULT_ZOOM].case_size)); //On commence avec le zoom 1

            _case.case_render = case_render;

            (*tile_map)(c, r) = _case;
        }
    }

    //On set la position des cases en fonction de la position de la camera
    int starting_column = camera_pos.x-list_zoom_level[zoom_level_index].n_case_x/2;
    int starting_row = camera_pos.y-list_zoom_level[zoom_level_index].n_case_y/2;
    int finishing_colum = camera_pos.x+list_zoom_level[zoom_level_index].n_case_x/2;
    int finishing_row = camera_pos.y+list_zoom_level[zoom_level_index].n_case_y/2;

    for(int r_t = starting_row, r = 0; r_t < finishing_row; r_t++, r++){

        for(int c_t = starting_column, c = 0; c_t < finishing_colum; c_t++, c++){

            (*tile_map)(c_t, r_t).case_render.setPosition(c*list_zoom_level[zoom_level_index].case_size, r*list_zoom_level[zoom_level_index].case_size);
        }
    }

    bw_game_loop = new Button_Widget;
    //bw_game_loop->LoadFont("Bebas.otf");
    bw_game_loop->setString("0");
    bw_game_loop->setTextColor(sf::Color::Black);
    bw_game_loop->setPosition(sf::Vector2f(15, 15));
    bw_game_loop->setCharacterSize(35);

}

void Game::Draw(sf::RenderWindow &window){

    interface->setWindowActive(true);

    int starting_column = camera_pos.x-list_zoom_level[zoom_level_index].n_case_x/2;
    int starting_row = camera_pos.y-list_zoom_level[zoom_level_index].n_case_y/2;
    int finishing_colum = camera_pos.x+list_zoom_level[zoom_level_index].n_case_x/2;
    int finishing_row = camera_pos.y+list_zoom_level[zoom_level_index].n_case_y/2;

    for(int r = starting_row; r < finishing_row; r++){

        for(int c = starting_column; c < finishing_colum; c++){

            window.draw((*tile_map)(c, r).case_render);
        }
    }

    window.draw(*bw_game_loop);

    window.display();

    interface->setWindowActive(false);

}

void Game::Event(sf::Event event, sf::RenderWindow *window){

    if(states == Paused){

        switch(event.type){

        }
    }
    else if(states == In_Process){

        switch(event.type){

        }
    }
    else if(states == Placement){

        switch(event.type){
        case sf::Event::MouseButtonPressed:
        {

            //On cherche la case clické
            int starting_column = camera_pos.x-list_zoom_level[zoom_level_index].n_case_x/2;
            int starting_row = camera_pos.y-list_zoom_level[zoom_level_index].n_case_y/2;
            int finishing_colum = camera_pos.x+list_zoom_level[zoom_level_index].n_case_x/2;
            int finishing_row = camera_pos.y+list_zoom_level[zoom_level_index].n_case_y/2;

            for(int c = starting_column; c < finishing_colum; c++){

                for(int r = starting_row; r < finishing_row; r++){


                    if((*tile_map)(c, r).case_render.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){

                        //Si on elle n'est pas encore marqué on la marque
                        if((*tile_map)(c, r).type_case == 0){

                            (*tile_map)(c, r).case_render.setFillColor(sf::Color::Black);
                            (*tile_map)(c, r).type_case = 1;
                        }
                        //Sinon on enlève la marque
                        else if((*tile_map)(c, r).type_case == 1){

                            (*tile_map)(c, r).case_render.setFillColor(sf::Color::White);
                            (*tile_map)(c, r).type_case = 0;
                        }
                    }
                }
            }

            UpdateCameraCases();
            interface->Draw();

            break;
        }
        }
    }

    //EVENT POUR TOUTES LES PHASES
    switch(event.type){
    case sf::Event::KeyPressed:
    {

        // EVENT ARROW
        if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down){

            if(event.key.code == sf::Keyboard::Left){

                //On verifie qu'on ne dépasse pas de l'écran
                if(camera_pos.x-list_zoom_level[zoom_level_index].n_case_x/2-1 >= 0){
                    camera_pos.x -= 1;
                }
            }
            else if(event.key.code == sf::Keyboard::Right){

                //On verifie qu'on ne dépasse pas de l'écran
                if(camera_pos.x+list_zoom_level[zoom_level_index].n_case_x/2+1 <= n_case_x){
                    camera_pos.x += 1;
                }
            }
            else if(event.key.code == sf::Keyboard::Up){

                //On verifie qu'on ne dépasse pas de l'écran
                if(camera_pos.y-list_zoom_level[zoom_level_index].n_case_y/2-1 >= 0){
                    camera_pos.y -= 1;
                }
            }
            else if(event.key.code == sf::Keyboard::Down){

                //On verifie qu'on ne dépasse pas de l'écran
                if(camera_pos.y+list_zoom_level[zoom_level_index].n_case_y/2+1 <= n_case_y){
                    camera_pos.y += 1;
                }
            }

            //On set la position des cases en fonction de la nouvelle position de la camera
            UpdateCameraCases();
            interface->Draw();
        }

        // EVENT SPACE
        if(event.key.code == sf::Keyboard::Space){

            if(states == Placement){
                states = In_Process;

                qDebug() << "Game started";

                //On lance la boucle de jeu
                this->start(QThread::NormalPriority);
            }
            else if(states == In_Process){
                states = Paused;
            }
            else if(states == Paused){
                states = In_Process;
            }
        }

        if(event.key.code == sf::Keyboard::O){

            if(game_speed-1 > 0){
                game_speed -= 1;
            }

            qDebug() << "Game speed setted to" << game_speed;
        }
        else if(event.key.code == sf::Keyboard::P){

            if(game_speed+1 < 3){
                game_speed += 1;
            }

            qDebug() << "Game speed setted to" << game_speed;
        }

        if(event.key.code == sf::Keyboard::Enter){
            ResetGame();
        }

        break;
    }
    case sf::Event::MouseWheelScrolled:
    {
        if(event.mouseWheelScroll.delta == -1){

            if(list_zoom_level.size() == zoom_level_index+1){
                zoom_level_index=0;
            }
            else{
                zoom_level_index+=1;
            }
        }
        else{

            if(zoom_level_index-1 < 0){
                zoom_level_index = list_zoom_level.size()-1;
            }
            else{
                zoom_level_index-=1;
            }
        }

        //On replace les cases et on les redimensionnent avec le nouveau zoom
        UpdateCameraCases();
        interface->Draw();

        break;
    }
    }
}

void Game::run(){

    game_thread_run = true;

    while(game_thread_run){

        if(states == Paused){
            this->msleep(250);

            continue;
        }
        else if(states == Placement){
            interface->Draw();
            this->usleep(250);

            continue;
        }

        qDebug() << "game loop : " << game_loop;

        newCaseGeneration();

        game_loop++;
        bw_game_loop->setString(QString::number(game_loop).toStdString());

        interface->Draw();

        if(game_speed == 0){
            this->msleep(1000);
        }
        else if(game_speed == 1){
            this->msleep(500);
        }
        else if(game_speed == 2){
            this->msleep(250);
        }

    }
}

void Game::UpdateCameraCases(){

    int starting_column = camera_pos.x-list_zoom_level[zoom_level_index].n_case_x/2;
    int starting_row = camera_pos.y-list_zoom_level[zoom_level_index].n_case_y/2;
    int finishing_colum = camera_pos.x+list_zoom_level[zoom_level_index].n_case_x/2;
    int finishing_row = camera_pos.y+list_zoom_level[zoom_level_index].n_case_y/2;

    for(int r_t = starting_row, r = 0; r_t < finishing_row; r_t++, r++){

        for(int c_t = starting_column, c = 0; c_t < finishing_colum; c_t++, c++){

            (*tile_map)(c_t, r_t).case_render.setSize(sf::Vector2f(list_zoom_level[zoom_level_index].case_size, list_zoom_level[zoom_level_index].case_size));
            (*tile_map)(c_t, r_t).case_render.setPosition(c*list_zoom_level[zoom_level_index].case_size, r*list_zoom_level[zoom_level_index].case_size);
        }
    }
}

int Game::countNeighbourMarquedCase(int case_x, int case_y){

    //qDebug() << "---" << case_x << case_y << n_case_x << n_case_y;

    int n_marqued_case = 0;

    if(case_x < n_case_x-1){
        if((*tile_map)(case_x+1, case_y).type_case == 1){
            n_marqued_case++;
        }
    }
    if(case_x > 0){
        if((*tile_map)(case_x-1, case_y).type_case == 1){
            n_marqued_case++;
        }
    }
    if(case_x < n_case_x-1 && case_y < n_case_y-1){
        if((*tile_map)(case_x+1, case_y+1).type_case == 1){
            n_marqued_case++;
        }
    }
    if(case_x > 0 && case_y > 0){
        if((*tile_map)(case_x-1, case_y-1).type_case == 1){
            n_marqued_case++;
        }
    }
    if(case_x < n_case_x-1 && case_y > 0){
        if((*tile_map)(case_x+1, case_y-1).type_case == 1){
         n_marqued_case++;
        }
    }
    if(case_x > 0 && case_y < n_case_y-1){
        if((*tile_map)(case_x-1, case_y+1).type_case == 1){
            n_marqued_case++;
        }
    }
    if(case_y < n_case_y-1){
        if((*tile_map)(case_x, case_y+1).type_case == 1){
            n_marqued_case++;
        }
    }
    if(case_y > 0){
        if((*tile_map)(case_x, case_y-1).type_case == 1){
            n_marqued_case++;
     }
    }

    //qDebug() << "4";

    return n_marqued_case;
}

void Game::newCaseGeneration(){

    QList<sf::Vector2i> list_case_to_spawn;
    QList<sf::Vector2i> list_case_to_kill;

    for(int c = 0; c < n_case_x; c++){

        for(int r = 0; r < n_case_y; r++){

            int n_neighbour_marqued_case = countNeighbourMarquedCase(c, r);
            if(n_neighbour_marqued_case < 2 || n_neighbour_marqued_case > 3){
                list_case_to_kill.append(sf::Vector2i(c, r));
            }
            else if(n_neighbour_marqued_case == 3){
                list_case_to_spawn.append(sf::Vector2i(c, r));
            }
        }
    }

    for(int i = 0; i < list_case_to_kill.size(); i++){

        (*tile_map)(list_case_to_kill.at(i).x, list_case_to_kill.at(i).y).type_case = 0;
        (*tile_map)(list_case_to_kill.at(i).x, list_case_to_kill.at(i).y).case_render.setFillColor(sf::Color::White);
    }

    for(int i = 0; i < list_case_to_spawn.size(); i++){

        (*tile_map)(list_case_to_spawn.at(i).x, list_case_to_spawn.at(i).y).type_case = 1;
        (*tile_map)(list_case_to_spawn.at(i).x, list_case_to_spawn.at(i).y).case_render.setFillColor(sf::Color::Black);
    }

}

void Game::ResetGame(){

    qDebug() << "Game resetted";

    game_thread_run = false;

    //On re-set-up la tile_map
    for(int r = 0; r < n_case_y; r++){

        for(int c = 0; c < n_case_x; c++){

            Case _case;
            _case.type_case = 0;

            sf::RectangleShape case_render;
            case_render.setFillColor(sf::Color::White);
            case_render.setOutlineColor(sf::Color::Black);
            case_render.setOutlineThickness(1);
            case_render.setSize(sf::Vector2f(list_zoom_level[DEFAULT_ZOOM].case_size, list_zoom_level[DEFAULT_ZOOM].case_size));

            _case.case_render = case_render;

            (*tile_map)(c, r) = _case;
        }
    }

    game_loop = 0;
    zoom_level_index = DEFAULT_ZOOM;

    states = Placement;

    bw_game_loop->setString(QString::number(game_loop).toStdString());

    UpdateCameraCases();
    interface->Draw();

}


