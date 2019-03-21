/**
 *   author: Shubham Srivastava
 *   created: 26 January 2019  20:20:37
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *start = NULL;
void insertnodeatbeg()
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	int n;
	cout<<"Enter a number to insert at beg\n";
	cin>>n;
	temp->data = n;
	temp->next = start;
	start = temp;
}

void insertnodeatend()
{
	struct Node *temp, *ptr;
	temp = (struct Node *)malloc(sizeof(struct Node));
	int n;
	cout<<"Enter a number to insert at end\n";
	cin>>n;
	ptr = start;
	temp->data = n;
	temp->next = NULL;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}

void insertnodeafter()
{
	struct Node *temp, *ptr, nextptr;
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter a number to be inserted\n");
	int n,d;
	cin>>n;
	cout<<"Enter a value after which number is inserted\n";
	cin>>d;
	ptr = start;
	temp->data = n;
	while(ptr->data != d)
	{
		ptr = ptr->next;
	}
	temp->next = ptr->next;
	ptr->next = temp;
}

void insertnodebefore()
{
	struct Node *temp, *ptr, *prevptr;
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter a number to be inserted\n");
	int n,d;
	cin>>n;
	cout<<"Enter a value before which number is inserted\n";
	cin>>d;
	temp->data = n;
	ptr = start;
	bool flag = false;
	while(ptr->data != d)
	{
		prevptr = ptr;
		ptr = ptr->next;
		flag = true;
	}
	if(flag == true)
	{
		prevptr->next = temp;
		temp->next = ptr;
	}
	else
	{
		temp->next = start;
		start = temp;
	}
}

void printlist()
{
	struct Node *temp;
	temp = start;
	cout<<"Result : ";
	while(temp != NULL)
	{
		cout<<temp->data<<"  ";
		temp = temp->next;
	}
	cout<<endl;
}

void deleteatbeg()
{
	cout<<"in\n";
	struct Node *temp;
	temp = start;
	start = start->next;
	free(temp);
}

void deleteatend()
{
	struct Node *temp,*ptr;
	ptr = start;
	while(ptr->next != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
	}
	temp->next = NULL;
	free(ptr);
}

void deletenode()
{
	struct Node  *ptr, *prevptr;
	cout<<"Enter a number for deletion\n";
	int n;
	cin>>n;
	ptr = start;
	while(ptr->data != n)
	{
		prevptr = ptr;
		ptr = ptr->next;
	}
	prevptr->next = ptr->next;
	free(ptr);
}

void reverselist()
{
	struct Node *prev=NULL, *curr, *next=NULL;
	curr = start;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	start = prev;
}

int main(){
    int n,e;
    cout<<"Enter the number you want in beginning of link list\n";
    cin>>n;
    for(int i=0;i<n;i++){
    	insertnodeatbeg();
    	printlist();
    }
    cout<<"Enter the number you want at end of link list\n";
    cin>>e;
    for(int j=0;j<e;j++){
    	insertnodeatend();
    	printlist();
    }
    insertnodeafter();
    printlist();
    insertnodebefore();
    printlist();
    insertnodeafter();
    printlist();
    insertnodebefore();
    printlist();
    reverselist();
    printlist();
    deleteatbeg();
    printlist();
    deleteatend();
    printlist();
    deleteatbeg();
    printlist();
    deleteatend();
    printlist();
    deletenode();
    printlist();
    reverselist();
    printlist();
return 0;
}