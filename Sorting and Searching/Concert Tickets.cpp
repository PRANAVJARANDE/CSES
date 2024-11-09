#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n,m;cin>>n>>m;
    multiset<ll> s1;
    for(int i=0;i<n;i++)
    {
        ll x;cin>>x;
        s1.insert(x);
    }

    for(int i=0;i<m;i++)
    {
        int j;cin>>j;
        if(s1.empty())
        {
            cout<<"-1"<<endl;
            continue;
        }
        int mini=*s1.begin();
        if(j<mini)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            auto it=s1.upper_bound(j);
            it--;
            cout<<(*it)<<endl;
            s1.erase(it);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
