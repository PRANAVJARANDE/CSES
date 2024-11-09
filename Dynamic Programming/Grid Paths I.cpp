#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

bool issafe(int x,int y)
{
    if(x<0 || y<0 || x>6 || y>6)return 0;
    return 1;
}

int ans;
void helper(int x,int y,int in,string&s,vector<vector<int>>&vis)
{
    if(!issafe(x,y))return;
    if(in==48 || (x==6 && y==0))
    {
        if(in==48 && (x==6 && y==0))ans++;
        return;
    }
    
    if((!issafe(x-1,y) || vis[x-1][y]) && (!issafe(x+1,y) || vis[x+1][y]))
    {
        if(issafe(x,y-1) && issafe(x,y+1) && !vis[x][y-1] && !vis[x][y+1])
            return;
    }

    if((!issafe(x,y-1) || vis[x][y-1]) && (!issafe(x,y+1) || vis[x][y+1]))
    {
        if(issafe(x-1,y) && issafe(x+1,y) && !vis[x-1][y] && !vis[x+1][y])
            return;
    }

    vis[x][y]=1;
    if(s[in]=='D' || s[in]=='?')
    {
        if(issafe(x+1,y) && vis[x+1][y]==0)
        {
            helper(x+1,y,in+1,s,vis);
        }
    }
    if(s[in]=='U' || s[in]=='?')
    {
        if(issafe(x-1,y) && vis[x-1][y]==0)
        {
            helper(x-1,y,in+1,s,vis);
        }
    }
    if(s[in]=='L' || s[in]=='?')
    {
        if(issafe(x,y-1) && vis[x][y-1]==0)
        {
            helper(x,y-1,in+1,s,vis);
        }
    }
    if(s[in]=='R' || s[in]=='?')
    {
        if(issafe(x,y+1) && vis[x][y+1]==0)
        {
            helper(x,y+1,in+1,s,vis);
        }
    }
    vis[x][y]=0;
    return;
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    string s;cin>>s;
    vector<vector<int>>vis(7,vector<int>(7,0));
    ans=0;
    helper(0,0,0,s,vis);
    cout<<ans<<endl;
    return 0;
}
