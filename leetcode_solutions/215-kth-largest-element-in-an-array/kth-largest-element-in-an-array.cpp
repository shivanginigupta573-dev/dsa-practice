class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return Partition(nums, k);
        
    }
    int Partition(vector<int> &nums, int k){
     int   len=nums.size();
    int pivot = nums[len-1]; //let the lasr elemnt be the pivot
    vector<int> leftnums;
    vector<int> midnums; 
    vector<int> rightnums; 
    for (int i=0;i<len;i++){
        if (nums[i] > pivot){
            leftnums.push_back(nums[i]); 
        }
        else if (nums[i] < pivot){
            rightnums.push_back(nums[i]); 
        }
        else{
            midnums.push_back(nums[i]); 
        }
    }
    if (k <= leftnums.size()){
        return Partition(leftnums, k);
    }
    if (leftnums.size() + midnums.size() < k){
        return Partition(rightnums, k - leftnums.size() - midnums.size());
    }
    return pivot;


}
};