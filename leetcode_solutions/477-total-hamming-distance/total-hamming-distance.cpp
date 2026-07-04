class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long long total= 0;
        int n = nums.size();

        for(int i = 0; i < 32; i++) {
            int ones = 0;
            for(int num : nums)
                if(num & (1 << i)) ones++;
            total += 1LL * ones * (n - ones);
        }
        return total;
    }
};