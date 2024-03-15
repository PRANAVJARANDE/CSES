#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int helper(int n,int m,string a,string b,vector<vector<int>>&dp)
{
    if(n==0) return m;
    if(m==0) return n;

    if(dp[n][m]!=-1)return dp[n][m];
    if(a[n-1]==b[m-1])
    {
        return dp[n][m]=helper(n-1,m-1,a,b,dp);
    }

    int op1=1+helper(n-1,m,a,b,dp);
    int op2=1+helper(n,m-1,a,b,dp);
    int op3=1+helper(n-1,m-1,a,b,dp);
    return dp[n][m]=min(op1,min(op2,op3));
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i!=0)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            }
            if(j!=0)
            {
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
            if(i!=0 && j!=0)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
                }
            }
        }
    }

    cout<<dp[n][m];
    
    return 0;
}
