#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int maximumProfit(vector<int> &p) {
          // code here
          int n = p.size();
          int total = 0; // for profit
          for(int i = 1;i < n;i++){ // iterating loop for getting maximum profit
              if(p[i] > p[i-1]){ // checking for the profit
                  total += p[i] - p[i-1]; // adding the sum
              }
          }
          return total; // returning the total
      }
  };


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;
        cout << "\n";
    }
    return 0;
}