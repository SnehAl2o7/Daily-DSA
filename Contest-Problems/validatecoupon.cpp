#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int, string>> validCoupons;
        unordered_map<string, int> businessPriority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        for (int i = 0; i < code.size(); i++) {
            if (validateString(code[i]) && businessPriority.count(businessLine[i]) && isActive[i]) {
                validCoupons.push_back({businessPriority[businessLine[i]], code[i]});
            }
        }

        sort(validCoupons.begin(), validCoupons.end());

        vector<string> result;
        for (auto& p : validCoupons) {
            result.push_back(p.second);
        }
        return result;
    }

    bool validateString(const string& input) {
        if (input.empty()) return false;
        for (char ch : input) {
            if (!isalnum(ch) && ch != '_') {
                return false;
            }
        }
        return true;
    }

};

int main(){
    
}