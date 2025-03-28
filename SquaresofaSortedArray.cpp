#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n1 = nums.size();
            int i = 0, j = n1-1;
            int n = n1-1;
            vector<int> ans(n1,0);
            while(i <= j){
                int left = nums[i]*nums[i];
                int right = nums[j]*nums[j];
                if(left > right){
                    ans[n] = left;
                    i++;
                }
                else{
                    ans[n] = right;
                    j--;
                }
                n--;
            }   
            return ans;
        }
    };

int main(){
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ans = s.sortedSquares(nums);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
        }
        return 0;
        
}