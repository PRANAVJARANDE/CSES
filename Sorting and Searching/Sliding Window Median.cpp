#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve() 
{
    ll n,k;cin>>n>>k;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    multiset<ll, greater<ll>> maxi;
    multiset<ll> mini;
    ll i = 0;
    vector<ll> ans;
    for(int j=0; j<(int)nums.size(); j++) 
    {
        maxi.insert(nums[j]);

        if(!mini.empty() && *maxi.begin() > *mini.begin()) 
        {
            mini.insert(*maxi.begin());
            maxi.erase(maxi.begin());
        }
        if(maxi.size() > mini.size()+1) 
        {
            mini.insert(*maxi.begin());
            maxi.erase(maxi.begin());
        }
        if(mini.size() > maxi.size()+1) 
        {
            maxi.insert(*mini.begin());
            mini.erase(mini.begin());
        }
            
        if(j-i+1 == k) 
        {
            double val;
            val = maxi.size() >= mini.size() ? *maxi.begin() : *mini.begin();
            ans.push_back(val);
                
            if(maxi.find(nums[i]) != maxi.end()) 
            {
                maxi.erase(maxi.find(nums[i]));
            }
            else if(mini.find(nums[i]) != mini.end()) 
            {
                mini.erase(mini.find(nums[i]));
            }   
            i++;
        }
    }
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
