#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end()); // sorting the array so that sequence will be maintained
            long long sum = 0; // for calculating the sum
            int left = 0; // left for index
            int res = 1; // res for frequency cnt
    
            for(int right = 0;right < nums.size();right++){ 
                sum += nums[right]; // adding values to sum
    
                // checking how much elements can be converted
                while((long long) (right - left+1) * nums[right]-sum > k){
                    sum -= nums[left]; // :left sum decreasesas the value keep getting checked
                    left++; // increasing left
                }
                res = max(res,right-left+1); // getting the max frequency
            }
             // returning the answer
            return res;
        }
    };

int main(){
    Solution obj;
    vector<int> nums = {1,4,8,13};
    int k = 5;
    cout<<obj.maxFrequency(nums,k)<<endl;   
}