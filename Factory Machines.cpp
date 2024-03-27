#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n,t;cin>>n>>t;
    vector<ll> a(n);
    ll mini=LLONG_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mini=min(mini,a[i]);
    }
    ll l=1,r=mini*t;
    ll fans=r;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        ll ans=0;
        for(ll x: a)
        {
            ll ta=mid/x;
            ans+=ta;
        }

        if(ans<t)
        {
            l=mid+1;
        }
        else
        {
            fans=mid;
            r=mid-1;
        }
    }
    cout<<fans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;    
    solve();
    return 0;
}
