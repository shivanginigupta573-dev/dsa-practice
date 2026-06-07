class Solution {
public:
    int lcs(int i,int j,string &s1,string &s2,vector<vector<int>>&memo)
    {
        if(i==0||j==0 )
        {
            return 0;
        }
        if(memo[i][j]!=-1)
        return memo[i][j];
        if(s1[i-1]==s2[j-1])
        {
           return memo[i][j]=1+lcs(i-1,j-1,s1,s2,memo);
        }
        else
        {
           return  memo[i][j]=max(lcs(i-1,j,s1,s2,memo),lcs(i,j-1,s1,s2,memo));
        }
    }

    int minInsertions(string s) { 
        //this is similar to lcs or lps just n-lps
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        return n-lcs(n,n,s,rev,memo);
    }
};