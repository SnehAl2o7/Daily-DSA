#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
  int fib(int n){
      int first=1,second=1;
      int sum=0;
      for(int i=3;i<=n;i++){
          sum=first+second;
          first=second;
          second=sum;
      }
      return sum;
  }
    int countConsec(int n) {
        return (1<<n) - fib(n+2);
    }
};

int main(){
    
}