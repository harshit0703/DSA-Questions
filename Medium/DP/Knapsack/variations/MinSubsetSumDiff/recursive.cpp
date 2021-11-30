#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n){
    
    if(n == 0 || sum == 0){
        return true;
    }

    if(arr[n-1] > sum){
        return subsetSum(arr, sum, n-1);
    }

    return subsetSum(arr, sum, n-1) || subsetSum(arr, sum - arr[n-1], n-1);

}

int main()
{
    int arr[] = {1, 5, 11, 6};
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += arr[i];
    }
    
    // we need to check for each value from 0 to sum/2 if a subset exist or not

    int ans = INT_MAX;

    for(int i = 0; i <= sum/2; i++){
        if(subsetSum(arr, i, 4)){
            ans = min(ans, sum - 2*i);
        }
    }
    cout<<ans;
    return 0;
}