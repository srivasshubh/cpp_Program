#include<bits/stdc++.h>
using namespace std;
int uni(int v, int n, int parent[])
{
	if(v==parent[v])
	{
		return v;
	}
	return uni(parent[v],n,parent);
}
int main()
{
	int n,e;
	cin>>n>>e;
	pair <int,pair<int,int> > arr[e];
	for(int i=0;i<e;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		arr[i] = make_pair(w,make_pair(a,b));
	}
	sort(arr,arr+e);
	int parent[n+1];
	for(int i=0;i<=n;i++)
	{
		parent[i] = i;
	}
	int count=0,j=0,max=0;
	while(count!=(n-1))
	{
		int a1,a2;
		a1 = uni(arr[j].second.first,n,parent);
		a2 = uni(arr[j].second.second,n,parent);
		if(a1!=a2)
		{
			count++;
			cout<<arr[j].second.first<<"   "<<arr[j].second.second<<endl;
			parent[a1] = a2;
			max = max + arr[j].first;
		}
		j++;
	}
	cout<<max;
}
