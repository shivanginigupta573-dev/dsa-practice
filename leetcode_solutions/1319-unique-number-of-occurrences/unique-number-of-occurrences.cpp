class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
          mp[arr[i]]++;
        }
        unordered_set<int>set;
        for(auto it :mp)
        {
            int freq=it.second;
            if(set.count(freq))
            return false;
            set.insert(freq);

        }
        return true;
    }
};