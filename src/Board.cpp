#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
    }
}

void Board::printBoard(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 0)
                cout << ".";
            else if (board[i][j] == 1)
                cout << "X";
            else
                cout << "O";

            if (j < 2)
                cout << " | ";
        }

        cout << endl;

        if (i < 2)
            cout << "--+---+--" << endl;
    }
}

bool Board::checkWin(){
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return true;
        }
    }
    
    if (board[0][0] != 0 &&board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return true;
    }
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return true;
    }
    return false;
}

void Board::setCell(int row, int col, int player){
    board[row][col] = player;
}

int Board::getCell(int row, int col){
    return board[row][col];
}

bool Board::isFull(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

void Board::clear() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
}
            

