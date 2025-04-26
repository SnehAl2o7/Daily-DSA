#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findDisappearedNumbersSet(vector<int>& nums){
            vector<int> ans; 
            int n = nums.size(); // size of array
            sort(nums.begin(),nums.end()); // sorting to get sequence
            unordered_set<int> map; // to store elements with single occurrence
            for(int i : nums){
                map.insert(i); // inserting into the set
            }
            
            for(int i = 1;i<=n;i++){
                if(map.find(i) == map.end()){ // this will check whether the elemnet is
                    // in the set or not 
                    ans.push_back(i); // if not then push to the array
                }
            }
            return ans;
        }

        // optimum and fast solution
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            vector<int> ans; 
            int n = nums.size(); // size of array
            sort(nums.begin(),nums.end()); // sorting to get sequence
            unordered_set<int> map; // to store elements with single occurrence
            for(int i : nums){
                map.insert(i); // inserting into the set
            }
            for(int i = 1;i<=n;i++){
                if(map.find(i) == map.end()){ // this will check whether the elemnet is
                    // in the set or not 
                    ans.push_back(i); // if not then push to the array
                }
            }
            return ans;
        }
};

int main(){
    Solution cp;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = cp.findDisappearedNumbers(nums);
    for(int i : ans){
        cout<<i<<" ";
    }

}