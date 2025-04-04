#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
     bool dfs(int node, int parent, vector<bool> &visited, vector<vector<int>> &adj) {
      visited[node] = true;
      for (int neighbor : adj[node]) {
          if (!visited[neighbor]) {
              if (dfs(neighbor, node, visited, adj))
                  return true;
          } else if (neighbor != parent) {
              // Found a back-edge — cycle detected
              return true;
          }
      }
      return false;
  }
  
  bool isCycle(int V, vector<vector<int>> &edges) {
      vector<vector<int>> adj(V);
      for (auto &edge : edges) {
          adj[edge[0]].push_back(edge[1]);
          adj[edge[1]].push_back(edge[0]); // Undirected
      }
  
      vector<bool> visited(V, false);
      for (int i = 0; i < V; ++i) {
          if (!visited[i]) {
              if (dfs(i, -1, visited, adj))
                  return true;
          }
      }
      return false;
  }
  };

int main(){
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        // cout << "~"
        //      << "\n";
    }
    return 0;
}