#include "Game.h"
#include <iostream>
using namespace std;


Game::Game(){
    currentPlayer = 1;
}

bool Game::playerMove(Move move){
    if(board.getCell(move.row, move.col) != 0){
        return false;
    }
    board.setCell(move.row, move.col, currentPlayer);
    return true;
}

void Game::nextTurn(){
    currentPlayer = 3 - currentPlayer;
}

void Game::aiMove()
{
    Move  move = ai.getBestMove(board);
    board.setCell(move.row, move.col, currentPlayer);
}

bool Game::isGameOver(){
    if(board.checkWin() || board.isFull()){
        return true;
    }
    return false;
}

Board &Game::getBoard()
{
    return board;
}


