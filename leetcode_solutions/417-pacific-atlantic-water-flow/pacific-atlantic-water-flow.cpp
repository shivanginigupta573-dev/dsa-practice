class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& vis, vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n
                    &&!vis[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        if (m == 0 || n == 0) return {};

        queue<pair<int,int>> pacQ, atlQ;
        vector<vector<bool>> pacVis(m, vector<bool>(n, false));
        vector<vector<bool>> atlVis(m, vector<bool>(n, false));

        // init: Pacific = top row + left col
        for (int i = 0; i < m; i++) {
            pacQ.push({i, 0});
            pacVis[i][0] = true;
            atlQ.push({i, n-1});
            atlVis[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pacQ.push({0, j});
            pacVis[0][j] = true;
            atlQ.push({m-1, j});
            atlVis[m-1][j] = true;
        }

        bfs(pacQ, pacVis, heights);
        bfs(atlQ, atlVis, heights);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacVis[i][j] && atlVis[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};