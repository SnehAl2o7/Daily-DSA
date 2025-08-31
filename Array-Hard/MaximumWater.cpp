class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left = 0;                    // Left pointer
    int right = arr.size() - 1;      // Right pointer
    int maxWater = 0;                // Maximum water

    while (left < right) {
        // Calculate the width and height
        int width = right - left;
        int height = min(arr[left], arr[right]);

        // Calculate water and update maximum water
        int currentWater = width * height;
        maxWater = max(maxWater, currentWater);

        // Move the pointer pointing to the shorter line inward
        if (arr[left] < arr[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
    }
};

int main(){

}
