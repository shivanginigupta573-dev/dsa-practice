class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //since minimum cost is asked we will use dp
        int n=cost.size();
        vector<int>dp(n+1);
        dp[0]=0;//for 0 stairs we need 0 steps
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};