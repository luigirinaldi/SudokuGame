#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include "validCheck.h"

class sudoku
{
	public:
		sudoku(int size);
		std::vector<int> gameBoard;
		int subLen;
		int sideLen;
		void run();
		void printBoard();
		void makeBoard();
		bool makeRandomBoard();
		int randomNum(int range);
	private:
		static const int NUM_ATTEMPTS = 100;
};