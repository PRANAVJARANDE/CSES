#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    ll maxi=1e6 + 2;
    vector<ll>dp(maxi,0);
    for(int i=1;i<maxi;i++)
    {
        for(int j=i;j<maxi;j+=i)
        {
            dp[j]++;
        }
    }
    int t;cin >> t;
    while (t--) 
    {
        ll n;cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
