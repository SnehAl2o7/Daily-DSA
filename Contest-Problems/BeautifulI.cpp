#include<bits/stdc++.h>
using namespace std;

bool checkColumnsAlternate(const vector<vector<int>>& mat) {
    int n = mat.size();
    if(n == 0) return true;
    int m = mat[0].size();

    // For each column, compute the total sum and maximum.
    for (int j = 0; j < m; j++) {
        int colSum = 0;
        int colMax = mat[0][j];
        for (int i = 0; i < n; i++) {
            colSum += mat[i][j];
            colMax = max(colMax, mat[i][j]);
        }
        // If the total sum isn't twice the maximum, then (sum - max) != max.
        if(colSum != 2 * colMax) {
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> mat = {{1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};
    cout << boolalpha << checkColumnsAlternate(mat) << endl;
}