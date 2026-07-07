class Solution {
public:
    bool dfs(int node,int color,vector<vector<int>>&adj,vector<int>&vis)
    {
       vis[node]=color;
       for( int nei:adj[node])
       {
          if(vis[nei]==0)
            {
                if(!dfs(nei,-color,adj,vis))
                return false;
            }
            else
            {
                if(vis[nei]==vis[node])
                return false;
            }
       }
       return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for( auto & x:dislikes)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(!dfs(i,1,adj,vis))
                return false;
            }
        }
        return true;
    }
};