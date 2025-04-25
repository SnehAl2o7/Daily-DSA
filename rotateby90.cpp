#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& mat) {
            int n = mat.size();
            for(int i = 0;i < n;i++){
                for(int j = 0;j<i;j++){
                   swap(mat[i][j],mat[j][i]); // swapping the elements for transposing the values in the matrix
                }
            }
    
            for(int i = 0;i < n;i++){
                // reversing the individual vector in the matrix
                reverse(mat[i].begin(),mat[i].end());
            }
        }
    };

int main(){
    Solution obj;
    vector<vector<int>> matrix = {{1,2,3},
{4,5,6},
{7,8,9}};

    obj.rotate(matrix);

    for(int i = 0;i < matrix.size();i++){
        for(int j = 0;j < matrix.size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}