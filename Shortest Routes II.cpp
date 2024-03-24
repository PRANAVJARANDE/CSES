#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

const ll INF = LLONG_MAX;

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[b][a]);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dist[a][b] != INF)
            cout << dist[a][b] << endl;
        else
            cout << "-1" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
