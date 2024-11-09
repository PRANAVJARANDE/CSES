#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long


class dsu
{
public:
    int *parent;
    int *sz;
    int k;

    dsu(int x)
    {
        k=x;
        parent=new int[k];
        sz=new int[k];
        for(int i=0;i<k;i++)
        {
            parent[i]=i;
            sz[i]=1;
        }
    }

    int find_set(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        parent[x]=find_set(parent[x]);
        return parent[x];
    }

    void union_set(int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b)
        {
            return;
        }

        if(sz[a]>sz[b])
        {
            parent[b]=a;
            sz[a]=sz[a]+sz[b];
        }
        else
        {
            parent[a]=b;
            sz[b]=sz[b]+sz[a];
        }
    }
};


void solve()
{
    ll n,m;cin>>n>>m;
    vector<vector<ll>> adj;
    dsu d1(n);

    bool bb=0;
    ll ans;
    for(int i=0;i<m;i++)
    {
        ll a,b,c;cin>>a>>b>>c;
        a--;
        b--;
        if(a==b && c<0)
        {
            ans=a+1;
            bb=1;
        }
        d1.union_set(a,b);
        adj.push_back({a,b,c});
    }

    


    if(bb==1)
    {
        cout<<"YES"<<endl;
        cout<<ans<<" "<<ans<<endl;
        return;
    }

    vector<ll> dist(n,LONG_MAX);
    vector<ll> prev(n,-1);
    ll src=adj[0][0];
    ll par=d1.find_set(src);
    dist[src]=0;
    
    for(int i=0;i<n;i++)
    {
        if(d1.find_set(i)!=d1.find_set(src))dist[d1.find_set(i)]=0;
    }

    ll till=-1;
    for(int i=0;i<n;i++)
    {
        till=-1;
        for(auto x: adj)
        {
            if(dist[x[0]]==LONG_MAX)continue;
            if(dist[x[1]]>dist[x[0]]+x[2])
            {
                dist[x[1]]=dist[x[0]]+x[2];
                prev[x[1]]=x[0];
                till=x[1];
            }
        }
    }


    if(till==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        vector<int> ans;
        int in=till;
        for(int i=0;i<=n;i++)
        {
            in=prev[in];
        }
        
        int st=in;
        ans.push_back(in);
        in=prev[in];
        while(in!=st)
        {
            ans.push_back(in);
            in=prev[in];
        }
        ans.push_back(st);
        reverse(ans.begin(),ans.end());
        for(int x: ans)
        {
            cout<<x+1<<" ";
        }
        cout<<endl;
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
