#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // Step 1: Line Sweep Marking
        map<int,int> mp; // Using map for automatic sorting
        for(vector<int> &x : intervals){
            mp[x[0]]++;       // Interval starts at x[0] → +1
            mp[x[1]+1]--;     // Interval ends at x[1] → mark end+1 for prefix sum
        }
        
        // Step 2: Convert map to vector for prefix processing
        vector<pair<int,int>> temp;
        for(auto &x : mp){
            temp.push_back({x.first, x.second});
        }
        
        // Step 3: Compute prefix sum (frequency at each point)
        for(int i = 1; i < temp.size(); ++i){
            temp[i].second += temp[i-1].second;
        }
        
        // Step 4: Find the maximum integer with frequency ≥ k
        int ans = -1;
        for(int i = 1; i < temp.size(); ++i){
            // The range between temp[i-1].first and temp[i].first - 1 has frequency = temp[i-1].second
            if(temp[i-1].second >= k){
                ans = temp[i].first - 1; // Update to the highest possible in this range
            }
        }
        
        return ans;
    }
};

int main(){
    return 0;
}