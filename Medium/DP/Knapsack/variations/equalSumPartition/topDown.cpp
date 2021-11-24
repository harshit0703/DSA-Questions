#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum){
    int DP[n+1][sum+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum + 1; j++){
            if(i == 0){
                DP[i][j] = false;
            }
            if(j == 0){
                DP[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum + 1; j++){

            if(arr[i-1] > j){
                DP[i][j] = DP[i-1][j];
            }

            else if(arr[i-1] <= j){

                bool included = DP[i-1][j - arr[i-1]];
                bool not_included = DP[i-1][j];

                DP[i][j] = included || not_included;

            }
        }
    }
    
    return DP[n][sum];
}

bool equalSumPartition(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if(sum % 2 != 0){
        return false;
    }

    if(subsetSum(arr, n, sum/2)){
        return true;
    }
    
    return false;
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    cout<<equalSumPartition(arr, 4);
    return 0;
}