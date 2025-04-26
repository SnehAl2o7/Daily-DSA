#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans; // declaring returing matrix
            int n = matrix.size(), m = matrix[0].size(); // assigning size of n and m
            // for matrix size
            int i = 0; // for accessing the left over elements
            while (ans.size() != n * m) { // the breaking condition for the loop
            // when all n*m elements get  filled break loop
                int left = i, right = m - (i + 1); // assigning the left and right
                // corners of matrix
                int up = i, down = n - (i + 1); // assigning the top and bottom corners of matrix
                while (left <= right && ans.size() !=n*m) { // going from left corner to right as per pattern
                    ans.push_back(matrix[up][left++]); // as we find elements we store it to solution
                }
                
                while (up < down && ans.size() != n * m) { // moving from right top to right bottom using pre-increment for no overlapping of data
                    ans.push_back(matrix[++up][right]);
                }
                left = i; // re-assigning the value for reusing
                up = i+1; // assigning +1 so that loop does't get copy value reassigned to ans. 
                while (right > left && ans.size() != n * m) { // moving from right bottom to left bottom
                    ans.push_back(matrix[down][--right]);
                }
                while (down > up && ans.size() != n * m) { // moving from left bottom to left top and avoiding pre-inserted elements
                    ans.push_back(matrix[--down][left]);
                }
                i++; // incrementing i so that left over elements can also get added to the solution.
            }
    
            return ans; // returning the solution
        }
    };

    int main(){
        Solution obj;
        vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
        vector<int> ans = obj.spiralOrder(matrix);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
            }
            return 0;
    }