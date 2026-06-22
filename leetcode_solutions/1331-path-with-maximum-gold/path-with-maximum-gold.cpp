class Solution {
public:
     int solver(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>&vis)
     {
        //base cases
        if(i<0||j<0||i>=m||j>=n)
        return 0;
        if(grid [i][j]==0)
        return 0;
        if(vis[i][j]==1)
        return 0;
        //boundary conditions
        
        vis[i][j]=1;
        int gold=grid[i][j]+max({ solver(grid,i-1,j,m,n,vis),
                        solver(grid,i,j-1,m,n,vis),
                        solver(grid,i+1,j,m,n,vis),
                        solver(grid,i,j+1,m,n,vis),
        });
        vis[i][j]=0;
        return gold;

     }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int  ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0){
                ans=max(ans,solver(grid,i,j,m,n,vis));
                }
            }
        }
        return ans;
        
    }
};