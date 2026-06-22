class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int i;
        int n=nums.size();
        long long maxm=*max_element(nums.begin(),nums.end());
        long long minm=*min_element(nums.begin(),nums.end());
        return (long  long)k*(maxm-minm);
        
        
    }
};