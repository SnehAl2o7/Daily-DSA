#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> DifffreqNear(vector<int> arr){
        map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }
        
        vector<int>ans(arr.size(),-1);
        stack<pair<int,int>>st;
        
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                st.push({i,mp[arr[i]]});
            }
            else{
                while(!st.empty()&&arr[i]!=arr[st.top().first] && mp[arr[i]] > st.top().second){
                    ans[st.top().first]=arr[i];
                    st.pop();
                }
                
                st.push({i,mp[arr[i]]});
            }
        }
        
        return ans;
    }
};


int main(){
    
}