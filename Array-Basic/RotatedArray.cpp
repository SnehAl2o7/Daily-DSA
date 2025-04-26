#include<bits/stdc++.h>
using namespace std;

// using the in-built reverse approach
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k = k%n; // making k in range [0, n)
            reverse(nums.begin(),nums.begin()+ (n-k)); // reversing the starting part before k elements
            reverse(nums.begin()+(n-k),nums.end()); // reversing the part after k elements
            reverse(nums.begin(),nums.end()); // reversing the whole array
        }

    // using the O(n) space approach
    void rotateSpace(vector<int>& nums, int k) {
        int n = nums.size(); // size fo array
       k = k%n; // making k in range [0, n)
       vector<int> rotated(n,0); // initailzing the rotated array
       int diff = n-k; // storing the rotated index
       int i = 0; // index to insert in rotated
       while(n-k < n){ // loop till all elements are inserted
            rotated[i] = nums[n-k]; // inserting the element at the rotated index
            i++; // incrementing the index
            k--; // decrementing k
       }

       // inserting the remaining elements
       for(int j = 0;j < diff;j++){
            rotated[i] = nums[j];
            i++;
       }

       // copying the rotated array to the original array
       nums = rotated;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3,4,5,6,7};
    cout << "before rotation : "<< endl;
    for(int i: nums){
        cout<<i<<" ";
    }

    obj.rotate(nums,3);
    cout << "\nafter rotation : "<< endl;
    for(int i: nums){
        cout<<i<<" ";
        }
    
    obj.rotateSpace(nums,3);
    cout << "\nafter rotation using space : "<< endl;   
    for(int i: nums){
        cout<<i<<" ";
        }
        
        return 0;
}