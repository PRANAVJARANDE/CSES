#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve() 
{
    ll n;cin>>n;
    vector<ll>dp(n+1,INT_MAX); 
    dp[0]=0;
    for (int i=1;i<=n;i++) 
    {
        string s=to_string(i);
        for(char ch:s) 
        {
            int rem=ch-'0';
            if(i-rem>=0)dp[i]=min(dp[i],1+dp[i-rem]); 
        }
    }
    cout<<dp[n]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    
    return 0;
}
