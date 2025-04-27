#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int MajorityElement(vector<int> nums){   
        unordered_map<int,int> mpp;
        for(int i: nums){
            mpp[i]++;
        }

        for(auto it: mpp){
            if(it.second > nums.size()/2){
                return it.first;
            }
        }

        return 0;
    }

    int MajorityElementO1(vector<int> nums){
        int n = nums.size();
        int ele, cnt = 0;
        for(int i = 0;i < n ;i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(ele == nums[i]){
                cnt++;
            }
            else {
                cnt--;
            }
        }
        return ele;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,3};
    cout<<s.MajorityElementO1(nums)<<endl;
    cout <<s.MajorityElement(nums)<<endl;
    return 0;
}