class Solution {
public:
   void solver(int n,vector<int>&nums,vector<int>&arr,vector<vector<int>>& ans,vector<int>&vis)
   {  
      //base case
      if(arr.size()==n)
      {
        ans.push_back(arr);
        return;
      }
      //recursion
      for(int i=0;i<n;i++)
      {
        if(vis[i]==0)
        {
            vis[i]=1;
            arr.push_back(nums[i]);
            solver(n,nums,arr,ans,vis);
            //backtrack
            arr.pop_back();
            vis[i]=0;


        }
      }


   }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        int n=nums.size();
        vector<int>vis(n,0);
        solver(n,nums,arr,ans,vis);
        return ans;
    }
};