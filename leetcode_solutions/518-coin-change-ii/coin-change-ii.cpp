class Solution {
public:
     int solve(vector<int>& coins,int amount,int i,int n,vector<vector<int>>&memo)
     {
           // 
           if(amount==0)
           return 1;
           if(amount<0)
           return 0;
           if(i==n)//coins over
           return 0;
           if(memo[i][amount]!=-1)
           return memo[i][amount];
           int take=solve(coins,amount-coins[i],i,n,memo);
           int skip=solve(coins,amount,i+1,n,memo);
           return memo[i][amount]=take+skip;
           
     }

    int change(int amount, vector<int>& coins) {
        //similar to unbounded kanpsack subtract the target
        int n=coins.size();
        int sum=0;
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));
        return solve(coins,amount,0,n,memo);
    }
};