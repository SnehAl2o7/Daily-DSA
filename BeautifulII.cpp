#include<bits/stdc++.h>
using namespace std;

bool isbeautiful(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int commonRow = -1;

    for (int j = 0; j < m; j++) {
        int colSum = 0;
        int colMax = mat[0][j];
        int maxRow = 0;

        for (int i = 0; i < n; i++) {
            colSum += mat[i][j];
            if (mat[i][j] > colMax) {
                colMax = mat[i][j];
                maxRow = i;
            }
        }

        if (colSum != 2 * colMax) return false;
        if (j == 0) commonRow = maxRow;
        else if (maxRow != commonRow) return false;
    }

    return true;
}

int minOperation(vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return 0;
    int m = mat[0].size();

    if (isbeautiful(mat)) return 0;

    // Precompute column sums
    vector<int> colSum(m, 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            colSum[j] += mat[i][j];
        }
    }

    int minSteps = INT_MAX;

    for (int r = 0; r < n; r++) {
        int steps = 0;
        for (int j = 0; j < m; j++) {
            int othersSum = colSum[j] - mat[r][j];
            steps += abs(othersSum - mat[r][j]);
        }
        minSteps = min(minSteps, steps);
    }

    return minSteps;
}


int main(){
    vector<vector<int>> mat = {{1, 2, 3}, {4,
        5, 6}, {7, 8, 9}};
    
    cout << minOperation(mat) << endl;
}