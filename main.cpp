#include "src/tictactoe.hpp"
#include <iostream>

using namespace std;

bool askPlayAgain(){

  string answer;

  while(true){

    cout<<"Would you like to play again (yes/no)? ";
    getline(cin,answer);

    if(answer=="yes"||answer=="Yes"||answer=="y"||answer=="Y")
      return true;

    if(answer=="no"||answer=="No"||answer=="n"||answer=="N")
      return false;

    cout<<"That is not a valid entry!\n";
  }
}

int main() {

  cout<<"Welcome to Tic-Tac-Toe!\n";

  bool playAgain = true;

  while(playAgain){

    TicTacToe game;

    game.printBoard();

    while(true){

      string input;

      cout<<"What is your move? ";
      getline(cin,input);

      if(!game.isValidMove(input)){
        cout<<"That is not a valid move! Try again.\n";
        continue;
      }

      int pos = input[0] - '0';

      game.makeMove(pos);

      game.printBoard();

      if(game.checkWin()){
        cout<<"Player "<<game.getCurrentPlayer()<<" wins!\n";
        break;
      }

      if(game.checkDraw()){
        cout<<"It's a draw!\n";
        break;
      }

      game.switchPlayer();
    }

    playAgain = askPlayAgain();
  }

  cout<<"Goodbye!\n";
}
