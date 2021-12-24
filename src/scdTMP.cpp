#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>

// do not alter the header inclusion
// do not include any additional headers
// do not use using namespace std;

// do not change the code already present in this source file 
// complete the functions by adding your code where indicated
// do not add any other functions to the program

// in this program we are going to represent the sudoku as a one dimensional vector
// linearised by row, for instance the 4x4 sudoku: 
// 1 2 3 4
// 4 1 2 76
// 4 4 4 1
// 9 4 1 -7
// will be represented as: 
// 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7

// function twod_to_oned maps two-dimensional indices to a one-dimensional one 
// it takes in input:
// - the two indices row and col of a two dimensional data structure
// - the length of the row, rowlen
// it returns:
// - the corresponding one-dimensional index

int twod_to_oned(int row, int col, int rowlen){
	return row*rowlen+col;
}

// function mfind
// takes in input:
// - a vector of integers v
// - an integer n
// returns:
// the index of the element n in v, if n is in v
// -1 if n is not in v
// for instance:
// v: 3 2 5; n: 2 | return: 1
// v: 3 1 2; n: -6 | return: -1
// v: 1 1 -12 1 5; n: 5 | return: 4

int mfind(const std::vector<int>& v, int n){
// write your code here
// loop through vector comparing each value to n
	for(int i = 0;i < v.size();i++){
		if(v[i]==n){
			// value n is found inside the vector
			return i;
		}
	}
	return -1;
}

// function check_sequence
// takes in input:
// - a vector of integers v
// returns:
// - true if v contains all the numbers from 1 to v.size() and false otherwise
// for instance:
// v: 3 2 5 | return: false
// v: 3 1 2 | return: true
// v: 1 1 -12 1 5 | return: false
// note that check_sequence must (meaningfully) use function mfind
bool check_sequence(const std::vector<int>& v){
	// write your code here
	/*
	  Potential alternative solution:
		each time one of the values is found, pop_back the value
		to reduce the size of the vector making it quicker to find 
	*/

	// straight forward method
	// loop through array and as soon as one of the values is not found return false
	// otherwise return true since all values were found
	for(int i = 0;i < v.size();i++){
		// check for i+1 since i starts from 0
		if(mfind(v,i+1) == -1){
			// value is not found
			return false;
		}
	}
	// all values were found
	return true;
}

// function get_row
// takes in input:
// - a row index r
// - a one dimensional vector 'in' representing a sudoku
// provides in output:
// - a vector out containing the r-th row of in
// for example:
// r: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 2 3 4
// r: 3; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 9 4 1 -7
// note that this function must (meaningfully) use function twod_to_oned
void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
	// write your code here

	// get dimension of sudoku 
	int side = std::sqrt(in.size());
	// insert corresposding values in out vector
	for(int i = 0;i < side;i++){
		out.push_back(in[twod_to_oned(r,i,side)]);
	}

}

// function get_col
// like get_row but for columns
// for example: 
// c: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 4 4 9
// note that this function must (meaningfully) use function twod_to_oned
void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
	// write your code here

	// get dimension of sudoku 
	int side = std::sqrt(in.size());
	// insert corresposding values in out vector
	for(int i = 0;i < side;i++){
		out.push_back(in[twod_to_oned(i,c,side)]);
	}
}

// function get_subsq
// like the two functions above but for subsquares
// we consider subsquares to be indexed from left to right
// and then from top to bottom 
// for example:
// subs: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 2 4 1
// subs: 1; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 3 4 2 76
// subs: 2; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 4 4 9 4
// subs: 3; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 4 1 1 -7
// note that this function must (meaningfully) use function twod_to_oned
void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){
	// write your code here

	// get dimension of sudoku 
	int side = std::sqrt(in.size());
	int sub_len = std::sqrt(side);
	int start_row = (subs/sub_len)*sub_len;
	int start_col = (subs%sub_len)*sub_len;
	// ****REMOVE*****
	std::cout << "subsq " << subs << "(" << start_row << start_col << "):" << std::endl;
	// ****REMOVE*****
	for(int r = start_row;r < (start_row+sub_len);r++){
		for(int c = start_col;c < (start_col+sub_len);c++){
			// ****REMOVE*****
			std::cout << in[twod_to_oned(r,c,side)] << " ";
			// ****REMOVE*****
			out.push_back(in[twod_to_oned(r,c,side)]);
		}
		// ****REMOVE*****
		std::cout << std::endl;
		// ****REMOVE*****
	}
}


