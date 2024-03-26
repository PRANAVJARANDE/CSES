#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    ll in=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=in+1)
        {
            in=a[i]+in;
        }
        else
        {
            cout<<in+1<<endl;
            return;
        }
    }
    cout<<in+1<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
