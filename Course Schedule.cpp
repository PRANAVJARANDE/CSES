#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int> indeg(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
    }   

    queue<int> q1;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q1.push(i);
        }
    }

    vector<int>ans;
    while(!q1.empty())
    {
        int k=q1.front();
        q1.pop();
        ans.push_back(k);
        for(int x: adj[k])
        {
            indeg[x]--;
            if(indeg[x]==0)
            {
                q1.push(x);
            }
        }
    }
    if(ans.size()==n)
    {
        for(int x: ans)
        {
            cout<<x<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
