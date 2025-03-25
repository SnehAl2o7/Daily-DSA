#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
       int n = arr.size(); // getting size of array
       int pivot = -1; // to get the number to change
       for(int i = n-2;i >= 0;i--){ // to iterate from behid
           if(arr[i] < arr[i+1]){ // checking for conditin
               pivot = i; // changing value of pivot
               break;
           }
       }
       
       if(pivot == -1){ // if no such number found
           reverse(arr.begin(),arr.end()); /// reverse the array
           return;
       }
       
       for(int i = n-1;i > pivot;i--){ // to find the number to change
           if(arr[i] > arr[pivot]){ // checking for condition
               swap(arr[i],arr[pivot]); // swapping the numbers
               break;
           }
       }
       
       reverse(arr.begin()+pivot+1, arr.end()); // reverse the rest array
    }
};

int main(){
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
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}