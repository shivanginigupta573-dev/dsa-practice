class Solution {
public:
    void solve(int x,int target,int k,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(temp.size()==k)
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        for(int i=x;i<=9;i++)
        {
            temp.push_back(i);
            solve(i+1,target-i,k,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
      //  int arr[]={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,n,k,ans,temp);
        return ans;        
        
    }
};