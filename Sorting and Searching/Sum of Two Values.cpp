#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

ll bs(int in,int k,int n,vector<vector<int>>&a)
{
    ll l=in,r=n-1;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(a[mid][0]==k)
        {
            return a[mid][1];
        }
        else if(a[mid][0]<k)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return -1;
}

void solve()
{
    ll n,x;cin>>n>>x;
    vector<vector<int>> a(n,vector<int>(2,0));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        a[i][1]=i+1;
    }
    sort(a.begin(),a.end());

    for(int i=0;i<n;i++)
    {
        int tar=x-a[i][0];
        ll ans=bs(i+1,tar,n,a);
        if(ans!=-1)
        {
            cout<<a[i][1]<<" "<<ans<<endl;
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
