#include<bits/stdc++.h>
using namespace std;
long long int powersum(long long int x, long long int n, long long int p)
{
    if(pow(p,n)>x)
        return 0;
    else if(pow(p,n)==x)
        return 1;
    return powersum(x,n,p+1) + powersum(x-pow(p,n),n,p+1);
}
int main()
{
    long long int x,n,p=1,ans;
    cin>>x>>n;
    ans = powersum(x, n, p);
    cout<<ans;
}

