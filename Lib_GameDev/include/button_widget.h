#ifndef BUTTON_WIDGET_H
#define BUTTON_WIDGET_H

#include <QDebug>
#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"

#include "lib_gamedev_global.h"

class LIB_GAMEDEVSHARED_EXPORT Button_Widget : public sf::Drawable, public sf::Transformable
{
public:
    Button_Widget();

    ~Button_Widget();

    void virtual draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool Contains(sf::Vector2i pos);

    /*Cette fonction prend on compte la taille de character
     *  du label, la definir donc avant */
    void setPosition(sf::Vector2f pos);

    sf::Vector2f getPosition();

    void setCharacterSize(int size);

    void Update();

    bool LoadFont(std::string file);
    void setFont(sf::Font &font);

    void setHighlight(int character_size, sf::Color color);
    void unHighlight();

    void setOutlineColor(sf::Color color);
    void setOutlineThickness(float thickness);
    void setFilledColor(sf::Color color);

    void setString(sf::String string);
    void setTextColor(sf::Color color);

    sf::String getString();

    sf::FloatRect getGlobalBounds();

private:
    sf::Text text;

    sf::Font *font_default;
    sf::Font *font;

    sf::RectangleShape hit_box;

    //Grossis et colorer ?
    bool highlight;

    //Valeur a remettre apres un highlight
    int character_size_highlight;
    sf::Color color_highlight;


    float pos_x;
    float pos_y;
};

#endif // BUTTON_WIDGET_H
