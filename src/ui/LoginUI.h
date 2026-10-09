#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Button.h"
#include "TextBox.h"


enum class LoginResult
{
    NONE,
    REGISTER,
    LOGIN_SUCCESS,
    REGISTER_SUCCESS,
    BACK
};


class LoginUI
{
private:

    sf::Font& font;


    // LOGIN

    TextBox loginUsername;
    TextBox loginPassword;

    Button loginButton;
    Button registerButton;


    // REGISTER

    TextBox registerUsername;
    TextBox registerPassword;
    TextBox registerConfirm;

    Button createAccountButton;
    Button backButton;


    sf::Text loginTitle;
    sf::Text registerTitle;


    void drawTitle(
        sf::RenderWindow& window,
        sf::Text& title,
        float y
    );


    void drawLabel(
        sf::RenderWindow& window,
        const std::string& text,
        float x,
        float y
    );

    void layoutLogin(const sf::RenderWindow& window);
    void layoutRegister(const sf::RenderWindow& window);


public:

    LoginUI(
        sf::Font& font
    );


    LoginResult handleClick(
        sf::Vector2f mousePosition
    );


    LoginResult handleRegisterClick(
        sf::Vector2f mousePosition
    );


    void handleTextInput(
        char32_t unicode
    );


    void handleBackspace();


    void drawLogin(
        sf::RenderWindow& window
    );


    void drawRegister(
        sf::RenderWindow& window
    );
};

#endif
