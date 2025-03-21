class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int mount = 0;
        for(int i = 1;i < n-1;i++){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                int a = i-1, b = i+1;
                while(a > 0 && arr[a] > arr[a-1]){
                
                    a--;
                }
                while(b < n-1 && arr[b] > arr[b+1]){
                  
                    b++;
                }
                mount = Math.max(mount,b-a+1);
            }
        }
        return mount;
    }
}

public class longestMountainJava{
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] arr = {2,1,4,7,3,2,5};
        System.out.println(s.longestMountain(arr));
    }
}