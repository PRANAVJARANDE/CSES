#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void build(int node,int i,int j,vector<ll>&a,vector<ll>&tree)
{
    if(i==j)
    {
        tree[node]=a[i];
        return;
    }
    ll mid=(i+j)/2;
    build(2*node+2,mid+1,j,a,tree);
    build(2*node+1,i,mid,a,tree);
    tree[node]=tree[2*node+2]^tree[2*node+1];
}

ll query(int node,int i,int j,vector<ll>&tree,int l,int r)
{
    if(i>r || j<l)
    {
        return 0;
    }

    if(l<=i && j<=r)
    {
        return tree[node];
    }
    ll mid=(i+j)/2;
    return query(2*node+1,i,mid,tree,l,r)^query(2*node+2,mid+1,j,tree,l,r);
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n,q;cin>>n>>q;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ll> tree(4*n);
    build(0,0,n-1,a,tree);
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<query(0,0,n-1,tree,l-1,r-1)<<endl;
    }
    return 0;
}
