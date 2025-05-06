#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int countSubarrays(vector<int> &arr, int k) {
          // code here
          unordered_map<int,int> mpp;
          
          int currSum = 0;
          int res =0;
          
          for(int i =0;i < arr.size();i++){
              currSum += arr[i];
              
              if(currSum == k){
                  res++;
              }
              
              if(mpp.find(currSum -k) != mpp.end()){
                  res += mpp[currSum-k];
              }
              
              mpp[currSum]++;
          }
          
          return res;
      }
  };

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
    }

    return 0;
}
  