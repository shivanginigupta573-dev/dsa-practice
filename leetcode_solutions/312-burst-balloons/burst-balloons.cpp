class Solution { 
public: 
    int maxCoins(vector<int>& nums) { 
        int n = nums.size(); 
        // Create an extended array bounded by virtual balloons of value 1
        vector<int> arr(n + 2, 1); 
        for(int i = 0; i < n; i++) {
            arr[i + 1] = nums[i]; 
        }

        // dp[i][j] represents the max coins from bursting balloons between i and j (exclusive)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); 

        // Classic interval DP: iterate the left boundary backwards
        for (int l = n; l >= 0; l--) {
            // The right boundary must be at least l + 2 to contain a balloon to burst
            for (int r = l + 2; r <= n + 1; r++) {
                // i is the last balloon to burst in the open interval (l, r)
                for (int i = l + 1; i < r; i++) { 
                    dp[l][r] = max(dp[l][r], dp[l][i] + dp[i][r] + arr[l] * arr[i] * arr[r]); 
                } 
            } 
        } 
        return dp[0][n + 1]; 
    } 
};
