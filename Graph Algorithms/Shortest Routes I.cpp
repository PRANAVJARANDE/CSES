#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n,e;cin>>n>>e;
    vector<vector<pair<ll,ll>>>adj(n+1);
    for(int i=0;i<e;i++)
    {
        ll a,b,c;cin>>a>>b>>c; 
        adj[a].push_back({b,c});
    }   

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q1;
    vector<ll>dist(n+1,LLONG_MAX);
    dist[1]=0;
    q1.push({0,1});

    while(!q1.empty())
    {
        ll in=q1.top().second;
        ll d=q1.top().first;
        q1.pop();

        if(d>dist[in])continue;
        for(auto x: adj[in])
        {
            if(dist[x.first]==LLONG_MAX || dist[x.first]>d+x.second)
            {
                dist[x.first]=d+x.second;
                q1.push({dist[x.first],x.first});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
