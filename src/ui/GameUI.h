#ifndef GAME_UI_H
#define GAME_UI_H
#include <SFML/Graphics.hpp>
#include "../Game.h"
#include "Button.h"

class GameUI{
private:
    sf::Texture xTexture;
    sf::Texture oTexture;
    sf::Font& font;
    Button replayButton;
    Button backButton;
    bool texturesLoaded;
    float getBoardSize(
        const sf::RenderWindow& window
    ) const;
    float getBoardX(
        const sf::RenderWindow& window
    ) const;
    float getBoardY(
        const sf::RenderWindow& window
    ) const;
    void layoutButtons(const sf::RenderWindow& window);
    void drawBoard(
        sf::RenderWindow& window
    );
    void drawPieces(
        sf::RenderWindow& window,
        Game& game
    );
    void drawResult(
        sf::RenderWindow& window,
        Game& game
    );
public:
    GameUI(
        sf::Font& font
    );
    bool loadTextures();
    void update(
        sf::RenderWindow& window
    );
    void draw(
        sf::RenderWindow& window,
        Game& game
    );
    bool handleClick(
        sf::RenderWindow& window,
        Game& game,
        sf::Vector2f mousePos
    );
};

#endif

