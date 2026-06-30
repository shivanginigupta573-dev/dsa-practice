class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        
        // cash: max profit if we do not hold a stock
        // hold: max profit if we hold a stock
        int cash = 0;
        int hold = -prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            // Store previous cash to use in the hold update
            int prev_cash = cash;
            
            // Update states
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, prev_cash - prices[i]);
        }
        
        return cash;
        
    }
};