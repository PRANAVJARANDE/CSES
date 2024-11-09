#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long


ll query(ll node,ll i,ll j,vector<ll>&tree,ll l,ll r)
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
    return query(2*node+1,i,mid,tree,l,r)+query(2*node+2,mid+1,j,tree,l,r);
}

void update(int node,int i,int j,vector<ll>&tree,int in,ll val)
{
    if(i==j)
    {
        tree[node]=val;
        return;
    }

    ll mid=(i+j)/2;
    if(in<=mid)
    {
        update(2*node+1,i,mid,tree,in,val);
    }
    else
    {
        update(2*node+2,mid+1,j,tree,in,val);
    }
    tree[node]=tree[2*node+1]+tree[2*node+2];
}


ll helper(ll alive,vector<ll>&tree,ll n)
{
    ll l=0,r=n-1;
    while(l<r)
    {
        ll mid=l+(r-l)/2;
        ll pal=query(0,0,n-1,tree,0,mid);
        if(pal<alive+1)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}



void solve()
{
    ll n,k;cin>>n>>k;
    vector<ll>tree(4*n,0);
    for(int i=0;i<n;i++)
    {
        update(0,0,n-1,tree,i,1);
    }

    int in=k;
    vector<ll> ans;
    while(tree[0])
    {
        in=in%tree[0];
        ll ou=helper(in,tree,n);
        ans.push_back(ou+1);
        update(0,0,n-1,tree,ou,0);
        in=in+k;
    }
    for(ll x: ans)
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
