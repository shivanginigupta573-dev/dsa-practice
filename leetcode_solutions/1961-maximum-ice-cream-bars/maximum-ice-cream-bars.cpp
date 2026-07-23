class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxC=* max_element(costs.begin(),costs.end());
        unordered_map<int,int>freq(maxC+1);
        for(int c:costs)
        {
            freq[c]++;
        }
        int ans=0;
       for(int p=1;p<=maxC+1;p++)
       {
        if(freq[p]==0)
        continue;
        if(coins<p)
        {
            break;
        }
        int canBuy=min(freq[p],coins/p);
        ans+=canBuy;
        coins-=canBuy*p;
        if(coins<p)
        break;
       }
        return ans;
    }
};