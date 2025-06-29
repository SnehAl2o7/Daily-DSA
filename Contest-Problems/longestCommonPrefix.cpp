#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int commonPrefixLen(const string& a, const string& b) {
    int len = min(a.length(), b.length());
    for (int i = 0; i < len; ++i)
        if (a[i] != b[i]) return i;
    return len;
}

vector<int> longestCommonPrefix(vector<string>& words) {
    int n = words.size();
    if (n == 1) return {0};

    vector<int> lcp(n - 1);
    for (int i = 0; i < n - 1; ++i)
        lcp[i] = commonPrefixLen(words[i], words[i + 1]);

    // prefix max
    vector<int> prefixMax(n - 1), suffixMax(n - 1);
    prefixMax[0] = lcp[0];
    for (int i = 1; i < n - 1; ++i)
        prefixMax[i] = max(prefixMax[i - 1], lcp[i]);

    suffixMax[n - 2] = lcp[n - 2];
    for (int i = n - 3; i >= 0; --i)
        suffixMax[i] = max(suffixMax[i + 1], lcp[i]);

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        int maxLCP = 0;
        if (i > 1) maxLCP = max(maxLCP, prefixMax[i - 2]);
        if (i < n - 2) maxLCP = max(maxLCP, suffixMax[i + 1]);
        if (i > 0 && i < n - 1)
            maxLCP = max(maxLCP, commonPrefixLen(words[i - 1], words[i + 1]));
        result[i] = maxLCP;
    }
    return result;
}
};


int main(){}