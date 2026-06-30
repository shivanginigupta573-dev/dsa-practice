class Solution {
public:
    void solve(int idx,string digits,vector<string>&ans,string combos[],string s)
    {
        int n=digits.size();
        if(idx==n)
        {
            ans.push_back(s);
            return;
        }
        int d=digits[idx]-'0';
        for(int i=0;i<combos[d].size();i++)
        {
           solve(idx+1,digits,ans,combos,s+combos[d][i]);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string combos[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//empty for  zero and 1
        string s="";
        solve(0,digits,ans,combos,s);
        return ans;
        
    }
};