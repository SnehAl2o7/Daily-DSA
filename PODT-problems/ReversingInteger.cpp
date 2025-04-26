#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int ans = 0; // to store the value 
            while(x != 0){ // the answer 
                int digit = x%10; // the remainder to add
                // check for the overflow condition 
                if((ans>INT_MAX/10)||(ans<INT_MIN/10)){ 
                    return 0; // if found return 0
                }
                 // rest reversing the number
                ans = (ans*10)+digit;
                // decreasing the number
                x /= 10;
            }
            return ans;
        }
    };

int main(){
    Solution obj;
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;
    cout << obj.reverse(n) << endl;
    }
    return 0;
}