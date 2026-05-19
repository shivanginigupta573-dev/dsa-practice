class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && 
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            } else if (mid > 0 && nums[mid - 1] > nums[mid]) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return -1; // This should not be reached
    }
};

