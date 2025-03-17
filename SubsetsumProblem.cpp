#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          int n = arr.size();
      vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
  
      // If sum is 0, empty subset exists
      for (int i = 0; i <= n; i++) dp[i][0] = true;
  
      // Fill DP table
      for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= sum; j++) {
              if (arr[i - 1] > j) 
                  dp[i][j] = dp[i - 1][j];  // Exclude current element
              else
                  dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];  // Include or exclude
          }
      }
      return dp[n][sum];
      }
  };