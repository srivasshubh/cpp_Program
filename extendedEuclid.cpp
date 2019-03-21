#include<iostream>
using namespace std;
int d,x,y;
void extendedEuclid(int a, int b)
{
	if(b==0)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		extendedEuclid(b,a%b);
		int temp;
		temp = x;
		x = y;
		y = temp - (a/b)*y;
		cout<<"x:"<<x<<endl;
		cout<<"y:"<<y<<endl;
		cout<<"temp:"<<temp<<endl;
		cout<<"A:"<<a<<endl;
		cout<<"B:"<<b<<endl;
	}
	cout<<endl;
}
int main()
{
	extendedEuclid(16,10);
	cout<<"GCD of 16 and 10 is: "<<d<<endl;
	cout<<"Coofecient of X and Y are :"<<x<<"and"<<y<<endl;
	return 0;
}
