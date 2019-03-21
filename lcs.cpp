/**
 *   author: Subodh Kumar Rai
 *   created: 04 February 2019  11:57:42
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll modInverse(ll a)
{
    ll n= 1000000007;
    ll tot = 1;
    ll pow = n-2;
    for(int i = 0; i < 31; i++){
    	if( (1<<i)&pow )
    		tot = (tot*a)%n;
    	a = (a*a)%n;
    }
    return tot;
}


void solve()
{
	long long n,m,k;
	cin>>n>>k>>m;
	bool flag=0;
	long long p,q,a,b;
	a=-1;
	b=-1;
	if(n>k && n%k!=0)
	{
		n = n%k;
		flag = 1;
	}
	else if(n%k==0)
	{
		if(n>k){
			n = k;
			flag = 1;
		}
	}
	long long s;
	if(!flag){
		p = floor((float)m/2)+1;
		q = p;
		p = 1 + (p-1)*2;
		if(p != (m))
		{
			long long temp1,temp2,i;
			a = 1;
			b = n;
			for(i=1;i<q-1;i++)
			{
				ll t = __gcd(a,b);
				a = a/t;
				b = b/t;
				temp2 = pow(n,i+1);
				temp1 = pow(n-1,i);
				a = a*temp2/b + temp1;
				b = temp2;
			}
			ll t = __gcd(a,b);
			a = a/t;
			b = b/t;
			temp1 = pow(n-1,i);
			temp2 = pow(n,(i))*(n+k);
			a = a*temp2/b + temp1;
			b = temp2;
		}
		else
		{
			//cout<<" l;"<<endl;
			long long temp1,temp2;
			a = 1;
			b = n;
			for(int i=1;i<q;i++)
			{
				ll t = __gcd(a,b);
				a = a/t;
				b = b/t;
				temp2 = pow(n,i+1);
				temp1 = pow(n-1,i);
				a = a*temp2/b + temp1;
				b = temp2;
			}
		}
	}
	if(flag)
	{
		m--;
		p = floor((float)m/2)+1;
		q = p;
		p = 2 + (p-1)*2;
		if(p != (m+1))
		{
			long long temp1,temp2,i;
			a = 1;
			b = n;
			for(i=1;i<q-1;i++)
			{
				ll t = __gcd(a,b);
				a = a/t;
				b = b/t;
				temp2 = pow(n,i+1);
				temp1 = pow(n-1,i);
				a = a*temp2/b + temp1;
				b = temp2;
			}
			ll t = __gcd(a,b);
			a = a/t;
			b = b/t;
			temp1 = pow(n-1,i);
			temp2 = pow(n,(i))*(n+k);
			a = a*temp2/b + temp1;
			b = temp2;
		}
		else
		{
			long long temp1,temp2;
			a = 1;
			b = n;
			
		}
	}
	ll t = __gcd(a,b);
	a = a/t;
	b = b/t;
	cout<<(a*modInverse(b))%mod;
}

int main(){
    long long t;
    cin>>t;
    while(t--)
    {
    	solve();
    	cout<<endl;
    }
return 0;
}