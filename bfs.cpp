#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	long long int n,e;
	cin>>n>>e;
	vector <int> nodes[e+1];
	for(int i=0;i<e;i++)
	{
		long long int a,b;
		cin>>a>>b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	bool check[e];
	for(int i=0;i<e;i++)
	{
		check[i] = false;
	}
	queue<int> q;
	long long int start;
	cin>>start;
	check[start] = true;
	q.push(start);
	while(!q.empty())
	{
		int front;
		front = q.front();
		cout<<front<<"   ";
		q.pop();
		for(vector<int>::iterator itr = nodes[front].begin(); itr!=nodes[front].end();++itr)
		{
			if(check[*itr]==false)
			{
			check[*itr] = true;
			q.push(*itr);
		    }
		}
	}
}
