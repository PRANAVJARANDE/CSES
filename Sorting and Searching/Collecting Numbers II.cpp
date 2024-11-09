#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int change(int pos,int num,vector<int>&a,int n)
{
    int ans=0;
    if(pos>0)
    {
        if(a[pos-1] < a[pos] && a[pos-1]>=num)ans++;
        if(a[pos-1] > a[pos] && a[pos-1]<=num)ans--;
    }
    if(pos<n-1)
    {
        if(a[pos+1] < a[pos] && a[pos+1]>=num)ans--;
        if(a[pos+1] > a[pos] && a[pos+1]<=num)ans++;    
    }
    a[pos]=num;
    return ans;
}

void solve()
{
    int n,m;cin>>n>>m;
    vector<int> nums(n);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        nums[i]--;
        a[nums[i]]=i;
    }
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i])ans++;
    } 

    while(m--)
    {
        int i,j;cin>>i>>j;
        i--;
        j--;
        int a1=min(nums[i],nums[j]),a2=max(nums[j],nums[i]);
        int l1=a[a1],l2=a[a2];
        swap(nums[i],nums[j]);
        ans+=change(a1,l2,a,n);
        ans+=change(a2,l1,a,n);
        cout<<ans<<endl;
    }
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
