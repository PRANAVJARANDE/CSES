#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll n,x;cin>>n>>x;
    vector<vector<ll>> a(n,vector<ll>(2,0));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        a[i][1]=i+1;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        ll t=x-a[i][0];
        int l=i+1,r=n-1;
        while(l<r)
        {
            ll s=a[l][0]+a[r][0];
            if(s==t)
            {
                cout<<a[i][1]<<" "<<a[l][1]<<" "<<a[r][1];
                return;
            }
            else if(s<t)
            {
                l++;
            }
            else
            {
                r--;
            }
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
