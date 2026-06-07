class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=0,i;
        int len=nums.size();
        for(i=0;i<len;i++)
        {  

            if(i>jump)
            {
                return false;
            }
            jump=max(jump,i+nums[i]);
        }
       return true;
        
    }
};