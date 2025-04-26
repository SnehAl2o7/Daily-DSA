#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int left =0, res = 0;
            int k = unordered_set<int>(nums.begin(),nums.end()).size();
            unordered_map<int, int> mpp;
    
            for (int i = 0; i < nums.size(); ++i) {
                mpp[nums[i]]++;
                while (mpp.size() == k) {
                    res += nums.size() - i;  
                    mpp[nums[left]]--;
                    if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                    left++;
                }
            }
            return res;
        }
    };

int main(){
    Solution obj;
    vector<int> nums={1,2,4,3,6,7,9};
    cout << obj.countCompleteSubarrays(nums) << endl;
    return 0;
}