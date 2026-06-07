class Solution {
public:
   int lcs(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&memo)
   {
     if(i==0||j==0)
     {
        return 0;
     }
     if(memo[i][j]!=-1)
     {
        return memo[i][j];
     }
     if(nums1[i-1] == nums2[j-1])
     {
        return memo[i][j]=1+lcs(i-1,j-1,nums1,nums2,memo);
     }
     else
     {
        return memo[i][j]=max(lcs(i-1,j,nums1,nums2,memo),lcs(i,j-1,nums1,nums2,memo));
     }
   }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        // this is same as longest common subsiquesnce but on array just look at 
        //the example
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        return lcs(n,m ,nums1,nums2,memo);
    }
};