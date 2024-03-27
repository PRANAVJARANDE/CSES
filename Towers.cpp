#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    multiset<int> s1;
    for(int i=0;i<n;i++)
    {
        auto it=s1.upper_bound(a[i]);
        if(it==s1.end())
        {
            s1.insert(a[i]);
        }
        else
        {
            s1.erase(it);
            s1.insert(a[i]);
        }
    }
    cout<<(int)s1.size()<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
