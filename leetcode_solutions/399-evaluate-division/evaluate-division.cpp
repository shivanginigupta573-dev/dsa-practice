class Solution {
public:
double dfs(string node, string& target, unordered_map<string, int>& vis, 
               unordered_map<string, unordered_map<string, double>>& g) {
        if (node == target) return 1.0;
        vis[node]=1;
        for (auto& nei : g[node]) {
            string next_node = nei.first;
            double weight = nei.second;
            if (vis[next_node] != 1) {
                double path_result = dfs(next_node, target, vis, g);
                if (path_result!=-1.0) {
                    return weight * path_result; 
                }
            }
        }
        
        return -1.0;
    }



    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string ,double>>g;
        for(int i=0;i<equations.size();i++)
        {
            string a=equations[i][0];
            string b=equations[i][1];
            double w=values[i];
            g[a][b]=w;
            g[b][a]=1.0/w;
        }
            vector<double> ans;
            for (auto& q : queries)
         {
            string src = q[0];
            string dst = q[1];
            if (g.find(src) == g.end() || g.find(dst) == g.end())
             {
                ans.push_back(-1.0);
            } else 
            {
                unordered_map<string, int> vis; // New visited map for each query
                ans.push_back(dfs(src, dst, vis, g));
            }
        }
        
        return ans;
        }
        
    
};