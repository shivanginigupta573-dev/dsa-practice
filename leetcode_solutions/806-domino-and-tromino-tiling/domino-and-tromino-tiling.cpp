class Solution {
public:
int MOD=1e9+7;
    long long solve(int i,vector<int>&memo)
    {
        if(i==1 || i==2)
        return i;
        if(i==3)
        return 5;
        if(memo[i]!=-1)
        return memo[i];
        return memo[i]=(2*solve(i-1,memo)+solve(i-3,memo))%MOD;
    }
    int numTilings(int n) {
        vector<int>memo(n+1,-1);
        return solve(n,memo);
    }
};
/*
Grid Construction DP basically a recursion if we draw some  basic combinations 2 3  then recurrence relationn . 
  F(N) = 2 * F(N-1) + F(N-3)
 base cases F(1) = 1, F(2) = 2, F(3) = 5  Always apply modulo 1e9 + 7 at each addition step to prevent integer overflow
*/