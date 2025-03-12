#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minTimeToVisitAllPoints(vector<vector<int>>& points) {
            int n = points.size(); // calculating the size of array
            int cnt=0; // to store the time taken
            for(int i = 1;i < n;i++){
                // checking the value of difference between the x1 and x2 and y1 and y2 then storing the max value to the cnt variable.
                // by checking this we can tell their distance from where one point ot anothr
                int sub1 = abs(points[i][0] - points[i-1][0]); 
                int sub2 = abs(points[i][1] - points[i-1][1]);
                cnt += max(sub1,sub2); // storing the elements to mae a 
            }
            return cnt;
        }
        
};

int main (){
    Solution obj;
    vector<vector<int>> points = {{1,1},{3,4},{5,6}};
    cout << obj.minTimeToVisitAllPoints(points)<<endl;


}