#include<bits/stdc++.h>
using namespace std;

vector<int> kClosestNos(vector<int>arr, int k, int x){
    priority_queue<pair<int,int>>maxH;
    for (int i = 0; i < arr.size(); i++)
    {
        int diff = abs(x - arr[i]);
        maxH.push({diff, arr[i]});        // when we make a heap with a pair it automatically perform its func acc to first value
        if(maxH.size() > k){
            maxH.pop();
        }
    }

    vector<int> ans;

    while(!maxH.empty()){
        pair<int, int>p = maxH.top();
        ans.push_back(p.second);
        maxH.pop();
    }
    
    return ans;
}

int main()
{
    vector<int>arr = {5, 6, 7, 8, 9};
    int k = 3;  // how many closest numbers you want
    int x = 7;  // from what number you want to look for the closest numbers
    vector<int>ans = kClosestNos(arr, k, x);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}