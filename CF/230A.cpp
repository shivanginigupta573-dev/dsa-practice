#include<bits/stdc++.h>
using namespace std;
void solve(int s,int n,vector<pair<int,int>>xy)
{
    sort(xy.begin(),xy.end());
    for(int i=0;i<n;i++)
    {
        if(s>xy[i].first)
        {
            s=s+xy[i].second;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    int s,n;
    cin>>s>>n;
    vector<pair<int,int>>xy(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        xy[i]={x,y};
    }
    solve ( s,n,xy);
}