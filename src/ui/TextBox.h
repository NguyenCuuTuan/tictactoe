#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <string>

class TextBox
{
private:

    sf::RectangleShape box;

    sf::Text text;

    std::string value;

    bool active;

    bool password;


    void updateText();


public:

    TextBox(
        sf::Font& font,
        unsigned int fontSize,
        bool password = false
    );


    void setPosition(
        float x,
        float y
    );

    void setSize(
        float width,
        float height
    );


    bool contains(
        sf::Vector2f mousePosition
    );


    void setActive(
        bool active
    );


    bool isActive() const;


    void addCharacter(
        char32_t character
    );


    void removeCharacter();


    void clear();


    std::string getValue() const;


    void draw(
        sf::RenderWindow& window
    );
};

#endif
