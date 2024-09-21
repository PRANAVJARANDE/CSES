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


void build(int node,int i,int j,vector<ll>&a,vector<pair<ll,ll>>&tree)
{
    if(i==j)
    {
        tree[node]={a[i],a[i]};
        return;
    }
    ll mid=(i+j)/2;
    build(2*node+2,mid+1,j,a,tree);
    build(2*node+1,i,mid,a,tree);
    tree[node]={min(tree[2*node+2].first,tree[2*node+1].first),max(tree[2*node+2].second,tree[2*node+1].second)};
}

ll query(int node,int i,int j,vector<pair<ll,ll>>&tree,int val)
{
    ll l=tree[node].first;
    ll r=tree[node].second;
    if(val>r)
    {
        return -1;
    }
    if(i==j)
    {
        tree[node]={l-val,r-val};
        return i+1;   
    }
    ll mid=(i+j)/2;
    ll fop=query(2*node+1,i,mid,tree,val);
    if(fop!=-1)
    {
        tree[node]={min(tree[2*node+2].first,tree[2*node+1].first),max(tree[2*node+2].second,tree[2*node+1].second)};
        return fop;
    }
    ll sop=query(2*node+2,mid+1,j,tree,val);
    if(sop!=-1)
    {
        tree[node]={min(tree[2*node+2].first,tree[2*node+1].first),max(tree[2*node+2].second,tree[2*node+1].second)};
        return sop;
    }
    return -1;
}


void solve()
{
    ll n,q;cin>>n>>q;
    vll a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<pair<ll,ll>>tree(4*n);
    build(0,0,n-1,a,tree);
    while(q--)
    {
        ll k;cin>>k;
        ll ans=query(0,0,n-1,tree,k);
        if(ans==-1)ans=0;
        cout<<ans<<" ";
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
