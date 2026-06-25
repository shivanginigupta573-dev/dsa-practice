class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        string prefix="";
        for(char c:searchWord)
        {
            prefix+=c;
            vector<string>curr;
            for(string &p:products)
            {
                if(p.substr(0,prefix.size())==prefix)
                {
                    curr.push_back(p);
                }
                if(curr.size()==3)
                break;
            }
            ans.push_back(curr);
        }

       return ans; 
    }
};