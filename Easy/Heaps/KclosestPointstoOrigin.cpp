#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findClosestPoints(vector<pair<int, int>>arr, int k){
    priority_queue<pair<int, pair<int, int>>>maxH;
    for (int i = 0; i < arr.size(); i++)
    {   
        int first = arr[i].first;
        int second = arr[i].second;
        int dist = pow(first + second, 2);
        maxH.push({dist, {first, second}});
        if(maxH.size() > k){
            maxH.pop();
        }
    }

    vector<pair<int, int>>ans;

    while(!maxH.empty()){
        ans.push_back({maxH.top().second});
        maxH.pop();
    }
    
    return ans;
}

int main()
{
    vector<pair<int, int>>arr = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    vector<pair<int, int>>ans = findClosestPoints(arr, 2);
    for(auto i : ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}