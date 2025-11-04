#include <bits/stdc++.h>
using namespace std;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<ll, ll> pl; 
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long>> vllp;
typedef vector<pl> vpl;
typedef vector<vector<ll>> vvl;

const ld PI = 3.1415926535897932384626; 
ll min(ll a,ll b) { if (a<b) return a; return b; }
ll max(ll a,ll b) { if (a>b) return a; return b; }


void helper(ll in,ll par,vvl&adj,vector<set<ll>>&colors,vll&ans)
{
    for(auto x:adj[in])
    {
        if(x!=par)
        {
            helper(x,in,adj,colors,ans);
            if(colors[in].size()<colors[x].size())swap(colors[in],colors[x]);
            for(auto z:colors[x])colors[in].insert(z);
        }
    }
    ans[in]=colors[in].size();
}

void solve()
{
    ll n;cin>>n;
    vll a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vvl adj(n);
    for(int i=0;i<n-1;i++)
    {
        ll u,v;cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<set<ll>>colors(n);
    for(int i=0;i<n;i++)colors[i].insert(a[i]);

    vll ans(n);
    helper(0,-1,adj,colors,ans);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
}


// Main  -----------------------------------------------------------------------------------------

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
