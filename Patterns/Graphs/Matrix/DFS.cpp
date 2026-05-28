class Solution {
public:
    // THE ENGINE: Standard 4-Directional Grid Walk
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, int& cell_counter) {
        vis[x][y] = 1;
        cell_counter++; // MODULE PLUG-IN: Tracks size of the current component if needed

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            // Standard Safety Guard
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == 1) {
                dfs(nx, ny, grid, vis, m, n, cell_counter);
            }
        }
    }
};
/*
Pattern 1: Global Island Counter
The Problem Goal: Count the total number of disconnected landmasses anywhere in the grid.
Examples: LeetCode 200 (Number of Islands)
The Tweak: Run a standard nested loop across the entire matrix. Every time you hit an unvisited land cell,
 fire the DFS engine and increment your global island_count++.
----------------------------------------------------------------------------------------------------------
Pattern 2: Outside-In (Boundary Filtration)
The Problem Goal: You need to ignore or eliminate elements that can reach the edge of the matrix board.
Examples: LeetCode 1020 (Number of Enclaves), LeetCode 130 (Surrounded Regions)
The Tweak: Run your nested loops in two separate phases. Phase 1 restricts the conditional filter strictly 
o the borders (i == 0 || i == m-1 || j == 0 || j == n-1) to pre-visit all invalid nodes. Phase 2 processes 
only what remains unvisited in the interior.
-------------------------------------------------------------------------------------------------------
Pattern 3: Component Area Evaluator
The Problem Goal: Find the size or max capacity of the largest connected asset block.
Examples: LeetCode 695 (Max Area of Island)
The Tweak: Pass an explicit tracking integer reference (int& cell_counter) down through your DFS call stack. 
Every time a recursion node triggers (vis[x][y] = 1), increment cell_counter++. Track a global max tracking 
variable outside.
*/