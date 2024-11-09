#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long
 
int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    map<ll,ll> m;
    ll ans=0;
    ll l=0;
    for(int i=0;i<n;i++)
    {
        l=max(l,m[a[i]]);
        ans=max(ans,i-l+1);
        m[a[i]]=i+1;
    }
    cout<<ans<<endl;
    return 0;
}
