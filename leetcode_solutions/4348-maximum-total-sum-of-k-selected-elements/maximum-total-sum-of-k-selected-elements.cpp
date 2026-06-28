class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        
        sort(nums.rbegin(),nums.rend());
        long long totalsum=0;
        for(int i=0;i<k;i++)  
        {
             if(mul==0)
            {
                totalsum+=nums[i];
            }
        
            if(mul!=0 )
            {
                long long x=(long long)nums[i]*mul;
                totalsum+=x;
                mul--;
            }
        }
        return totalsum;
    }
};