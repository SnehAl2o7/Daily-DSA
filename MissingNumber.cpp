#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Self came up solution
        int missingNumberSort(vector<int>& nums) {
            sort(nums.begin(),nums.end());//sort the array in sequence
            int n = nums.size();//getting lenght of array
            for(int i = 0;i<n;i++){
                if(i != nums[i]){ //checking the index is missing by comparing with which increase in a sequence
                    return i; //returning missing
                }
            }
            return n; //if all number till n-1 are there return n 
        }

        // Optimum solution
        int missingNumberXor(vector<int>& nums) {
            int n = nums.size(); //size
            int XorSum = 0; // calculating xor of all number from 0 to n
            for(int i = 0;i<=n;i++){
                XorSum ^= i; // storing xor from 0 to n
            }
            int XorNums = 0; // calculating xor of all number in array
            for(int i : nums){
                XorNums ^= i; // storing xor of all number in array
            }
            return XorSum^XorNums; // calculating value to return answer
        }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,3};
    cout<<s.missingNumberSort(nums)<<endl;
    cout<<s.missingNumberXor(nums)<<endl;
    return 0;
}