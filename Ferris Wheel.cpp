#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    multiset<ll> s1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s1.insert(a[i]);
    }
    ll ans=0;
    while(!s1.empty())
    {
        auto iot=s1.rbegin();
        ll e=*iot;
        ll rem=x-e;
        s1.erase(s1.find(e));
        auto it=s1.upper_bound(rem);
        if(it!=s1.begin())
        {
            it--;
            s1.erase(it);
        }
        ans++;
    }
    cout<<ans<<endl;

}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
