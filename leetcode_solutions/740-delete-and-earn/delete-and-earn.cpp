class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxm=*max_element(nums.begin(),nums.end());
        vector<int>cnt(maxm+1,0);
        vector<int>dp(maxm+1,0);
        for(int num:nums)
         cnt[num]++;
        
        dp[1]=cnt[1];
        for(int i=2;i<=maxm;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
        }
       return dp[maxm];
    }
};