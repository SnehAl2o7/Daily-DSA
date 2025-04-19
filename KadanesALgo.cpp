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

        void printSubarray(vector<int> &nums){
            long long Max_sum = LONG_MIN;
            long long sum = 0;
            int start = -1, end = -1;
            for(int i = 0;i < nums.size();i++){
                if(sum == 0) start = i;
                sum += nums[i];
                
                if(sum > Max_sum){
                    Max_sum = sum;
                    end = i;
                }
                if(sum < 0){
                    sum = 0;
                }
            }
        
            while(start <= end){
                cout << nums[start] << " ";
                start++;
            }
        }
    };

    


int main(){
    Solution Sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1};
    cout << Sol.maxSubArray(nums) << endl;
    Sol.printSubarray(nums);
    return 0;
}
