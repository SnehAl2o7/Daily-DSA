#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            if (k < 0 || nums.empty()) return false;
            unordered_set<int> window;
            for (int i = 0; i < nums.size(); ++i) {
                if (i > k) window.erase(nums[i - k - 1]);
                if (!window.insert(nums[i]).second) return true;
            }
            return false;
        }
    };

    int main(){
        Solution s;
        vector<int> nums = {1,2,3,1};
        int k = 3;
        cout<<s.containsNearbyDuplicate(nums,k)<<endl;
        return 0;
    }
    