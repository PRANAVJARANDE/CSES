#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n,m,k;cin>>n>>m>>k;
    vector<vector<vector<ll>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q1;
    q1.push({0,1});
    vector<int> vis(n+1,0);
    vector<ll> dist(n+1,LLONG_MAX);
    vector<int> cnt(n+1,0);
    dist[1]=0;
    while(!q1.empty())
    {
        ll dist=q1.top().first;
        ll node=q1.top().second;
        q1.pop();

        cnt[node]++;

        if(vis[node]==1)continue;
        if(node==n)
        {
            cout<<dist<<" ";
            if(cnt[n]==k)return;
        }

        if(cnt[node]<=k)
        {
            for(auto x: adj[node])
            {
                q1.push({dist+x[1],x[0]});
            }
        }
        
    }
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
