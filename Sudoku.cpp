#include"Sudoku.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>


using namespace std;

void Sudoku::giveQuestion()
{
	int boardboard[9][9] = 
	{
		{0,0,0,0,1,0,0,5,0},
		{6,0,0,0,0,0,8,0,0},
		{0,0,5,4,2,0,0,7,0},
		{0,0,7,6,0,0,0,0,3},
		{1,0,0,0,5,0,0,0,9},
		{3,0,0,0,0,7,4,0,0},
		{0,6,0,0,8,9,1,0,0},
		{0,0,3,0,0,0,0,0,5},
		{0,2,0,0,7,0,0,0,0}
	};
	
	for(i = 0 ; i < 9 ; i++)
	{
		for(j = 0 ; j < 9 ; j++)
		{
			printf("%d ",boardboard[i][j]);
		}
		printf("\n");
	}
}
void Sudoku::readIn()
{
	for( i = 0 ; i < 9 ; i++)
	{
		scanf("%d %d %d %d %d %d %d %d %d",&readboard[i][0],&readboard[i][1],&readboard[i][2],&readboard[i][3],&readboard[i][4],&readboard[i][5],&readboard[i][6],&readboard[i][7],&readboard[i][8]);	
	}

}
void Sudoku::solve()
{
	ansnum = 0;
	for(j = 0 ; j < 9 ; j++)
	{
		if(!checkRow(j))
		{
			printf("0\n");
			exit(1);
		}
		if(!checkCol(j))
		{
			printf("0\n");
			exit(1);
		}
		if(!checkCell(j+1))
		{
			printf("0\n");
			exit(1);
		}
	}
	recur();
	if(ansnum == 0)
	{
		printf("0\n");
		exit(1);
	}

	printf("1\n");	
	for( i = 0 ; i < 9 ; i++)
	{
		for( j = 0 ; j < 9 ; j++)
		{
			printf("%d ",answer[i][j]);
		}
		printf("\n");
	}

}
bool Sudoku::recur()
{
	int cell;
	int num;
	int col = 0;
	int row = 0;
	int a = 0;
    for(i = 0 ; i < 9 ; i++)
	{
		for(j = 0 ; j < 9 ; j++)
		{
			if(readboard[i][j] == 0)//check which unity is zero
			{	
				a = 1;
				col = i;
				row = j;
				cell = 3*(col/3)+(row/3)+1;
				i = 10;
				j = 10;
			}
		}
	}
	if(a == 0)
	{
		if(checkCol(8) && checkCell(9) && checkRow(8))
		{
			ansnum++;
			if(ansnum > 1)
			{
				printf("2\n");
				exit(1);
			}
			for(i = 0 ; i < 9 ; i++)
			{
				for(j = 0 ; j < 9 ; j++)
				{
					answer[i][j] = readboard[i][j];
				}
			}
		}		
		return false;
	}
	
	for(num = 1 ; num < 10 ; num++)
	{
		if(checkall(col,row,cell,num))//check if there are the same num in the col row cell 
		{			
			readboard[col][row] = num;
	  		if(recur())
			{
				return true;
			}
			else
			{   
				readboard[col][row] = 0;
			}
		}
	}
	return false;
}
void Sudoku::changeNum(int a , int b)
{
	for(i = 0 ; i < 9 ; i++)
	{
		for(j = 0 ; j < 9 ; j++)
		{
			if(readboard[i][j] == a)
			{
				readboard[i][j] = b;
			}
			else if(readboard[i][j] == b)
			{
				readboard[i][j] = a;
			}
		}
	}
}
void Sudoku::changeCol(int a , int b)
{
	int temp[9][3];
	int row = 0;
	int t = 3*a;
	int m = 3*b;
	for(m ; m < 3*b+3 ; m++)
	{
		for(i = 0 ; i < 9 ; i++)
		{
			temp[i][row] = readboard[i][t];
			readboard[i][t] = readboard[i][m];
			readboard[i][m] = temp[i][row];
		}
		t++;
		row++;
	}
}
void Sudoku::changeRow(int a , int b)
{
	int col  = 0;
	int temp[3][9];
	int t = 3*a;
	int m = 3*b;
	
	for(m ; m < 3*b+3 ; m++)
	{
		for(i = 0 ; i < 9 ; i++)
		{
			temp[col][i] = readboard[t][i];
			readboard[t][i] = readboard[m][i];
			readboard[m][i] = temp[col][i];
		}
		t++;
		col++;
	}

}
void Sudoku::rotate(int n)
{
	int temp[9][9];
	for(i = 0 ; i < 9 ; i++)
	{
		for(j = 0 ; j < 9 ; j++)
		{
			temp[i][j] = readboard[i][j];
		}
	}
	if(n%4 == 1)
	{
		for(i = 0 ; i < 9 ; i++)
		{
			for(j = 0 ; j < 9 ; j++)
			{
				readboard[i][j] = temp[8-j][i];
			}
		}
		return;
	}

	if(n%4 == 2)
	{
		for(i = 0 ; i < 9 ; i++)
		{
			for(j = 0 ; j < 9 ; j++)
			{
				readboard[i][j] = temp[8-i][8-j];
			}
		}
		return;
	}

	if(n%4 == 3)
	{
		for(i = 0 ; i < 9 ; i++)
		{
			for(j = 0 ; j < 9 ; j++)
			{
				readboard[i][j] = temp[j][8-i];
			}
		}
		return;
	}
}
void Sudoku::flip(int n)
{
	int temp[9][9];

	for(i = 0 ; i < 9 ; i ++)
	{
		for(j = 0 ; j < 9 ; j ++)
		{
			temp[i][j] = readboard[i][j];
		}
	}
	if(n == 0)
	{
		for(i = 0 ; i < 9 ; i++)
		{
			for(j = 0 ; j < 9 ; j++)
			{
				readboard[i][j] = temp[8-i][j];
			}
		}
		return;
	}

	if(n == 1)
	{
		for(i = 0 ; i < 9 ; i++)
		{
			for(j = 0 ; j < 9 ; j++)
			{
				readboard[i][j] = temp[i][8-j];
			}
		}
		return;
	}

}
void Sudoku::transform()
{
	change();
	print();

}
void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%3+1);
	flip(rand()%2);
}


