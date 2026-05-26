class Solution {
public:
    // YOUR FIND FUNCTION (with 1-line path compression tweak)
    int find(vector<int>& arr, int x) {
        if (arr[x] == -1) {
            return x; 
        }
        // Path compression: updates arr[x] dynamically during recursion
        return arr[x] = find(arr, arr[x]); 
    }

    // THE CORE ENGINE
    // Change return type based on what the problem asks (int, bool, vector<int>)
    int solveUnionFind(int n, vector<vector<int>>& edges) {
        // 1. Initialize your array
        vector<int> arr(n, -1); // Use n + 1 if nodes are 1-indexed!
        
        // 2. Initialize tracking variables (Pick what you need based on the pattern below)
        int components = n; 
        int redundant_edges = 0;

        // 3. Loop through edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int rootU = find(arr, u);
            int rootV = find(arr, v);

            if (rootU == rootV) {
                // TWEAK PLACEHOLDER A: They are already connected!
                redundant_edges++; 
            } else {
                // TWEAK PLACEHOLDER B: They are in different components, merge them!
                arr[rootV] = rootU; // Union step
                components--;
            }
        }

        // 4. Return final insight
        return components; 
    }
};