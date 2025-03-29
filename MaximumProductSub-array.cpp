#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find maximum product subarray
      int maxProduct(vector<int> &arr) {
          // Your Code Here
          
          int n = arr.size();
          int curr = arr[0]; // getting the current maximum value
          int mex = arr[0]; // getting the maximum product sub-array
          int mini = arr[0]; // getting the current product as minimum current 
          
          for(int i = 1;i < n;i ++){ // iterationg the array
              int temp = max({arr[i],arr[i]*mini,arr[i]*curr}); //getting the current max
              mini = min({arr[i],arr[i]*mini,arr[i]*curr}); // getting the current mini
              curr = temp; // storing in the curr
              mex = max(mex,curr); // getting the maximum by changing 
          }
          return mex;
      }
  };

  int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        // cout << "~"
        //      << "\n";
    }
    return 0;
}
