#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v = {4, 2, 3, 1};
    vector<int> ans;
    stack<int> st;
    for(int i= 0; i<v.size(); i++){

        // the stack is always containing the right most remaining vector for every element
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            while(!st.empty() && st.top() <= v[i]){
                st.pop();
            }

              if(st.empty()){
            ans.push_back(-1);
        }else{
            ans.push_back(st.top());
        }

        }

      st.push(v[i]);
    }

    // in this way we only traverse the given vector 1 time hence the optimized time compexity becomes O(n) instead of O(n^2)

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}