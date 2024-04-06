#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long
 
ll n,m;
vector<ll>a;
ll helper(int in,int prev,vector<vector<ll>>&dp)
{
    if(prev<=0 || prev>m)return 0;
    if(in>=n)return 1;
 
    if(dp[in][prev]!=-1)return dp[in][prev];
    if(a[in]==0)
    {
        ll op1=helper(in+1,prev+1,dp)%MOD;
        ll op2=helper(in+1,prev,dp)%MOD;
        ll op3=helper(in+1,prev-1,dp)%MOD;
        return dp[in][prev]=((op1%MOD)+(op2%MOD)+(op3%MOD))%MOD;
    }
    else
    {
        if(abs(prev-a[in])<=1)
            return dp[in][prev]=helper(in+1,a[in],dp)%MOD;
        else
            return dp[in][prev]=0;
    }
}
 
 
 
int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
 
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));
    if(a[0]==0)
    {
        ll ans=0;
        for(int i=1;i<=m;i++)
        {
            ans=(ans+helper(1,i,dp)%MOD)%MOD;    
        }
        cout<<ans<<endl;
    }
    else
    {
        ll ans=helper(1,a[0],dp);
        cout<<ans<<endl;
    }
    
    
    return 0;
}
