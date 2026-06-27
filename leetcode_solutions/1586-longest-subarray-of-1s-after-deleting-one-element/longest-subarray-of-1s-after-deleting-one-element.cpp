class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxLen=0;
         int l=0,r=0;
         int zero=0;
         while(r!=n)
         {
            if(nums[r]==0)
            {
                zero++;
            }
            while(zero>1 )
            {
               if(nums[l]==0)
               {
                zero--;
               }
               l++;
            }
             maxLen=max(maxLen,r-l+1);
             r++;
         }
        return (maxLen-1);
    }
};