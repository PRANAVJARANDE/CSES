#include <bits/stdc++.h>
using namespace std;

vector<int> dx={1,-1,0,0};
vector<int> dy={0,0,1,-1};
vector<char>dir={'D','U','R','L'};
int n,m;

bool issafe(int i,int j)
{
    if(i<n && j<m && i>=0 && j>=0)return 1;
    return 0;
}

bool helper(int i,int j,vector<vector<char>>&a,vector<vector<int>>&mons,vector<char>&ans)
{
    if(a[i][j]=='M')return 0;
    if(a[i][j]=='#')return 0;

    if(i==0 || j==0 || i==n-1 || j==m-1)
    {
        return 1;
    }


    a[i][j]='M';
    vector<vector<int>> nmos;
    for(auto x: mons)
    {
        for(int z=0;z<4;z++)
        {
            int nx=x[0]+dx[z];
            int ny=x[1]+dy[z];
            if(issafe(nx,ny))
            {
                if(a[nx][ny]=='.')
                {
                    nmos.push_back({nx,ny});
                    a[nx][ny]='M';
                }
            }
        }
    }

    for(int z=0;z<4;z++)
    {
        int nx=i+dx[z];
        int ny=j+dy[z];
        if(issafe(nx,ny) && a[nx][ny]=='.')
        {
            ans.push_back(dir[z]);
            if(helper(nx,ny,a,nmos,ans)==1)
            {
                return 1;
            }
            ans.pop_back();
        }
    }

    for(auto x: nmos)
    {
        a[x[0]][x[1]]='.';
    }
    a[i][j]='.';
    return 0;    
}

void solve()
{
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m,'0'));
    int x,y;
    vector<vector<int>> mons;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='A')
            {
                a[i][j]='.';
                x=i,y=j;
            }
            else if(a[i][j]=='M')
            {
                mons.push_back({i,j});
            }
        }
    }

    vector<char> ans;
    bool b=helper(x,y,a,mons,ans);
    if(b==1)
    {
        cout<<"YES"<<endl;
        cout<<(int)ans.size()<<endl;
        for(char x: ans)
        {
            cout<<x;
        }
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
