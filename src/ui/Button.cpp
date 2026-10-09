#include "Button.h"


Button::Button(
    sf::Font& font,
    const std::string& title,
    unsigned int fontSize
)
    : text(font, title, fontSize)
{
    shape.setSize({
        360.f,
        60.f
    });


    normalColor =
        sf::Color(
            45,
            110,
            220
        );


    hoverColor =
        sf::Color(
            65,
            135,
            245
        );


    shape.setFillColor(
        normalColor
    );


    shape.setOutlineThickness(
        2.f
    );


    shape.setOutlineColor(
        sf::Color(
            100,
            170,
            255
        )
    );


    text.setFillColor(
        sf::Color::White
    );


    centerText();
}


// ==================================================
// SET POSITION
// ==================================================

void Button::setPosition(
    float x,
    float y
)
{
    shape.setPosition({
        x,
        y
    });

    centerText();
}


// ==================================================
// SET SIZE
// ==================================================

void Button::setSize(
    float width,
    float height
)
{
    shape.setSize({
        width,
        height
    });

    centerText();
}


// ==================================================
// CENTER TEXT
// ==================================================

void Button::centerText()
{
    sf::FloatRect bounds =
        text.getLocalBounds();


    float x =
        shape.getPosition().x +
        (
            shape.getSize().x -
            bounds.size.x
        ) / 2.f -
        bounds.position.x;


    float y =
        shape.getPosition().y +
        (
            shape.getSize().y -
            bounds.size.y
        ) / 2.f -
        bounds.position.y;


    text.setPosition({
        x,
        y
    });
}


// ==================================================
// CONTAINS
// ==================================================

bool Button::contains(
    sf::Vector2f mousePosition
)
{
    return shape
        .getGlobalBounds()
        .contains(mousePosition);
}


// ==================================================
// HOVER
// ==================================================

void Button::updateHover(
    sf::Vector2f mousePosition
)
{
    if (contains(mousePosition))
    {
        shape.setFillColor(
            hoverColor
        );
    }
    else
    {
        shape.setFillColor(
            normalColor
        );
    }
}


// ==================================================
// DRAW
// ==================================================

void Button::draw(
    sf::RenderWindow& window
)
{
    window.draw(shape);

    window.draw(text);
}
