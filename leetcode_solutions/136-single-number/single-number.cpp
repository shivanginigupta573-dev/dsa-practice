class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i,XOR=0;
        for(i=0;i<nums.size();i++)
        {
            XOR=XOR^nums[i];
        }
        return XOR;
        
        
    }
};