#ifndef AI_H
#define AI_H

#include "Board.h"

struct Move{
    int row;
    int col;
};

class AI{
    private:
        int minimax(Board& board, int currentPlayer, int depth);

    public:
        Move getBestMove(Board& board);
};

#endif