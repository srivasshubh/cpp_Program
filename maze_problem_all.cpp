#include<iostream>
using namespace std;
void findpath(int maze[3][3],int n, int x, int y, int path[3][3])
{
	if(x<0 || x>n-1 || y<0 || y>n-1)
	{
		return;
	}
	if(maze[x][y]==0 || path[x][y]==1)
	{
		return;
	}
	if(x == n-1 && y == n-1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==(n-1) && j==(n-1))
				{
					cout<<"1 ";
				}
				else
				{
					cout<<path[i][j]<<"  ";
				}
			}
			cout<<"\n";
		}
		cout<<endl;
		return;
	}
	path[x][y]=1;
	//Left
	findpath(maze,n,x,y+1,path);
	//Right
	findpath(maze,n,x,y-1,path);
	//Down
	findpath(maze,n,x+1,y,path);
	//Up
	findpath(maze,n,x-1,y,path);
	path[x][y]=0; 
}
void checkpath(int maze[3][3], int n)
{
	int x=0,y=0;
	int path[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    findpath(maze,n,x,y,path);
    return;
}
int main()
{
	int n=3;
	int maze[3][3]={{1,1,1},{1,1,1},{1,1,1}};
	checkpath(maze, n);
}
