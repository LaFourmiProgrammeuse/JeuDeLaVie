#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <QDebug>
#include <QThread>

#include <QList>

#include <SFML/System/Clock.hpp>

template <class T>
class Event_Handler : public QThread
{
public:
    Event_Handler(float loop_frequency){

        qDebug() << "Constructeur Event Handler";

        this->loop_frequency = loop_frequency;
    }

    void newEvent(void (*event_function)(), int time_before_event, bool repeat, T function_event_class){

        Event event;
        event.repeat = repeat;
        event.time_before_event = time_before_event;
        event.event_function = event_function;
    }

private:
    struct Event{
        void (*event_function)() = nullptr;
        int time_before_event = 0;

        int basic_time_for_repeat = 0;
        bool repeat = false;

        T function_event_class;

    };

    QVector<Event> list_event;

    void run(){

        while(1){

            sf::Clock clock;

            for(int i = 0; i < list_event.size(); i++){

                list_event[i].time_before_event-loop_frequency;

                if(list_event[i].time_before_event < 0){

                    if(list_event[i].repeat == true){

                        list_event[i].time_before_event = list_event[i].basic_time_for_repeat;
                        (*list_event[i].event_function)();
                    }
                }
            }

            if((loop_frequency - clock.getElapsedTime().asMilliseconds()) > 0){
                this->usleep((loop_frequency - clock.getElapsedTime().asMilliseconds()));
            }
        }
    }

    float loop_frequency;

};

#endif // EVENT_HANDLER_H
