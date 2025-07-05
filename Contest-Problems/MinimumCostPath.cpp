#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
         vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

       
        priority_queue<tuple<long long, int, int, int>, vector<tuple<long long, int, int, int>>, greater<>> pq;

        dp[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        int dir[2][2] = {{0, 1}, {1, 0}};

        while (!pq.empty()) {
            auto [cost, i, j, t] = pq.top(); pq.pop();
            if (dp[i][j][t] < cost) continue; 

            if (t % 2 == 1) { 
                for (auto& d : dir) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (ni < m && nj < n) {
                        long long moveCost = (ni + 1) * (nj + 1);
                        if (dp[ni][nj][0] > cost + moveCost) {
                            dp[ni][nj][0] = cost + moveCost;
                            pq.push({dp[ni][nj][0], ni, nj, 0});
                        }
                    }
                }
            } else {
                long long wait = waitCost[i][j];
                if (dp[i][j][1] > cost + wait) {
                    dp[i][j][1] = cost + wait;
                    pq.push({dp[i][j][1], i, j, 1});
                }
            }
        }

       
        return min(dp[m-1][n-1][0], dp[m-1][n-1][1]);
    }
};

int main(){
    
}