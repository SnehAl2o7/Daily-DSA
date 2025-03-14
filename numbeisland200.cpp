#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        // using the bfs approach
        int numIslandsbfs(vector<vector<char>>& g) {
            int n = g.size(), m = g[0].size();
            int cnt = 0;
    
            vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(g[i][j] == '1') { // Found an island
                        cnt++;
                        bfs(g, i, j, directions, n, m);
                    }
                }
            }
            return cnt;
        }
    
    private:
        void bfs(vector<vector<char>>& grid, int i, int j, vector<pair<int,int>>& directions, int rows, int cols) {
            queue<pair<int,int>> q;
            q.push({i, j});
            grid[i][j] = '0'; // Mark as visited
    
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
    
                for (auto [dx, dy] : directions) {
                    int ni = x + dx;
                    int nj = y + dy;
    
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == '1') {
                        q.push({ni, nj});
                        grid[ni][nj] = '0'; // Mark as visited
                    }
                }
            }
        }
    
    // using the dfs approach
    public:
    int numIslandsdfs(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {  // Found an island
                    count++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') return;

        grid[i][j] = '0';  // Mark as visited

        // Explore 4 directions
        dfs(grid, i + 1, j, n, m); // Down
        dfs(grid, i - 1, j, n, m); // Up
        dfs(grid, i, j + 1, n, m); // Right
        dfs(grid, i, j - 1, n, m); // Left
    }
};


int main (){
    Solution ob;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout<< ob.numIslandsdfs(grid)<<endl;
    return 0;
}