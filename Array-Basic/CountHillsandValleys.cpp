#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        std::vector<int> unique;
        for (int num : nums) {
            if (unique.empty() || unique.back() != num) {
                unique.push_back(num);
            }
        }

        if (unique.size() < 3) return 0;

        int count = 0;
        for (int i = 1; i < unique.size() - 1; ++i) {
            if ((unique[i] > unique[i - 1] && unique[i] > unique[i + 1]) ||
                (unique[i] < unique[i - 1] && unique[i] < unique[i + 1])) {
                ++count;
            }
        }

        return count;
    }
};

int main(){
    return 0;
}