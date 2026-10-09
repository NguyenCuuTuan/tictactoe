#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "AI.h"

enum GameState
{
    LOGIN_SCREEN,
    REGISTER_SCREEN,
    MENU_SCREEN,
    GAMEPLAY,
    GAME_OVER
};

class Game
{
private:
    Board board;
    AI ai;

    int currentPlayer;
    GameState currentState;
    int gameResult;

public:
    Game();

    bool playerMove(Move move);

    void nextTurn();

    void aiMove();

    bool isGameOver();

    Board& getBoard();

    GameState getState() const
    {
        return currentState;
    }

    void setState(GameState state)
    {
        currentState = state;
    }

    int getResult() const
    {
        return gameResult;
    }

    void checkAndSetResult();

    void reset();
};

#endif