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

    vector<int> col(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(col[i]==0)
        {
            col[i]=1;
            queue<pair<int,int>> q1;
            q1.push({i,1});
            while(!q1.empty())
            {
                int k=q1.front().first;
                int co=q1.front().second;
                q1.pop();
                int tc;
                if(co==1)tc=2;
                else tc=1;

                for(int x: adj[k])
                {
                    if(col[x]==tc)
                    {
                        continue;
                    }
                    else if(col[x]==0)
                    {
                        col[x]=tc;
                        q1.push({x,tc});
                    }
                    else 
                    {
                        cout<<"IMPOSSIBLE"<<endl;
                        return;
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<col[i]<<" ";
    }
    cout<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
