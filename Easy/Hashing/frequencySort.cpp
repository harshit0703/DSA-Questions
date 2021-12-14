#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int>& v){
    map<int, int>mp;
    for(auto i : v){
        mp[i]++;
    }

    sort(v.begin(), v.end(), [&](int a, int b){
        return mp[a] != mp[b] ? mp[a] < mp[b] : a > b; // this thing is called lamda function which is used to manipulate the built in funtions according to the user needs
    });

    return v;

}

int main()
{
    vector<int>v = {-1,1,-6,4,5,-6,1,4,1};
    vector<int>ans = frequencySort(v);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}