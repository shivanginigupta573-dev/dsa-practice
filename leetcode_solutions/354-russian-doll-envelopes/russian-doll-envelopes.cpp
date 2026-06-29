class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // width same -> height DESC
            return a[0] < b[0]; // width ASC
        });

        vector<int> lis;
        for (auto& e : envelopes) {
            int h = e[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) lis.push_back(h);
            else *it = h;
        }
        return lis.size();        
    }
};