#ifndef GAME_H
#define GAME_H

#include <QThread>
#include <QDebug>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Interface;

#include "interface.h"
#include "matrix.h"
#include "button_widget.h"

enum Game_States{In_Process, Paused, Placement};

struct Zoom_Level{
    int n_case_x;
    int n_case_y;
    int case_size;
};

/* type_case = 1 : Case remplie
 * type_case = 2 : Case pleine */
struct Case{
    sf::RectangleShape case_render;
    int type_case;
};

class Game  : public QThread
{
public:
    Game(Interface *interface, int n_case_x, int n_case_y);

    void Draw(sf::RenderWindow &window);
    void Event(sf::Event event, sf::RenderWindow *interface);

    void run();

    void UpdateCameraCases();
    void newCaseGeneration();

    void ResetGame();

    int countNeighbourMarquedCase(int case_x, int case_y);

private:
    int zoom_level_index;
    sf::Vector2i camera_pos;

    int n_case_x;
    int n_case_y;

    int case_size;
    const int DEFAULT_ZOOM = 0;

    //const GAME_SPEED =

    Matrix<Case> *tile_map;

    Interface *interface;

    int game_loop;
    Button_Widget *bw_game_loop;

    int game_speed = 0;

    Game_States states;

    QList<Zoom_Level> list_zoom_level;

    bool game_thread_run = false;

};

#endif // GAME_H
