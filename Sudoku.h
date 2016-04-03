#include<iostream>
#include<cstdio>
#include<cstdlib>


using namespace std;
class Sudoku
{
	public:
		void giveQuestion();/*create your own Sudoku
						use '0' to represent the blanks
						any two digits are separated by a space*/

		void readIn();//read in Sudoku board

		void solve();
		bool recur1();
		bool recur();/*Judge if the board read in by 'readIn()' is solvable
				  then solve it ,and print it out
				  Unsolvable: output a single character'0'
				  Exactly one solution:output a single character '1' in the first line
				 					   and print it out*/  
		void changeNum(int a , int b);
		void changeCol(int a , int b);
		void changeRow(int a , int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void change();
		void print();
		bool checkRow(int n);
		bool checkCol(int n);
		bool checkCell(int n);
		int  checkall(int col ,int row ,int cell , int num);
	private:
		int board[9][9];	
		int readboard[9][9];
		int answer[9][9];
		int ansnum;
		int i;
		int j;
};

