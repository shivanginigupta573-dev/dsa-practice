class Solution {
public:
    int findMin(vector<int>& nums) {
         if(nums.size()==1)
         {
            return nums[0];
         }
         int l=0,r=nums.size()-1;
        int minm=INT_MAX;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r])
            {
                minm=nums[mid+1];
                l=mid+1;
            }
            else
            {
                minm=min(minm,nums[mid]);
                r=mid;
            }
        }
        return minm;
    }
};