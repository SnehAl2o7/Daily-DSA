#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> smallerNumbersThanCurrentLoop(vector<int>& nums) {
            vector<int> ans; // for solution
            int n = nums.size();
            vector<int> value = nums; // copying the data for seeing the occurrence
            sort(value.begin(),value.end()); // sort the copying vector to get the index
            for(int i = 0;i<n;i++){
                for(int j = 0;j < n;j++){
                    if(nums[i] == value[j]){ // checking for the same value and returning the index
                        ans.push_back(j); // pushing the array
                        break;
                    }
                }
            }
            return ans; // returning the array
        }
        vector<int> smallerNumbersThanCurrentMap(vector<int>& nums) {
            vector<int> ans; 
            int n = nums.size(); // size of the array
            vector<int> value = nums; // copying the data for seeing the occurrence
            sort(value.begin(),value.end()); // sort the copying vector to get the index
            unordered_map<int,int> mpp; // making a hash_map for sorting index
            for(int i = n-1;i >= 0;i--){
                mpp[value[i]] = i; // storing the value and index of sorted array in the map
            }
            for(int i = 0;i<n;i++){
                if(mpp.find(nums[i]) != mpp.end()){ // checking the value of original in map and getting the index
                    ans.push_back(mpp[nums[i]]); // pushing the index into the array
                }
            }
            return ans;
        }
};

int main(){
    Solution s;
    vector<int> nums = {8,1,2,2,3};
    vector<int> ans1 = s.smallerNumbersThanCurrentLoop(nums);
    vector<int> ans2 = s.smallerNumbersThanCurrentMap(nums);
    for(int i = 0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}