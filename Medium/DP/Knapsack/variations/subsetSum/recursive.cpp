#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum){
    if(sum == 0){
        return true;        // if sum is 0 we will always have an empty subset
    }

    if(n == 0){
        return false;       // if there is no element in the array there is no possible ans exept for sum 0 which we have already 
                            // tackled
    }

    if(arr[n-1] > sum){
        return subsetSum(arr, n-1, sum);       // considering all elements are positive
    }

    bool included = subsetSum(arr, n-1, sum - arr[n-1]);
    bool not_included = subsetSum(arr, n-1, sum);

    return (included || not_included);

}

int main()
{
    int arr[] = {2, 3, 7, 8, 5};
    int sum = 11;
    cout<<subsetSum(arr, 5, sum);
    return 0;
}