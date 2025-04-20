#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n,0);
            int i = 0, j = 1;
            for(int k = 0;k < n;k++){
                if( nums[k] > 0){
                    ans[i] = nums[k];
                    i += 2;
                }
                else if( nums[k] < 0){
                    ans[j] = nums[k];
                    j += 2;
                }
            }
            return ans;
        }
    };


int main(){
    Solution sol;
    vector<int> nums = {-1,2,-3,4,2,-5};
    vector<int> ans = sol.rearrangeArray(nums);
    for(int i = 0;i < ans.size();i++){
        cout << ans[i] << " ";
        }
        return 0;
}