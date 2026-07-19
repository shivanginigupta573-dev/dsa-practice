class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> freq;
        int ans=0;

        for(int t:time) {
            int a=t%60;
            int b=(60-a)%60;

            if(freq.count(b)) 
            ans+=freq[b];

            freq[a]++; 
        }
        return ans;
    }
};