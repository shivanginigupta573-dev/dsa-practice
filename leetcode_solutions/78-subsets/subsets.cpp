class Solution {
public:
    void solve(int idx,vector<int>&nums, vector<vector<int>>&ans,vector<int>&arr)
    {
        if(idx<0)
        {
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[idx]);
        solve(idx-1,nums,ans,arr);
        arr.pop_back();
        solve(idx-1,nums,ans,arr);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(nums.size()-1,nums,ans,arr);
      return ans;
        
    }
};