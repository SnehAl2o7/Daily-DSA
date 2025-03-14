#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // using my own implemented approach
    int removeElementme(vector<int>& nums, int val){
        int cnt = 0; // to cnt rest element
        vector<int> ans; // an arrray to get values and reassign it
        for(int num:nums){ // iterating the array
            if(num != val){ // comparing the values
                ans.push_back(num); // if not equal, add to ans array
                cnt++; // increment cnt
            }
        }
        nums = ans; // reassign the array
        return cnt;
    }

    // using the optimum approach
        int removeElementop(vector<int>& nums, int val) {
            int k = 0;// a variable to place the elements of the array as answer and return as  the integer value
            for(int num:nums){ // iterating all the values
                if(num != val){ // comparing
                    nums[k] = num; // assigning the right value to nums
                    k++; // increasing to get the count
                }
            }
            return k; 
        }
    };


    int main(){
        Solution s;
        vector<int> nums = {3,2,2,3};
        int val = 3;
        cout<<s.removeElementme(nums,val)<<endl;
        cout<<s.removeElementop(nums,val)<<endl;
        return 0;
    }