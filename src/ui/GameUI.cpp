#include "GameUI.h"

#include <algorithm>
#include <iostream>

using namespace std;


// =====================================================
// CONSTRUCTOR
// =====================================================

GameUI::GameUI(sf::Font& fontReference)
    : font(fontReference),

      replayButton(
          fontReference,
          "CHOI LAI",
          18
      ),

      backButton(
          fontReference,
          "QUAY VE",
          18
      ),

      texturesLoaded(false)
{
    // Load X / O
    texturesLoaded = loadTextures();
}


// =====================================================
// LOAD TEXTURE
// =====================================================

bool GameUI::loadTextures()
{
    bool success = true;


    if (!xTexture.loadFromFile(
            "assets/X.png"))
    {
        cout
            << "Loi: Khong the tai assets/X.png\n";

        success = false;
    }


    if (!oTexture.loadFromFile(
            "assets/O.png"))
    {
        cout
            << "Loi: Khong the tai assets/O.png\n";

        success = false;
    }


    return success;
}


// =====================================================
// BOARD SIZE
// =====================================================

float GameUI::getBoardSize(
    const sf::RenderWindow& window
) const
{
    const float windowWidth = static_cast<float>(window.getSize().x);
    const float windowHeight = static_cast<float>(window.getSize().y);
    const float boardY = windowHeight >= 500.f ? 65.f : 36.f;
    const float buttonHeight = windowHeight >= 500.f ? 50.f : 40.f;
    const float verticalGap = 18.f;
    const float bottomMargin = 12.f;

    const float availableWidth = std::max(0.f, windowWidth - 32.f);
    const float availableHeight = std::max(
        0.f,
        windowHeight - boardY - verticalGap - buttonHeight - bottomMargin
    );

    return std::max(0.f, std::min({availableWidth, availableHeight, 600.f}));
}


// =====================================================
// BOARD X
// =====================================================

float GameUI::getBoardX(
    const sf::RenderWindow& window
) const
{
    float windowWidth =
        static_cast<float>(
            window.getSize().x
        );


    float boardSize =
        getBoardSize(window);


    return (
        windowWidth -
        boardSize
    ) / 2.f;
}


// =====================================================
// BOARD Y
// =====================================================

float GameUI::getBoardY(
    const sf::RenderWindow& window
) const
{
    return window.getSize().y >= 500 ? 65.f : 36.f;
}


void GameUI::layoutButtons(const sf::RenderWindow& window)
{
    const float width = static_cast<float>(window.getSize().x);
    const float height = static_cast<float>(window.getSize().y);
    const float buttonHeight = height >= 500.f ? 50.f : 40.f;
    const float gap = 16.f;
    const float buttonWidth = std::max(
        80.f,
        std::min(280.f, (width - 48.f - gap) / 2.f)
    );
    const float totalWidth = buttonWidth * 2.f + gap;
    const float startX = (width - totalWidth) / 2.f;
    const float y = getBoardY(window) + getBoardSize(window) + 18.f;

    replayButton.setSize(buttonWidth, buttonHeight);
    backButton.setSize(buttonWidth, buttonHeight);
    replayButton.setPosition(startX, y);
    backButton.setPosition(startX + buttonWidth + gap, y);
}


// =====================================================
// UPDATE
// =====================================================

void GameUI::update(
    sf::RenderWindow& window
)
{
    layoutButtons(window);

    sf::Vector2i mouse =
        sf::Mouse::getPosition(window);


    sf::Vector2f mousePosition{
        static_cast<float>(mouse.x),
        static_cast<float>(mouse.y)
    };


    replayButton.updateHover(
        mousePosition
    );


    backButton.updateHover(
        mousePosition
    );
}


// =====================================================
// DRAW BOARD
// =====================================================

