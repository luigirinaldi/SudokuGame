#include <iostream>
#include "sudoku.h"

int main( int argc, char* args[] ){
	sudoku game = sudoku(2);

	/*
	int attempts = 0;
	while(!game.makeRandomBoard()){
		attempts++;
	}

	std::cout << attempts << std::endl;
	*/

	game.makeBoard();

	game.printBoard();

	if(valid_sudoku(game.gameBoard)){
		std::cout << "sudoku is valid" << std::endl;
	} else {
		std::cout << "sudoku isn't valid" << std::endl;
	}

	return 0;
}