#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     string concatHex36(int n) {
        string ans = "";
        int sq = n * n;
        
        int cube = n * n * n;

        while (sq > 0) {
            int rem = sq % 16;
            ans += toHexChar(rem);
            sq /= 16;
        }
        reverse(ans.begin(), ans.end()); 
        int size = ans.size();
         
        while(cube > 0){
            int rem = cube % 36;
            ans += toHexaTri(rem);
            cube /= 36;
        }

        reverse(ans.begin() + size, ans.end()); 
        return ans;
    }

    char toHexChar(int n) {
        if (n < 10)
            return '0' + n;
        else {
            switch (n) {
                case 10: return 'A';
                case 11: return 'B';
                case 12: return 'C';
                case 13: return 'D';
                case 14: return 'E';
                case 15: return 'F';
                default: return '?'; 
            }
        }
    }

    char toHexaTri(int n){
         if (n >= 0 && n <= 9)
            return '0' + n;
        else {
            switch (n) {
                case 10: return 'A';
                case 11: return 'B';
                case 12: return 'C';
                case 13: return 'D';
                case 14: return 'E';
                case 15: return 'F';
                case 16: return 'G';
                case 17: return 'H';
                case 18: return 'I';
                case 19: return 'J';
                case 20: return 'K';
                case 21: return 'L';
                case 22: return 'M';
                case 23: return 'N';
                case 24: return 'O';
                case 25: return 'P';
                case 26: return 'Q';
                case 27: return 'R';
                case 28: return 'S';
                case 29: return 'T';
                case 30: return 'U';
                case 31: return 'V';
                case 32: return 'W';
                case 33: return 'X';
                case 34: return 'Y';
                case 35: return 'Z';
                default: return '?'; // Fallback for invalid input
            }
        }
    }
};

int main(){

}
