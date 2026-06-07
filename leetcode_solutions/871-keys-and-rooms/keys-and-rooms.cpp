class Solution {
public:
//adjacency list given so bfs but dfs can also be performed
    void bfs(vector<vector<int>>&rooms,vector<int>&vis ,queue<int>&q)
    {    
        while(!q.empty())
        {
          int curr=q.front();
          q.pop();
          for(int key:rooms[curr])
          {
            if(!vis[key])
            {
                vis[key]=1;
                q.push(key);
            }
          }

        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
         vector<int>vis(n,0);
         queue<int>q;
         vis[0]=1;
         q.push(0);
        bfs(rooms,vis,q);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            return false;
        }
        return true;
    }
};