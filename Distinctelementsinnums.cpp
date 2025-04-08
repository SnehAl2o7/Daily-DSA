#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<int> mpp(101);
            for (int i = nums.size() - 1; i >= 0; --i)
                if (++mpp[nums[i]] > 1) 
                    return (i + 3) / 3;
            return 0;
        }
    };

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,2,3,3,5,7};
    cout << s.minimumOperations(nums) << endl;
    return 0;
}