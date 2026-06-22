class Solution {
public:
    bool dfs(int node,int color,vector<vector<int>>& graph,vector<int>&vis)
    {
        vis[node]=color;
        for(auto & nei:graph[node])
        {
            if(vis[nei]==0)
            {
                if(!dfs(nei,-color,graph,vis))
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(!dfs(i,1,graph,vis))
                {
                    return false;
                }
            }
        }
return true;
        
    }
};