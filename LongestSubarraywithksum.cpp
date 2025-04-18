#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int LongestSubarray(vector<int> nums, long long k){
            int n = nums.size();
            int left = 0, right = 0;
            int cnt = 0;
            long long sum = nums[0];
            while(right < n){
                while(left <= right && sum > k){
                    sum -= nums[left];
                    left++;
                }
                if(sum == k){
                    cnt = max(cnt,right-left+1);
                }
                right++;
                if(right < n){
                    sum += nums[right];
                }
            }
            return cnt;
        }
};

int main(){
    Solution obj;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            }
        long long k;
        cin >> k;
        cout << obj.LongestSubarray(nums,k) << endl;
    }
    return 0;
}