#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int,int> mpp;
            for(int i = 1;i <= n;i++){
                int sum = Digit_Sum(i);
                mpp[sum]++;
            }
            int Max_Size = 0;
            for(auto it: mpp){
                Max_Size = max(Max_Size,it.second);
            }
    
            int cnt = 0;
            for(auto it: mpp){
                if(Max_Size == it.second){
                    cnt++;
                }
            }
            return cnt;
        }
    
        int Digit_Sum(int k){
            int sum = 0;
            while(k != 0){
                sum += k%10;
                k /= 10;
            }
            return sum;
        }
    };

    int main(){
        Solution sol;
        int t;
        cin >> t;
        while(t--){
            int n;
        cin >> n;
        cout << sol.countLargestGroup(n) << endl;
        }
        return 0;
    }