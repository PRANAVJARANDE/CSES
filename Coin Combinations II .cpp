#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n,x;cin>>n>>x;
    vector<int> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i][j]=dp[i-1][j];
            ll ind=j-a[i-1];
            if(ind>=0)
            {
                (dp[i][j]+=dp[i][ind])%=MOD;
            }
        }
    }
    cout<<dp[n][x]<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
