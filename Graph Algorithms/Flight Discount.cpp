#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long


vector<ll> djk(int n,vector<vector<vector<ll>>>&adj,ll s)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q1;
    q1.push({0,s});
    vector<ll> dist(n+1,LLONG_MAX);
    dist[s]=0;
    
    while(!q1.empty())
    {
        ll dis=q1.top().first;
        ll node=q1.top().second;
        q1.pop();

        if(dis>dist[node])continue;
        for(auto x: adj[node])
        {
            if(dist[x[0]]==LLONG_MAX || dist[x[0]]>dist[node]+x[1])
            {
                dist[x[0]]=dist[node]+x[1];
                q1.push({dist[x[0]],x[0]});
            }
        }
    }
    return dist;
}


void solve()
{
    ll n,m;cin>>n>>m;
    vector<vector<vector<ll>>> adj(n+1),adj1(n+1);
    for(int i=0;i<m;i++)
    {
        ll a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj1[b].push_back({a,c});
    }

    ll ans=LLONG_MAX;
    vector<ll> a1=djk(n,adj,1);
    vector<ll> a2=djk(n,adj1,n);

    for(int i=1;i<=n;i++)
    {
        for(auto x: adj[i])
        {
            if(a1[i]!=LLONG_MAX && a2[x[0]]!=LLONG_MAX)
            {
                ll fr=a1[i]+a2[x[0]]+(x[1]/2);
                ans=min(ans,fr);
            }
        }
    }

    cout<<ans<<endl;
    
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
