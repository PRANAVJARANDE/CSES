#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    long long n;cin>>n;
    unordered_map<int,int> m;
    for(int i=0;i<n-1;i++)
    {
        int y;cin>>y;
        m[y]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(m.find(i)==m.end())
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
