#include<bits/stdc++.h>
using namespace std;
void solve(string s,int n,int m,vector<pair<int,int>>&lr)
{
    vector<int>pref(n,0);
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1];
        if(s[i]==s[i-1])
        {
            pref[i]++;
        }
    }
        for(int i=0;i<m;i++)
        {
            cout<<pref[lr[i].second-1]-pref[lr[i].first-1]<<endl;
        }
    
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int m;
    cin>>m;
    vector<pair<int,int>>lr(m);
    for(int i=0;i<m;i++)
    {
        cin >> lr[i].first >> lr[i].second;
    }
    solve(s,n,m,lr);
}
