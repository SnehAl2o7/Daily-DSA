#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    // the solution made by me it's not even using extra space until a carry condtion 
    // 9,99,999,.. came up but it is still not giving a 100% space optimization

    // 100% time optimized solution
        vector<int> plusOneme(vector<int>& d) {
            int n = d.size(); // get the size
            int i = n-1; // to access the last element
            int carry = 1; // using carry for addition
            while(i >= 0){ // iterating d
                
                if(d[i] + carry == 10){ // if adding last digit create a carry
                    d[i] = 0;
                }
                else { // if no carry is generated.
                    d[i] += carry;
                    carry = 0; // making carry 0
                }
                i--;
            }
    
            if(carry == 1){ // if after summing the carry still remains 1
                vector<int> ans(n+1,0); // making a vector of size n +  1
                // initializing pointer for accessing elements
                i = ans.size() - 1; 
                int j = n-1;
            while(j >= 0){
                ans[i] = d[j]; // assigning values to ans
                i--;
                j--;
            }
                ans[0] = 1; // when all the elements are accessed asssiging 1 to start for 9,99,999,9999,.. cases
                return ans;
            }
            // if no carry is found then return the original array d
            return d;
        }


        // 100% time and space optimized solution
        vector<int> plusOneop(vector<int>& d) {
            vector<int> ans;
            int carry = 1;
            for(int i = d.size()-1;i >= 0;i--){
                if(d[i]+carry > 9){
                    ans.push_back(0);
                }
                else {
                    ans.push_back(d[i] + carry);
                    carry = 0;
                }
            }
            if(carry > 0) ans.push_back(carry);
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> d(n);
    for(int i = 0;i < n;i++){
        cin>>d[i];
    }
    // vector<int> ans = s.plusOneme(d);
    // for(int num : ans){
    //     cout << num << " ";
    // }

    vector<int> ans1 = s.plusOneop(d);
    for(int num : ans1){
        cout << num << " ";
    }
    return 0;

}