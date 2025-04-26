#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int orangesRotting(vector<vector<int>>& mat) {
          // Code here
          int n = mat.size();
          int m = mat[0].size();
          queue<pair<int, int>> q;
          int freshCount = 0;
          
          // Step 1: Store all rotten oranges and count fresh ones
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  if (mat[i][j] == 2) {
                      q.push(make_pair(i, j));
                  } else if (mat[i][j] == 1) {
                      freshCount++;
                  }
              }
          }
          
          // If there are no fresh oranges, return 0
          if (freshCount == 0) return 0;
      
          // Directions for up, down, left, right
          vector<pair<int, int>> directions = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
          int time = 0;
      
          // Step 2: Perform BFS to rot adjacent oranges
          while (!q.empty()) {
              int size = q.size();
              bool rotten = false;
              
              for (int i = 0; i < size; i++) {
                  pair<int, int> cell = q.front();
                  q.pop();
                  int x = cell.first;
                  int y = cell.second;
      
                  for (int d = 0; d < directions.size(); d++) {
                      int newX = x + directions[d].first;
                      int newY = y + directions[d].second;
      
                      // Check if in bounds and is a fresh orange
                      if (newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] == 1) {
                          mat[newX][newY] = 2;  // Make it rotten
                          freshCount--;  // Reduce fresh count
                          q.push(make_pair(newX, newY));
                          rotten = true;
                      }
                  }
              }
      
              if (rotten) time++;  // Increment time only if at least one orange rotted in this step
          }
      
          // Step 3: If fresh oranges remain, return -1
          return (freshCount == 0) ? time : -1;
      }
  };

  int main() {
    vector<vector<int>> mat = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}
    };

    Solution s;
    cout << "Minimum time to rot all oranges: " << s.orangesRotting(mat) << endl;
    return 0;
}