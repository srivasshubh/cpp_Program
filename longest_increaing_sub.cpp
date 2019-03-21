/**
 *   author: Shubham Srivastava
 *   created: 30 January 2019  16:33:13
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    int n;cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector <int> dp(n,1);
    vector <int> parent(n,-1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && dp[i] < (dp[j]+1))
            {
                dp[i] = dp[j]+1;
                parent[i] = j;
            }
        }
    }
    int maxi = dp[0]; int pos;
    for(int l=1;l<n;l++)
        if(maxi < dp[l]){
        	maxi = dp[l];
        	pos = l;
        }
    cout<<maxi<<endl;
    vector <int> ans;
    while(pos != -1)
    {
    	ans.push_back(arr[pos]);
    	pos = parent[pos];
    }
    for(auto i : ans)
    	cout<<i<<"   ";
return 0;
}