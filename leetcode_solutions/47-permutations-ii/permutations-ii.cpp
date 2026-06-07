class Solution {
public:
void solver(int n,vector<int>&nums,vector<int>&arr,vector<vector<int>>&ans,vector<int>& vis)
{
    if(arr.size()==n){
      ans.push_back(arr);
      return ;
    }
      //recurse
      for(int i=0;i<n;i++)
      {
        if(vis[i] == 1)
         continue;
            if(i>0 && nums[i]==nums[i-1] && vis[i-1]==0) {
                continue;
            }
            vis[i] = 1;
            arr.push_back(nums[i]);
            solver(n, nums, arr, ans, vis);
            arr.pop_back();
            vis[i] = 0;
      }  
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>arr;
        vector<int>vis(n,0);
        sort(nums.begin(),nums.end());
        solver(n,nums,arr,ans,vis);
        return ans; 

    }
};