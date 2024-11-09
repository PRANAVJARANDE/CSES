#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int helper(int in,int prev,vector<int>&a,int n,vector<vector<int>>&dp)
{
    if(in>=n)return  0;
    if(dp[in][prev]!=-1)return dp[in][prev];
    if(a[prev]<a[in])
    {
        int op2=1+helper(in+1,in,a,n,dp);
        int op1=helper(in+1,prev,a,n,dp);
        return dp[in][prev]=max(op1,op2);
    } 
    else
    {
        return dp[in][prev]=helper(in+1,prev,a,n,dp);
    }
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(int i=0;i<n;i++)
    {
        ans=max(ans,1+helper(i+1,i,a,n,dp));
    }
    cout<<ans<<endl;
    
    return 0;
}
