class Solution {
public:
 bool isPalindrome(string &s,int i,int j)
     {
        while(i<=j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
     }
   void solver(string &s, int i, int n, vector<string> &strarr,vector<vector<string>> &ans) {
        if (i==n) {
            ans.push_back(strarr);
            return;
        }
        for (int j=i;j<n;j++) {
            if (isPalindrome(s,i,j) ){
                strarr.push_back(s.substr(i, j-i+1));
                solver(s, j+1, n, strarr, ans);
                strarr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
     int n=s.length();
     vector<vector<string>>ans;
     vector<string>strarr;
     solver(s,0,n,strarr,ans);
     return ans;

    }
};