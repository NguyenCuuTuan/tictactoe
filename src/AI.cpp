#include <iostream>
#include <climits>
#include <algorithm>
#include "AI.h"
using namespace std;


int AI::minimax(Board& board, int currentPlayer, int depth){
    if (board.checkWin()){
        int winner = 3 - currentPlayer;
        if (winner == 2)
            return 10 - depth;
        return depth - 10;      
    }
    if (board.isFull()) 
        return 0;


    if(currentPlayer == 2){
        int bestScore = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getCell(i, j) == 0) {
                    board.setCell(i, j, 2);
                    int score = minimax(board, 1, depth + 1);; 
                    board.setCell(i, j, 0);
                    bestScore = max(score, bestScore); 
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getCell(i, j) == 0) {
                    board.setCell(i, j, 1);
                    int score =minimax(board, 2, depth + 1);
                    board.setCell(i, j, 0);
                    bestScore = min(score, bestScore); 
                }
            }
        }
        return bestScore;
    }
}


Move AI::getBestMove(Board& board){
    Move bestMove{-1, -1};
    int bestScore = INT_MIN;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board.getCell(i, j) == 0){
                board.setCell(i, j, 2);
                int score = minimax(board, 1, 0);
                board.setCell(i, j, 0);
                if (score > bestScore){
                    bestScore = score;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }
    return bestMove;
}

