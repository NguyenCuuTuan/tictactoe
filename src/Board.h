#ifndef BOARD_H
#define BOARD_H

struct Move
{
    int row;
    int col;
};

class Board{
    private:
        int board[3][3];

    public:
        Board();
        void clear();
        void printBoard();
        bool checkWin();
        void setCell(int row, int col, int player);
        int getCell(int row, int col);
        bool isFull();
};

#endif