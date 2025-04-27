#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
            // use the map to get the single occurenece
            unordered_map<int,int> mpp;
            for(int i:nums){
                mpp[i]++;
            }
    
            for(auto it:mpp){ // iterate over the map
                if(it.second == 1) return it.first;
            }
            return 0;
    
            
        }

        int singleNumberXor(vector<int>& nums) {
            // using the XOR operation to get the occurrence
            int XOR_value = 0;
        for(int i:nums){
            XOR_value ^= i; // using XOR as a^a = 0 and a^0 = a using this in loop we get the 
            // single occurence
        }
        return XOR_value;
        }
    };

int main(){
    vector<int> nums = {2,2,1,3,4,5,4,3,5};
    Solution obj;
    cout<<obj.singleNumber(nums)<<endl;
    cout<<obj.singleNumberXor(nums)<<endl;
}