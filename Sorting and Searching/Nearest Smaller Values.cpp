#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    stack<int> s1;
    for(int i=0;i<n;i++)
    {
        while(!s1.empty() && a[i]<=a[s1.top()])
        {
            s1.pop();
        }
        if(s1.empty())cout<<"0"<<" ";
        else cout<<(int)s1.top()+1<<" ";
        s1.push(i);
    }
    return 0;
}