void GameUI::drawBoard(
    sf::RenderWindow& window
)
{
    float boardSize =
        getBoardSize(window);


    float boardX =
        getBoardX(window);


    float boardY =
        getBoardY(window);


    float cellSize =
        boardSize / 3.f;


    // -------------------------------------------------
    // Background
    // -------------------------------------------------

    sf::RectangleShape boardBackground({
        boardSize,
        boardSize
    });


    boardBackground.setPosition({
        boardX,
        boardY
    });


    boardBackground.setFillColor(
        sf::Color(
            245,
            247,
            250
        )
    );


    boardBackground.setOutlineThickness(
        3.f
    );


    boardBackground.setOutlineColor(
        sf::Color(
            45,
            50,
            60
        )
    );


    window.draw(
        boardBackground
    );


    // -------------------------------------------------
    // Vertical lines
    // -------------------------------------------------

    sf::RectangleShape verticalLine({
        4.f,
        boardSize
    });


    verticalLine.setFillColor(
        sf::Color(
            45,
            50,
            60
        )
    );


    verticalLine.setPosition({
        boardX + cellSize,
        boardY
    });


    window.draw(
        verticalLine
    );


    verticalLine.setPosition({
        boardX + cellSize * 2.f,
        boardY
    });


    window.draw(
        verticalLine
    );


    // -------------------------------------------------
    // Horizontal lines
    // -------------------------------------------------

    sf::RectangleShape horizontalLine({
        boardSize,
        4.f
    });


    horizontalLine.setFillColor(
        sf::Color(
            45,
            50,
            60
        )
    );


    horizontalLine.setPosition({
        boardX,
        boardY + cellSize
    });


    window.draw(
        horizontalLine
    );


    horizontalLine.setPosition({
        boardX,
        boardY + cellSize * 2.f
    });


    window.draw(
        horizontalLine
    );
}


// =====================================================
// DRAW PIECES
// =====================================================

void GameUI::drawPieces(
    sf::RenderWindow& window,
    Game& game
)
{
    if (!texturesLoaded)
    {
        return;
    }


    float boardSize =
        getBoardSize(window);


    float boardX =
        getBoardX(window);


    float boardY =
        getBoardY(window);


    float cellSize =
        boardSize / 3.f;


    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            int player =
                game.getBoard()
                    .getCell(
                        row,
                        col
                    );


            if (player == 0)
            {
                continue;
            }


            float targetSize =
                cellSize * 0.72f;


            const sf::Texture* texture =
                nullptr;


            if (player == 1)
            {
                texture = &xTexture;
            }
            else if (player == 2)
            {
                texture = &oTexture;
            }


            if (texture == nullptr)
            {
                continue;
            }


            sf::Vector2u textureSize =
                texture->getSize();


            if (
                textureSize.x == 0 ||
                textureSize.y == 0
            )
            {
                continue;
            }


            sf::Sprite piece(
                *texture
            );


            float scale = targetSize /
                static_cast<float>(
                    std::max(textureSize.x, textureSize.y)
                );

            piece.setScale({scale, scale});


            const float renderedWidth = static_cast<float>(textureSize.x) * scale;
            const float renderedHeight = static_cast<float>(textureSize.y) * scale;

            float posX =
                boardX +
                col * cellSize +
                (cellSize - renderedWidth) / 2.f;


            float posY =
                boardY +
                row * cellSize +
                (cellSize - renderedHeight) / 2.f;


            piece.setPosition({
                posX,
                posY
            });


            window.draw(
                piece
            );
        }
    }
}


// =====================================================
// DRAW RESULT
// =====================================================

void GameUI::drawResult(
    sf::RenderWindow& window,
    Game& game
)
{
    if (
        game.getState() !=
        GAME_OVER
    )
    {
        return;
    }


    int result =
        game.getResult();


    string message;


    if (result == 1)
    {
        message = "BAN THANG!";
    }
    else if (result == 2)
    {
        message = "BAN THUA!";
    }
    else
    {
        message = "TRAN DAU HOA!";
    }


    sf::Text resultText(
        font,
        message,
        36
    );


    resultText.setFillColor(
        sf::Color::White
    );


    resultText.setStyle(
        sf::Text::Bold
    );


    float windowWidth =
        static_cast<float>(
            window.getSize().x
        );


    sf::FloatRect bounds =
        resultText.getLocalBounds();


    resultText.setPosition({
        (windowWidth -
         bounds.size.x) / 2.f -
            bounds.position.x,

        45.f
    });


    window.draw(
        resultText
    );
}


