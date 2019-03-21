/**
 *   author: Shubham Srivastava
 *   created: 06 February 2019  01:54:39
**/

//https://www.geeksforgeeks.org/Microsoft-topics-interview-preparation/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct Trie
{
    Trie *character[27];
    int isLeaf;
};

Trie *newnode()
{
    Trie *trie = new Trie();
    trie->isLeaf=false;
    for(int i=0;i<=26;i++)
        trie->character[i] = nullptr;
    return trie;
}
void insert(Trie *curr, string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(curr->character[(int)s[i]-97] == nullptr)
            curr->character[(int)s[i]-97] = newnode();
        curr = curr->character[(int)s[i]-97];
    }
    curr->isLeaf = true;
}

bool search(Trie *curr, string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(curr->character[(int)s[i]-97] != nullptr)
            curr = curr->character[(int)s[i]-97];
        else
            return 0;
    }
    return curr->isLeaf;
}
int main(){
    long long t;
    cin>>t;
    Trie* head = new Trie();
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1 == "add")
            insert(head,s2);
        else 
            cout<<search(head,s2)<<endl;
    }
return 0;
}