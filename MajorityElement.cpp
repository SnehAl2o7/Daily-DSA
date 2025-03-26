#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find the majority elements in the array
      vector<int> findMajority(vector<int>& arr) {
          // Your code goes here.
          int n = arr.size();
          
          int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;
          // assigning variables to store and values of elements with high priority
          for(int ele : arr){ // iterating through the array
              if(ele1 == ele){ // if the element is equal to ele1
                  cnt1++; 
              }
              
              else if(ele2 == ele){ // if the element is equal to ele2
                  cnt2++;
              }
              
              else if (cnt1 == 0){ // if cnt1 is 0
                  ele1 = ele; // assign the element to ele1
                  cnt1++; // increment cnt1
              }
              else if(cnt2 == 0){ // if cnt2 is 0
                  ele2 = ele; // assign the element to ele2
                  cnt2++;  // increment cnt2
              }
              else {
                  cnt1--; // decrease cnt1
                  cnt2--; // decrease cnt2
              }
          }
          vector<int> ans; // assigning the returning vector
          cnt1 = 0;
          cnt2 = 0; // making the cnt's 0
          
          for(int ele : arr){ // iterating through the array
            // after storing the highest occur in ele1 and el2 
            // we again iterate the array to count the frequency of ele1 and ele2
              if(ele1 == ele) cnt1++;
              if(ele2 == ele) cnt2++;
          }
           // checking for n/3 > frequency
          if(cnt1 > n/3) ans.push_back(ele1);
          if(cnt2 > n/3 && ele1 != ele2) ans.push_back(ele2);
          
          // solving the trouble some error for 2 elements
          if(ans.size() == 2 && ans[0] > arr[1]){
              swap(ans[0],ans[1]);
          }
          
          // returning the vector
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