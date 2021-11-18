#include<bits/stdc++.h>
using namespace std;

int largestSubarrSize(vector<int> arr, int sum){        // this approach won't work for negative nos as here we assume once 
    int i = 0;                                          // we are greater than the requrired sum we cannot increase the size
    int j = 0;                                          // of the window as it will only increase the current sum but this
    int currSum = 0;                                    // may not be true in the case of negative nos
    int ans = -1;

    while(j < arr.size()){
        currSum += arr[j];
        if(currSum < sum){
            j++;
        }
        else if(currSum > sum){
            while(currSum > sum){
                currSum -= arr[i];
                i++;
            }
            j++;
        }
        else if(currSum == sum){
            int size = j - i + 1;
            ans = max(ans, size);
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 1, 1, 1, 2, 3, 5};
    int ans = largestSubarrSize(arr, 5);
    cout<<ans;
    return 0;
}