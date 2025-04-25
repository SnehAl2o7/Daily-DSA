#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            long long count = 0, equals = 0;
            unordered_map<int, long long> mpp;
            mpp[0] = 1;
    
            for (int i : nums) {
                if (i % modulo == k) equals++;
    
                int rem = equals % modulo;
                int needed = (rem - k + modulo) % modulo;
    
                count += mpp[needed];
                mpp[rem]++;
            }
    
            return count;
        }
    };

int main(){
    Solution obj;
    vector<int> ans={1,5,4,48,56,6,5};
    cout << obj.countInterestingSubarrays(ans,5,1);
    return 0;
}