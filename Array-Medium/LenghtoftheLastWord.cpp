#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int i = s.size() - 1; // we start from the last of the string.
            long long cnt = 0; // to calculate the length of the last string
            while(i >=0){ // check that loop get end if string is empty
                if(s[i] != ' '){ // checking that if no space found we increase the size of len
                    cnt++;
                }
                if(cnt > 0 && s[i] == ' '){ // checking that if last string is over and a space is encountered we break the loop to get the solution.
                    break;
                }
                i--; // to iterate over elements
            }
            return cnt; // return len
        }
};
     // this is to minimize the space 
auto init = []()
{ 
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return 'c';
}();


int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.lengthOfLastWord(str)<<endl;
    return 0;
}