#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<ll,ll> m;
    int l=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
        while(m.size()>k)
        {
            m[a[l]]--;
            if(m[a[l]]==0)
            {
                m.erase(a[l]);
            }
            l++;
        }
        ans+=i-l+1;
    }
    cout<<ans<<endl;

}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
