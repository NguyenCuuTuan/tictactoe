#include "LoginUI.h"
#include <algorithm>


// =====================================================
// CONSTRUCTOR
// =====================================================

LoginUI::LoginUI(
    sf::Font& fontReference
)
    : font(fontReference),

      loginUsername(
          fontReference,
          20
      ),

      loginPassword(
          fontReference,
          20,
          true
      ),

      loginButton(
          fontReference,
          "DANG NHAP",
          20
      ),

      registerButton(
          fontReference,
          "TAO TAI KHOAN",
          18
      ),

      registerUsername(
          fontReference,
          20
      ),

      registerPassword(
          fontReference,
          20,
          true
      ),

      registerConfirm(
          fontReference,
          20,
          true
      ),

      createAccountButton(
          fontReference,
          "DANG KY",
          20
      ),

      backButton(
          fontReference,
          "QUAY LAI",
          18
      ),

      loginTitle(
          fontReference,
          "DANG NHAP",
          40
      ),

      registerTitle(
          fontReference,
          "TAO TAI KHOAN",
          40
      )
{
    // LOGIN

    loginUsername.setPosition(
        270.f,
        230.f
    );

    loginPassword.setPosition(
        270.f,
        330.f
    );

    loginButton.setPosition(
        270.f,
        430.f
    );

    registerButton.setPosition(
        270.f,
        510.f
    );


    // REGISTER

    registerUsername.setPosition(
        270.f,
        190.f
    );

    registerPassword.setPosition(
        270.f,
        290.f
    );

    registerConfirm.setPosition(
        270.f,
        390.f
    );

    createAccountButton.setPosition(
        270.f,
        480.f
    );

    backButton.setPosition(
        270.f,
        560.f
    );


    loginTitle.setFillColor(
        sf::Color(35, 50, 80)
    );

    registerTitle.setFillColor(
        sf::Color(35, 50, 80)
    );
}


// =====================================================
// TITLE
// =====================================================

void LoginUI::drawTitle(
    sf::RenderWindow& window,
    sf::Text& title,
    float y
)
{
    const float windowWidth = static_cast<float>(window.getSize().x);
    const sf::FloatRect bounds = title.getLocalBounds();

    title.setPosition({
        (windowWidth - bounds.size.x) / 2.f - bounds.position.x,
        std::max(8.f, y)
    });

    window.draw(title);
}


void LoginUI::layoutLogin(const sf::RenderWindow& window)
{
    const float width = static_cast<float>(window.getSize().x);
    const float height = static_cast<float>(window.getSize().y);
    const float controlWidth = std::max(120.f, std::min(360.f, width - 40.f));
    const float x = (width - controlWidth) / 2.f;
    const float top = std::max(18.f, (height - 332.f) / 2.f);

    loginUsername.setSize(controlWidth, 52.f);
    loginPassword.setSize(controlWidth, 52.f);
    loginButton.setSize(controlWidth, 54.f);
    registerButton.setSize(controlWidth, 52.f);

    loginUsername.setPosition(x, top + 30.f);
    loginPassword.setPosition(x, top + 130.f);
    loginButton.setPosition(x, top + 205.f);
    registerButton.setPosition(x, top + 280.f);
}


void LoginUI::layoutRegister(const sf::RenderWindow& window)
{
    const float width = static_cast<float>(window.getSize().x);
    const float height = static_cast<float>(window.getSize().y);
    const float controlWidth = std::max(120.f, std::min(360.f, width - 40.f));
    const float x = (width - controlWidth) / 2.f;
    const float top = std::max(12.f, (height - 388.f) / 2.f);

    registerUsername.setSize(controlWidth, 50.f);
    registerPassword.setSize(controlWidth, 50.f);
    registerConfirm.setSize(controlWidth, 50.f);
    createAccountButton.setSize(controlWidth, 52.f);
    backButton.setSize(controlWidth, 50.f);

    registerUsername.setPosition(x, top + 28.f);
    registerPassword.setPosition(x, top + 108.f);
    registerConfirm.setPosition(x, top + 188.f);
    createAccountButton.setPosition(x, top + 268.f);
    backButton.setPosition(x, top + 338.f);
}


// =====================================================
// LABEL
// =====================================================

void LoginUI::drawLabel(
    sf::RenderWindow& window,
    const std::string& value,
    float x,
    float y
)
{
    sf::Text label(
        font,
        value,
        19
    );


    label.setFillColor(
        sf::Color(60, 65, 75)
    );


    label.setPosition({
        x,
        y
    });


    window.draw(label);
}


// =====================================================
// LOGIN CLICK
// =====================================================

