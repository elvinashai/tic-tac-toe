#include "../src/tictactoe.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Game starts with player X") {

    TicTacToe game;

    REQUIRE(game.getCurrentPlayer() == 'X');
}

TEST_CASE("Detect win condition") {

    TicTacToe game;

    // simulate moves
    game.makeMove(1);
    game.makeMove(2);
    game.makeMove(3);

    REQUIRE(game.checkWin() == true);
}

TEST_CASE("Invalid move rejected") {

    TicTacToe game;

    REQUIRE(game.isValidMove("10") == false);
}