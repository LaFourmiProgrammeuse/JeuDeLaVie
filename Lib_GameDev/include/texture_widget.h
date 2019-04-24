#ifndef TEXTURE_WIDGET_H
#define TEXTURE_WIDGET_H

#include <string>

#include <QDebug>

#include "SFML/Graphics.hpp"

#include "lib_gamedev_global.h"

class LIB_GAMEDEVSHARED_EXPORT Texture_Widget : public sf::Drawable, public sf::Transformable
{
public:
    Texture_Widget();
    Texture_Widget(std::string file);

    void virtual draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool getCollision(sf::Vector2i pos);

    bool LoadTexture(std::string file);

    void setHitBoxSize(float width, float height);
    void setPosition(sf::Vector2f pos);

    bool Contains(sf::Vector2i pos);

    void setHitBoxBorderThickness(float border_tickness);
    void setHitBoxOutlineColor(sf::Color color);

    void setHitBoxColor(sf::Color color);

private:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::RectangleShape hit_box;

};

#endif // TEXTURE_WIDGET_H
