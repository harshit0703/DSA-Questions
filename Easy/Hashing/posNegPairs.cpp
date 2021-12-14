#include<bits/stdc++.h>
using namespace std;

// in this question there is no need for hashing

vector<int> PosNegPair(int arr[], int n){

    sort(arr, arr+n);
    int st = 0;
    int en = n-1;

    vector<int>ans;

    while(st < en){
        if(arr[st] + arr[en] == 0){
            ans.push_back(arr[en]);
            ans.push_back(arr[st]);
            st++;
            en--;
        }
        else if(abs(arr[st]) < arr[en]){
            en--;
        }else{
            st++;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int arr[] = {4, 8, 9, -4, 1, -1, -8, -9};
    vector<int> ans = PosNegPair(arr, 8);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}