#include "MenuUI.h"
#include <algorithm>


MenuUI::MenuUI(
    sf::Font& fontReference
)
    : font(fontReference),

      title(
          fontReference,
          "TIC TAC TOE",
          42
      ),

      welcome(
          fontReference,
          "CHON CHE DO CHOI",
          24
      ),

      playComputerButton(
          fontReference,
          "CHOI VOI MAY",
          20
      ),

      exitButton(
          fontReference,
          "THOAT GAME",
          20
      )
{
    title.setFillColor(
        sf::Color(
            35,
            50,
            80
        )
    );


    welcome.setFillColor(
        sf::Color(
            70,
            75,
            90
        )
    );


    playComputerButton.setPosition(
        270.f,
        280.f
    );


    exitButton.setPosition(
        270.f,
        380.f
    );
}


// =====================================================
// CLICK
// =====================================================

MenuResult MenuUI::handleClick(
    sf::Vector2f mousePosition
)
{
    if (
        playComputerButton.contains(
            mousePosition
        )
    )
    {
        return MenuResult::PLAY_COMPUTER;
    }


    if (
        exitButton.contains(
            mousePosition
        )
    )
    {
        return MenuResult::EXIT;
    }


    return MenuResult::NONE;
}


// =====================================================
// DRAW
// =====================================================

void MenuUI::draw(
    sf::RenderWindow& window
)
{
    const float width = static_cast<float>(window.getSize().x);
    const float height = static_cast<float>(window.getSize().y);
    const float buttonWidth = std::max(120.f, std::min(360.f, width - 40.f));
    const float buttonX = (width - buttonWidth) / 2.f;
    const float titleY = std::max(24.f, height * 0.16f);

    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setPosition({
        (width - titleBounds.size.x) / 2.f - titleBounds.position.x,
        titleY
    });
    window.draw(title);

    sf::FloatRect welcomeBounds = welcome.getLocalBounds();
    welcome.setPosition({
        (width - welcomeBounds.size.x) / 2.f - welcomeBounds.position.x,
        titleY + 78.f
    });
    window.draw(welcome);

    playComputerButton.setSize(buttonWidth, 58.f);
    exitButton.setSize(buttonWidth, 58.f);
    playComputerButton.setPosition(buttonX, std::max(titleY + 175.f, height * 0.48f));
    exitButton.setPosition(buttonX, std::max(titleY + 265.f, height * 0.63f));

    playComputerButton.draw(window);
    exitButton.draw(window);
}
