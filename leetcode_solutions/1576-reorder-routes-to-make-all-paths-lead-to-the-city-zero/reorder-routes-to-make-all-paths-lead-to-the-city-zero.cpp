class Solution {
public:
  int ans=0;
   void dfs(int node,vector<int> adj[],vector<int>&vis,set<pair<int, int>>&original)

   {
        vis[node]=1;
        for(auto & nei:adj[node])
        {
            if(vis[nei]!=1)
            {
               if(original.count({node,nei}))
                {
                    ans++;
                }
                dfs(nei,adj,vis,original);
            }
        }
   }
    int minReorder(int n, vector<vector<int>>& connections) {
        //hehe  naive approach passed only 71/77 lets try dfs
        //aim:Treat the graph as undirected. Start a dfs from the root, if you come 
        //across an edge in the forward direction, you need to reverse the edge.
        //form adjacency  list
        vector<int>adj[n];
        int len=connections.size();
        set<pair<int, int>> original;
        for(int i=0;i<len;i++)
        {
           adj[connections[i][0]].push_back(connections[i][1]);
           //undirected so both sides
           adj[connections[i][1]].push_back(connections[i][0]);
           original.insert({connections[i][0],connections[i][1]});

        }
        vector<int>vis(n,0);
        dfs(0,adj,vis,original);
        return ans;
    }
};