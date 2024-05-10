#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    int n,m;cin>>n>>m;
    vector<vector<vector<ll>>>adj(n);
    for(int i=0;i<m;i++)
    {
        ll a,b,c;cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>q1;
    vector<int> vis(n,0);
    q1.push({0,0});
    ll ans=0;

    while(!q1.empty())
    {
        ll cs=q1.top()[0];
        ll u=q1.top()[1];
        q1.pop();
        if(vis[u]==1){
            continue;
        }
        vis[u]=1;
        ans+=cs;
        for(auto x: adj[u])
        {
            q1.push({x[1],x[0]});
        }
    }

    for(int x: vis)
    {
        if(x==0)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;


    return 0;
}
