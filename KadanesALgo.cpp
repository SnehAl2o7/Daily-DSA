#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            long long Max_sum = LONG_MIN;
            long long sum = 0;
            for(int i = 0;i < nums.size();i++){
                sum += nums[i];
                if(sum > Max_sum){
                    Max_sum = sum;
                }
                if(sum < 0){
                    sum = 0;
                }
            }
            return Max_sum;
        }
    };

int main(){
    Solution Sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1};
    cout << Sol.maxSubArray(nums) << endl;
    return 0;
}