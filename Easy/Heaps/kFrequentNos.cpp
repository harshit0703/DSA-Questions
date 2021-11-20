#include<bits/stdc++.h>
using namespace std;

vector<int> findkFreqNos(vector<int>arr, int k){
    unordered_map<int, int>mp;
    for(auto i : arr){
        mp[i]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minH;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        minH.push({i->second, i->first});
        if(minH.size() > k){
            minH.pop();
        }
    }

    vector<int> ans;
    while(!minH.empty()){
        ans.push_back(minH.top().second);
        minH.pop();
    }
    
    return ans;
}

int main()
{
    vector<int>arr = {1, 1, 1, 3, 2, 2, 4};
    vector<int>ans = findkFreqNos(arr, 2);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}