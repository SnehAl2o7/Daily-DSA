#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int MaxAbs(vector<int> &arr){
        int sum = 0;
        sort(arr.begin(),arr.end());
        int len = arr.size()/2;
        int i = 0, j= arr.size()-1;
        while(len-- > 0 && i < j){
            sum += abs(arr[i] - arr[j]);
            i++;
            j--;
        }
        return sum;
    }
};

int main (){
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << obj.MaxAbs(arr) << endl;
    return 0;
}

