class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long a, long long e) {
        long long res = 1;
        while (e) {
            if (e & 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }

    int countAnagrams(string s) {
        // precompute factorials up to max len = 1e5
        int maxLen = s.size();
        vector<long long> fact(maxLen + 1, 1), invFact(maxLen + 1, 1);
        for (int i = 1; i <= maxLen; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[maxLen] = modPow(fact[maxLen], MOD - 2);
        for (int i = maxLen - 1; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;

        long long ans = 1;
        int i = 0, n = s.size();
        while (i < n) {
            // get one word
            int j = i;
            while (j < n && s[j]!= ' ') j++;
            int L = j - i; // length of word

            int freq[26] = {0};
            for (int k = i; k < j; k++) freq[s[k] - 'a']++;

            long long ways = fact[L];
            for (int f : freq) {
                if (f > 1) ways = ways * invFact[f] % MOD;
            }
            ans = ans * ways % MOD;
            i = j + 1; // skip space
        }
        return ans;
    }
};