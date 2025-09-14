#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int totalGas = 0, totalCost = 0, tank = 0, startIndex = 0;
    
    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        // If tank is negative, reset and try next station
        if (tank < 0) {
            startIndex = i + 1;
            tank = 0;
        }
    }

    return (totalGas >= totalCost) ? startIndex : -1;
    }
};
