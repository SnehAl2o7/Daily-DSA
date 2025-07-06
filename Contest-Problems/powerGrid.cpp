#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<set<int>> onlineInGroup;

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (onlineInGroup[px].size() < onlineInGroup[py].size()) {
            swap(px, py);
        }

        parent[py] = px;
        onlineInGroup[px].insert(onlineInGroup[py].begin(), onlineInGroup[py].end());
        onlineInGroup[py].clear();
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c + 1);              
        onlineInGroup.resize(c + 1);
        vector<bool> isOnline(c + 1, true);
        vector<int> result;


        for (int i = 1; i <= c; ++i) {
            parent[i] = i;
            onlineInGroup[i].insert(i);
        }

        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            unite(u, v);
        }

        for (auto& q : queries) {
            int type = q[0], x = q[1];

            if (type == 1) {
                if (isOnline[x]) {
                    result.push_back(x);
                } else {
                    int root = find(x);
                    if (!onlineInGroup[root].empty()) {
                        result.push_back(*onlineInGroup[root].begin()); 
                    } else {
                        result.push_back(-1);
                    }
                }
            } else if (type == 2) {
                if (isOnline[x]) {
                    isOnline[x] = false;
                    int root = find(x);
                    onlineInGroup[root].erase(x);
                }
            }
        }

        return result;
    }
};

int main(){
    
}