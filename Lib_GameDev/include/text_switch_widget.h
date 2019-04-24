#ifndef text_Switch_Widget_H
#define text_Switch_Widget_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <QDebug>

#include <lib_gamedev_global.h>

class LIB_GAMEDEVSHARED_EXPORT Text_Switch_Widget : public sf::Drawable, public sf::Transformable
{
public:
    Text_Switch_Widget();

    //getters
    int getPositionList();

    //setters
    void setPositionList(int i);
    void setCharacterSize(float size);
    void setPosition(float x, float y);

    void operator <<(sf::Text *);

    void Next();
    void Previous();

    void Clear();

    void AddString(sf::Text *);
    void RemoveString(int position);
    void RemoveString(QString string);

    bool LoadFont(std::string file);

    bool CollisionRightArrow(float x, float y);
    bool CollisionLeftArrow(float x, float y);

    sf::Vector2f getSize();

    void Update();

private:
    QList<sf::Text *> m_listText;
    int m_position;

    sf::Font *default_font;
    sf::Font *font;

    sf::Texture m_texture_right_arrow;
    sf::Sprite m_sprite_right_arrow;

    sf::Texture m_texture_left_arrow;
    sf::Sprite m_sprite_left_arrow;

    float m_character_size;

    float pos_x;
    float pos_y;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // Text_Switch_Widget_H
