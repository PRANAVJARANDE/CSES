#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long


void solve()
{
    ll n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    vector<int> ans;
    int in=0;
    int kills=0;
    while(kills<n)
    {
        in=(in+1)%n;
        in=a[in]=a[a[in]];

        ans.push_back(in+1);
        a[in]=a[a[(in+1)%n]];
        kills++;

        in=(in+1)%n;
        in=a[in]=a[a[in]];
        
    }
    for(int x: ans)
    {
        cout<<x<<" ";
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
