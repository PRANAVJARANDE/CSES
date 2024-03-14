#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

ll helper(ll n,vector<int>&dp)
{

    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }

    if(dp[n]!=-1)return dp[n];

    ll op1=helper(n-1,dp);
    ll op2=helper(n-2,dp);
    ll op3=helper(n-3,dp);
    ll op4=helper(n-4,dp);
    ll op5=helper(n-5,dp);
    ll op6=helper(n-6,dp);

    return dp[n]=((op1)%MOD + (op2)%MOD + (op3)%MOD + (op4)%MOD + (op5)%MOD + (op6)%MOD)%MOD;
    
}


void solve()
{
    int n;cin>>n;
    vector<int>dp(n+1,-1);
    cout<<helper(n,dp)<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
