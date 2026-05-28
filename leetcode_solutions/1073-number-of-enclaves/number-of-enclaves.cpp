class Solution {
public:
  void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&grid,int n,int m)
  {
    vis[x][y]=1;
    //now we will traverse the depth first
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    for(int d=0;d<4;d++)
    {
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1)
        {
            dfs(nx,ny,vis,grid,n,m);
        }
    }
  }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
        //dfs only on boundary cells
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((i==0||i==n-1||j==0||j==m-1) && grid[i][j]==1 && !vis[i][j]) {
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};