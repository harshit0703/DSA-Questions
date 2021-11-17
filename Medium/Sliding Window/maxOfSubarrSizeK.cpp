#include<bits/stdc++.h>
using namespace std;

vector<int> subarrMax(vector<int> arr, int k){
    vector<int> ans;
    int maxEle = INT_MIN;

    int i = 0;
    int j = 0;

    if(k > arr.size()){
        ans.push_back(*max_element(arr.begin(), arr.end()));        // edge case
        return ans;
    }

    while(j < arr.size()){
        if(arr[j] > maxEle){
            maxEle = arr[j];
        }

        if(j - i + 1 < k){
            j++;
        }

        else if(j - i + 1 == k){
            ans.push_back(maxEle);
            if(arr[i] == maxEle){
                maxEle = INT_MIN;
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = subarrMax(arr, 3);
    for( auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}