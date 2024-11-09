#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long
 
void solve()
{
    ll n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
 
    ll ans=0;
    vector<ll> m(n,0);
    ll s=0;
    for(int i=0;i<n;i++)
    {
        s+=a[i];
        ans+=m[(s%n+n)%n];
        m[(s%n+n)%n]++;
    }
    ans+=m[0];
    cout<<ans<<endl;
}
 
 
int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
