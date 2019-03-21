#include<bits/stdc++.h>
using namespace std;
void optimise()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
	//optimise();
	long long t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long n;
		cin>>n;
		int arr[n];
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum = sum + arr[i];
		}
		long long count2=0,count1=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i] == 1)
				break;
			count1++;
		}
		for(int j=n-1;j>=0;j--)
		{
			if(arr[j]==1)
				break;
			count2++;
		}
		cout<<sum-min(count2,count1)<<"\n";
	}
}