class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[node]=1;
        //now check neighbours
        for(auto & nei:adj[node])
        {
            if(vis[nei]==0)
            {
                if(!dfs(nei,adj,vis))
                return false;
            }
           else if(vis[nei]==1)//cycle is found same node visited again in the path
            {
                return false;
            }

        }
        vis[node]=2;
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        
        vector<int>vis(numCourses,0);
        for(auto & pre:prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }
        for(int i =0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(!dfs(i,adj,vis))
                return false;
            }
        }
      return true;
        
    }
};