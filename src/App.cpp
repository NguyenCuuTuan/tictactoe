#include "App.h"
#include <iostream>


// Khởi tạo cửa sổ, font, trạng thái ban đầu và các UI
App::App()
    : window(sf::VideoMode({1000, 800}), "Tic Tac Toe"),
      font(),
      state(AppState::LOGIN),
      loginUI(font),
      menuUI(font),
      gameUI(font),
      game()
{
    window.setFramerateLimit(60);
    loadResources();
}


// Tải các tài nguyên cần thiết cho chương trình
bool App::loadResources(){
    if(!font.openFromFile("assets/font.ttf")){
        std::cout << "Loi: Khong the tai font!\n";
        return false;
    }

    return true;
}


// Chạy vòng lặp chính của game
void App::run(){
    while(window.isOpen() && state != AppState::EXIT){
        processEvents();
        update();
        render();
    }
}


// Nhận và phân loại các sự kiện từ cửa sổ
void App::processEvents(){
    while(auto event = window.pollEvent()){

        // Xử lý khi người chơi đóng cửa sổ
        if(event->is<sf::Event::Closed>()){
            state = AppState::EXIT;
            window.close();
            return;
        }

        // Cap nhat view khi cua so bi resize/maximize de tranh keo gian giao dien.
        if (event->is<sf::Event::Resized>()) {
            const sf::Vector2u size = window.getSize();
            window.setView(sf::View(sf::FloatRect(
                {0.f, 0.f},
                {static_cast<float>(size.x), static_cast<float>(size.y)}
            )));
        }

        // Gửi event đến đúng màn hình hiện tại
        switch(state){
            case AppState::LOGIN:
                handleLoginEvent(*event);
                break;

            case AppState::REGISTER:
                handleRegisterEvent(*event);
                break;

            case AppState::MENU:
                handleMenuEvent(*event);
                break;

            case AppState::GAME:
                handleGameEvent(*event);
                break;

            case AppState::EXIT:
                break;
        }
    }
}


// Xử lý thao tác của người chơi ở màn hình Login
void App::handleLoginEvent(const sf::Event& event){

    // Nhận ký tự người chơi nhập vào ô Login
    if(const auto* textEntered = event.getIf<sf::Event::TextEntered>()){
        loginUI.handleTextInput(textEntered->unicode);
    }

    // Xử lý phím Backspace để xóa ký tự
    if(const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()){
        if(keyPressed->code == sf::Keyboard::Key::Backspace){
            loginUI.handleBackspace();
        }
    }

    // Xử lý khi người chơi click chuột
    if(const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()){
        if(mousePressed->button == sf::Mouse::Button::Left){

            // Lấy vị trí chuột khi người chơi click
            sf::Vector2f mousePosition{
                static_cast<float>(mousePressed->position.x),
                static_cast<float>(mousePressed->position.y)
            };

            // Kiểm tra người chơi đã click vào nút nào
            LoginResult result = loginUI.handleClick(mousePosition);

            // Xử lý kết quả trả về từ LoginUI
            switch(result){
                case LoginResult::REGISTER:
                    state = AppState::REGISTER;
                    break;

                case LoginResult::LOGIN_SUCCESS:
                    state = AppState::MENU;
                    break;

                default:
                    break;
            }
        }
    }
}


// Xử lý thao tác của người chơi ở màn hình Register
void App::handleRegisterEvent(const sf::Event& event){

    // Nhận ký tự người chơi nhập vào form đăng ký
    if(const auto* textEntered = event.getIf<sf::Event::TextEntered>()){
        loginUI.handleTextInput(textEntered->unicode);
    }

    // Xử lý phím Backspace để xóa ký tự
    if(const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()){
        if(keyPressed->code == sf::Keyboard::Key::Backspace){
            loginUI.handleBackspace();
        }
    }

    // Xử lý khi người chơi click chuột
    if(const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()){
        if(mousePressed->button == sf::Mouse::Button::Left){

            // Lấy vị trí chuột khi người chơi click
            sf::Vector2f mousePosition{
                static_cast<float>(mousePressed->position.x),
                static_cast<float>(mousePressed->position.y)
            };

            // Kiểm tra người chơi đã click vào nút nào
            LoginResult result = loginUI.handleRegisterClick(mousePosition);

            // Xử lý kết quả trả về từ Register
            switch(result){
                case LoginResult::REGISTER_SUCCESS:
                    state = AppState::LOGIN;
                    break;

                case LoginResult::BACK:
                    state = AppState::LOGIN;
                    break;

                default:
                    break;
            }
        }
    }
}


// Xử lý thao tác của người chơi ở màn hình Menu
void App::handleMenuEvent(const sf::Event& event){

    // Kiểm tra người chơi có click chuột hay không
    if(const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()){
        if(mousePressed->button == sf::Mouse::Button::Left){

            // Lấy vị trí chuột khi click
            sf::Vector2f mousePosition{
                static_cast<float>(mousePressed->position.x),
                static_cast<float>(mousePressed->position.y)
            };

            // Kiểm tra người chơi đã chọn nút nào trong Menu
            MenuResult result = menuUI.handleClick(mousePosition);

            // Xử lý kết quả trả về từ Menu
            switch(result){

                // Người chơi chọn chơi với máy
                case MenuResult::PLAY_COMPUTER:
                    game.reset();
                    state = AppState::GAME;
                    break;

                // Người chơi chọn thoát game
                case MenuResult::EXIT:
                    state = AppState::EXIT;
                    window.close();
                    break;

                default:
                    break;
            }
        }
    }
}


// Xu ly click khi dang o man hinh Game
void App::handleGameEvent(const sf::Event& event){
    if(const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()){
        if(mousePressed->button == sf::Mouse::Button::Left){

            // Lay vi tri chuot
            sf::Vector2f mousePosition{
                static_cast<float>(mousePressed->position.x),
                static_cast<float>(mousePressed->position.y)
            };

            bool backToMenu = gameUI.handleClick(
                window,
                game,
                mousePosition
            );

            // Neu bam Back thi quay lai Menu
            if (backToMenu) {
                state = AppState::MENU;
            }
        }
    }
}


// Cập nhật trạng thái của game theo từng frame
void App::update(){
    switch(state){
        case AppState::LOGIN:
            break;

        case AppState::REGISTER:
            break;

        case AppState::MENU:
            break;

        case AppState::GAME:

            // Cập nhật các thành phần đang diễn ra trong Game
            gameUI.update(window);
            break;

        case AppState::EXIT:
            break;
    }
}


// Ve giao dien hien tai
void App::render(){
    window.clear(sf::Color(18, 24, 38));

    switch(state){
        case AppState::LOGIN:
            loginUI.drawLogin(window);
            break;

        case AppState::REGISTER:
            loginUI.drawRegister(window);
            break;

        case AppState::MENU:
            menuUI.draw(window);
            break;

        case AppState::GAME:
            gameUI.draw(window, game);
            break;

        case AppState::EXIT:
            break;
    }

    // Hien thi frame
    window.display();
} 