class Solution {
public:
queue<int>q;
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>>&q,int n)
     {
        int dx[]={0,0,1,-1,1,1,-1,-1};
        int dy[]={1,-1,0,0,1,-1,1,-1};
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            int current_distance=grid[x][y];
            if(x==n-1 && y==n-1)
            return current_distance;
        
        for(int d=0;d<8;d++)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0)
           {
                grid[nx][ny]=current_distance+1;
                q.push({nx,ny});
           }
        }
        }
         return -1;
     }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //starting with edge case
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)
        {
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        return bfs (grid,q,n);
        
        
    }
};