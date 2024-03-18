#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

ll gta(int in,int n,vector<ll>&st,ll k)
{
    ll l=in,r=n-1;
    ll ans=n;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(st[mid]>k)
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    ll n;cin>>n;
    vector<vector<ll>> a(n,vector<ll>(3,0));
    vector<ll>st(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        st[i]=a[i][0];
    }
    sort(a.begin(),a.end());
    sort(st.begin(),st.end());
    vector<ll>dp(n+1,0);

    for(int i=n-1;i>=0;i--)
    {
        ll nxin = gta(i+1,n,st,a[i][1]);
        dp[i]=max(dp[i+1],a[i][2]+dp[nxin]);
    }
    cout<<dp[0]<<endl;
    return 0;
}
