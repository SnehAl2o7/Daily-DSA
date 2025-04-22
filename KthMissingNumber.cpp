#include<bits/stdc++.h>>
using namespace std;

class Solution {
    public:
      int kthMissing(vector<int> &arr, int k) {
          // Your code goes here
          int n = arr.size();
          int i = 1;
          int j = 0;
          while(k != 0){
              if(j < n){
                  if(arr[j] == i){
                      j++;
                  }
                  else {
                      k--;
                  }
                  i++;
              }
              else {
                  i++;
                  k--;
              }
          }
          return i-1;
      }
  };

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
