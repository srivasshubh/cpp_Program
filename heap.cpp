/**
 *   author: Shubham Srivastava
 *   created: 03 March 2019  16:31:02
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void heapify(int arr[],int i,int n)
{
	int left,right;
	left = 2*i+1;
	right = 2*i+2;
	int largest = i;
	if(left <n && arr[left] > arr[largest])
		largest = left;
	if(right <n && arr[right] > arr[largest])
		largest = right;
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,largest,n);
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int j=n/2-1;j>=0;j--)
    {
    	heapify(arr,j,n);
    }
    for(int i=n-1;i>=0;i--)
    {
    	swap(arr[i],arr[0]);
    	heapify(arr,0,i);
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
return 0;
}