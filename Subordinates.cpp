#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long


int helper(int in,vector<vector<int>>&adj,vector<int>&dp)
{
    if(dp[in]!=-1)return dp[in];
    int ans=adj[in].size();
    for(int x: adj[in])
    {
        ans+=helper(x,adj,dp);
    }
    return dp[in]=ans;
}

void solve()
{
    int n;cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int a;cin>>a;
        adj[a].push_back(i);
    }
    vector<int> dp(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        cout<<helper(i,adj,dp)<<" ";
    }
    cout<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
