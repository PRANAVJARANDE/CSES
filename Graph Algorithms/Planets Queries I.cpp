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


#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define ff first
#define ss second


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


void solve()
{
    ll n,q;cin>>n>>q;
    vvl adj(n);
    vvl up(31,vll(n,-1));
    for(int i=0;i<n;i++)
    {
        ll u;cin>>u;
        u--;
        up[0][i]=u;
    }
    
    
    for(int j=1;j<31;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(up[j-1][i]!=-1)up[j][i]=up[j-1][up[j-1][i]];
        }
    }

    while(q--)
    {
        ll x,k;cin>>x>>k;
        x--;
        ll ans=x;
        for(int i=0;i<31;i++)
        {
            if(k & (1<<i))
            {
                ans=up[i][ans];
            }
        }
        cout<<ans+1<<endl;
    }   
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();    
    return 0;
}