void Sudoku::print()
{
	for(i = 0 ; i < 9 ; i++)
	{
		for(j = 0 ; j < 9 ; j++)
		{
			printf("%d ",readboard[i][j]);
		}
		printf("\n");
	}
}
bool Sudoku::checkRow(int n)
{
	int check[9] = {0,0,0,0,0,0,0,0,0};	
	for(i = 0 ; i < 9 ; i++)
	{
		if(readboard[n][i] > 0)
		{
			check[readboard[n][i]-1]++;
			if(check[readboard[n][i]-1] != 1)
			{
				return false;
			}
		}
	}

	return true;
}


bool Sudoku::checkCol(int n)
{
	int check[9] = {0,0,0,0,0,0,0,0,0};
	for(i = 0 ; i <  9 ; i++)
	{
		if(readboard[i][n] > 0)
		{
			check[readboard[i][n]-1]++;
			if(check[readboard[i][n]-1] != 1)
			{
				return false;
			}
		}
	}
	return true;
}

bool Sudoku::checkCell(int n)
{
	int check[9] = {0,0,0,0,0,0,0,0,0};
	int col;
	int row;
	
	for(i = 0 ; i < 9 ; i++)
	{
		col = 3*((n-1)/3)+(i/3);
		row = (i%3)+3*((n-1)%3);
		if(readboard[col][row] > 0)
		{
			check[readboard[col][row]-1]++;
			if(check[readboard[col][row]-1] != 1)
			{
				return false;
			}
		}
	}
	return true;
}
int  Sudoku::checkall(int col , int row ,int cell,int num)
{
	int location;
	int c;
	int r;
	for(i = 0 ; i < 9 ; i++)
	{	
		c = 3*((cell-1)/3)+(i/3);
		r = (i%3)+3*((cell-1)%3);

		if((readboard[col][i] == num)||readboard[i][row] == num||readboard[c][r] == num)
		{
			return 0;
		}
	}
	return 1;
}







