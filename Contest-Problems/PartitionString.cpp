#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> partitionString(string s) {
         unordered_set<string> seen;
    vector<string> result;
    int n = s.length();

    int i = 0;
    while (i < n) {
        string current = "";
        int j = i;
        
        while (j < n) {
            current += s[j];
            if (seen.find(current) == seen.end()) {
                break; 
            }
            j++;
        }

       if (seen.find(current) == seen.end()) {
            result.push_back(current);
        }
        
       // result.push_back(current); 
        
        seen.insert(current);
        i = j + 1;
    }

    return result;
    }
};

int main(){}
