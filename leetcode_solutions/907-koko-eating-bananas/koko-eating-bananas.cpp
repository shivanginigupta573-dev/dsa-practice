class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i, max = 0;
        for (i = 0; i < piles.size(); i++) {
            if (max < piles[i])  {
                max = piles[i];
            }
        }
        int low = 1, high = max, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) /2;
            long long totalhrs = helper(piles, mid);
            if (totalhrs <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    long long helper(vector<int>& piles, int h) {
        long long totalhrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalhrs += (piles[i] + h - 1) / h;
        }
        return totalhrs;
    }
};


