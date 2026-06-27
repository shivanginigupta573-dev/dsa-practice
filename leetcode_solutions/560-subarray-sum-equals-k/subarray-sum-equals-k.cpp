class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
           prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        unordered_map<int,int >freq;
        // for(int num:prefixSum)
        // {
        //     freq[num]++;
        // }
        int ans=0;
        for(int num:prefixSum )
        {
              if(num==k)
              {
                ans++;
              }
            if(freq.count(num-k))
              ans=ans+freq[num-k];
              freq[num]++;
        }
        return ans;
    }
};