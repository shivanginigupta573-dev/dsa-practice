class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>map;
       for(string str:strs)
       {
          string sortedstr=str;
          sort(sortedstr.begin(),sortedstr.end());
          map[sortedstr].push_back(str);
       }
       //forming the answr array
       vector<vector<string>> ans;
       for(auto& x:map)
       {
          ans.push_back(x.second);
       }
        return ans;
    }
};