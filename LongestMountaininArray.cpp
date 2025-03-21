#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestMountain(vector<int>& arr) {
            int n = arr.size(); // calculating the size of array
            int mount = 0; // mount the height of mountain
            for(int i =1;i < n-1;i++){ // loop from i = 1 as 0 and n-1 cannot be the 
            // top of mountain
                if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){ // checking for peak of mountain
                    int a = i-1, b = i+1; // to checking the lenght of mountain on both sides 
                    int mex = 3; // minimum size of a mountain
                    while(a > 0 && arr[a] > arr[a-1]){ // checking for the left array to check for condition
                        mex++;
                        a--;
                    }
                    while( b < n-1 && arr[b] > arr[b+1] ){ // checking for right array to check for condition
                        mex++;
                        b++;
                    }
                    mount = max(mount,mex); // calculating the longest of mountain from all peeks
                } 
            }
            return mount; // returning the mountain length
        }
    };

int main(){
    Solution s;
    vector<int> arr = {2,2,2};
    vector<int> arr1 = {2,1,4,7,3,2,5};
    cout<<s.longestMountain(arr)<<endl;
    cout<<s.longestMountain(arr1)<<endl;
    return 0;
}