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

ll n;
// ll helper(ll in,ll dir,vll&a,vvl&dp)
// {
//     if(dp[in][dir]!=-1)return dp[in][dir];
//     ll ans=1;
//     if(dir==1)
//     {
//         for(int i=in+1;i<n && a[i]<a[in];i++)
//         {
//             ll op1=helper(i,1,a,dp);
//             ll op2=helper(i,0,a,dp);
//             ans=max(ans,1+max(op1,op2));
//         }
//     }
//     else
//     {
//         for(int i=in-1;i>=0 && a[i]<a[in];i--)
//         {
//             ll op1=helper(i,1,a,dp);
//             ll op2=helper(i,0,a,dp);
//             ans=max(ans,1+max(op1,op2));
//         }
//     }
//     return dp[in][dir]=ans;
// }

void solve()
{
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vll nmax(n,n);
    stack<int>s1;
    for(int i=n-1;i>=0;i--)
    {
        while(!s1.empty() && a[s1.top()]<=a[i])
        {
            s1.pop();
        }
        if(!s1.empty())nmax[i]=s1.top();
        s1.push(i);
    }

    vll pmax(n,-1);
    stack<int>s2;
    for(int i=0;i<n;i++)
    {
        while(!s2.empty() && a[s2.top()]<=a[i])
        {
            s2.pop();
        }
        if(!s2.empty())pmax[i]=s2.top();
        s2.push(i);
    }

    // for(auto x:nmax)cout<<x<<" ";
    // cout<<endl;

    vvl temp(n);
    for(int i=0;i<n;i++)temp[i]={a[i],i};
    sort(temp);
    vll dis(n,1);

    for(auto x:temp)
    {
        int val=x[0];
        int in=x[1];
        if(nmax[in]!=n)dis[nmax[in]]=max(dis[nmax[in]],dis[in]+1);
        if(pmax[in]!=-1)dis[pmax[in]]=max(dis[pmax[in]],dis[in]+1);
    }

    ll ans=1;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dis[i]);
    }
    cout<<ans<<endl;
    






    
    // ll ans=1;
    // vvl dp(n,vll(2,-1));
    // for(int i=0;i<n;i++)
    // {
    //     ll op1=helper(i,0,a,dp);
    //     ll op2=helper(i,1,a,dp);
    //     ans=max(ans,max(op1,op2));
    // }
    // cout<<ans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;    
    solve();
    return 0;
}
