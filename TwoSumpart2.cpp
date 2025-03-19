#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            int i = 0, j = n-1;
            while(i < j){
                int sum = nums[i] + nums[j];
                if(sum == target) return {i+1,j+1};
                else if(sum > target) j--;
                else i++;
            }
            return {};
        }
    };

int main(){
    int n, target;
    cin>>n;
    cin >> target;
    vector<int> ques(n,0);
    for(int i = 0;i < n;i++){
        cin >> ques[i];
    }
    Solution s;
    vector<int> ans = s.twoSum(ques,target);
    for(int i:ans){
        cout << i << " ";
    }
    return 0;
}