// function valid_sudoku 
// takes in input:
// - a one dimensional vector representing a sudoku
// returns:
// - a boolean which is true if the sudoku is valid and false if it isn't valid

// write your code where indicated
// i.e. within the two remaining incomplete 'for' loops
// do not alter anything else

bool valid_sudoku(const std::vector<int>& sg){
	int side = std::sqrt(sg.size()); 
	std::vector<int> seq;

	// for each row...
	for(int i = 0; i < side; i++){
		seq.clear();
		get_row(i, sg, seq);
		
		if(!check_sequence(seq)){ 
			// ****REMOVE*****
			std::cout << "row " << i << " bad" << std::endl;
			// ****REMOVE*****
			return false;
		}
		// ****REMOVE*****
		std::cout << "row " << i << " ok!" << std::endl;
		// ****REMOVE*****
	}
	
	// for each column...
	for(int i = 0; i < side; i++){
		// write your code here

		seq.clear();
		get_col(i, sg, seq);
		
		if(!check_sequence(seq)){ 
			// ****REMOVE*****
			std::cout << "col " << i << " bad" << std::endl;
			// ****REMOVE*****
			return false;
		}
		// ****REMOVE*****
		std::cout << "col " << i << " ok!" << std::endl;
		// ****REMOVE*****
	}
	
	// for each subsquare...
   for(int i = 0; i < side; i++){
		// write your code here

		seq.clear();
		get_subsq(i, sg, seq);
		
		if(!check_sequence(seq)){ 
			// ****REMOVE*****
			std::cout << "subsq " << i << " bad" << std::endl;
			// ****REMOVE*****
			return false;
		}
		// ****REMOVE*****
		std::cout << "subsq " << i << " ok!" << std::endl;
		// ****REMOVE*****
	}

	// if the program execution gets to here it means that 
	// it hasn't executed a "return false" above
	// so the sudoku is valid:
	
	return true;
}

// do not alter the main

int main(){
	
	std::vector<int> s;
		
	// beginning of block of code reading the sudoku from the text file
	std::string filename;
	
	std::cout << "please enter name of file containing the sudoku" << std::endl;
	std::cin >> filename;
	
	std::ifstream infile;
	infile.open(filename);
	
	if(!infile.is_open()){
		std::cout << "error, can't open input file" << std::endl;
		return EXIT_FAILURE;
	}
	
	int tmp;
	
	while(infile >> tmp){
		s.push_back(tmp);
	}
	// end of block of code reading the sudoku from the text file
	// we now have the content of the sudoku in vector s
		
	int side = std::sqrt(s.size());

	// ****REMOVE****
	std::cout << "Side lenght:" << side << std::endl;
	// ****REMOVE****

	// assuming it is a valid square grid in terms of size
	// (if it isn't, the program will not work properly, which is expected)
	
	// printing the content of the sudoku (as a square);
	// the sudoku is stored as a one-dimensional vector
	// but the vector can be indexed using two indices
	// by converting the indices of a two dimensional representation
	// into the corresponding one-dimensional index (using our function twod_to_oned)
	
	for(int i = 0; i < side; i++){
		for(int j = 0; j < side; j++){
			std::cout << s[twod_to_oned(i,j,side)] << " ";
		}
		std::cout << std::endl;
	}
	
	// calling the function checking if the sudoku is a valid one:
	
	bool valid = valid_sudoku(s);
	
	if(valid){
		std::cout << "valid" << std::endl;
	}
	else{
		std::cout << "not valid" << std::endl; 
	}
	
}