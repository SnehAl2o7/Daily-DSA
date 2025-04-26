#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st; // creating a stack to implement logic
            for(int i = 0;i < s.size();i++){
                if(s[i] == '(' || s[i] == '{' || s[i] == '['){ // checking for opening in the string
                    st.push(s[i]); // if found push the char
                }
                else {
                    if(st.empty()) return false; // checking for empty
                if(s[i] == ')' && st.top() == '(' ) st.pop(); // popping
                else if ( s[i] == '}' && st.top() == '{' ) st.pop();
                else if (s[i] == ']' && st.top() == '[' ) st.pop();
                else return false; // if not return fasle;
                }
            }
    
            return st.empty();
        }
    };


    int main (){
        Solution obj;
        string s = "([]{{})";
        cout << boolalpha << obj.isValid(s) << endl;
        return 0;
    }