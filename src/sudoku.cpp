#include "sudoku.h"

sudoku::sudoku(int size)
{
	// seeding the random number generator at the start of the program
	std::srand((unsigned) time(0)); 

	this->subLen = size;
	this->sideLen = size*size; 

	std::cout << "Initialized sudoku with size " << this->subLen << " and side length " << this->sideLen << std::endl;

	//this->makeRandomBoard();
}

void sudoku::makeBoard(){
	int counter = 0;
	while(!this->makeRandomBoard()); //generating board
	while(!valid_sudoku(this->gameBoard)){
		while(!this->makeRandomBoard()); //generating board
		if(counter%100 == 0){std::cout << counter << std::endl;}
		counter++;
	}
	std::cout << "generating took " << counter << " iterations" << std::endl;
}

bool sudoku::makeRandomBoard()
{
	//std::cout << "Making board" << std::endl;
	this->gameBoard.clear();
	
	//local variable for writability
	int sideLen = this->sideLen;

	// bool arrays representing whether the number has been generated or not
	// subs indicates the subsquares of the sudoku
	bool generatedRow[sideLen][sideLen] {0};
	bool generatedCol[sideLen][sideLen] {0};
	bool generatedSubs[sideLen][sideLen] {0};

	for(int row = 0; row < sideLen;row++){
		for(int col = 0; col < sideLen; col++){
			generatedRow[row][col] = 0;
			generatedCol[row][col] = 0;
			generatedSubs[row][col] = 0;
		}
	}

	// variable to contained newly generated number
	int newNum = 0;
	// var to count number of times the new number has been generated and spot infite loops
	int attempts = 0;
	// var to keep track on which subsquare the counters are on
	int subsq = 0;

	for(int row = 0; row < sideLen;row++){
		for(int col = 0; col < sideLen; col++){
			newNum = this->randomNum(sideLen);
			subsq = (row/(this->subLen)) + (col/(this->subLen));
			while((attempts < NUM_ATTEMPTS) && (generatedRow[row][newNum] || generatedCol[col][newNum] )){//|| generatedSubs[subsq][newNum])){
				newNum = this->randomNum(sideLen);
				attempts++;
			}

			//std::cout << "row " << row << " col " << col << " (" << subsq << ")  " << attempts << std::endl;
			 
			if(attempts < NUM_ATTEMPTS){
				attempts = 0;
				// if the while loop is passed, a number was found and the bool arrays can be updated
				generatedRow[row][newNum] = 1;
				generatedCol[col][newNum] = 1;
				generatedSubs[subsq][newNum] = 1;

				// at this point the board can be filled;
				this->gameBoard.push_back(newNum+1);
			} 
			else {
				/*
				for(int i = 0;i< this->gameBoard.size();i++){
					std::cout << this->gameBoard[i] << " " ;
				}
				std::cout << std::endl;
				*/
				return 0;
			}
		}
	}

	//board is successfully created
	return 1;
}

void sudoku::printBoard()
{
	for(int r = 0; r < this->sideLen; r++){
		for(int c = 0; c < this->sideLen; c++){
			std::cout << this->gameBoard[twod_to_oned(r,c,this->sideLen)] << " ";
		}
		std::cout << std::endl;
	}
}

// generated random number between 0 and range
int sudoku::randomNum(int range)
{
	float num = float(std::rand())/RAND_MAX;
	return int(num*range);
}