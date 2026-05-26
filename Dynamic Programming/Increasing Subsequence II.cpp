#include <bits/stdc++.h>
using namespace std;
typedef long long int int64;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<ll>> vvl;
#define MOD (int)(1e9 + 7)
#define endl "\n"

#define all(ds) (ds).begin(), (ds).end()
#define sort(ds) sort(all(ds))

ll min(ll a,ll b) { if (a<b) return a; return b; }
ll max(ll a,ll b) { if (a>b) return a; return b; }

ll query(int node,int i,int j,vector<ll>&tree,int l,int r)
{
    if(i>r || j<l)return 0;
    if(l<=i && j<=r)return tree[node]%MOD;
    ll mid=(i+j)/2;
    return tree[node]=((query(2*node+1, i, mid, tree, l, r)%MOD)+(query(2*node+2, mid+1, j, tree, l, r)%MOD))%MOD;
}

void update(int node,int i,int j,vector<ll>&tree,int in,ll val)
{
    if(i==j)
    {
        tree[node]=((tree[node]%MOD)+(val%MOD))%MOD;
        return;
    }

    ll mid=(i+j)/2;
    if(in<=mid)update(2*node+1,i,mid,tree,in,val);
    else update(2*node+2,mid+1,j,tree,in,val);
    tree[node]=((tree[2*node+1]%MOD)+(tree[2*node+2]%MOD))%MOD;
}

void solve()
{
    ll n;cin>>n;
    vll a(n);
    set<ll>s1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s1.insert(a[i]);
    }
    ll in=0;
    map<ll,ll>m;
    for(auto x:s1)m[x]=in++;
    for(auto &x:a)x=m[x];
    
    ll sz=in+5;
    vll tree(4*sz,0);

    ll ans=0;
    for(auto x:a)
    {
        ll cnt=(query(0,0,sz-1,tree,0,x-1)+1)%MOD;
        ans=((ans%MOD)+(cnt%MOD))%MOD;
        update(0,0,sz-1,tree,x,cnt);
    }
    cout<<ans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
