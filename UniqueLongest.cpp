#include<bits/stdc++.h>
using namespace std;

vector<int> findUniqueLengthsOptimized(int n, int d, vector<vector<int>> &arr) {
    vector<int> lengths(n, 0);           // Store the current length of each node
    vector<int> result;                  // To store the unique counts for each day
    unordered_map<int, int> freq;        // Frequency map: length value -> count

    // Initially, all nodes have length 0.
    freq[0] = n;

    for (int i = 0; i < d; i++) {
        int node = arr[i][0] - 1;        // Convert to 0-based index
        int increase = arr[i][1];

        int oldLength = lengths[node];
        int newLength = oldLength + increase;
        lengths[node] = newLength;

        // Update frequency for the old length
        freq[oldLength]--;
        if (freq[oldLength] == 0) {
            freq.erase(oldLength);
        }

        // Update frequency for the new length
        freq[newLength]++;

        // The size of the frequency map gives the count of unique lengths
        result.push_back(freq.size());
    }

    return result;
}

int main() {
    int n = 5, d = 5;
    vector<vector<int>> arr = {
        {1, 2},  // Day 1: Increase node 1 by 2
        {2, 3},  // Day 2: Increase node 2 by 3
        {1, 1},  // Day 3: Increase node 1 by 1
        {3, 2},  // Day 4: Increase node 3 by 2
        {2, 1}   // Day 5: Increase node 2 by 1
    };

    vector<int> result = findUniqueLengthsOptimized(n, d, arr);

    // Print the unique count of lengths for each day
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
