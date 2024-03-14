#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<ll> dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0)
            {
                (dp[i]+=dp[i-a[j]]) %=MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
