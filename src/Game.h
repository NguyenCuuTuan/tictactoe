#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "AI.h"

class Game{
    private:
        Board board;
        AI ai;
        int currentPlayer;

    public:
        Game();
        bool playerMove(Move move);
        void nextTurn();
        void aiMove();
        bool isGameOver();
        Board& getBoard(); 
};

#endif
