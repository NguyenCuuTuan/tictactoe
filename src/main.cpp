#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"

// =====================================================
// VẼ X
// =====================================================

void drawX(sf::RenderWindow& window, int row, int col)
{
    float x = col * 200.f;
    float y = row * 200.f;

    sf::VertexArray lines(sf::PrimitiveType::Lines, 4);

    lines[0].position = {x + 40.f, y + 40.f};
    lines[1].position = {x + 160.f, y + 160.f};

    lines[2].position = {x + 160.f, y + 40.f};
    lines[3].position = {x + 40.f, y + 160.f};

    lines[0].color = sf::Color::Red;
    lines[1].color = sf::Color::Red;
    lines[2].color = sf::Color::Red;
    lines[3].color = sf::Color::Red;

    window.draw(lines);
}


// =====================================================
// VẼ O
// =====================================================

void drawO(sf::RenderWindow& window, int row, int col)
{
    sf::CircleShape circle(60.f);

    circle.setPosition({
        col * 200.f + 40.f,
        row * 200.f + 40.f
    });

    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(5.f);
    circle.setOutlineColor(sf::Color::Blue);

    window.draw(circle);
}


// =====================================================
// MAIN
// =====================================================

int main()
{
    // =================================================
    // TẠO CỬA SỔ
    // =================================================

    sf::RenderWindow window(
        sf::VideoMode({600, 600}),
        "Tic Tac Toe"
    );

    window.setFramerateLimit(60);


    // =================================================
    // TẠO GAME
    // =================================================

    Game game;


    // =================================================
    // TẠO ĐƯỜNG KẺ BÀN CỜ
    // =================================================

    sf::RectangleShape lineVertical;
    sf::RectangleShape lineHorizontal;

    lineVertical.setSize({5.f, 600.f});
    lineVertical.setFillColor(sf::Color::Black);

    lineHorizontal.setSize({600.f, 5.f});
    lineHorizontal.setFillColor(sf::Color::Black);


    // =================================================
    // GAME LOOP
    // =================================================

    while (window.isOpen())
    {
        // =================================================
        // XỬ LÝ EVENT - SFML 3
        // =================================================

        while (auto event = window.pollEvent())
        {
            // -------------------------------------------------
            // ĐÓNG CỬA SỔ
            // -------------------------------------------------

            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }


            // -------------------------------------------------
            // CLICK CHUỘT
            // -------------------------------------------------

            if (auto* mouseButton =
                event->getIf<sf::Event::MouseButtonPressed>())
            {
                // Chỉ xử lý chuột trái
                if (mouseButton->button == sf::Mouse::Button::Left)
                {
                    int mouseX = mouseButton->position.x;
                    int mouseY = mouseButton->position.y;


                    // =================================================
                    // XÁC ĐỊNH Ô ĐƯỢC CLICK
                    // =================================================

                    int col = mouseX / 200;
                    int row = mouseY / 200;


                    // Kiểm tra có nằm trong bàn cờ không
                    if (row >= 0 && row < 3 &&
                        col >= 0 && col < 3)
                    {
                        std::cout
                            << "Click: "
                            << row << ", "
                            << col
                            << std::endl;


                        // =================================================
                        // PLAYER ĐÁNH
                        // =================================================

                        if (game.playerMove({row, col}))
                        {
                            std::cout
                                << "Player move OK"
                                << std::endl;


                            // =================================================
                            // KIỂM TRA PLAYER THẮNG / HÒA
                            // =================================================

                            if (game.isGameOver())
                            {
                                std::cout
                                    << "Game Over"
                                    << std::endl;

                                continue;
                            }


                            // =================================================
                            // CHUYỂN LƯỢT PLAYER -> AI
                            // =================================================

                            game.nextTurn();


                            // =================================================
                            // AI ĐÁNH
                            // =================================================

                            game.aiMove();


                            std::cout
                                << "AI move OK"
                                << std::endl;


                            // =================================================
                            // KIỂM TRA AI THẮNG / HÒA
                            // =================================================

                            if (game.isGameOver())
                            {
                                std::cout
                                    << "Game Over"
                                    << std::endl;

                                continue;
                            }


                            // =================================================
                            // CHUYỂN LƯỢT AI -> PLAYER
                            // =================================================

                            game.nextTurn();
                        }
                        else
                        {
                            std::cout
                                << "O nay da co quan!"
                                << std::endl;
                        }
                    }
                }
            }
        }


        // =================================================
        // XÓA MÀN HÌNH
        // =================================================

        window.clear(sf::Color::White);


        // =================================================
        // VẼ 2 ĐƯỜNG DỌC
        // =================================================

        lineVertical.setPosition({
            200.f,
            0.f
        });

        window.draw(lineVertical);


        lineVertical.setPosition({
            400.f,
            0.f
        });

        window.draw(lineVertical);


        // =================================================
        // VẼ 2 ĐƯỜNG NGANG
        // =================================================

        lineHorizontal.setPosition({
            0.f,
            200.f
        });

        window.draw(lineHorizontal);


        lineHorizontal.setPosition({
            0.f,
            400.f
        });

        window.draw(lineHorizontal);


        // =================================================
        // LẤY BOARD TỪ GAME
        // =================================================

        Board& board = game.getBoard();


        // =================================================
        // VẼ X / O
        // =================================================

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                int player = board.getCell(row, col);


                // Player 1 = X
                if (player == 1)
                {
                    drawX(window, row, col);
                }


                // Player 2 = O
                else if (player == 2)
                {
                    drawO(window, row, col);
                }
            }
        }


        // =================================================
        // HIỂN THỊ
        // =================================================

        window.display();
    }


    return 0;
}