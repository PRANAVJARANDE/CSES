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

void dfs2(int in,vector<int>&vis,vector<vector<int>>&radj)
{
    vis[in]=1;
    for(int x:radj[in])
    {
        if(vis[x]==0)
            dfs2(x,vis,radj);
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

    dfs2(topo[0],vis,radj);

    int a1=-1,a2=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==1)a1=i;
        else a2=i;
    }
    
    if(a2==-1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
        cout<<a2+1<<" "<<a1+1<<endl;
    }
}

int main() 
{
    solve();
    return 0;
}
