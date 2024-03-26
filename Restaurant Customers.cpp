#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n;cin>>n;
    vector<vector<ll>> a;
    for(int i=0;i<n;i++)
    {
        ll x,y;cin>>x>>y;
        a.push_back({x,1});
        a.push_back({y,-1});
    }
    ll ans=0;
    ll cnt=0;
    sort(a.begin(),a.end());
    for(auto x: a)
    {
        if(x[1]==1)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
