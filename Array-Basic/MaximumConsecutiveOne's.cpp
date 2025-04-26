#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int n = nums.size(); // size of vector
            int max_cnt = 0; // the maximum count
            int cnt = 0; // temp count
            for(int i = 0;i < n;i++){ // iterating the vector
                if(nums[i] == 1){ // checking for one's 
                    cnt++;
                }
                else { // if chain of 1 breaks
                    cnt = 0;
                }
                max_cnt = max(max_cnt,cnt); // storing the sequence to the max_cnt
            }
            return max_cnt; // return maximum number
        }
    };

int main(){
    Solution obj;
    vector<int> nums = {1,1,0,1,1,1};
    cout << obj.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}