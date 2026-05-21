class Solution {
public:
   bool solve(int i,unordered_set<string>&wordSet,string& s,vector<int>& memo)
   {
     
      if(i==s.size())
      {
        return true;
      }
      if(memo[i]!=-1)
      {
        return (bool)memo[i];
      }
      for(int j = i+1; j <= s.size(); j++) {
                string sub = s.substr(i, j-i);
                if(wordSet.count(sub) && solve(j, wordSet, s, memo))
                    return memo[i]=1;
            }
            return memo[i] =0;
    
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        vector<int>memo(n,-1);
        return solve(0,wordSet,s,memo);



    }
};