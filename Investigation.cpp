#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>dis;
struct Comparator {
    bool operator() (ll x, ll y) const {
        return dis[x] == dis[y] ? x < y : dis[x] < dis[y];
    }
};

int MOD=1e9+7;
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
    }
    
    set<ll,Comparator>q1;
    dis.resize(n,LLONG_MAX);
    vector<ll>cnt(n,0);
    vector<int>mini(n,INT_MAX);
    vector<int>maxi(n,INT_MIN);
    cnt[0]=1;
    dis[0]=0;
    mini[0]=0;
    maxi[0]=0;
    q1.insert(0);
    while(!q1.empty())
    {
        int u=*q1.begin();
        ll d=dis[u];
        q1.erase(q1.begin());

        for(auto x: adj[u])
        {
            int v=x[0];
            int w=x[1];
            if(dis[v]>=d+w)
            {
                if(dis[v]!=LLONG_MAX) q1.erase(v);
                if(dis[v]==d+w)
                {
                    cnt[v]=(cnt[v]+cnt[u])%MOD;
                    maxi[v]=max(maxi[v],maxi[u]+1);
                    mini[v]=min(mini[v],mini[u]+1);
                }
                if(dis[v]>d+w)
                {
                    dis[v]=d+w;
                    cnt[v]=cnt[u];
                    mini[v]=mini[u]+1;
                    maxi[v]=maxi[u]+1;
                }
                q1.insert(v);
            }
        }
    }
    cout<<dis[n-1]<<" "<<cnt[n-1]<<" "<<mini[n-1]<<" "<<maxi[n-1]<<endl;
    return 0;
}
