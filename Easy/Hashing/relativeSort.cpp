#include<bits/stdc++.h>
using namespace std;

vector<int> relativeSort(vector<int>& arr1, vector<int>& arr2){

    map<int, int>mp;    // ordered map is required to store the remaining elements in sorted way
    for(auto i : arr1){
        mp[i]++;
    }

    vector<int> ans;

    for(auto i : arr2){

        if(mp.find(i) != mp.end()){
            auto temp = mp.find(i);
            int count = temp->second;
            vector<int>v(count, i); // this is shorthand to create a vector with value i count number of times
            ans.insert(ans.end(), v.begin(), v.end()); // this will insert the complete v at the end of ans vector
            mp.erase(i);
        }

    }

    for(auto i : mp){
        int ele = i.first;
        int count = i.second;
        vector<int>v(count, ele);
        ans.insert(ans.end(), v.begin(), v.end());
    }

    return ans;

}

int main()
{
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> ans = relativeSort(arr1, arr2);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}