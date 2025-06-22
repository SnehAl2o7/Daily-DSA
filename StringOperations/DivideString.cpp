#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();

        int i;
        for(i = 0;i+k <= n;i+=k){
            ans.push_back(s.substr(i,k));
        }
        
        if(i< n){
            string st = s.substr(i);
            st += string(k-st.length(),fill);
            ans.push_back(st);
        }

        return ans;

    }
};

int main(){
    string s = "qweqrterdsfgdfgdf";
    int k = 5;
    char fill = 'z';
    Solution obj;
    vector<string> ans = obj.divideString(s,k,fill);

    for(string s : ans){
        cout << s << ",";
    }
}