class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int c=0;
        unordered_map<int,int>mp;
        for( auto i:nums)
        {
            mp[i]++;
        }
        vector<pair<int,int>>nums2(mp.begin(),mp.end());
        //use lambda function
        sort(nums2.begin(),nums2.end(),[](const auto & a,const auto & b){
           return a.second>b.second;
        });
        for(auto & it:nums2)
        {
            if(c==k)
            break;
            if(c<k)
            ans.push_back(it.first);
            c++;

        }

      return ans;
    }
};