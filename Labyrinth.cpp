#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int n, m;

bool issafe(int i, int j, vector<vector<bool>>& vis) 
{
    return (i < n && j < m && i >= 0 && j >= 0 && vis[i][j]==0);
}

int main() {
    cin >> n >> m;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<char>> mp(n, vector<char>(m));
    int x, y, fx, fy;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            char ch;cin>>ch;
            if(ch=='#') 
            {
                vis[i][j]=1;
            } 
            else if(ch=='A') 
            {
                vis[i][j]=1;
                dist[i][j]=0;
                x=i;
                y=j;
            }
            else if(ch=='B')
            {
                fx=i;
                fy=j;
            }
        }
    }

    priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> q1;
    q1.push({0,{x, y}});

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<char> dir_char = {'U', 'D', 'L', 'R'};

    while (!q1.empty()) 
    {
        int dis = q1.top().first;
        int i0 = q1.top().second[0];
        int j0 = q1.top().second[1];
        q1.pop();

        if (i0 == fx && j0 == fy) 
        {
            cout<<"YES"<<endl;
            cout<<dist[i0][j0]<<endl;
            string ans="";
            while (i0 != x || j0 != y) 
            {
                for(int k = 0; k < 4; k++)
                {
                    int ni = i0 + dirs[k].first;
                    int nj = j0 + dirs[k].second;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && dist[ni][nj]+1==dist[i0][j0]) 
                    {
                        ans+=dir_char[k];
                        i0=ni;
                        j0=nj;
                        break;
                    }
                }
            }
            reverse(ans.begin(), ans.end());
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]=='R')cout<<"L";
                else if(ans[i]=='L')cout<<"R";
                else if(ans[i]=='U')cout<<"D";
                else cout<<"U";
            }
            return 0;
        }

        for (int k = 0; k < 4; k++) 
        {
            int ni = i0 + dirs[k].first;
            int nj = j0 + dirs[k].second;
            if(issafe(ni, nj, vis) && dist[ni][nj]>dis+1) 
            {
                dist[ni][nj] = dis + 1;
                q1.push({dist[ni][nj], {ni, nj}});
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
