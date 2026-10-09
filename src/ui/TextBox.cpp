#include "TextBox.h"


TextBox::TextBox(
    sf::Font& font,
    unsigned int fontSize,
    bool passwordMode
)
    : text(font, "", fontSize)
{
    password = passwordMode;

    active = false;


    box.setSize({
        360.f,
        55.f
    });


    box.setFillColor(
        sf::Color(
            248,
            249,
            252
        )
    );


    box.setOutlineThickness(
        2.f
    );


    box.setOutlineColor(
        sf::Color(
            180,
            185,
            195
        )
    );


    text.setFillColor(
        sf::Color(
            30,
            30,
            30
        )
    );
}


// =====================================================
// POSITION
// =====================================================

void TextBox::setPosition(
    float x,
    float y
)
{
    box.setPosition({
        x,
        y
    });


    text.setPosition({
        x + 15.f,
        y + 12.f
    });
}


void TextBox::setSize(
    float width,
    float height
)
{
    box.setSize({width, height});
}


// =====================================================
// CONTAINS
// =====================================================

bool TextBox::contains(
    sf::Vector2f mousePosition
)
{
    return box
        .getGlobalBounds()
        .contains(mousePosition);
}


// =====================================================
// ACTIVE
// =====================================================

void TextBox::setActive(
    bool state
)
{
    active = state;


    if (active)
    {
        box.setOutlineColor(
            sf::Color(
                45,
                110,
                220
            )
        );
    }
    else
    {
        box.setOutlineColor(
            sf::Color(
                180,
                185,
                195
            )
        );
    }
}


// =====================================================
// IS ACTIVE
// =====================================================

bool TextBox::isActive() const
{
    return active;
}


// =====================================================
// ADD CHARACTER
// =====================================================

void TextBox::addCharacter(
    char32_t character
)
{
    if (character < 32 ||
        character > 126)
    {
        return;
    }


    if (value.length() >= 30)
    {
        return;
    }


    value +=
        static_cast<char>(character);


    updateText();
}


// =====================================================
// REMOVE CHARACTER
// =====================================================

void TextBox::removeCharacter()
{
    if (!value.empty())
    {
        value.pop_back();

        updateText();
    }
}


// =====================================================
// UPDATE TEXT
// =====================================================

void TextBox::updateText()
{
    if (password)
    {
        std::string hidden(
            value.length(),
            '*'
        );

        text.setString(hidden);
    }
    else
    {
        text.setString(value);
    }
}


// =====================================================
// CLEAR
// =====================================================

void TextBox::clear()
{
    value.clear();

    updateText();
}


// =====================================================
// GET VALUE
// =====================================================

std::string TextBox::getValue() const
{
    return value;
}


// =====================================================
// DRAW
// =====================================================

void TextBox::draw(
    sf::RenderWindow& window
)
{
    window.draw(box);

    window.draw(text);
}
