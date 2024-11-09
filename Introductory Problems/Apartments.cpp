#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n,m,k;cin>>n>>m>>k;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
 
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
 
    int i=0,j=0,c=0;
    while(i<n && j<m)
    {
        int ll=a[i]-k;
        int ul=a[i]+k;
 
        if(ll<=b[j] && b[j]<=ul)
        {
            c++;
            i++;
            j++;
        }
        else if(b[j]<ll)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout<<c<<endl;
 
    return 0;
}