/*
There are n cities. Some roads connections[i] = [x, y, cost] connecting city x and y with cost. Find minimum cost to connect all n cities (make graph connected). If impossible return -1.

Example:
n=3, connections = [[1][2][5],[1][3][6],[2][3][1]]
Answer: 6 -> Pick 2-3 cost 1, 1-2 cost 5 = 6

This is direct Kruskal.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int find(vector<int>& arr, int x)
{
    if(arr[x]==-1)
    {
        return x;
    }
    // Path compression added (only change from your code)
    return arr[x] = find(arr, arr[x]);
}

    int minimumCost(int n, vector<vector<int>>& connections) {
        // Sort by cost - imp for Kruskal
        sort(connections.begin(), connections.end(),
             [](vector<int>& a, vector<int>& b){
                 return a[2] < b[2];
             });

        vector<int> arr(n+1, -1); // your DSU array
        int totalCost = 0;
        int edgesUsed = 0;

        for(int i=0; i<connections.size(); i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            int cost = connections[i][2];

            int rootA = find(arr, a);
            int rootB = find(arr, b);

            if(rootA == rootB) {
                continue; // cycle - skip (in 684 we returned here)
            }

            // Union
            arr[rootB] = rootA;
            totalCost += cost;
            edgesUsed++;

            if(edgesUsed == n-1) break;
        }

        if(edgesUsed == n-1) return totalCost;
        else return -1; // not all cities connected
    }
};

// Test it
int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> connections = {{1,2,5},{1,3,6},{2,3,1}};
    cout << sol.minimumCost(n, connections) << endl; // 6

    n = 4;
    connections = {{1,2,3},{3,4,4}};
    cout << sol.minimumCost(n, connections) << endl; // -1 (not possible)

    return 0;
}