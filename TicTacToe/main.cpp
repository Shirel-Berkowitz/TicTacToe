#include "TicTacToe.h"

int main() {
    try {
        TicTacToe game(4, 4);
            game.printBoard();

            game.makeMove(1);
            game.printBoard();

            game.makeMove(5);
            game.printBoard();

            game.makeMove(2);
            game.printBoard();

            game.makeMove(6);
            game.printBoard();

            game.makeMove(3);
            game.printBoard();

            game.makeMove(7);
            game.printBoard();

            game.makeMove(4);
            game.printBoard();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
