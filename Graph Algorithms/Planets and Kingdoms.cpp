#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void dfs(int in,vector<int>&vis,vector<vector<int>>&adj,vector<int>&topo)
{
    vis[in]=1;
    for(int x:adj[in])
    {
        if(vis[x]==0)
            dfs(x,vis,adj,topo);
    }
    topo.push_back(in);
}

void dfs2(int in,vector<int>&vis,vector<vector<int>>&radj,int col,vector<int>&res)
{
    vis[in]=1;
    res[in]=col;
    for(int x:radj[in])
    {
        if(vis[x]==0)
            dfs2(x,vis,radj,col,res);
    }
}

void solve() 
{
    int n,mm;cin>>n>>mm;
    vector<vector<int>> adj(n),radj(n);
    for(int i=0;i<mm;i++)
    {
        int a,b;cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);           
        radj[b].push_back(a);
    }

    vector<int> vis(n,0);
    vector<int>topo;
    for(int i=0;i<n;i++)
        if(vis[i]==0)dfs(i,vis,adj,topo);

    vis.assign(n, 0);
    reverse(topo.begin(),topo.end());
    int col=0;
    vector<int> res(n,0);
    for(int i: topo)
    {
        if(vis[i]==0)
        {
            col++;
            dfs2(i,vis,radj,col,res);
        }
    }
    cout<<col<<endl;
    for(int x: res)
    {
        cout<<x<<" ";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
