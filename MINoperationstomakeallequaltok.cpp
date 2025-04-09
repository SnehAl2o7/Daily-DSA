#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int n = nums.size(); // taking size of array
            int cnt = 0; // for the number of operations
            
            unordered_map<int,int> mpp; // using map so not repeated statement will be there
            for(int i : nums){ // inserting elements in mpp
                mpp[i]++;
            }
    
            for(auto it:mpp){ // iterating the mpp
                if(it.first > k) cnt++; // if value is greater than k increases
                else if(it.first < k) return -1; // if negative value is found return -1
            }
    
            return cnt; // if everything is good return cnt
            
        }
    };

int main(){
    Solution obj;
    vector<int> nums = {10,8,8,10};
    int k = 8;
    cout<<obj.minOperations(nums,k) << endl;
}