#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            int ele1 = INT_MIN, ele2 = INT_MIN ;
            int cnt1 = 0, cnt2 = 0;
            for(int ele : nums){
                if(ele == ele1){
                    cnt1++;
                }
                else if(ele == ele2){
                    cnt2++;
                }
                else if(cnt1 == 0 && ele != ele2){
                    ele1 = ele;
                    cnt1 = 1;
                }
                else if(cnt2 == 0 && ele != ele1){
                    ele2 = ele;
                    cnt2 = 1;
                }
                else {
                    cnt1--;
                    cnt2--;
                }
            }
            vector<int> ans;
            cnt1 = 0, cnt2 = 0;
            for(int i : nums){
                if(i == ele1)cnt1++;
                if(i == ele2)cnt2++;
            }
            if(cnt1 > n/3)ans.push_back(ele1);
            if(cnt2 > n/3) ans.push_back(ele2);
            return ans;
        }
    };

int main(){
    Solution obj;
    vector<int> nums = {1,4,5,4,8,4,4,5,5,5,7};
    vector<int> ans = obj.majorityElement(nums);
    for(int i:ans){
        cout << i << " ";
    }
    return 0;
}