#include<iostream>
using namespace std;
int main()
{
	int num;
	cin>>num;
	bool arr[num];
	for(int a=2;a<num;a++)
	{
		arr[a] = true;
	}
	for(int i=2;i<num;i++)
	{
		if(arr[i] == true)
		{
		   for(int j=2*i;j<=num;j=j+i)
		   {
		    	arr[j] = false;
		   }
	    }
	    if(arr[i] == true)
	    {
	    	cout<<i<<"  ";
		}
	}
	return 0;
}
