#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> P;
bool visited[MAX];
vector <P> nodes[MAX];

long long int prim(long long int n)
{
	priority_queue <P, vector<P>, greater<P> > q;
	long long int y,min_cost;
	min_cost = 0;
	P p;
	q.push(make_pair(0,n));
	while(!q.empty()) 
	{
		p = q.top();
		q.pop();
		n = p.second;
		if(visited[n]==true)
		{
			continue;
		}
		min_cost += p.first;
		visited[n] = true;
		for(int i=0;i<nodes[n].size();++i)
		{
			y = nodes[n][i].second;
			if(visited[y]==false)
			{
				q.push(nodes[n][i]);
			}
		}
	}
	return min_cost;
}

int main()
{
	long long int n,e,min,t;
	cin>>n>>t>>e;
	for(int i=0;i<e;i++)
	{
		long long int a,b,w;
		cin>>a>>b>>w;
		nodes[a].push_back(make_pair(w,b));
		nodes[b].push_back(make_pair(w,a));
	}
	int start;
	cin>>start;
	min = prim(start);
	cout<<min;
}
