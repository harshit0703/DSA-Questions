#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v = {1,3,2,4};
    vector<int> ans;
    stack<int> st;
    for(int i= v.size()-1; i>=0; i--){

        // the stack is always containing the right most remaining vector for every element
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            while(!st.empty() && st.top() <= v[i]){
                st.pop();
            }
            ans.push_back(st.top());
        }

        st.push(v[i]);
    }

    // in this way we only traverse the given vector 1 time hence the optimized time compexity becomes O(n) instead of O(n^2)

    reverse(ans.begin(), ans.end());

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}