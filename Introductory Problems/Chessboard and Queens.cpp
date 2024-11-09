#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

bool issafe(int x,int y,vector<vector<char>>&v1,int n)
{
    for(int i=0;i<x;i++)
    {
        if(v1[i][y]=='Q')return 0;
    }
    int i=x,j=y;
    while(i>=0 && y>=0)
    {
        if(v1[i][j]=='Q')return 0;
        i--;
        j--;
    }
    i=x,j=y;
    while(i>=0 && j<n)
    {
        if(v1[i][j]=='Q')return 0;
        i--;
        j++;
    }
    return 1;
}

int solve(int x,vector<vector<char>>&a)
{
    if(x>=8)return 1;

    int ans=0;
    for(int i=0;i<8;i++)
    {
        if(issafe(x,i,a,8) && a[x][i]=='.')
        {
            a[x][i]='Q';
            ans+=solve(x+1,a);
            a[x][i]='.';
        }
    }
    return ans;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    vector<vector<char>> a(8,vector<char>(8,'.'));
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<solve(0,a)<<endl;       
    return 0;
}
