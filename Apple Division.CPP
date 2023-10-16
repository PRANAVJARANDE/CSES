#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long
#define vin vector<int> v1(n); for (int i = 0; i < n; i++) cin >> v1[i]; 
    
long long mod_pow(long long base, long long exponent, int mod) {
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

long long sumOfAP(long long a, long long d, long long n) 
{
    long long sum = (n * (2 * a + (n - 1) * d)) / 2;
    return sum;
}

ll gpsum(ll k,ll n,ll m)
{
    if(n==1) return 1;
    ll res = ((1+mod_pow(k,n/2,m)))%m * gpsum(k,n/2,m)%m;
    if(n&1){
        res = ((res*k)%m + 1)%m;
    }
    return res;
}


long long gcd(long long a, long long b) 
{
    return __gcd(a,b);
}

long long lcm(long long a, long long b) 
{
    return abs(a * b) / __gcd(a,b);
}

long long ncr(long long n,long long r)
{
    if(r==0)
        return 1;
        
    if(r>n-r)
        r=n-r;
        
    long long ans=1;
    for(int i=1;i<=r;i++)
        ans=ans*(n-i+1)/i;
    return ans;
}

unsigned long long fact(int n) 
{
    if (n < 0) 
        return 0;

    vector<unsigned long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) 
        dp[i] = (dp[i - 1] * i) % MOD;

    return dp[n];
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;

    int t;cin >> t;
    while (t--) 
    {
        
        
    }
    return 0;
}
