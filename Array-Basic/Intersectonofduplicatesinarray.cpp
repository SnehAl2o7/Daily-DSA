#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
          // code here
          unordered_set<int> mpp(a.begin(),a.end());
          vector<int> res;
          for(int i = 0;i < b.size();i++){
              if(mpp.find(b[i]) != mpp.end()){
                  res.push_back(b[i]);
                  mpp.erase(b[i]);
              }
          }
          return res;
      }
  };

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}