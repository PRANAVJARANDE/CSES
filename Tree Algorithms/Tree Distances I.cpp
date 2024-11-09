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
ll calch(ll in,ll par)
{
    ll ans=0;
    ll ans1=0;
    for(ll x:adj[in])
    {
        if(x!=par)
        {
            ll res=1+calch(x,in);
            if(res>ans)
            {
                ans1=ans;
                ans=res;
            }
            else if(res>ans1)
            {
                ans1=res;
            }
        }
    }
    h[in]={ans,ans1};
    return ans;
}
 
vll v1;
void helper(ll in,ll par,ll up)
{
    ll ans1=h[in][0];
    ll ans2=h[in][1];
    ll op1=up;
    ll op2=ans1;
    v1[in]=max(op1,op2);  
    for(int x:adj[in])
    {
        if(x!=par)
        {   
            ll nup=up+1;
            if(h[x][0]==ans1-1)
            {
                nup=max(nup,ans2+1);
            }
            else
            {
                nup=max(nup,ans1+1);
            }
            helper(x,in,nup);
        }
    }
}
 
void solve()
{
    ll n;cin>>n;
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