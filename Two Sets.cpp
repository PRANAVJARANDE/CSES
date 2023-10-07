#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long
#define vin vector<int> v1(n); for (int i = 0; i < n; i++) cin >> v1[i]; 

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    if(n%4==1 || n%4==2)
    {
        cout<<"NO"<<endl;
    }
    else if(n%4==3)
    {
        cout<<"YES"<<endl;
        int a=n/2;
        cout<<a+1<<endl;
        for(int i=1;i<=n;i+=4)
        {
            cout<<i<<" ";
            if(i+1<=n)
            {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
        cout<<a<<endl;
        for(int i=3;i<=n;i+=4)
        {
            cout<<i<<" ";
            if(i+1<=n)
            {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<n/2<<endl;
        cout<<"1 ";
        for(int i=4;i<=n;i+=4)
        {
            cout<<i<<" ";
            if(i+1<=n)
            {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
        cout<<n/2<<endl;
        for(int i=2;i<=n;i+=4)
        {
            cout<<i<<" ";
            if(i+1<=n)
            {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;

    }
    return 0;
}
