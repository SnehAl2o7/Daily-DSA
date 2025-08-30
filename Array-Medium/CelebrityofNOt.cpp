#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int> check(n,0);
        for(int i = 0;i < n;i++){
            for(int j =0 ;j < n;j++){
                if(mat[i][j]){
                    check[j]++;
                    check[i]--;
                } 
                    
            }
        }
        
        for(int i = 0;i < n;i++){
            if(check[i] == n-1) return i;
        }
        
        return -1;
    }
};
