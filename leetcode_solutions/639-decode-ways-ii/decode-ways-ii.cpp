class Solution {
public:
    int const m=1e9+7;
    int numDecodings(string s) {
        int n=s.size();
        if(n==0||s[0]=='0')
         return 0;
        vector<long long>dp(n+1,0);
        dp[0]=1;
        dp[1]=s[0]=='*'?9:1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]!='0')
            {
                if(s[i-1]=='*')
                {
                    dp[i]=(dp[i]+9LL*dp[i-1])%m;                }
                else
                {
                    dp[i]=(dp[i]+dp[i-1])%m;
                }
            }
            char prev = s[i-2], curr = s[i-1];
            if (prev == '*' && curr == '*') {
                dp[i] = (dp[i] + 15LL * dp[i-2]) % m;
            } else if (prev == '*') {
                if (curr <= '6')
                 dp[i] = (dp[i] + 2LL * dp[i-2]) % m;
                else 
                 dp[i] = (dp[i] + dp[i-2]) % m;
            } else if (curr == '*') 
            {
                if (prev == '1') 
                 dp[i] = (dp[i] + 9LL * dp[i-2]) % m;
                else if (prev == '2') 
                 dp[i] = (dp[i] + 6LL * dp[i-2]) % m;
            } else {
                int val = (prev - '0') * 10 + (curr - '0');
                if (val >= 10 && val <= 26) {
                    dp[i] = (dp[i] + dp[i-2]) % m;
                }
            }
        }

        return dp[n];
    }
};