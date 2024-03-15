#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n,x;cin>>n>>x;
    vector<int>price(n),pages(n);
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n;i++)cin>>pages[i];

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i][j]=dp[i-1][j];
            int l=j-price[i-1];
            if(l>=0)
            {
                dp[i][j]=max(dp[i][j],pages[i-1]+dp[i-1][l]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}
