#include <bits/stdc++.h>
using namespace std;

int till;
vector<int>ans;
int dfs(int in,int pa,vector<vector<int>>&adj,vector<int>&vis,vector<int>&mark)
{
    if(mark[in]==1)
    {
        //cycle detected
        till=in;
        ans.push_back(in);
        return 1;
    }

    mark[in]=1;
    for(int x: adj[in])
    {
        vis[x]=1;
        if(x!=pa)
        {
            int b=dfs(x,in,adj,vis,mark);
            if(b==1)
            {
                ans.push_back(in);
                if(till==in)
                {
                    return 2;
                }
                return 1;
            }
            else if(b==2)
            {
                return 2;
            }
        }
    }
    mark[in]=0;
    return 0;
}

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

    vector<int>vis(n+1,0),mark(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            bool b=dfs(i,-1,adj,vis,mark);
            if(b==1)
            {
                cout<<(int)ans.size()<<endl;
                for(int x: ans)
                {
                    cout<<x<<" ";
                }
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
