class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
       unordered_map<int, pair<int, int>> mp; 
        for(int num:nums)
        {
            if(mp.find(num) != mp.end()) {
                mp[num].second++;
                continue;
            }
            int x=num;
            int maxm=0;
            int minm=9;
            while(x>0)
            {
                int d=x%10;
                maxm=max(maxm,d);
                minm=min(minm,d); 
                x=x/10;  

            }
             mp[num] = {maxm - minm, 1};
        }
        int maxm=INT_MIN;
        long ans=0;
        for(auto & it : mp) {
            if(it.second.first > maxm) {
                maxm = it.second.first;
            }
        }
        
        for(auto & it : mp) {
            if(it.second.first == maxm) {
                // Multiply the number by its frequency to account for duplicates
                ans += (long)it.first * it.second.second; 
            }
        }
        
        return ans;

    }
};