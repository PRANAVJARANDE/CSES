#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    map<ll,ll> m;
    ll s=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        m[s]++;
        s+=a[i];
        ans+=m[s-x];
    }
    cout<<ans<<endl;
    return 0;
}
