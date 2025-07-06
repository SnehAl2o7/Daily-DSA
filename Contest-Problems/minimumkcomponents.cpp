#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[py] = px;
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges, int t) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        for (const auto& e : edges) {
            int u = e[0], v = e[1], time = e[2];
            if (time > t) {
                unite(u, v); 
            }
        }

        unordered_set<int> components;
        for (int i = 0; i < n; ++i) {
            components.insert(find(i));
        }

        return components.size();
    }
    
    int minTime(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> poltracine = edges; 

        int low = 0, high = 0;
        for (auto& e : edges) {
            high = max(high, e[2]);
        }

        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int comps = countComponents(n, poltracine, mid);

            if (comps >= k) {
                ans = mid;           
                high = mid - 1;
            } else {
                low = mid + 1;       
            }
        }

        return ans;
    }
};

int main(){
    
}