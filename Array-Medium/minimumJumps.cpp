class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0]; // Maximum index we can reach
    int steps = arr[0];     // Steps we can take
    int jumps = 1;          // Jumps needed

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps; // Reached the last index

        maxReach = max(maxReach, i + arr[i]); // Update maxReach
        steps--; // Use one step to move forward

        if (steps == 0) { // If no steps left
            jumps++; // Take a jump
            if (i >= maxReach) return -1; // Cannot move forward
            steps = maxReach - i; // Reset steps
        }
    }

    return -1;
    }
};

int main(){
  
}
