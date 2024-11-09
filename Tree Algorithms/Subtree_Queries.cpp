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

vll a;                          // node          ---->  val
vvl adj;
vvl tmm;                         // node          ---->  [start,end]
vll st;                         // starte time   ---->  which node
void dfs(int in,int par,ll& l)
{
    tmm[in][0]=l;
    st[l]=in;
    for(int x: adj[in])
    {
        if(x!=par)
        {
            l++;
            dfs(x,in,l);
        }
    }
    tmm[in][1]=l;
}

void build(int node,int i,int j,vector<ll>&tree)
{
    if(i==j)
    {
        tree[node]=a[st[i]];
        return;
    }
    ll mid=(i+j)/2;
    build(2*node+2,mid+1,j,tree);
    build(2*node+1,i,mid,tree);
    tree[node]=tree[2*node+2]+tree[2*node+1];
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
    return query(2*node+1,i,mid,tree,l,r)+query(2*node+2,mid+1,j,tree,l,r);
}

void update(int node,int i,int j,vector<ll>&tree,int in)
{
    if(i==j)
    {
        tree[node]=a[st[i]];
        return;
    }

    ll mid=(i+j)/2;
    if(in<=mid)
    {
        update(2*node+1,i,mid,tree,in);
    }
    else
    {
        update(2*node+2,mid+1,j,tree,in);
    }
    tree[node]=tree[2*node+1]+tree[2*node+2];
}


void solve()
{
    ll n,q;cin>>n>>q;
    a=vll(n);
    for(int i=0;i<n;i++)cin>>a[i];
    adj=vvl(n);
    tmm=vvl(n,vll(2,0));
    st=vll(n,0);
    for(int i=1;i<n;i++)
    {
        ll u,v;cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll l=0;
    dfs(0,-1,l);
    vll tree(4*n,0);
    build(0,0,n-1,tree);

    while(q--)
    {
        ll ty;cin>>ty;
        ll in;cin>>in;
        in--;
        if(ty==1)
        {
            ll x;cin>>x;
            ll s=tmm[in][0];
            a[in]=x;
            update(0,0,n-1,tree,s);
        }
        else    
        {
            ll s=tmm[in][0],e=tmm[in][1];
            ll ans=query(0,0,n-1,tree,s,e);
            cout<<ans<<endl;
        }
    }


}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    
        solve();
    
    return 0;
}
