#include "validCheck.h"

int twod_to_oned(int row, int col, int rowlen){
	return row*rowlen+col;
}

int mfind(const std::vector<int>& v, int n){
// loop through vector comparing each value to n
	for(int i = 0;i < v.size();i++){
		if(v[i]==n){
			// value n is found inside the vector
			return i;
		}
	}
	return -1;
}

bool check_sequence(const std::vector<int>& v){
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

void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
	// get dimension of sudoku 
	int side = std::sqrt(in.size());
	// insert corresposding values in out vector
	for(int i = 0;i < side;i++){
		out.push_back(in[twod_to_oned(r,i,side)]);
	}

}

void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
	// write your code here

	// get dimension of sudoku 
	int side = std::sqrt(in.size());
	// insert corresposding values in out vector
	for(int i = 0;i < side;i++){
		out.push_back(in[twod_to_oned(i,c,side)]);
	}
}

void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){
	// write your code here

	// get dimension of sudoku 
	int side = std::sqrt(in.size());
	int sub_len = std::sqrt(side);
	int start_row = (subs/sub_len)*sub_len;
	int start_col = (subs%sub_len)*sub_len;
	for(int r = start_row;r < (start_row+sub_len);r++){
		for(int c = start_col;c < (start_col+sub_len);c++){
	
			out.push_back(in[twod_to_oned(r,c,side)]);
		}

	}
}

bool valid_sudoku(const std::vector<int>& sg){
	int side = std::sqrt(sg.size()); 
	std::vector<int> seq;

	// for each row...
	for(int i = 0; i < side; i++){
		seq.clear();
		get_row(i, sg, seq);
		
		if(!check_sequence(seq)){ 
	
			return false;
		}

	}
	
	// for each column...
	for(int i = 0; i < side; i++){
		// write your code here

		seq.clear();
		get_col(i, sg, seq);
		
		if(!check_sequence(seq)){ 
	
			return false;
		}

	}
	
	// for each subsquare...
   for(int i = 0; i < side; i++){
		// write your code here

		seq.clear();
		get_subsq(i, sg, seq);
		
		if(!check_sequence(seq)){ 
	
			return false;
		}

	}

	// if the program execution gets to here it means that 
	// it hasn't executed a "return false" above
	// so the sudoku is valid:
	
	return true;
}