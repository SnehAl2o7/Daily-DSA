
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Self applied approach
        bool containsDuplicateMap(vector<int>& nums) {
            unordered_map<int,int> mpp;//declare a map to store frequency of elements
            for(int i:nums){
                mpp[i]++;//storing values with frequency in mpp
            }
            for(auto  i:mpp){
                if(i.second >= 2){ // checking where it has duplicates or not.
                    return true;
                }
            }
            return false;
        }

        // Optimised approach
        bool containsDuplicateSet(vector<int>& nums) {
            unordered_set<int> map; //creating a set
            for(int i : nums){
                map.insert(i);//inserting elements in set
            }
    // set will not accept duplicate value so there will be change in values. 
            if(map.size() == nums.size()) return false; //if size get same means no duplicate
            return true;
        }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout<<"Contains Duplicate: "<<s.containsDuplicateMap(nums)<<endl; // using map
    cout<<"Contains Duplicate: "<<s.containsDuplicateSet(nums)<<endl; // using set
}