#include<bits/stdc++.h>
using namespace std;
void optimise()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    optimise();
    long long n;
    cin>>n;
    vector <long long> s(n),p(n);
    vector < pair < long long, long long> > v;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>p[j];
        v.push_back(make_pair(s[j],p[j]));
    }
    sort(v.begin(),v.end());
    long long query;
    cin>>query;
    while(query--)
    {
        long long q;
        cin>>q;
        if(q <= v[0].first)
            cout<<v[0].second<<"\n";
        else if(q >= v[n-1].first)
            cout<<v[n-1].second<<"\n";
        else{
        long long lower,upper,mid;
        lower = 0;
        upper = n-1;
        while(lower<=upper)
        {
            mid = (lower + upper)/2;
            if(v[mid].first == q)
            {
                break;
            }
            else if(v[mid].first > q && v[mid-1].first <= q)
            {
                mid = mid-1;
                break;
            }
            else if(v[mid].first <= q && v[mid+1].first > q)
            {
                break;
            }
            else if(v[mid].first < q)
            {
                lower = mid+1;
            }
            else if(v[mid].first > q)
            {
                upper = mid-1;
            }
        } 
        cout<<v[mid].second<<"\n";}
    }
}