class Solution {
public:
    int solve(vector<int>& arr, int k, vector<int>& memo, int i) {
        if (i>=arr.size()) {
            return 0;
        }
        if (memo[i]!=-1) {
            return memo[i];
        }

        int max_val=0;
        int max_ans=0;
        int n=arr.size();
        for (int len=1; len<=k && i+len-1<n;len++) {
            max_val=max(max_val, arr[i+len-1]);
            int current_sum = (max_val*len)+solve(arr,k,memo,i+len);
            max_ans=max(max_ans, current_sum);
        }
        return memo[i]=max_ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> memo(arr.size(), -1);
        return solve(arr, k, memo, 0);
    }
};