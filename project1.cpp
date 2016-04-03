#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"Sudoku.h"

using namespace std;

int main()
{
	Sudoku S;

	S.giveQuestion();
	printf("\n");
	S.readIn();
	S.solve();
	printf("\n");
	S.readIn();
	S.transform();

	return 0 ;
}

