#include<bits/stdc++.h>
using namespace std;
long long int partition(long long int arr[], long long int start, long long int end)
{
	int pivot = arr[end];
	int pIndex = start;
	int temp1;
	for(int i=start;i<end;i++)
	{
		if(pivot >= arr[i])
		{
			temp1 = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp1;
			pIndex++;
		}
	}
	int temp;
	temp = arr[end];
	arr[end] = arr[pIndex];
	arr[pIndex] = temp;
    return pIndex;
}
void quicksort(long long int arr[], long long int start, long long int end)
{
	if(start < end)
	{
		long long int pIndex;
		pIndex = partition(arr, start, end);
		quicksort(arr, start, pIndex-1);
		quicksort(arr, pIndex+1, end);
	}
	return ;
}
int main()
{
	long long int n;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	quicksort(arr, 0, n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"   ";
	}
}
