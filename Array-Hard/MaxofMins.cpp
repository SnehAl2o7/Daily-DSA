class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
    vector<int> left(n, -1), right(n, n);

    // Step 1: Compute Previous Smaller Elements (PSE)
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push(i);
    }

    // Step 2: Compute Next Smaller Elements (NSE)
    while (!s.empty()) s.pop(); // Clear the stack
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top();
        }
        s.push(i);
    }

    // Step 3: Compute result array
    vector<int> ans(n + 1, INT_MIN);
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1; // Window size where arr[i] is minimum
        ans[len] = max(ans[len], arr[i]); // Store the maximum of minimums
    }

    // Step 4: Fill unfilled entries in ans array
    for (int i = n - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    // Return the result excluding the first dummy index
    return vector<int>(ans.begin() + 1, ans.end());
    }
};
