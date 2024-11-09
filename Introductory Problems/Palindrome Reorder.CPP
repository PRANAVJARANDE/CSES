#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;cin>>s;
    int n=s.size();
    unordered_map<char,int>m;
    for(char x: s)
    {
        m[x]++;
    }
    char ch='-';
    int c=0;
    for(auto i: m)
    {
        if((i.second)%2==1)
        {
            c++;
            ch=i.first;
        }
    }
    if(c>1)
    {
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    string ans;
    for(auto i: m)
    {
        if((i.first)==ch)continue;
        for(int j=0;j<(i.second)/2;j++)
        {
            ans+=i.first;
        }
    }
    string t=ans;
    reverse(t.begin(),t.end());
    if(ch!='-')
    {
        for(int i=0;i<m[ch];i++)
        {
            ans+=ch;
        }
    }
    ans=ans+t;
    cout<<ans<<endl;

}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
