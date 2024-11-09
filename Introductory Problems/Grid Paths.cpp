#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

ll helper(int i,int j,int n,vector<vector<char>>&a,vector<vector<ll>>&dp)
{
    if(i>=n || j>=n)return 0;
    if(a[i][j]=='*')return dp[i][j]=0;
    if(i==n-1 && j==n-1)return dp[i][j]=1;
    if(dp[i][j]!=-1)return dp[i][j];

    ll op1=helper(i+1,j,n,a,dp)%MOD;
    ll op2=helper(i,j+1,n,a,dp)%MOD;
    return dp[i][j]=(op1+op2)%MOD;
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    vector<vector<char>> a(n,vector<char>(n,'.'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)    
        {
            cin>>a[i][j];
        }
    }
    vector<vector<ll>> dp(n,vector<ll>(n,-1));
    cout<<helper(0,0,n,a,dp)<<endl;
    return 0;
}
