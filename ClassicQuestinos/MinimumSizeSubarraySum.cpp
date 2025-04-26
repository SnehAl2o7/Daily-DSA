#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            // Basic sliding window question
            int left =0, right=0; // assigning the pointer in array to get access  
            int total = 0; // total for sum
            int res = INT_MAX; //to check for the minimum length
    
            while(right < nums.size()){ // iterating till right reach end of array    
                if(nums[right] == target) return 1; // checking for break condition
                total += nums[right]; // increasing total
               
                while(total >= target){ // checking the sum can reach target or not
                    res = min(res, right-left+1); // updating the res
                    total -= nums[left]; // reducing the pointer
                    left++; // increasing the pointer
                    
                }
                right++; // increasing the right
            }
    
            if(res == INT_MAX) return 0; // checking for no such subarray
            else return res; // if sub-array found getting the solution
        }
    };

int main(){
    Solution solution;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << solution.minSubArrayLen(target, nums) << endl;
    return 0;
}