#ifndef MENU_UI_H
#define MENU_UI_H

#include <SFML/Graphics.hpp>

#include "Button.h"


enum class MenuResult
{
    NONE,
    PLAY_COMPUTER,
    EXIT
};


class MenuUI
{
private:

    sf::Font& font;

    sf::Text title;

    sf::Text welcome;

    Button playComputerButton;

    Button exitButton;


public:

    MenuUI(
        sf::Font& font
    );


    MenuResult handleClick(
        sf::Vector2f mousePosition
    );


    void draw(
        sf::RenderWindow& window
    );
};

#endif
