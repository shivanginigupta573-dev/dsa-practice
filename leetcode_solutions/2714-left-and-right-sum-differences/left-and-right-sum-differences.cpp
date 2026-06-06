class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftSum;
        vector<int>rightSum;
        leftSum.push_back(0); 
        int left=0,right=0;
        for(int i=0;i<n;i++)
        {
            left=left+nums[i];
            leftSum.push_back(left);
            right=right+nums[n-i-1];
            rightSum.push_back(right);
        }
        rightSum.pop_back();
        reverse(rightSum.begin(),rightSum.end());
        rightSum.push_back(0);
        leftSum.pop_back();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return ans;
    }
};