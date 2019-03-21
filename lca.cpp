/**
 *   author: Shubham Srivastava
 *   created: 30 January 2019  03:02:46
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector <long long> node[100005];
vector< vector<long long> > parent(100005, vector<long long>(20, -1));
ll max_log;
ll height[100005];

void dfs(int s, int p)
{
	parent[s][0] = p;
	if(p+1)
		height[s] = height[p] + 1;
	for(int i=1;i<max_log;i++)
		if(parent[s][i-1]+1)
			parent[s][i] = parent[parent[s][i-1]][i-1];
	for(auto itr : node[s])
		if(p-itr)
			dfs(itr,s);
}

ll lca(ll v, ll u)
{
	if(height[v] < height[u])
		swap(v,u);
	for(int i=max_log-1;i>=0;i--)
	{
		if(parent[v][i]+1 && height[parent[v][i]] >= height[u])
			v = parent[v][i];
	}
	if(v == u)
		return  v;
	for(int i=max_log-1;i>=0;i--)
	{
		if(parent[v][i] - parent[u][i]){
			v = parent[v][i];
			u = parent[u][i];
		}
	}
	return parent[v][0];
}

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        long long a,b;
        cin>>a>>b;
        a--;b--;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    max_log = ceil(log2(n));
    dfs(0,-1);
    long long k1,ans;
    cin>>k1;
    long long query[k1+1];
    for(int i=0;i<k1;i++){
        cin>>query[i];
    }
    ans = query[0];
    for(int i=1;i<k1;i++){
        ans = lca(ans,query[i]);
    }
    cout<<ans;
return 0;
}