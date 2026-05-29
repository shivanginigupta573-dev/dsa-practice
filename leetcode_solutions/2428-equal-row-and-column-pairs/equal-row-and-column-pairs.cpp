class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>rows;
        unordered_map<int,vector<int>>cols;
        //row traversal
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                rows[i].push_back(grid[i][j]);
                cols[i].push_back(grid[j][i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(rows[i]==cols[j]) {
                    ans++;
                }
            }
        } 
        return ans;
    }
};