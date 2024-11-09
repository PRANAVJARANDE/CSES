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
    vector<bool> dp(100001,0);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=100000-a[i];j>=0;j--)
        {
            if(dp[j]==1)
            {
                dp[j+a[i]]=1;
            }
        }
    }
    vector<int>ans;
    for(int i=1;i<100001;i++)
    {
        if(dp[i]==1)ans.push_back(i);
    }
    cout<<(int)ans.size()<<endl;
    for(int x: ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
