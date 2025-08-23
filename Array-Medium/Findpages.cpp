bool check(vector<int> &arr, int k, int mid) {
        int cnt = 1;  // Start with one student
        int maxe = 0; // Current pages assigned to the current student
        
        for (int x : arr) {
            // If adding the current book doesn't exceed mid
            if (maxe + x <= mid) {
                maxe += x; // Add the book to the current student
            } else {
                ++cnt;    // Need a new student
                maxe = x; // Start the new student with the current book
            }
        }
        
        // Check if the number of students used is <= k
        return (cnt <= k);
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        // If there are fewer books than students, allocation is impossible
        if (n < k) return -1;
        
        // The minimum possible maximum is at least the largest book
        int low = *max_element(arr.begin(), arr.end());
        // The maximum possible maximum is the sum of all pages
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        // Binary search over the range [low, high]
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Check if mid is feasible
            if (check(arr, k, mid)) {
                ans = mid;   // Update answer to mid
                high = mid - 1; // Try for a smaller value
            } else {
                low = mid + 1; // Try for a larger value
            }
        }
        return ans;
    }
