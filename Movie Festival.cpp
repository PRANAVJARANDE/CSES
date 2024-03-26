#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n;cin>>n;
    vector<vector<ll>> arr;
    for(int i=0;i<n;i++)
    {
        ll a,b;cin>>a>>b;
        arr.push_back({b,a});
    }
    sort(arr.begin(),arr.end());

    ll ans=1;
    ll maxi=arr[0][0];
    for(int i=1;i<n;i++)
    {
        if(arr[i][1]>=maxi)
        {
            ans++;
            maxi=arr[i][0];
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
