/**
 *   author: Shubham Srivastava
 *   created: 25 March 2019  17:54:12
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
vector <int> a(100005),t(100005);

void build(int v, int tl, int tr)
{
	if(tl == tr)
		t[v] = a[tl];
	else
	{
		int tm;
		tm = (tl+tr)/2;
		build(v*2, tl,tm);
		build(v*2+1, tm+1,tr);
		t[v] = t[2*v] + t[2*v+1];
	}
}

int sum(int v, int tl, int tr, int l, int r)
{
	if(l<0 || r>(n-1) || l>r)
		return -1;
	if(l<=tl && r>=tr)
		return t[v];
	if(tr<l || tl>r)
		return 0;
	int mid = tl+(tr-tl)/2;
	return sum(2*v,tl,mid,l,r)+sum(2*v+1,mid+1,tr,l,r);
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
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    build(1, 0, n-1);
    for(int i=0;i<20;i++)
    	cout<<t[i]<<"  ";
    cout<<endl;
    int q;cin>>q;
	while(q--)
	{
		int l,r;cin>>l>>r;
		cout<<sum(1,0,n-1,l,r)<<endl;
	}
	int pos,value;cin>>pos>>value;
	update(1,0,n-1,pos,value);
	int que;cin>>que;
	while(que--)
	{
		int l,r;cin>>l>>r;
		cout<<sum(1,0,n-1,l,r)<<endl;
	}
return 0;
}