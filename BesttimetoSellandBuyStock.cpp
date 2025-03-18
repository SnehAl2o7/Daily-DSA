#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // greedy two pointer approach
        int maxProfitgreedy(vector<int>& p) {
            int n = p.size();// getting the size of array
            int i = 0; // initial point
            int j = 1;// second point
            int profit = 0; // returning profit
            while(j != n){ // loop till right reach the end
               if(p[i] < p[j]){ // checking for smaller in left and greater in right
                int val = p[j] - p[i]; // assign the semi-profit value
                profit = max(profit,val); // update the max profit
               }
               else{ // if left is greater than right
                    i = j;  // restarting the search by assigning the value of j to i
                    // for me start of the problem
               }
               j++; // left increment
            }
            return profit; // returning profit
        }

        int maxProfitmin(vector<int>& prices) {
            int cnt =0; // cnt for max profit
            int min_prices = prices[0]; // to track the current minimum price
            for(int i=1;i<prices.size();i++) 
            {
                // cnt for updating the max profit
                    cnt = max(cnt,prices[i]-min_prices);
                    // min to update the minimum price
                    min_prices = min(prices[i],min_prices);
                
            }

            return cnt; // returning the max profit
    
        }
    };

int main (){
    int n;
    cin >>n;
    vector<int> prices(n);
    for(int i = 0;i<n;i++){
        cin >> prices[i];
    }
    Solution s;
    cout << s.maxProfitgreedy(prices) << endl;
    cout << s.maxProfitmin(prices) << endl;
    return 0;
}