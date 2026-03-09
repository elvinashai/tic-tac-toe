#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <array>
#include <string>

class TicTacToe {

private:
    std::array<char,9> board;
    char currentPlayer;

public:

    TicTacToe();

    void initializeBoard();
    void printBoard() const;

    bool isValidMove(const std::string& input) const;
    void makeMove(int position);

    bool checkWin() const;
    bool checkDraw() const;

    void switchPlayer();

    char getCurrentPlayer() const;
};

#endif
