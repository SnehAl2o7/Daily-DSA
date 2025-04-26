#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
            vector<pair<int,int>> index;
            for(int i =0;i<m;i++){
                for(int j = 0;j < n;j++){
                    if(mat[i][j] == 0){
                        index.push_back({i,j});
                    }
                }
            }
    
            for(auto it:index){
                int x = it.first;
                int y = it.second;
                for(int i = 0;i < n;i++){
                    mat[x][i] = 0;
                }
                for(int j = 0;j <m;j++){
                    mat[j][y] = 0;
                }
            }
        }
    
    };

int main(){
    Solution obj;
    vector<vector<int>> mat = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}; 
    obj.setZeroes(mat);
    for(int i = 0;i < mat.size();i++){
        for(int j = 0;j < mat[i].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}