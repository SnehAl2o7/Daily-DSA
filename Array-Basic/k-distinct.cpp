#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        int r = 0;
        for(int i = 0;i< nums.size();i++){
            if(nums[i] == key){
                int l = max(r,i-k);
                r = min(n-1,i+k) + 1;
                for(int j = l;j < r;j++){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

int main(){
    
}