// =====================================================
// DRAW
// =====================================================

void GameUI::draw(
    sf::RenderWindow& window,
    Game& game
)
{
    layoutButtons(window);

    window.clear(
        sf::Color(
            18,
            24,
            38
        )
    );


    // -------------------------------------------------
    // TITLE
    // -------------------------------------------------

    sf::Text title(
        font,
        "TIC TAC TOE",
        30
    );


    title.setFillColor(
        sf::Color::White
    );


    title.setStyle(
        sf::Text::Bold
    );


    sf::FloatRect titleBounds =
        title.getLocalBounds();


    float windowWidth =
        static_cast<float>(
            window.getSize().x
        );


    title.setPosition({
        (windowWidth -
         titleBounds.size.x) / 2.f -
            titleBounds.position.x,

        10.f
    });


    window.draw(title);


    // -------------------------------------------------
    // BOARD
    // -------------------------------------------------

    drawBoard(window);


    // -------------------------------------------------
    // X / O
    // -------------------------------------------------

    drawPieces(
        window,
        game
    );


    // -------------------------------------------------
    // RESULT
    // -------------------------------------------------

    drawResult(
        window,
        game
    );


    // -------------------------------------------------
    // BUTTONS
    // -------------------------------------------------

    replayButton.draw(
        window
    );


    backButton.draw(
        window
    );
}


// =====================================================
// HANDLE CLICK
// =====================================================

bool GameUI::handleClick(
    sf::RenderWindow& window,
    Game& game,
    sf::Vector2f mousePos
)
{
    layoutButtons(window);

    // -------------------------------------------------
    // BACK TO MENU
    // -------------------------------------------------

    if (
        backButton.contains(
            mousePos
        )
    )
    {
        return true;
    }


    // -------------------------------------------------
    // REPLAY
    // -------------------------------------------------

    if (
        replayButton.contains(
            mousePos
        )
    )
    {
        game.reset();

        return false;
    }


    // -------------------------------------------------
    // Không cho đánh khi game đã kết thúc
    // -------------------------------------------------

    if (
        game.getState() ==
        GAME_OVER
    )
    {
        return false;
    }


    // -------------------------------------------------
    // BOARD
    // -------------------------------------------------

    float boardSize =
        getBoardSize(window);


    float boardX =
        getBoardX(window);


    float boardY =
        getBoardY(window);


    float cellSize =
        boardSize / 3.f;


    // -------------------------------------------------
    // Click ngoài bàn
    // -------------------------------------------------

    if (
        mousePos.x < boardX ||
        mousePos.x >= boardX + boardSize ||
        mousePos.y < boardY ||
        mousePos.y >= boardY + boardSize
    )
    {
        return false;
    }


    // -------------------------------------------------
    // Tính row / col
    // -------------------------------------------------

    int col =
        static_cast<int>(
            (mousePos.x - boardX) /
            cellSize
        );


    int row =
        static_cast<int>(
            (mousePos.y - boardY) /
            cellSize
        );


    if (
        row < 0 ||
        row >= 3 ||
        col < 0 ||
        col >= 3
    )
    {
        return false;
    }


    // -------------------------------------------------
    // Player move
    // -------------------------------------------------

    bool moved =
        game.playerMove({
            row,
            col
        });


    if (!moved)
    {
        return false;
    }


    // -------------------------------------------------
    // KIỂM TRA THẮNG / HÒA
    // -------------------------------------------------

    if (game.isGameOver())
    {
        game.checkAndSetResult();

        game.setState(
            GAME_OVER
        );

        return false;
    }


    // -------------------------------------------------
    // Đổi lượt
    // -------------------------------------------------

    game.nextTurn();


    // -------------------------------------------------
    // AI MOVE
    // -------------------------------------------------

    game.aiMove();


    // -------------------------------------------------
    // KIỂM TRA AI THẮNG / HÒA
    // -------------------------------------------------

    if (game.isGameOver())
    {
        game.checkAndSetResult();

        game.setState(
            GAME_OVER
        );

        return false;
    }


    // -------------------------------------------------
    // Đổi lại lượt player
    // -------------------------------------------------

    game.nextTurn();


    return false;
}