LoginResult LoginUI::handleClick(
    sf::Vector2f mousePosition
)
{
    if (loginUsername.contains(mousePosition))
    {
        loginUsername.setActive(true);
        loginPassword.setActive(false);

        return LoginResult::NONE;
    }


    if (loginPassword.contains(mousePosition))
    {
        loginUsername.setActive(false);
        loginPassword.setActive(true);

        return LoginResult::NONE;
    }


    if (registerButton.contains(mousePosition))
    {
        loginUsername.setActive(false);
        loginPassword.setActive(false);

        return LoginResult::REGISTER;
    }


    if (loginButton.contains(mousePosition))
    {
        if (
            loginUsername.getValue().empty() ||
            loginPassword.getValue().empty()
        )
        {
            return LoginResult::NONE;
        }


        return LoginResult::LOGIN_SUCCESS;
    }


    return LoginResult::NONE;
}


// =====================================================
// REGISTER CLICK
// =====================================================

LoginResult LoginUI::handleRegisterClick(
    sf::Vector2f mousePosition
)
{
    if (registerUsername.contains(mousePosition))
    {
        registerUsername.setActive(true);
        registerPassword.setActive(false);
        registerConfirm.setActive(false);

        return LoginResult::NONE;
    }


    if (registerPassword.contains(mousePosition))
    {
        registerUsername.setActive(false);
        registerPassword.setActive(true);
        registerConfirm.setActive(false);

        return LoginResult::NONE;
    }


    if (registerConfirm.contains(mousePosition))
    {
        registerUsername.setActive(false);
        registerPassword.setActive(false);
        registerConfirm.setActive(true);

        return LoginResult::NONE;
    }


    if (backButton.contains(mousePosition))
    {
        return LoginResult::BACK;
    }


    if (createAccountButton.contains(mousePosition))
    {
        if (
            registerUsername.getValue().empty() ||
            registerPassword.getValue().empty() ||
            registerConfirm.getValue().empty()
        )
        {
            return LoginResult::NONE;
        }


        if (
            registerPassword.getValue() !=
            registerConfirm.getValue()
        )
        {
            return LoginResult::NONE;
        }


        return LoginResult::REGISTER_SUCCESS;
    }


    return LoginResult::NONE;
}


// =====================================================
// TEXT INPUT
// =====================================================

void LoginUI::handleTextInput(
    char32_t unicode
)
{
    if (unicode < 32 ||
        unicode > 126)
    {
        return;
    }


    if (loginUsername.isActive())
    {
        loginUsername.addCharacter(unicode);
    }
    else if (loginPassword.isActive())
    {
        loginPassword.addCharacter(unicode);
    }
    else if (registerUsername.isActive())
    {
        registerUsername.addCharacter(unicode);
    }
    else if (registerPassword.isActive())
    {
        registerPassword.addCharacter(unicode);
    }
    else if (registerConfirm.isActive())
    {
        registerConfirm.addCharacter(unicode);
    }
}


// =====================================================
// BACKSPACE
// =====================================================

void LoginUI::handleBackspace()
{
    if (loginUsername.isActive())
    {
        loginUsername.removeCharacter();
    }
    else if (loginPassword.isActive())
    {
        loginPassword.removeCharacter();
    }
    else if (registerUsername.isActive())
    {
        registerUsername.removeCharacter();
    }
    else if (registerPassword.isActive())
    {
        registerPassword.removeCharacter();
    }
    else if (registerConfirm.isActive())
    {
        registerConfirm.removeCharacter();
    }
}


// =====================================================
// DRAW LOGIN
// =====================================================

void LoginUI::drawLogin(
    sf::RenderWindow& window
)
{
    layoutLogin(window);

    const float height = static_cast<float>(window.getSize().y);
    const float top = std::max(18.f, (height - 332.f) / 2.f);
    drawTitle(window, loginTitle, top - 76.f);

    const float width = static_cast<float>(window.getSize().x);
    const float controlWidth = std::max(120.f, std::min(360.f, width - 40.f));
    const float x = (width - controlWidth) / 2.f;

    drawLabel(window, "Ten dang nhap", x, top);
    drawLabel(window, "Mat khau", x, top + 100.f);

    loginUsername.draw(window);
    loginPassword.draw(window);
    loginButton.draw(window);
    registerButton.draw(window);
}


void LoginUI::drawRegister(
    sf::RenderWindow& window
)
{
    layoutRegister(window);

    const float height = static_cast<float>(window.getSize().y);
    const float top = std::max(12.f, (height - 388.f) / 2.f);
    drawTitle(window, registerTitle, top - 76.f);

    const float width = static_cast<float>(window.getSize().x);
    const float controlWidth = std::max(120.f, std::min(360.f, width - 40.f));
    const float x = (width - controlWidth) / 2.f;

    drawLabel(window, "Ten dang nhap", x, top);
    drawLabel(window, "Mat khau", x, top + 80.f);
    drawLabel(window, "Nhap lai mat khau", x, top + 160.f);

    registerUsername.draw(window);
    registerPassword.draw(window);
    registerConfirm.draw(window);
    createAccountButton.draw(window);
    backButton.draw(window);
}
