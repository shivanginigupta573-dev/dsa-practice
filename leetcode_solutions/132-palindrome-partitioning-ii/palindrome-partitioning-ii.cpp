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
      int solve(string &s,int i,int j,vector<vector<int>>&memo)
      {
        if(i>=j)
        {
            return 0;
        }
        if(isPalindrome(s,i,j))
          return 0;
        if(memo[i][j]!=-1)
        return memo[i][j];
         int minm=INT_MAX;
          for(int k=i;k<=j-1;k++)
          {
            if(isPalindrome(s,i,k)) 
            {
                int temp=1+solve(s,k+1,j,memo);
                minm = min(temp, minm);
            }
          }
          return memo[i][j]=minm;
      }
    int minCut(string s) {
        //concept of matrix multiplication
        int n=s.length();
        vector<vector<int>>memo(n,vector<int>(n,-1));
        return solve(s,0,n-1,memo);

    }
};