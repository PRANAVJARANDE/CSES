#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long
 
int main() 
{
    int n;cin>>n;
    ll sum=(n*(n+1))/2;
    if(sum%2)
    {
        cout<<"0"<<endl;
    }
    else 
    {
        sum/=2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                dp[i][j]=dp[i-1][j];
                int l=j-i;
                if(l>=0)
                {
                    (dp[i][j]+=dp[i-1][l])%=MOD;
                }
            }
        }
        cout<<dp[n-1][sum];
    }
    return 0;
}
