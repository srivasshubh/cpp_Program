#include<iostream>
using namespace std;
void merging(int arr[],int l, int m, int h)
{
	int i,j,k=0;
	int temp[h-l+1];
	i = l;
	j = m + 1;
	while(i<=m && j<=h)
	{
		if(arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i<=m)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	while(j<=h)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	for(int i=l,t=0;i<=h;i++,t++)
	{
		arr[i] = temp[t];
	}
}
void mergesort(int l, int h, int arr[])
{
	int mid;
	if(l<h)
	{
		mid = (l+h)/2;
	    mergesort(l,mid,arr);
	    mergesort(mid+1,h,arr);
	    merging(arr,l,mid,h);
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergesort(0,n-1,arr);
	cout<<"Sorted Array\n";
	for(int q=0;q<n;q++)
	{
		cout<<arr[q]<<"   ";
	}
}
