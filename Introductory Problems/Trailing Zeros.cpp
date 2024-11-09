#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    long long ans=0;
    while(n>=5)
    {
        n=n/5;
        ans+=n;
    }
    cout<<ans<<endl;
    return 0;
}
