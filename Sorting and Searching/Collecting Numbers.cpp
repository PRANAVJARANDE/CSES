#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++)
    {
        int k;cin>>k;
        a[k]=i;
    }
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]>a[i])ans++;
    } 
    cout<<ans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
