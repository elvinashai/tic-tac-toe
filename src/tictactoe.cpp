#include "tictactoe.hpp"
#include <iostream>
#include <cctype>

using namespace std;

TicTacToe::TicTacToe() {
    initializeBoard();
    currentPlayer = 'X';
}

void TicTacToe::initializeBoard() {
    for(int i=0;i<9;i++){
        board[i] = '1' + i;
    }
}

void TicTacToe::printBoard() const {

    cout << "\n";
    cout << "    " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    cout << "  -----+-----+-----\n";
    cout << "    " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    cout << "  -----+-----+-----\n";
    cout << "    " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "\n";
}

bool TicTacToe::isValidMove(const string& input) const {

    if(input.size()!=1 || !isdigit(input[0]))
        return false;

    int pos = input[0] - '0';

    if(pos < 1 || pos > 9)
        return false;

    if(board[pos-1]=='X' || board[pos-1]=='O')
        return false;

    return true;
}

void TicTacToe::makeMove(int position) {
    board[position-1] = currentPlayer;
}

bool TicTacToe::checkWin() const {

    int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for(auto& w : wins){
        if(board[w[0]]==currentPlayer &&
           board[w[1]]==currentPlayer &&
           board[w[2]]==currentPlayer)
            return true;
    }

    return false;
}

bool TicTacToe::checkDraw() const {

    for(char c : board){
        if(c!='X' && c!='O')
            return false;
    }

    return true;
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer=='X') ? 'O' : 'X';
}

char TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}
