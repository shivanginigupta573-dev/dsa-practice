class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //floyds algorithm linked list problem
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];//1 jump
            fast=nums[nums[fast]];//2 jump
        }while(slow!=fast);//we found a cycle
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};