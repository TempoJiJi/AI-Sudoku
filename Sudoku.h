#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Sudoku{
	public:
		bool check(int n);
		void ReadIn();
		void answer(int n);
		void Solve();
		void place_dark();
		void place_num();
		void take_num();
		void GiveQuestion();
	private:
		int count;
		int map[12][12];
		int sudoku[12][12];
		bool rand_check[10];
};
