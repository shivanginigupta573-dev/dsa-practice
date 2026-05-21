#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;  // currently visiting
    
    for(auto neighbor : adj[node]) {
        if(vis[neighbor] == 0) {
            if(!dfs(neighbor, adj, vis))
                return false;  // cycle found deeper
        }
        else if(vis[neighbor] == 1) {
            return false;  // cycle found
        }
        // vis==2 means already done, skip
    }
    
    vis[node] = 2;  // fully done
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    vector<int> vis(numCourses, 0);
    
    for(auto& pre : prerequisites)
        adj[pre[0]].push_back(pre[1]);
    
    for(int i = 0; i < numCourses; i++)
        if(vis[i] == 0)
            if(!dfs(i, adj, vis))
                return false;
    
    return true;
}