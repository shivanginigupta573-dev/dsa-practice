class Solution {
public:
    bool solve(int idx,vector<int>&nums,vector<int>&sides,int target)
    {
        if(idx==nums.size())
        {
            if(sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target)
            {
                return true;
            }
        }
        int stick=nums[idx];
        //loop through all sides
        for(int i=0;i<4;i++)
        {
            if(sides[i]+stick>target)
            continue;
            //skip duplicate bucket states
            if(i>0 && sides[i]==sides[i-1])
            continue;
            sides[i]+=stick;
            if(solve(idx+1,nums,sides,target))
            return true;
            sides[i]-=stick;//backtrack;
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4!=0)
        return false;
        if(n<4)
        return false;
        sort(nums.rbegin(), nums.rend());
        vector<int> sides(4, 0);
        return solve(0, nums, sides, sum / 4);
        
    }
};