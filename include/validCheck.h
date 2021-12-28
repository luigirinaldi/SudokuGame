#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>

int twod_to_oned(int row, int col, int rowlen);
int mfind(const std::vector<int>& v, int n);
bool check_sequence(const std::vector<int>& v);
void get_row(int r, const std::vector<int>& in, std::vector<int>& out);
void get_col(int c, const std::vector<int>& in, std::vector<int>& out);
void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out);
bool valid_sudoku(const std::vector<int>& sg);