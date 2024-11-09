#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve(int n,int src,int hel,int dst,vector<vector<int>>&ans)
{
    if(n==0)return;
    solve(n-1,src,dst,hel,ans);
    ans.push_back({src,dst});
    solve(n-1,hel,src,dst,ans);
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n;cin>>n;
    vector<vector<int>> ans;
    solve(n,1,2,3,ans);
    cout<<(int)ans.size()<<endl;
    for(auto x: ans)
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    return 0;
}
