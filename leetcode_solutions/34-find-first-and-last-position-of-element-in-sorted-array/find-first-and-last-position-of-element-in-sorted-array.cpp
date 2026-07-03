class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int beg=0;
        int end=nums.size()-1;
        while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
            if(target==nums[mid])
            {
                //now choose the starting index
                int start=mid;
                int last=mid;
                while (start > 0 && nums[start - 1] == target) {
                    start--;
                }
                
                // Expand rightward as long as we see the target
                while (last < nums.size() - 1 && nums[last + 1] == target) {
                    last++;
                }
                
                ans[0] = start;
                ans[1] = last;
                return ans; 
            }
            else if(target>nums[mid])
            {
                beg=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};