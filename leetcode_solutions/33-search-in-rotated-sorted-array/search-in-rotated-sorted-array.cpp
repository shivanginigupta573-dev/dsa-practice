class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg,mid,end;
        beg=0;
        end=nums.size()-1;
        while(beg<=end)
        {
            mid=beg+(end-beg)/2;
            if(nums[mid]==target)    
            return mid;  
            //check which aprt is sorted
            //left part parted
            if(nums[beg]<=nums[mid])
            {   
                if(target>=nums[beg]&& nums[mid]>target)
                {
                    //eliminate the right half
                    end=mid-1;
                }
                //else eliminate the left half
                else
                {
                    beg=mid+1;
                }
            }
            //if right sorted
             else  if (nums[mid]<=nums[end])
            {   
                if(target>nums[mid]&& nums[end]>=target)
                {
                    //eliminate the left half
                    beg=mid+1;
                }
                //else eliminate the right half
                else
                {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};