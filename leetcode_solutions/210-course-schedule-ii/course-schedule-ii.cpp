class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int>&vis,vector<int>&order)
    {
        vis[node]=1;
        //visit the neighbours of node
        for( auto it :adj[node])
        {
             if(vis[it]==0)
             {
                //do traversal
                if(dfs(it,adj,vis,order)==false)
                return false;

             }
             else if(vis[it]==1)
             {
                return false;
             }
        }
        vis[node]=2;
        order.push_back(node);
        return true;
    }

    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int> vis(numCourses,0);
        vector<int> order;
        for(auto& pre:prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }
        for(int i=0;i<numCourses;i++)
        {
           if(vis[i] == 0)
            if(!dfs(i, adj, vis,order))
                return {};
        }
       // reverse(order.begin(), order.end());
        return order;
       
    }
};