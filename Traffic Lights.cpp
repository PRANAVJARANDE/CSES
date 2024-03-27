#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    ll x,n;cin>>x>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    multiset<int> ans;
    ans.insert(x);
    set<int> div;
    div.insert(0);
    div.insert(x);

    for(int x: a)
    {
        auto it=div.lower_bound(x);
        int maxi=*it;
        it--;
        int mini=*it;
        div.insert(x);
        ans.erase(ans.find(maxi-mini));
        ans.insert(maxi-x);
        ans.insert(x-mini);
        int os=*ans.rbegin();
        cout<<os<<" ";
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
