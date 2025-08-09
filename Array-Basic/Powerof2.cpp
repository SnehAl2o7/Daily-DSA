class Solution {
   public:
   bool is Powerof2(int n){
     return n>0 && (n & (n-1)) == 0;
   }
};
