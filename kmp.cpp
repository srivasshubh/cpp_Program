/**
 *   author: Shubham Srivastava
 *   created: 28 February 2019  01:46:47
**/

//https://practice.geeksforgeeks.org/problems/implement-strstr/1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int arr[s2.length()+1];
    arr[0] = 0;
    int len = 0;
    int i = 1;
    while(i < s2.length())
    {
    	if(s2[i] == s2[len])
    	{
    		len++;
    		arr[i] = len;
    		i++;
    	}
    	else{
    		if(len != 0)
    		{
    			len = arr[len-1];
    		}
    		else
    		{
    			arr[i] = len;
    			i++;
    		}
    	}
    }
    for(int i=0;i<s2.length();i++)
    	cout<<arr[i]<<" ";
    cout<<endl;
    int j=0;i=0;
    while(i < s1.length())
    {
    	if(s1[i] == s2[j])
    	{
    		i++;j++;
    	}
    	if(j == s2.length()){
    		cout<<"pattern found  "<<i-j<<endl;
    		break;
    	}
    	else
    	{
    		if(i < s1.length() && s1[i] != s2[j])
    			if(j!=0)
    				j = arr[j-1];
    			else
    				i++;
    	}
    }
return 0;
}