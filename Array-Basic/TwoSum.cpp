#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // BRUTE-FORCE APPROACH
        vector<int> twoSumloop(vector<int>& nums, int target) {
            int n = nums.size(); // getting size of array
            for(int i = 0;i<n;i++){
                for(int j = i+1;j < n;j++){ // using 2 loops to iterate over array 
                    // and check if sum of two elements is equal to target
                    if(nums[i] + nums[j] == target)return {i,j};
                }
            }
            return {};
        }
    // OPTIMIZED APPROACH and we can also use two pass in this approach
        vector<int> twoSumMap(vector<int>& nums, int target) {
            int n = nums.size();
            unordered_map<int,int> mpp; // create a map to store values in it
            for(int i = 0;i<n;i++){
                int val = target - nums[i]; // calculate the value which is needed to get target
                if(mpp.find(val) != mpp.end()){ // checking that value exist or not
                    return {mpp[val],i}; // if exist we must return vector
                }
                mpp[nums[i]] = i; // updating values in map
                // mpp[nums[i]]++;
            }    
            return {};
        }
};

int main (){

    Solution s;
    vector<int> nums = {3,3};
    int target = 6;
    vector<int> ans = s.twoSumMap(nums,target);
    cout<<"Index of first element is : "<<ans[0]<<endl;
    cout<<"Index of second element is : "<<ans[1]<<endl;
    vector<int> sol = s.twoSumloop(nums,target);
    cout<<"Index of first element is : "<<sol[0]<<endl;
    cout<<"Index of second element is : "<<sol[1]<<endl;
    return 0;
}