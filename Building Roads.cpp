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
    int n,e;cin>>n>>e;
    dsu d1(n+1);

    for(int i=0;i<e;i++)
    {
        int a,b;cin>>a>>b;
        d1.union_set(a,b);
    }
    set<int> s1;
    for(int i=1;i<=n;i++)
    {
        s1.insert(d1.find_set(i));
    }
    vector<int> ans;
    for(int x: s1)
    {
        ans.push_back(x);
    }

    int a=ans.size()-1;
    cout<<a<<endl;
    for(int i=0;i<a;i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
        solve();
    return 0;
}
