#include <QCoreApplication>

#include "controller.h"

/*#include <X11/Xlib.h>
#include <xcb/xcb.h>*/

int main(int argc, char **argv){

    //XInitThreads();

    QCoreApplication app(argc, argv);
    std::cout << "Working directory :" << app.applicationFilePath().toStdString() << std::endl;

    Controller controller;
    controller.createNewGame();

    return app.exec();
}
