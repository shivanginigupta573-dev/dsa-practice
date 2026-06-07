class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        if(n1!=n2)
        return false;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(char ch:word1)
        {
            mp1[ch]++;
        }
        for(char ch:word2)
        {
            mp2[ch]++;
        }
        for(auto it :mp1)
        {
           char curr=it.first;
           if(mp2.find(curr)==mp2.end())
           return false;
        }
        vector<int> f1,f2;
        for(auto it:mp1)
        {
            f1.push_back(it.second);
        }
        for(auto it:mp2)
        {
            f2.push_back(it.second);
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());

      return f1==f2;
        
    }
};