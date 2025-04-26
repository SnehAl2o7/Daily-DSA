#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int>mpp;
            mpp[0] = 1;
            int cnt = 0, PrefixSum = 0;
            for(int i = 0;i < nums.size();i++){
                PrefixSum += nums[i];
                int remove = PrefixSum - k;
                cnt += mpp[remove];
                mpp[PrefixSum] += 1;
            }
            return cnt;
        }
    };

int main(){
    Solution obj;
    vector<int> nums={1,2,3,-3,1,1,1,4,2,-1};
    int k = 3;
    cout << obj.subarraySum(nums,k);
    return 0;
}