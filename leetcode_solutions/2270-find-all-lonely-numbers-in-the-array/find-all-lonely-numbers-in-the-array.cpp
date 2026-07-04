class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums)
        {
            mp[num]++;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]+1)== false && mp.count(nums[i]-1)==false && mp[nums[i]]==1)
            ans.push_back(nums[i]);
        }
        return ans;
    }
};