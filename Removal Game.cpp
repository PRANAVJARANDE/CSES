#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

ll helper(int i,int j,vector<int>&a,vector<vector<ll>>&dp)
{
    if(i==j)return a[i];
    if(dp[i][j]!=-1)return dp[i][j];
    
    ll op1=a[j]-helper(i,j-1,a,dp);
    ll op2=a[i]-helper(i+1,j,a,dp);
    return dp[i][j]=max(op1,op2);
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    vector<int>a(n);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    vector<vector<ll>>dp(n,vector<ll>(n,-1));
    ll ans=(helper(0,n-1,a,dp)+sum)/2;
    cout<<ans<<endl;
    return 0;
}
