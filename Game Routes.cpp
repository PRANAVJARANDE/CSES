#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int> indeg(n+1,0);
    for(int i=0;i<m;i++)
    {
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    
    ll ans=0;
    queue<ll> q1;
    vector<ll> dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q1.push(i);
        }
    }
    dp[1]=1;
    while(!q1.empty())
    {
        int k=q1.front();
        q1.pop();
        
        for(int v: adj[k])
        {
            dp[v]=(dp[v]+dp[k])%MOD;
            indeg[v]--;
            if(indeg[v]==0)
            {
                q1.push(v);
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
