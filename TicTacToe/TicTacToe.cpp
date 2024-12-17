#include "TicTacToe.h"

TicTacToe::TicTacToe(int boardSize, int winSequence) {
    this->boardSize = boardSize;
    this->winSequence = winSequence;
    this->currentPlayer = 'X';

    if (boardSize < 3 || boardSize < winSequence) {
        throw std::invalid_argument("Invalid board size or win sequence.");
    }

    initializeBoard();
}

void TicTacToe::initializeBoard() {
    int num = 1;
    board.resize(boardSize, std::vector<char>(boardSize));
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = '0' + num++;
        }
    }
}

void TicTacToe::printBoard() const {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                std::cout << board[i][j] << " ";
            }
            else {
                int number = board[i][j] - '0';
                std::cout << number << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool TicTacToe::isValidMove(int position) const {
    if (position < 1 || position > boardSize * boardSize) {
        return false;
    }
    int row = (position - 1) / boardSize;
    int col = (position - 1) % boardSize;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

void TicTacToe::makeMove(int position) {
    int row = (position - 1) / boardSize;
    int col = (position - 1) % boardSize;
    board[row][col] = currentPlayer;

    if (checkWin(row, col)) {
        printBoard();
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
        exit(0);
    }

    if (isBoardFull()) {
        printBoard();
        std::cout << "It's a draw!" << std::endl;
        exit(0);
    }

    switchPlayer();
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool TicTacToe::isBoardFull() const {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell != 'X' && cell != 'O') {
                return false;
            }
        }
    }

    return true;
}

bool TicTacToe::checkWin(int row, int col) const {
    return checkLine(row, col, 0, 1) ||
        checkLine(row, col, 1, 0) ||
        checkLine(row, col, 1, 1) ||
                   checkLine(row, col, 1, -1);
}

bool TicTacToe::checkLine(int startRow, int startCol, int dRow, int dCol) const {
    char symbol = currentPlayer;
    int count = 0;
    for (int i = -winSequence + 1; i < winSequence; ++i) {
        int r = startRow + i * dRow;
        int c = startCol + i * dCol;
        if (r >= 0 && r < boardSize && c >= 0 && c < boardSize && board[r][c] == symbol) {
            count++;
            if (count == winSequence) {
                return true;
            }
        }
        else {
            count = 0;
        }
    }

    return false;
}

void TicTacToe::play() {
    int move;
    while (true) {
        printBoard();
        std::cout << "Player " << currentPlayer << ", enter your move: ";
        std::cin >> move;

        if (!isValidMove(move)) {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        makeMove(move);
    }
}
