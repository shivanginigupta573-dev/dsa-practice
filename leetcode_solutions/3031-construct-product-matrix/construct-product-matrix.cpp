class Solution {
public:
    int mod = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sz=n*m;

        vector<int>matrix(sz);
        vector<int>prefix(sz,1);
        vector<int>suffix(sz, 1);

        int k=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                matrix[k++]=grid[i][j];
            }
        }

        for (int i=1;i < sz; i++) {
            prefix[i] = (1LL * prefix[i - 1] * (matrix[i - 1] % mod)) % mod;
        }

        for (int i = sz - 2; i >= 0; i--) {
            suffix[i] = (1LL * suffix[i + 1] * (matrix[i + 1] % mod)) % mod;
        }

        vector<vector<int>> ans(n, vector<int>(m));

        k = 0;
        for (int i = 0; i < sz; i++) {
            int val = (1LL * prefix[i] * suffix[i]) % mod;
            ans[k / m][k % m] = val;
            k++;
        }

        return ans;
    }
};