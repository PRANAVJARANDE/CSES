#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n;cin>>n;
    vector<ll> a(n);
    ll maxi=LLONG_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    if(maxi<0)
    {
        cout<<maxi<<endl;
        return;
    }
    ll s=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        s+=a[i];
        if(s<0)s=0;
        ans=max(ans,s);
    }
    cout<<ans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
