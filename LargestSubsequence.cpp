#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            if(n ==0)return 0;
            if(n==  1)return 1;
            sort(nums.begin(),nums.end());
            int cnt = 1;
            int Max_cnt = 1;
            for(int i = 1; i< n;i++){
                if(nums[i-1] == nums[i]) continue;
    
                if(nums[i-1]+1 == nums[i]){
                    cnt++;
                }
                else{
                    cnt = 1;
                }
                Max_cnt = max(Max_cnt,cnt);
            }
            return Max_cnt;
        }
    };

int main(){
    Solution obj;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << obj.longestConsecutive(nums) << endl;
    return 0;
}