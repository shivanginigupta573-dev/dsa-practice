class Solution {
public:
  int editDistance(string &x,string &y,int i,int j,vector<vector<int>>& memo)
  {
       if(i==0 )
       return j;
       if(j==0)
       return i;
       
       if(memo[i][j]!=-1 ){
        return  memo[i][j];
       }
       if(x[i-1]==y[j-1])
       {
        return memo[i][j]=editDistance(x,y,i-1,j-1,memo);
       }
       else
       {
        return memo[i][j]=1+min(min(editDistance(x,y,i-1,j-1,memo),editDistance(x,y,i-1,j,memo)), editDistance(x,y,i,j-1,memo));
       }
  }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        return editDistance(word1,word2,n,m,memo);
        
    }
};