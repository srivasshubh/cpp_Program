#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	for(int a=0;a<t;a++)
	{
		long long int n,m;
		cin>>n;
		vector <pair <long long int,long long int> > nodes[101];
		for(int i=0;i<n;i++)
		{
			long long int a,b;
			cin>>a>>b;
			nodes[a].push_back(make_pair(b,0));
		}
		cin>>m;
		int snake[m];
		for(int j=0;j<m;j++)
		{
			long long int c,d;
			cin>>c>>d;
			snake[j] = c; 
			nodes[c].push_back(make_pair(d,0));
		}
		long long int dist[101];
		for(int k=1;k<=100;k++)
		{
			dist[k] = INT_MAX;
			for(int l=1;l<=6;l++)
			{
				if(k+l>100)
				{
					break;
				}
				else
				{
					int flag=0;
					for(int i=0;i<m;i++)
					{
						if(snake[i]==k)
						{
							flag = 1;
							break;
						}
					}
					if(flag==0)
					{
						nodes[k].push_back(make_pair(k+l,1));
					}
				}
			}
		}
		priority_queue < pair<long long int,long long int>, vector<pair<long long int,long long int> >, greater<pair<long long int,long long int> > > que;
		long long int start = 1,q;
		dist[start] = 0;
		que.push(make_pair(0,start));
		while(!que.empty())
		{
			q = que.top().second;
			que.pop();
			for(int i=0;i<nodes[q].size();i++)
			{
				long long int l,weigth;
				weigth = nodes[q][i].second;
				l = nodes[q][i].first;
				if(dist[l] > dist[q] + weigth)
				{
					dist[l] = dist[q] + weigth;
					que.push(make_pair(dist[l],l));
				}
			}
		}
        if(dist[100]==INT_MAX)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<dist[100]<<endl;
        }
	}
}
