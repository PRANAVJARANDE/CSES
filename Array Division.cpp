#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

bool che(vector<ll>&a,ll mid,ll k)
{
    ll c=0;
    ll ps=0;
    for(int i=0;i<(int)a.size();i++)
    {
        if(a[i]>mid)return 0;
        if(ps+a[i]<=mid)
        {
            ps+=a[i];
        }
        else
        {
            c++;
            ps=a[i];
        }
    }
    if(ps>0)c++;
    if(c>k)return 0;
    return 1;
}

void solve()
{
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    ll l=0,r=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        r+=a[i];
    }
    
    ll ans=0;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(che(a,mid,k))
        {
            ans=mid;
            r=mid-1;
        } 
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
