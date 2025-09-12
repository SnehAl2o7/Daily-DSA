class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = arr[n-1] - arr[0];
        int tempmin,tempmax;
        tempmin = arr[0];
        tempmax = arr[n-1];
        
        for(int i = 1;i<n;i++){
            if(arr[i] - k < 0){
                continue;
            }
            tempmin = min(arr[0] + k,arr[i] -k);
            tempmax = max(arr[i-1]+k,arr[n-1]-k);
            ans = min(ans,tempmax - tempmin);
        }
        return ans;
    }
};
