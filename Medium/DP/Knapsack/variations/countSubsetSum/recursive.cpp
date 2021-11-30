#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int sum, int n){
    if(sum == 0){
        return 1;
    }

    if(n == 0){
        return 0;
    }

    if(arr[n-1] > sum){
        return countSubsetSum(arr, sum, n-1);
    }

    int ans = countSubsetSum(arr, sum, n-1) + countSubsetSum(arr, sum-arr[n-1], n-1);
    return ans;

}

int main()
{
    int arr[] = {2, 3, 5, 8, 10};
    int ans = countSubsetSum(arr, 10, 5);
    cout<<ans;
    return 0;
}