#include "AI.h"

#include <algorithm>
#include <climits>

using namespace std;


// =====================================================
// MINIMAX
// =====================================================

int AI::minimax(
    Board& board,
    int currentPlayer,
    int depth
)
{
    // Có người thắng
    if (board.checkWin())
    {
        int winner = 3 - currentPlayer;

        // AI (O = 2) thắng
        if (winner == 2)
        {
            return 10 - depth;
        }

        // Người chơi (X = 1) thắng
        return depth - 10;
    }


    // Bàn cờ đầy -> hòa
    if (board.isFull())
    {
        return 0;
    }


    // =================================================
    // AI - PLAYER 2
    // =================================================

    if (currentPlayer == 2)
    {
        int bestScore = INT_MIN;

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (
                    board.getCell(row, col) == 0
                )
                {
                    // Thử nước đi của AI
                    board.setCell(
                        row,
                        col,
                        2
                    );


                    int score =
                        minimax(
                            board,
                            1,
                            depth + 1
                        );


                    // Hoàn tác
                    board.setCell(
                        row,
                        col,
                        0
                    );


                    bestScore =
                        max(
                            bestScore,
                            score
                        );
                }
            }
        }

        return bestScore;
    }


    // =================================================
    // PLAYER - PLAYER 1
    // =================================================

    else
    {
        int bestScore = INT_MAX;

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (
                    board.getCell(row, col) == 0
                )
                {
                    // Thử nước đi của người chơi
                    board.setCell(
                        row,
                        col,
                        1
                    );


                    int score =
                        minimax(
                            board,
                            2,
                            depth + 1
                        );


                    // Hoàn tác
                    board.setCell(
                        row,
                        col,
                        0
                    );


                    bestScore =
                        min(
                            bestScore,
                            score
                        );
                }
            }
        }

        return bestScore;
    }
}


// =====================================================
// GET BEST MOVE
// =====================================================

Move AI::getBestMove(
    Board& board
)
{
    Move bestMove{
        -1,
        -1
    };


    int bestScore = INT_MIN;


    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            // Chỉ xét ô trống
            if (
                board.getCell(row, col) == 0
            )
            {
                // Thử cho AI đánh O
                board.setCell(
                    row,
                    col,
                    2
                );


                int score =
                    minimax(
                        board,
                        1,
                        0
                    );


                // Hoàn tác
                board.setCell(
                    row,
                    col,
                    0
                );


                // Lưu nước đi tốt nhất
                if (score > bestScore)
                {
                    bestScore = score;

                    bestMove.row = row;
                    bestMove.col = col;
                }
            }
        }
    }


    return bestMove;
}