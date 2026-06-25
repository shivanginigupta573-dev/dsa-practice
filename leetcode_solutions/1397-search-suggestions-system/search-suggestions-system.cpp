class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>res;
        sort(products.begin(),products.end());
        string prefix = "";
        auto it = products.begin();

        for (char c : searchWord) {
            prefix += c;
            it = lower_bound(it, products.end(), prefix); // starting from last pos
            vector<string> tmp;
            for (auto i = it; i < min(it + 3, products.end()) && i->substr(0, prefix.size()) == prefix; i++) {
                tmp.push_back(*i);
            }
            res.push_back(tmp);
        }
        return res;
    }
};