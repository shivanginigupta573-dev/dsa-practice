class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
    int n=grid[0].size();
    int fresh=0,x,y;
    queue<pair<int,int>>q;
   vector<vector<int>> vis(m, vector<int>(n, 0));
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({i,j});
            }
            else if(grid[i][j]==1)
            {
                fresh++;
            }
        }
    }
    int minutes=0;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    //int f=0;
    while(!q.empty())
    {  
        int size=q.size();//number of nodes at the current level
        for(int i=0;i<size;i++)
        {
            auto [x,y]=q.front();
            q.pop();
            //spread across all the four neighbours
           
                 for(int d=0; d<4; d++) 
                 {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1) {
                        fresh--;
                        grid[nx][ny] = 2;  // mark as rotten
                        q.push({nx, ny});
                    }
                 }
            
        }
        
        if(!q.empty()) minutes++; //one level complete
        
    }
      return fresh==0?minutes:-1;
    }
};