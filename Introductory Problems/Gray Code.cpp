#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

bool getbit(int n,int pos)
{
    return (n & (1<<pos));
}

void solve()
{
    int n;cin>>n;
    for(int i=0;i<pow(2,n);i++)
    {
        int t=i ^ (i>>1);
        for(int j=n-1;j>=0;j--)
        {
            cout<<getbit(t,j);
        }
        cout<<endl;
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
