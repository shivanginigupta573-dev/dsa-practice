class Solution {
public:
int solve(vector<int>&nums,int i,vector<int>&memo)
{
       int n=nums.size();
        if(i>=n)
        return 0;
        if(memo[i]!=-1)
        return memo[i];
        //we can take or skip that house following the constraint
        int take=nums[i]+solve(nums,i+2,memo);
        int skip=solve(nums,i+1,memo);
        memo[i]=max(take,skip);
        return memo[i];
}
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        return solve(nums,0,memo);//start with the first house
       
    }
};