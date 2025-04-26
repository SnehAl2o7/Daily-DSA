#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int rearrange(vector<int>& pages, vector<int>& shelf) {
          // code here
          int n = pages.size();
          unordered_map<int,int> mpp;
          for(int i = 0;i < n;i++){
              int first = shelf[i], second = pages[i];
              mpp[first] = max(mpp[first],second);
          }
          int total = 0;
          for(auto it:mpp){
              total += it.second;
          }
          
          int sum = 0;
          for(int i: pages){
              sum += i;
          }
          return (sum - total);
      }
  };

void input(vector<int> &arr){
    string line;
    getline(cin,line);
    stringstream ss(line);
    int num;
    while(ss >> num){
        arr.push_back(num);
    }
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        vector<int> pages, shelf;
        input(pages);
        input(shelf);
        Solution obj;
        int ans = obj.rearrange(pages,shelf);
        cout << ans << endl;
    }
}