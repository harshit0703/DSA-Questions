#include<bits/stdc++.h>
using namespace std;

stack<int> minStack;
int minele;

void push(int val){
    if(minStack.empty()){
        minele = val;
        minStack.push(val);
    }else if (val <= minele){
        minStack.push(2*val - minele);
        minele = val;
    }else{
        minStack.push(val);
    }
}

int pop(){
    if(minStack.empty()){
        return -1;
    }else if(minStack.top() < minele){
        minele = 2 * minele - minStack.top();
    }
    minStack.pop();
}

int minEle(){
    if(minStack.empty()) return -1;
    return minele;
}

vector<int> findNgr(vector<int> v){
    stack<int> st;
    vector<int> ans;

    for(int i = v.size() - 1; i >= 0; i--){
       if(st.empty()){
           ans.push_back(-1);
       }else{
           while(st.top() <= v[i]){
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

    reverse(ans.begin(), ans.end());
    return ans;

}

vector<int> stockSpan(vector<int> v){
    stack<pair<int, int>> st;
    vector<int> ans;

    for(int i = 0; i < v.size(); i++){
        if(st.empty()){
            ans.push_back(1);
        }else{
            while(st.top().first <= v[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(1);
            }else{
                ans.push_back(i - st.top().second);
            }
        }

        st.push({v[i], i});
    }

    return ans;
}

int MAH(vector<int> heights){

    // we need to calculate the max width possible for the rectangle at each bar and this can be found by finding the indexes of NSL and NSR

    // first finding NSL
    stack<pair<int, int>> st;
    vector<int> nsl;
    for(int i = 0; i < heights.size(); i++){
        if(st.empty()){
            nsl.push_back(-1);
        }
        else{
            while(st.top().first >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                nsl.push_back(-1);
            }else{
                nsl.push_back(st.top().second);
            }
        }

        st.push({heights[i], i});
    }

    // secondly finding NSR
    stack<pair<int, int>> en;
    vector<int> nsr;
    for(int i = heights.size() - 1; i >= 0; i--){
        if(en.empty()){
            nsr.push_back(heights.size());
        }else{
            while(en.top().first >= heights[i]){
                en.pop();
            }
            if(en.empty()){
                nsr.push_back(heights.size());
            }else{
                nsr.push_back(en.top().second);
            }
        }

        en.push({heights[i], i});
    }

    reverse(nsr.begin(), nsr.end());


    // now finding the max area 
    int ans = INT_MIN;
    for(int i = 0; i < heights.size(); i++){
        int area = (nsr[i] - nsl[i] - 1) * heights[i];
        ans = max(area, ans);
    }

    return ans;

}

int largestRectBinaryMatrix(vector<vector<int>> v){
    vector<int> buildings(v.size(), 0);
    int ans = INT_MIN;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == 0){
                buildings[j] = 0;
            }else{
                buildings[j] += 1;
            }
        }

        int area = MAH(buildings);
        ans = max(ans, area);
    }

    return ans;
}


int main()
{
    vector<int> v = {6, 2, 5, 4, 5, 1, 6};
    // vector<int> NGR = stockSpan(v);
    // for(auto i : NGR){
    //     cout<<i<<" ";
    // }
    int ans = MAH(v);
    cout<<ans;
    return 0;
}