#include<bits/stdc++.h>
using namespace std;

void dfs(int u,vector<vector<int>>&adj,vector<int>&vis,vector<int>&comp,int c)
{
    vis[u]=1;
    comp[u]=c;

    for(auto v:adj[u])
    {
        if(!vis[v])
            dfs(v,adj,vis,comp,c);
    }
}

void solve(int n,int x,int y,vector<int>&p)
{
    vector<vector<int>>adj(n);

    for(int i=0;i<n;i++)
    {
        if(i+x<n)
        {
            adj[i].push_back(i+x);
            adj[i+x].push_back(i);
        }

        if(i+y<n)
        {
            adj[i].push_back(i+y);
            adj[i+y].push_back(i);
        }
    }

    vector<int>vis(n,0),comp(n);
    int c=0;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,comp,c);
            c++;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(comp[i]!=comp[p[i]-1])
        {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;

        vector<int>p(n);

        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }

        solve(n,x,y,p);
    }

    return 0;
}