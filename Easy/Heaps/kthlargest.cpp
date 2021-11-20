#include<bits/stdc++.h>
using namespace std;

vector<int> kLargest(vector<int>arr, int k){
    priority_queue<int, vector<int>, greater<int>>minH;            // since we need to find the largest we will make a min Heap
    for(int i=0; i<arr.size(); i++){
        minH.push(arr[i]);
        if(minH.size() > k){
            minH.pop();
        }
    }
    vector<int> ans;
    while(!minH.empty()){
        ans.push_back(minH.top());
        minH.pop();
    }
    return ans;
}

int main()
{
    vector<int>arr = {7, 10, 4, 3, 20, 15};
    vector<int>ans = kLargest(arr, 3);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}