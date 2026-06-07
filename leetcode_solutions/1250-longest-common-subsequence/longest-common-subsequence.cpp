class Solution {
public:
   int lcs(string & x,string &y,int i,int j,vector<vector<int>>& memo)
   {
        if(i==0||j==0)
        return 0;
        if(memo[i][j]!=-1 )
        return  memo[i][j];
        if(x[i-1]==y[j-1])
        {
         return memo[i][j]=1+lcs(x,y,i-1,j-1,memo);
        }
        else
        {
           return  memo[i][j]=max(lcs(x,y,i-1,j,memo),lcs(x,y,i,j-1,memo));    
        }

   }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        return lcs(text1,text2,n,m,memo);
        
    }
};
//Recu