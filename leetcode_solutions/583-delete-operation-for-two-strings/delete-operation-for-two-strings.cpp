class Solution {
public:
int lcs(int i,int j,string &s1 ,string & s2,vector<vector<int>>& memo)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        if(s1[i-1]==s2[j-1])
        {
            return memo[i][j]=1+lcs(i-1,j-1,s1,s2,memo);
        }
        else
        {
        
            return memo[i][j]=max(lcs(i-1,j,s1,s2,memo),lcs(i,j-1,s1,s2,memo));
        }
    }
    int minDistance(string word1, string word2) {
                //similar to lcs but th catch is whenver the letter does not match calculate the sum of ascii chracter
        //let's gooo
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        int x=lcs(n,m,word1,word2,memo);
        return (n+m)-(2*x);
    }
};