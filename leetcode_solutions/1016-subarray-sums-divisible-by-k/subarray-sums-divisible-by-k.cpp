class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int n=nums.size();
        int curr=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
             curr+=nums[i];
             int rem=(curr%k+k)%k;
             if(mp.count(rem))
             res+=mp[rem];
             mp[rem]++;
        }
        return res;
    }
};