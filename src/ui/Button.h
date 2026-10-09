#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:

    sf::RectangleShape shape;

    sf::Text text;

    sf::Color normalColor;

    sf::Color hoverColor;


    void centerText();


public:

    Button(
        sf::Font& font,
        const std::string& title,
        unsigned int fontSize
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


    void updateHover(
        sf::Vector2f mousePosition
    );


    void draw(
        sf::RenderWindow& window
    );
};

#endif
