#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

const ll N=1e6+10;
int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    vector<ll> mid0(N,1),mid1(N,1);

    for(int i=2;i<N;i++)
    {
        mid0[i]=(2*mid0[i-1] + mid1[i-1])%MOD;
        mid1[i]=(4*mid1[i-1] + mid0[i-1])%MOD;
    }
    int t;cin >> t;
    while (t--) 
    {
        int n;cin>>n;
        ll ans=(mid0[n]+mid1[n])%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
