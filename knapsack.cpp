/**
 *   author: Shubham Srivastava
 *   created: 04 February 2019  02:16:07
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long n,sum;
    cin>>n>>sum;
    long long w[n],v[n];
    for(int i=0;i<n;i++)
    {
    	cin>>w[i]>>v[i];
    }

    long long dp[n+1][sum+1];

    for(int i=0;i<=n;i++)
    	for(int j=0;j<=sum;j++)
    		dp[i][j] = 0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=sum;j++)
    	{
    		if(j >= w[i-1])
    			dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
    		else
    			dp[i][j] = dp[i-1][j];
    	}
    }

    cout<<dp[n][sum];
return 0;
}