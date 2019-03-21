#include<bits/stdc++.h>
using namespace std;
int cunt=0;
void optimise()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void permute(string s, string choosen)
{
	if(s.empty()){
		cout<<choosen<<"\n";
		return;
	}
	else
	{
		for(int i=0;i<s.length();i++)
		{
			char c = s[i];
			choosen += c;
			s.erase(i,1);
			permute(s,choosen);
			s.insert(i,1,c);
			choosen.erase(choosen.length()-1,1);
		}
	}
}
int main()
{
 	string s;
 	cin>>s;
 	permute(s,"");
 	cout<<cunt<<"\n";
 }