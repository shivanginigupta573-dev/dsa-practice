class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        for(int x:arr1)
        {
            string s=to_string(x);
            for(int i=1;i<=s.size();i++)
        prefixes.insert(s.substr(0,i));
}

        int ans=0;
        for(int y:arr2) {
        string s=to_string(y);
        for(int i=1;i<=s.size();i++)
        if(prefixes.count(s.substr(0,i)))
            ans=max(ans,i);
}

return ans;
        }
    
};