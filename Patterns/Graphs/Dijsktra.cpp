#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // min-heap: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, node] = pq.top(); // fixed: top() not front()
        pq.pop();

        // if we already found a shorter path, skip
        if(d > dist[node]) continue;

        // traverse all neighbours of current node
        for(auto [nei, w] : adj[node]) { 
            if(dist[node] + w < dist[nei]) {
                dist[nei] = dist[node] + w; 
                pq.push({dist[nei], nei});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5; // nodes 0 to 4
    vector<vector<pair<int,int>>> adj(n);

    // Example graph:
    // 0 -> 1 weight 4, 0 -> 2 weight 1
    // 2 -> 1 weight 2, 2 -> 3 weight 5
    // 1 -> 3 weight 1, 1 -> 4 weight 3
    // 3 -> 4 weight 3
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 5});
    adj[1].push_back({3, 1});
    adj[1].push_back({4, 3});
    adj[3].push_back({4, 3});

    int src = 0;
    vector<int> shortestDist = dijkstra(n, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for(int i = 0; i < n; i++) {
        if(shortestDist[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << shortestDist[i] << "\n";
    }
    /*
    Expected:
    Node 0: 0
    Node 1: 3 // 0->2->1 = 1+2
    Node 2: 1 // 0->2 = 1
    Node 3: 4 // 0->2->1->3 = 1+2+1
    Node 4: 6 // 0->2->1->4 = 1+2+3
    */

    return 0;
}