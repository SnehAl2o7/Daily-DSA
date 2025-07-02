#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int SubsequenceAtmost(vector<int> arr){
             int n=arr.size();
         set<int>st; int s=0,e=0 , maxi=0;
         while(e<n){
             st.insert(arr[e]);
             if(st.size()<=2){
                 maxi=max(maxi,e-s+1);
                 e++;
             }
             else{
                st.erase(arr[s]);
                 s++;e=s;
             }
         }
         return maxi;
        }
};

int main(){
    
}