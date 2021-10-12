#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    // TC = O(n)
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans;
    stack<pair<int,int>> st;  // the first part will contain the element and  the second will contain the indexes

   for(int i=0; i<v.size(); i++){
       if(st.empty()){
           ans.push_back(-1);
       }
       else{
           while(!st.empty() && st.top().first <= v[i]){
               st.pop();
           }
           if(st.empty()){
               ans.push_back(-1);
           }else{
               ans.push_back(st.top().second); // ans will contain the indexes of the nearest largest to left elements
           }
       }
        st.push({v[i], i});

   }
    for(int i=0 ; i<ans.size(); i++){
        ans[i] = i - ans[i];
        cout<<ans[i]<<" ";
    }
    return 0;
}