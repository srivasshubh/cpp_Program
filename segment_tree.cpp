/**
 *   author: Shubham Srivastava
 *   created: 09 February 2019  01:22:18
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int t[100] = {0};

void build(int a[], int v, int tl, int tr)
{
	if(tl == tr)
		t[v] = a[tl];
	else
	{
		int tm;
		tm = (tl+tr)/2;
		build(a, v*2, tl,tm);
		build(a, v*2+1, tm+1,tr);
		t[v] = t[2*v] + t[2*v+1];
	}
}

int sum(int v, int tl, int tr, int l, int r)
{
	if(l > r)
		return 0;
	else if(l == tl && r == tr)
		return t[v];
	else{
		int tm = (tl + tr)/2;
		return sum(2*v, tl, tm, l, min(r,tm)) + sum(2*v+1, tm+1, tr, min(l,tm+1),r);
	}
}

void update(int v, int tl, int tr, int pos, int new_val)
{
	if(tl == tr)
		t[v] = new_val;
	else{
		int tm = (tl+tr)/2;
		if(pos <= tm)
			update(2*v, tl, tm, pos, new_val);
		else
			update(2*v+1, tm+1, tr, pos, new_val);
		t[v] = t[2*v] + t[2*v+1];
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    	cin>>a[i];
    build(a, 0, 0, n-1);
    for(int i=0;i<4*n;i++)
    	cout<<a[i]<<" ";

return 0;
}