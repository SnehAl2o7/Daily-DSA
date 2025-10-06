#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfMode(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        int sum = 0;
        for (auto& [num, f] : freq) {
            if (f == maxFreq) {
                sum += num;
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    cout << solution.sumOfMode(nums) << endl;
    return 0;
}
