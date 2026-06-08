class Solution {
public:
    bool solver(vector<vector<char>>& board, string& word, int i, int j, vector<vector<int>>& vis, int k, int m, int n) 
    {
        //base cases
        if(k==word.size())
        return true;
        if(i<0||j<0||i>=m||j>=n||vis[i][j]==1)
        return false;
        if(word[k]!=board[i][j])
        return false;
        vis[i][j]=1;
        //recurse up down left right
        bool found=solver(board,word,i-1,j,vis,k+1,m,n) || 
                     solver(board,word,i+1,j,vis,k+1,m,n) || 
                     solver(board,word,i,j-1,vis,k+1,m,n) || 
                     solver(board, word,i,j+1,vis,k+1,m,n); 
                     //backtrack
         vis[i][j]=0;
         return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
          for (int i=0;i<m;i++)
          {
            for(int j=0;j<n;j++)
            {
                if(solver(board,word,i,j,vis,0,m,n))
                return true;
            }
          }
      return false;
        
    }
};