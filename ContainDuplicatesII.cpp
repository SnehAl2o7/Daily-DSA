#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            // using sliding window
            unordered_map<int,int> mpp; // using a hash map to access value 
            for(int i = 0;i <nums.size();i++){ // loop to access elements
                int val = nums[i]; // storing value to check in mpp and compare
                if(mpp.find(val) != mpp.end() && i-mpp[val] <= k){ // checking in map
                    return true; // if found return ture
                }
                mpp[val] = i; // storing value in mpp at the same time
            }
            return false; // if no element is found return false;
        }
    };

    int main(){
        Solution s;
        vector<int> nums = {1,2,3,1};
        int k = 3;
        cout<<s.containsNearbyDuplicate(nums,k)<<endl;
        return 0;
    }