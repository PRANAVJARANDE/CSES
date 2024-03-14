#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    ll n,x;cin>>n>>x;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<ll>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0)
            {
                dp[i]=min(dp[i],1+dp[i-a[j]]);
            }
        }
    }

    if(dp[x]==INT_MAX)cout<<"-1"<<endl;
    else cout<<dp[x]<<endl;
    return 0;
}
  
