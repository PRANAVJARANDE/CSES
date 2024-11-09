#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    vector<vector<ll>>a(n,vector<ll>(2,0));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    sort(a.begin(),a.end());
    ll ans=0;
    ll psum=0;
    for(int i=0;i<n;i++)
    {
        psum+=a[i][0];
        ans+=a[i][1]-psum;
    }
    cout<<ans<<endl;
    return 0;
}
