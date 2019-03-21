#include<iostream>
using namespace std;
void bfs(x, y, visited[][], n, m, mat[][], des_x, des_y)
{
	if(x>=n || y>=m)
	{
		return false;
	}
	if(x<0 || y<0)
	{
		return false;
	}
	if(visited[x][y] == true)
	{
		return false;
	}
	if(mat[x][y] == 'X')
	{
		return false;
	}
	if(x== des_x && y==des_y)
	{
		return true;
	}
	if(bfs(x+1,y,visited,n,m,mat,des_x,des_y) == true)
	{
		cout<<x<<y<<endl;
		return true;
	}
	if(bfs(x-1,y,visited,n,m,mat,des_x,des_y) == true)
	{
		cout<<x<<y<<endl;
		return true;
	}
	if(bfs(x,y+1,visited,n,m,mat,des_x,des_y) == true)
	{
		cout<<x<<y<<endl;
		return true;
	}
	if(bfs(x,y-1,visited,n,m,mat,des_x,des_y) == true)
	{
		cout<<x<<y<<endl;
		return true;
	}
	return false;
}
int main()
{
	int x,y,n,m,des_x,des_y;
	int mat[n][m];
	bool visited[n][m];
	cin>>x>>y>>n>>m>>des_x>>des_y;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
			visited[i][j] = false;
		}
	}
	bfs(x,y,visited,n,m,mat,des_x,des_y)
	return 0;
}
