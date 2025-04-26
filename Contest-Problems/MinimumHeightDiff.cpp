#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int getMinDiff(vector<int> &arr, int k) {
          // code here
          int n = arr.size(); // getting the size
          sort(arr.begin(),arr.end()); // sorting to get in order
          int res = arr[n-1] - arr[0];  // getting the maximum height diff
          for(int i = 1;i < n;i++){ // iterating the loop
              if(arr[i] -k < 0){ // if decreasing the loop get negative skip
                  continue;
              }
              int mini = min(arr[0]+k,arr[i] -k); // get min by comparing 
              // first + k and other element -k
              int maxH = max(arr[i-1]+k, arr[n-1] - k); // same for get 
              // we check from first index + k to n-2 index + k and
              // compare with the largest element - k
              res = min(res,maxH - mini); // getting the minimum diff
          }
          return res; // returning the min diff
          
          
      }
  };

  int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        // cout << '~' << endl;
    }
    return 0;
}