class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        freq[0] = 1; // prefix sum 0 seen once before start
        int sum = 0, res = 0;

        for (int x : nums) {
            sum += (x == target? 1 : -1);
            // need prev prefix sums < current sum
            // because sum_j - sum_i > 0 → sum_i < sum_j
            for (auto& [val, cnt] : freq) {
                if (val < sum) res += cnt;
            }
            freq[sum]++;
        }
        return res;
    }
    
};