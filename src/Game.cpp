#include "Game.h"


Game::Game()
{
    currentPlayer = 1;

    currentState =
        LOGIN_SCREEN;

    gameResult = 0;
}


bool Game::playerMove(
    Move move
)
{
    if (
        board.getCell(
            move.row,
            move.col
        ) != 0
    )
    {
        return false;
    }


    board.setCell(
        move.row,
        move.col,
        currentPlayer
    );


    return true;
}


void Game::nextTurn()
{
    currentPlayer =
        3 - currentPlayer;
}


void Game::aiMove()
{
    Move move =
        ai.getBestMove(board);


    // Phòng trường hợp bàn cờ đã đầy
    if (
        move.row < 0 ||
        move.col < 0
    )
    {
        return;
    }


    board.setCell(
        move.row,
        move.col,
        currentPlayer
    );
}


bool Game::isGameOver()
{
    if (
        board.checkWin() ||
        board.isFull()
    )
    {
        return true;
    }


    return false;
}


Board& Game::getBoard()
{
    return board;
}


void Game::checkAndSetResult()
{
    if (board.checkWin())
    {
        gameResult =
            currentPlayer;
    }
    else if (board.isFull())
    {
        gameResult = 3;
    }
}


void Game::reset()
{
    board.clear();

    currentPlayer = 1;

    gameResult = 0;

    currentState =
        GAMEPLAY;
}