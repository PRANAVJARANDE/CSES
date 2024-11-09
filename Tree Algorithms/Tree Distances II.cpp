#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<ll>> vvl;
#define MOD (int)(1e9 + 7)
#define endl "\n"

ll min(ll a,ll b) { if (a<b) return a; return b; }
ll max(ll a,ll b) { if (a>b) return a; return b; }


vector<vll> h;
vector<vll>adj;
pair<ll,ll> calch(ll in,ll par)
{
    ll dis=0;
    ll anc=1;
    for(ll x:adj[in])
    {
        if(x!=par)
        {
            auto res=calch(x,in);
            dis+=res.first+res.second;
            anc+=res.second;
        }
    }
    h[in]={dis,anc};
    return {dis,anc};
}

ll n;
vll v1;
void helper(ll in,ll par,ll up)
{
    ll dis1=h[in][0]; 
    for(int x:adj[in])
    {
        if(x!=par)
        {   
            ll nup=up+dis1-h[x][0]-h[x][1]+n-h[x][1];
            helper(x,in,nup);
        }
    }
    v1[in]=up+dis1;
}

void solve()
{
    cin>>n;
    adj=vector<vll>(n);
    for(int i=0;i<n-1;i++)
    {
        ll u,v;cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    h=vector<vll>(n,vll(2,0));
    v1=vll(n,0);
    calch(0,-1);
    /* for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<h[i][0]<<" "<<h[i][1]<<endl;
    } */
    helper(0,-1,0);
    for(ll x:v1)
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
