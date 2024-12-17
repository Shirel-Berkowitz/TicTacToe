#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe(int boardSize, int winSequence);
    void play();
    void makeMove(int position);
    void printBoard() const;

private:
    int boardSize;
    int winSequence;
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void initializeBoard();
    bool isValidMove(int position) const;
    bool checkWin(int row, int col) const;
    bool checkLine(int startRow, int startCol, int dRow, int dCol) const;
    bool isBoardFull() const;
    void switchPlayer();
};
