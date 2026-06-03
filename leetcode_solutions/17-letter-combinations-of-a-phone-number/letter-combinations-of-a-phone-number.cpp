class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // '' '' for 0 and 1 cuz nothing maps to it

      string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s = ""; 
        helper(0, digits, s, ans, combos);
        return ans; 
    }


    void helper(int idx, string digits,string s,vector<string>&ans,string combos[])   
    {
        if(idx==digits.size())//base case
        {
            ans.push_back(s);
            return;
        }
        int digit=digits[idx]-'0';
        for(int i=0;i<combos[digit].size();i++)
        {
            helper(idx+1,digits,s+combos[digit][i],ans,combos);
        }
    }  
    
};