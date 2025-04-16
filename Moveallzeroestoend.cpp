#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n = nums.size(); // size of vector
            if(n == 1)return; // checking for the break case 
            int cnt = 0; // flag to get the changing index
            for(int i : nums){ // traverrsing the vector
                if(i != 0){ // checking for non-zero element
                    nums[cnt++] = i; // assigning value at first
                }
            }
            // assigning the zeroes at end 
            while(cnt < n){ 
                nums[cnt] = 0;
                cnt++;
            }
        }
    };

int main(){
    Solution obj;
    vector<int> nums = {0,1,0,3,12};
    cout <<"Before moving zeroes: ";
    for(int i : nums){
        cout<<i<<" ";
    }

    obj.moveZeroes(nums);

    cout<<"\n after moving zeroes: ";
    for(int i : nums){
        cout<<i<<" ";
        }
    return 0;
}