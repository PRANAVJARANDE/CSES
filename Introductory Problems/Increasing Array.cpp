#include <bits/stdc++.h>
using namespace std;
#define vin vector<int> v1(n);for(int i=0;i<n;i++)cin>>v1[i]; 

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    vin;
    long long k=0;
    for(int i=1;i<n;i++)
    {
        if(v1[i]<v1[i-1])
        {
            k+=v1[i-1]-v1[i];
            v1[i]=v1[i-1];
        }
    }
    cout<<k<<endl;
    return 0;
}
