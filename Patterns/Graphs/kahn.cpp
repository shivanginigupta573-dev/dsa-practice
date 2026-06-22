#include <bits/stdc++.h>
using namespace std;

// Kahn's Algorithm for Topological Sort - BFS
vector<int> kahnTopoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);

    // calculate indegree of all nodes
    for(int u = 0; u < n; u++) { // fixed: was i++
        for(int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    // store all nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            q.push(i); // fixed: was queue.push
    }

    vector<int> order;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        // traverse all neighbours
        for(int nei : adj[node]) {
            indegree[nei]--;
            if(indegree[nei] == 0) // if indegree becomes 0, push
                q.push(nei);
        }
    }

    // If order.size() == n then no cycle, else cycle exists
    return order.size() == n? order : vector<int>{};
}

int main() {
    int n = 6; // number of nodes 0 to 5
    vector<vector<int>> adj(n);

    // Example DAG:
    // 5 -> 2, 5 -> 0
    // 4 -> 0, 4 -> 1
    // 2 -> 3
    // 3 -> 1
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    // 0 and 1 have no outgoing edges

    vector<int> topo = kahnTopoSort(n, adj);

    if(topo.empty()) {
        cout << "Cycle detected. No topological order exists." << endl;
    } else {
        cout << "Topological Sort: ";
        for(int node : topo) {
            cout << node << " ";
        }
        cout << endl;
        // One valid output: 4 5 2 0 3 1
    }

    // Test with cycle: 0->1, 1->2, 2->0
    vector<vector<int>> adj2(3);
    adj2[0] = {1};
    adj2[1] = {2};
    adj2[2] = {0};

    vector<int> topo2 = kahnTopoSort(3, adj2);
    cout << "Graph with cycle result size: " << topo2.size() << endl; // 0

    return 0;
}