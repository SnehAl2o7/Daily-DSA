#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int n) {
            vector<vector<int>> ans;
            for(int i = 1;i <= n;i++){
               vector<int> res(i,1);
               int val = 0;
               int total = 1;
               while(val < i){
                    if(val == 0 || val == i-1) res[val] = 1;
                    else {
                        total = (total *(i-val))/val;
                        res[val] = total;
                    }
                    val++;
               }
               ans.push_back(res);
            }
            return ans;
        }
    };

int main(){
    Solution obj;
    int n;
    cin >> n;
    vector<vector<int>> triangle = obj.generate(n);
    for(int i = 0;i < triangle.size();i++){
        for(int j = 0;j < triangle[i].size();j++){
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}