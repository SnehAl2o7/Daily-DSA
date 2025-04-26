#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int num0 = 0, num1 = 0, num2 = 0;
    for(int i : nums){
        if(i == 0)num0++;
        else if(i == 1)num1++;
        else num2++;
    }

    for(int i = 0;i < n;i++){
        if(num0 != 0){ nums[i] = 0;
        num0--;
        }
        else if(num1 != 0){nums[i] = 1;
        num1--;
        }
        else nums[i] = 2;
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int i : nums)cout<<i<<" ";
    return 0;
}