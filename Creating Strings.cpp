#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int n;
void helper(int in,string &s,set<string>&v1)
{
    if(in==n-1)
    {
        v1.insert(s);
        return;
    }
    for(int i=in;i<n;i++)
    {
        swap(s[in],s[i]);
        helper(in+1,s,v1);
        swap(s[in],s[i]);
    }
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    string s;cin>>s;
    n=s.size();
    set<string>v1;
    helper(0,s,v1);
    cout<<(int)v1.size()<<endl;
    for(auto x: v1)
    {
        cout<<x<<endl;
    }
    return 0;
}
