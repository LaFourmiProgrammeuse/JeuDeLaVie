#ifndef TEXT_FIELD_WIDGET_H
#define TEXT_FIELD_WIDGET_H

#include <QDebug>

#include <SFML/Graphics.hpp>

#include <lib_gamedev_global.h>

class LIB_GAMEDEVSHARED_EXPORT Text_Field_Widget : public sf::Drawable, sf::Transformable
{
public:
    Text_Field_Widget();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool getHasFocus();
    void setHasFocus(bool has_focus);

    void setPosition(float x, float y);

    void setCharacterSize(int character_size);
    int getSizeText();

    void setSize(float width, float height);

    bool LoadFont(std::string file);

    void keyEntered(sf::Keyboard::Key key);

    void setOutlineColor(sf::Color color);
    void setOutlineThickness(float thickness);
    void setFilledColor(sf::Color color);

private:
    bool has_focus;

    sf::Text text;
    sf::RectangleShape hit_box;

    sf::Font *font;
    sf::Font *font_default;
};

#endif // TEXT_FIELD_WIDGET_H
