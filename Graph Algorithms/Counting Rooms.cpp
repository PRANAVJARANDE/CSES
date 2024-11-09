#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int n,m;
bool issafe(int i,int j,vector<vector<bool>>&vis)
{
    if(i<n && j<m && i>=0 && j>=0 && vis[i][j]==0)
    {
        vis[i][j]=1;
        return 1;
    }
    return 0;
}

int main() 
{
    cin>>n>>m;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char ch;cin>>ch;
            if(ch=='#')
            {
                vis[i][j]=1;
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==0)
            {
                ans++;
                vis[i][j]=1;
                queue<pair<int,int>> q1;
                q1.push({i,j});
                while(!q1.empty())
                {
                    int i0=q1.front().first;
                    int j0=q1.front().second;
                    q1.pop();
                    
                    if(issafe(i0+1,j0,vis))q1.push({i0+1,j0});
                    if(issafe(i0-1,j0,vis))q1.push({i0-1,j0});
                    if(issafe(i0,j0+1,vis))q1.push({i0,j0+1});
                    if(issafe(i0,j0-1,vis))q1.push({i0,j0-1});
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
