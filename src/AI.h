#ifndef AI_H
#define AI_H

#include "Board.h"

class AI
{
private:
    int minimax(
        Board& board,
        int currentPlayer,
        int depth
    );

public:
    AI() = default;

    Move getBestMove(
        Board& board
    );
};

#endif