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
#define MOD (int)(1e9 + 7)
#define endl "\n"
#define sqrt sqrtl
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define emb emplace_back 
#define mp make_pair
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>

#define all(ds) (ds).begin(), (ds).end()
// Clear Memory
#define clr(ds) memset(ds, 0, sizeof(ds))
// Ascending Vector
#define sort(ds) sort(all(ds))
// Descending Vector
#define rev(ds) reverse(all(ds))
// Total Sum
#define tsum(ds) (accumulate(all(ds), 0ll))
// Count frequency of x
#define ctx(ds, x) (count(all(ds), (x)))
// Size
#define sz(ds) ((ll)(ds).size())
// Min Value
#define minv(ds) (*min_element(all(ds)))
// Max Value
#define maxv(ds) (*max_element(all(ds)))
// Min Value Index
#define minIdx(ds) (min_element(all(ds)) - (ds).begin())
// Max Value Index
#define maxIdx(ds) (max_element(all(ds)) - (ds).begin())
// Binary Search
#define bs(ds, x) (binary_search(all(ds), x))
// Lower Bound Index
#define lob(ds, x) (lower_bound(all(ds), (x)) - (ds).begin())
// Upper Bound Index
#define upb(ds, x) (upper_bound(all(ds), (x)) - (ds).begin())
// Ceil Function
#define ceil(num, div) ((num % div != 0) ? ((num / div) + 1) : (num / div))

const ll INF = 0x3f3f3f3f;              //inf
const ll neg_INF = 0xcfcfcfcf;          //-inf
const ld EPS = 1e-9;                    //epsilon
const ld PI = 3.1415926535897932384626; //pi

ll min(ll a,ll b) { if (a<b) return a; return b; }
ll max(ll a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll mod_pow(ll a,ll b, ll m) { 
    ll res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}
ll mod_neg(ll a,ll b)
{
    ll ans=((a%b)+b)%b;
    return ans;
}
ll modinv(ll b, ll m){ return mod_pow(b,m-2,m); }
string to_upper(string a){ for(int i=0;i<(int)a.size();++i)if(a[i]>='a' && a[i]<='z')a[i]-='a'-'A';return a;}
string to_lower(string a){ for(int i=0;i<(int)a.size();++i)if(a[i]>='A' && a[i]<='Z')a[i]+='a'-'A';return a;}

//Interactive problem
ll ask(int i,int j)
{
    cout<<"? "<<i<<" "<<j<<endl;
    cout.flush();
    ll res;cin>>res;
    return res;
}

vvl adj;
vll d;
vvl anc;
void dfs(ll in,ll par,ll l)
{
    anc[in][0]=par;
    d[in]=l;
    for(int i=1;i<=20;i++)
    {
        if(anc[in][i-1]!=-1)
        {
            anc[in][i]=anc[anc[in][i-1]][i-1];
        }
    }
    for(ll x:adj[in])
    {
        if(x!=par)
        {
            dfs(x,in,l+1);
        }
    }
}

ll getlca(ll x,ll y)
{
    if(d[x]>d[y])swap(x,y);
        ll k=d[y]-d[x];
        for(int i=20;i>=0;i--)
        {
            if(k & (1<<i))
            {
                y=anc[y][i];
            }
        }
        if(x==y)
        {
            return x;
        }
        for(int i=20;i>=0;i--)
        {
            if(anc[x][i]!=anc[y][i])
            {
                x=anc[x][i];
                y=anc[y][i];
            }
        }
        return anc[x][0];
}

vll acnt;
vll ans;
ll dfs1(ll in,ll par)
{
    ll s=0;
    for(ll x:adj[in])
    {
        if(x!=par)
        {
            ll res=dfs1(x,in);
            s+=res;
        }
    }
    ans[in]+=s;
    ans[in]-=acnt[in];
    return ans[in]-acnt[in];
}

void solve()
{
    ll n,q;cin>>n>>q;
    adj=vvl(n);
    for(int i=1;i<n;i++)
    {
        ll u,v;cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    anc=vector<vll>(n,vll(21,-1));
    d=vll(n,0);
    dfs(0,-1,0);
    ans=vll(n,0);
    acnt=vll (n,0);
    while(q--)
    {
        ll u,v;cin>>u>>v;
        u--;
        v--;
        ll lca=getlca(u,v);
        acnt[lca]++;
        ans[u]++;
        ans[v]++;
    }
    dfs1(0,-1);
    for(ll x:ans)
    {
        cout<<x<<" ";
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
