#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n,e;cin>>n>>e;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<e;i++)
    {
        int a,b;cin>>a>>b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    //ucs
    vector<int> prev(n+1,-1);
    prev[1]=1;
    queue<int> q1;
    q1.push(1);
    while(!q1.empty())
    {
        int k=q1.front();
        q1.pop();

        if(k==n)
        {
            vector<int> ans;
            int in=n;
            while(in!=1)
            {
                ans.push_back(in);
                in=prev[in];
            }
            ans.push_back(1);
            reverse(ans.begin(),ans.end());
            cout<<(int)ans.size()<<endl;
            for(int x: ans)
            {
                cout<<x<<" ";
            }
            cout<<endl;
            return;
        }

        for(int x: adj[k])
        {
            if(prev[x]==-1)
            {
                prev[x]=k;
                q1.push(x);
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
