#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

const ll MOD = 1e9 + 7;

class node
{
public:
    bool endd;
    node* next[26];

    node()
    {
        endd = false;
        fill(next, next + 26, nullptr);
    }

    void insertt(const string& s)
    {
        node* temp = this;
        for (char c : s)
        {
            int index = c - 'a';
            if (temp->next[index] == nullptr)
            {
                temp->next[index] = new node();
            }
            temp = temp->next[index];
        }
        temp->endd = true;
    }
};

node* trie;
ll n;

void solve()
{
    string s;
    cin >> s;
    n = s.size();
    ll m;
    cin >> m;

    trie = new node();

    while (m--)
    {
        string h;
        cin >> h;
        trie->insertt(h);
    }

    vll dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        node* temp = trie;
        for (int j = i; j < n; j++)
        {
            int index = s[j] - 'a';
            if (temp->next[index] == nullptr) break;

            temp = temp->next[index];
            if (temp->endd)
            {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}
