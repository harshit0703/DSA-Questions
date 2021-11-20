#include<bits/stdc++.h>
using namespace std;

int connectRopes(vector<int>arr){
    priority_queue<int, vector<int>, greater<int>>minH;
    for(auto i : arr){
        minH.push(i);
    }

    int sum = 0;
    while(minH.size() >= 2){
        int first = minH.top();
        minH.pop();
        int second = minH.top();
        minH.pop();
        sum += first + second;
        minH.push(first + second);
    }

    return sum;
}

int main()
{
    vector<int>arr = {1, 4 ,3, 2, 5};
    int ans = connectRopes(arr);
    cout<<ans;
    return 0;
}