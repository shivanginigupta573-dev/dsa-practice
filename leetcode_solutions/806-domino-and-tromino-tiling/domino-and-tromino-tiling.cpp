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