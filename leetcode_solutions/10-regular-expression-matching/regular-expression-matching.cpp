class Solution {
public:
    bool solve(int i,int j,const string &s,const string &p,vector<vector<int>>&memo)
    {
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        if(j==p.size())
        {
            return memo[i][j]=(i==s.size());
        }
        bool first_match=i<s.size() && (p[j]==s[i]||p[j]=='.');

        bool ans;
        if(j+1<p.size() && p[j+1]=='*')
        {
            //skip x* or use x* if first matches
            ans=solve(i,j+2,s,p,memo)||(first_match && solve(i+1,j,s,p,memo));
        }
        else
        {
            ans=first_match && solve(i+1,j+1,s,p,memo);
        }
        return memo[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        //less abt regex more abt two pointers nd dp
        int n=s.size(),m=p.size();
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        return solve(0,0,s,p,memo);
        
    }
};