#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<pair<int,int>> q1;
    q1.push({0,1});
    vector<int> dist(n+1,0);
    vector<int> prev(n+1,-1);
    
    bool bo=0;
    while(!q1.empty())
    {
        int node=q1.front().second;
        int k=q1.front().first;
        q1.pop();

        if(node==n)
        {
            bo=1;
            continue;
        }

        for(int x: adj[node])
        {
            if(dist[x]<k+1)
            {
                dist[x]=dist[node]+1;
                q1.push({dist[x],x});
                prev[x]=node;
            }
        }
    }

    if(bo==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<int> ans;
    int in=n;
    while(in!=1)
    {
        ans.push_back(in);
        in=prev[in];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout<<(int)ans.size()<<endl;
    for(int x: ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
