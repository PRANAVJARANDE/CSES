#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n;cin>>n;
    vector<ll> a(n);
    ll s=0;
    ll maxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
        maxi=max(maxi,a[i]);
    }
    if(maxi>s-maxi) cout<<2*maxi<<endl;
    else cout<<s<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
