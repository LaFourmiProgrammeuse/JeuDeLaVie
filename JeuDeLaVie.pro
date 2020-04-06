CONFIG += console

HEADERS += \
    interface.h \
    controller.h \
    game.h

SOURCES += \
    interface.cpp \
    controller.cpp \
    game.cpp \
    main.cpp

INCLUDEPATH += $$_PRO_FILE_PWD_/SFML-2.5.1/include
DEPENDPATH += $$_PRO_FILE_PWD_/SFML-2.5.1/include

unix:!macx: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-window
unix:!macx: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-graphics
unix:!macx: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-network
unix:!macx: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-system
unix:!macx: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-audio

win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-window
win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-graphics
win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-network
win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-system
win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-audio

QMAKE_CXXFLAGS += -lX11
#CONFIG += c++11 strict_c++

win32: LIBS += -L$$_PRO_FILE_PWD_/Lib_GameDev/window/lib/ -lLib_GameDev
else:unix: LIBS += -L$$_PRO_FILE_PWD_/Lib_GameDev/linux/lib/ -lLib_GameDev

INCLUDEPATH += $$_PRO_FILE_PWD_/Lib_GameDev/include
DEPENDPATH += $$_PRO_FILE_PWD_/Lib_GameDev/include


