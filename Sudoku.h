#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

class Sudoku
{
	private:
		int i , j , k , l , an , bn , cn , dn;
		int input[9][9] , input2[9][9];
	public:
		void giveQuestion();
		void readIn();
		int avail( int row, int col, int num);
		int avail2( int row, int col, int num);
		int avail3( int row, int col, int num);
		int fill( int row, int col);
		int fill2( int row, int col);
		int fill3( int row, int col);
		void solve();
		void changeNum(int a , int b);
		void changeRow(int a , int b);
		void changeCol(int a , int b);
		void rotate(int n);
		void flip(int n);
		void transform();
};