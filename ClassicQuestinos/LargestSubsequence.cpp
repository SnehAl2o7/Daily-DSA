#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // own came up approach
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

    // optimized approach or required one

    int longestConsecutiveOpt(vector<int> & nums){
        int longest = 0;

        unordered_set<int> seq(nums.begin(),nums.end());
        
        for(auto it : seq){
            if(seq.find(it-1) == seq.end()){
                int cnt = 1;
                while(seq.find(it+cnt) != seq.end()){
                    cnt += 1;
                }
                longest = max(cnt,longest);
            }
        }
        return longest;
    }
    };

int main(){
    Solution obj;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << obj.longestConsecutive(nums) << endl;
    cout << obj.longestConsecutiveOpt(nums) << endl;
    return 0;
}