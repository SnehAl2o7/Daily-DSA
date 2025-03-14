#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // near to optimum approach
        int removeDuplicatesme(vector<int>& nums) {
            int k = 0; // for accessing the unique elements
            int n = nums.size(); // size of nums
            if(n == 1){ // base case 
                return 1;
            }
            int i = 0; // intializing pointer
            while( i < n-1){ // iterating
                if(nums[i] != nums[i+1]){ // checking for unique
                    nums[k] = nums[i]; // assigning values to nums and removing uniques with different values
                    k++;
                }
                i++;
            }
            nums[k++] = nums[i]; // assigning the left digit
            return k; // returning the answer
        }

        // optimal approach
        int removeDuplicatesop(vector<int>& nums) {
            if(nums.size() == 0) return 0;
            int k = 1; // for accessing the unique elements 
            for(int i = 1; i < nums.size(); i++){ // accessing the elements
                if(nums[i] != nums[i-1]){ // checking for unique
                    nums[k] = nums[i]; // assigning values to nums and removing uniques with different values
                    k++;
                }
            }
            return k;
        }
    };


int main(){
    Solution s;
    vector<int> nums = {1,1,1,2,2,3,4};
    int val = s.removeDuplicatesme(nums);
    cout << val << endl;
    for(int i = 0; i < val; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
