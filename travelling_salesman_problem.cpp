/**
 *   author: Shubham Srivastava
 *   created: 02 March 2019  00:38:07
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int dist[15][15];
int dp[1<<15][15];
int tsp(int mask, int pos, int n)
{
	int visited = ((1<<n)-1);
	if(visited == mask)
		return dist[pos][0];
	if(dp[mask][pos] != -1)
		return dp[mask][pos];
	int ans = INT_MAX,maxi;
	for(int i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)
		{
			maxi = dist[pos][i] + tsp(mask|(1<<i),i,n);
			ans = min(ans,maxi);
		}
	}
	return dp[mask][pos] = ans;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
    	int n;cin>>n;
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			cin>>dist[i][j];
    	for(int i=0;i<(1<<n);i++)
    		for(int j=0;j<n;j++)
    			dp[i][j] = -1;
    	cout<<tsp(1,0,n)<<endl;
    }
return 0;
}