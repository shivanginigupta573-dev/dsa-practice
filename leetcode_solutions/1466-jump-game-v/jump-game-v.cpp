class Solution {
public:
    int n, d;
    vector<int> dp;

    int dfs(int i,vector<int>& arr) {
        if(dp[i]!=-1) return dp[i];
        int ans=1; 
        for(int x=1;x<=d;++x) {
            int j=i+x;
            if(j>=n) 
            break;
            if(arr[j]>=arr[i])
             break;
            ans = max(ans,1+dfs(j,arr));
        }
        for(int x=1;x<=d;++x) {
            int j=i - x;
            if(j < 0) 
            break;
            if(arr[j]>=arr[i]) 
            break;
            ans=max(ans,1+dfs(j,arr));
        }

        return dp[i]=ans;
    }

    int maxJumps(vector<int>& arr,int d) {
        n=arr.size();
        this->d=d;
        dp.assign(n,-1);

        int res=0;
        for(int i=0;i<n;++i) {
            res=max(res,dfs(i, arr));
        }
        return res;
    }
};