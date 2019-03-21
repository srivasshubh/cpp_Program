#include<iostream>
using namespace std;
bool checkrow(int board[4][4],int row,int num)
{
	for(int j=0;j<4;j++)
	{
		if(board[row][j]==num)
		{
			return false;
		}
	}
	return true;
}
bool checkcol(int board[4][4],int col, int num)
{
	for(int i=0;i<4;i++)
	{
		if(board[i][col]==num)
		{
			return false;
		}
	}
	return true;
}
bool checkbox(int board[4][4],int row,int col, int num)
{
	int rowStart,colStart;
	rowStart = row - row%2;
	colStart = col - col%2;
	for(int i=rowStart;i<rowStart+2;i++)
	{
		for(int j=colStart;j<colStart+2;j++)
		{
			if(board[i][j]==num)
			{
				return false;
			}
		}
	}
	return true;
}
bool number_place(int board[4][4],int row, int col, int num)
{
	if(!checkrow(board,row,num))
	{
		return false;
	}
	if(!checkcol(board,col,num))
	{
		return false;
	}
	if(!checkbox(board,row,col,num))
	{
		return false;
	}
	return true;
}
bool sudokosolver(int board[4][4])
{
	int row = -1;
	int col = -1;
	bool isboard = false;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(board[i][j]==0)
			{
				
				row = i;
				col = j;
				isboard = true;
				break;
			}
		}
		if(isboard)
		{
			break;
		}
	}
	if(!isboard)
	{
		return true;
	}
	for(int num=1;num<=4;num++)
	{
		if(number_place(board,row,col,num))
		{
			board[row][col] = num;
		    if(sudokosolver(board))
		    {
			   return true;
		    }
		    board[row][col] = 0;
		}
	}
	return false;	
}
int main()
{
	int n;
	cout<<"Enter the value of n for n*n board: \n";
	cin>>n;
	int board[4][4];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int num;
			cin>>num;
			board[i][j] = num;
		}
	}
	cout<<sudokosolver(board)<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<"   ";
		}
		cout<<endl;
	}
}
