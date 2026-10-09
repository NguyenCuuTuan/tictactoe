#ifndef APP_H
#define APP_H
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "UI/LoginUI.h"
#include "UI/MenuUI.h"
#include "UI/GameUI.h"
#include "UI/GameUI.h"

enum class AppState{
    LOGIN,
    REGISTER,
    MENU,
    GAME,
    EXIT
};


class App{
    private:
        sf::RenderWindow window;
        sf::Font font;
        AppState state;
        LoginUI loginUI;
        MenuUI menuUI;
        GameUI gameUI;
        Game game;
        bool loadResources();
        void processEvents();
        void handleLoginEvent(
            const sf::Event& event
        );
        void handleRegisterEvent(
            const sf::Event& event
        );
        void handleMenuEvent(
            const sf::Event& event
        );
        void handleGameEvent(
            const sf::Event& event
        );
        void update();
        void render();
    public:
        App();
        void run();
};

#endif