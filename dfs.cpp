#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	vector<int> v[1000];
	int edges,a,b;
	cout<<"Enter the number of edges\n";
	cin>>edges;
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int j=0;j<1000;j++){
		if(!v[j].empty()){
			cout<<"[ "<<j<<" ]"<<"-->";
			for(vector<int>::iterator it = v[j].begin();it!=v[j].end();++it){
				cout<<*it<<"-->";
			}
			cout<<endl;
		}
	}
	stack<int> s;
	bool visited[1000];
	for(int k=0;k<1000;k++){
		visited[k] = false;
	}
	int start;
	cout<<"Enter the starting node\n";
	cin>>start;
	s.push(start);
	visited[start] = true;
	while(!s.empty()){
		int front;
		front = s.top();
		cout<<front<<"  ";
		s.pop();
		for(vector<int>::iterator itr=v[front].begin();itr!=v[front].end();++itr){
			if(visited[*itr]==false){
				visited[*itr] = true;
				s.push(*itr);
			}
		}
	}
	return 0;
}
