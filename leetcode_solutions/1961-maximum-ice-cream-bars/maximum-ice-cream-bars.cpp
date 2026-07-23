class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n=costs.size();
        int ans=0;
        int i=0;
        for (int i = 0; i < costs.size(); ++i) {
            if (coins < costs[i]) {
                return i;
            }
            coins -= costs[i];
        }
        
        return costs.size(); 
    }
};