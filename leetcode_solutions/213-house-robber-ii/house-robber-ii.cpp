class Solution {
public:
    int robHouse(vector<int>&nums,int i,int j)
    {
        int n=j-i+1;
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=nums[i-1];//1 based 
        for(int k=2;k<=n;k++)
        {
            dp[k]=max(nums[i+k-2]+dp[k-2],dp[k-1]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        if(n==1)
        {
            return nums[0];
        }
        int x1=robHouse(nums,1,n-1);
        int x2=robHouse(nums,2,n);
        return max(x1,x2);
        
    }
};