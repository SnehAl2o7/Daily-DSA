#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find the majority elements in the array
      vector<int> findMajority(vector<int>& arr) {
          // Your code goes here.
          int n = arr.size();
          
          int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;
          
          for(int ele : arr){
              if(ele1 == ele){
                  cnt1++;
              }
              
              else if(ele2 == ele){
                  cnt2++;
              }
              
              else if (cnt1 == 0){
                  ele1 = ele;
                  cnt1++;
              }
              else if(cnt2 == 0){
                  ele2 = ele;
                  cnt2++;
              }
              else {
                  cnt1--;
                  cnt2--;
              }
          }
          vector<int> ans;
          cnt1 = 0;
          cnt2 = 0;
          
          for(int ele : arr){
              if(ele1 == ele) cnt1++;
              if(ele2 == ele) cnt2++;
          }
          
          if(cnt1 > n/3) ans.push_back(ele1);
          if(cnt2 > n/3 && ele1 != ele2) ans.push_back(ele2);
          
          if(ans.size() == 2 && ans[0] > arr[1]){
              swap(ans[0],ans[1]);
          }
          
          
          return ans;
      }
  };

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}