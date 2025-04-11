#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[V];
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // since the graph is undirected
        }

        // Step 2: Initialize distance vector
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Step 3: Min-heap priority queue (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Visit all neighbors
            for (auto &neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;
                if (d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main(){
    Solution solution;
    int V = 9;
    vector<vector<int>> edges = {{0, 1, 4}, {0,
        7, 8}, {1, 7, 11}, {1,
            2, 8}, {2, 3, 7}, {2,
                5, 4}, {2, 8, 2}, {3,
                    5, 14}, {3, 4, 9}, {4,
                        5, 10}, {5, 6, 2}, {6,
                            7, 1}, {6, 8, 6}, {7,
                                8, 7}};
    
                                vector<int> dist = solution.dijkstra(V, edges, 0);
                                for (int i = 0; i < V; i++) {
                                    cout << "Vertex " << i << " is at distance " << dist[i] << endl
                                    << endl;
                                    }
                                    return 0;
}
