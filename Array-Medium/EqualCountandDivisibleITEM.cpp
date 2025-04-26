#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
           int count = 0; // Initialize count of pairs
            int n = nums.size(); // Get the size of the array
            
            // Iterate over the array
            for (int i = 0; i < n - 1; i++) { 
                for (int j = i + 1; j < n; j++) {
                    if (nums[i] == nums[j] && ((long long)i * j) % k == 0) { // checking the condition
                        count++; // increasing the count
                    }
                }
            }
    
            return count;
    
        }
    };

int main(){
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5,1};
    int k = 2;
    cout << obj.countPairs(nums, k);
    return 0;
}