#include<bits/stdc++.h>
using namespace std;

vector<int> freqSort(vector<int> arr){
    priority_queue<pair<int, int>>maxH;
    unordered_map<int, int> mp;
    for(auto i : arr){
        mp[i]++;
    }
    for(auto i = mp.begin(); i != mp.end(); i++){
        maxH.push({i->second, i->first});
    }
    
    vector<int>ans;

    while(!maxH.empty()){
        int cnt = maxH.top().first;
        for (int i = 0; i < cnt; i++)
        {
            ans.push_back(maxH.top().second);
        }
        maxH.pop();
    }

    return ans;
}

int main()
{
    vector<int>arr = {1, 1, 1, 3, 2, 2, 4, 4, 4};
    vector<int>ans = freqSort(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}