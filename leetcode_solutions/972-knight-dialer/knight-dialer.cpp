class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;
        // neighbors[i] = digits you can reach from digit i
        vector<vector<int>> moves = {
            {4,6}, // 0
            {6,8}, // 1
            {7,9}, // 2
            {4,8}, // 3
            {0,3,9}, // 4
            {}, // 5
            {0,1,7}, // 6
            {2,6}, // 7
            {1,3}, // 8
            {2,4} // 9
        };
        vector<vector<long long>> dp(n+1,vector<long long>(10 ,0));//dp[i][d]=len i ending with digit d
        for(int d=0;d<=9;d++)
        {
            dp[1][d]=1;//with length onr we can hav 10 ways one on each
        }
        for(int len=2;len<=n;len++)
        {
            for(int d=0;d<=9;d++)
            {
                for(int prev:moves[d])
                {
                    dp[len][d]=(dp[len][d]+dp[len-1][prev])%MOD;
                }
            }
        }
        long long ans=0;
        for(int d=0;d<=9;d++)
         ans=(ans+dp[n][d])%MOD;
         return ans;
    }
};