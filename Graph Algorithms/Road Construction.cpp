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
    set<int> s1;

    dsu(int x)
    {
        k=x;
        parent=new int[k];
        sz=new int[k];
        for(int i=0;i<k;i++)
        {
            s1.insert(i);
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

    int union_set(int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b)
        {
            return sz[a];
        }

        if(sz[a]>sz[b])
        {
            s1.erase(b);
            parent[b]=a;
            sz[a]=sz[a]+sz[b];
            return sz[a];
        }
        else
        {
            s1.erase(a);
            parent[a]=b;
            sz[b]=sz[b]+sz[a];
            return sz[b];
        }
    }

    int getc()
    {
        return (int)s1.size();
    }

};


void solve()
{
    ll n,m;cin>>n>>m;
    dsu d1(n);
    int maxi=1;
    for(int i=0;i<m;i++)
    {
        ll a,b;cin>>a>>b;
        a--;
        b--;
        maxi=max(maxi,d1.union_set(a,b));
        int a1=d1.getc();
        cout<<a1<<" "<<maxi<<endl;
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
