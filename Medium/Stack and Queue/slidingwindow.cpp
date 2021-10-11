#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(){
    // TC = O(n) by using deque
    int n, k;
    cin>>n>>k;
    vector<int> arr;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    vector<int> ans;
    deque<int> dq;

    for(int i=0; i<k; i++){
        
        while(!dq.empty() && arr[dq.back()] < arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        
    }

    ans.push_back(arr[dq.front()]); // for first window

    for(int i=k; i<n; i++){

        if(dq.front() == i-k){
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] < arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }

    for(int i: ans){
        cout<<i<<" ";
    }

    return 0;
}