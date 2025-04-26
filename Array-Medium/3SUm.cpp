#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size(); // for size of nums
            vector<vector<int>> ans; // returning the answer
            sort(nums.begin(),nums.end()); // for negative and positive to arrange
            int i = 0; // for looping
            while(i < n-2){ // fixing i then apply 2 pointer for rest
                int j = i+1; // j as i+1 for approach
                int k = n-1; // starting from zero
                while( j < k){ // loop for 2 pointe 
                    int sum = nums[i] + nums[j] + nums[k]; // sum for checking
                    if(sum == 0){  // found
                        ans.push_back({nums[i],nums[j],nums[k]}); // inserting in the ans
                        j++; // increasing
                        k--; // decrerasing 
                        
                        // checking for duplicates from  start
                        while(j < k && nums[j] == nums[j-1]) j++; // Skip duplicate second elements 
                        // checking for duplicates from end
                        while(j < k && nums[k] == nums[k+1]) k--; // Skip duplicate third elements  
                    }
                    else if(sum > 0) k--; // if not increase k
                    else j++; // else j ++
                }
                while(i < n - 2 && nums[i] == nums[i + 1]) i++; // checking for duplicates before j
                i++; // incrementing i if no duplicates found
     
            }
            return ans; // returning the solution
        }
    };

int main (){
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = s.threeSum(nums);
    for(auto it : ans){
        for(auto it2 : it){
            cout << it2 << " "; 
            }
        cout << endl;
    }
    return 0;
}